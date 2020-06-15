/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Laser
*/

#include "Laser.hpp"

indie::Laser::Laser()
{
}

indie::Laser::Laser(const core::vector3df &pos, const core::vector3df &radius, const float diam, const int range)
{
    setZp(pos, radius, 0.4, range);
    setZm(pos, radius, 0.4, range);
    setXp(pos, radius, 0.4, range);
    setXm(pos, radius, 0.4, range);
}

indie::Laser::~Laser()
{
}

indie::Laser &indie::Laser::operator=(const Laser &to_cmp)
{
    mat = to_cmp.mat;
    rayXp = to_cmp.rayXp;
    rayXm = to_cmp.rayXm;
    rayZp = to_cmp.rayZp;
    rayZm = to_cmp.rayZm;
    endXp = to_cmp.endXp;
    endXm = to_cmp.endXm;
    endZp = to_cmp.endZp;
    endZm = to_cmp.endZm;
    return (*this);
}

void indie::Laser::setXp(const core::vector3df &pos, const core::vector3df &radius, const float diam, const int range)
{
    rayXp.push_back(core::line3d<f32>(core::vector3df(pos.X + radius.X, pos.Y, pos.Z), core::vector3df(pos.X + radius.X + range, pos.Y, pos.Z)));
    rayXp.push_back(core::line3d<f32>(core::vector3df(pos.X + radius.X, pos.Y + diam, pos.Z), core::vector3df(pos.X + radius.X + range, pos.Y + diam, pos.Z)));
    rayXp.push_back(core::line3d<f32>(core::vector3df(pos.X + radius.X, pos.Y - diam, pos.Z), core::vector3df(pos.X + radius.X + range, pos.Y - diam, pos.Z)));
    rayXp.push_back(core::line3d<f32>(core::vector3df(pos.X + radius.X, pos.Y, pos.Z + diam), core::vector3df(pos.X + radius.X + range, pos.Y, pos.Z + diam)));
    rayXp.push_back(core::line3d<f32>(core::vector3df(pos.X + radius.X, pos.Y, pos.Z - diam), core::vector3df(pos.X + radius.X + range, pos.Y, pos.Z - diam)));
}

void indie::Laser::setXm(const core::vector3df &pos, const core::vector3df &radius, const float diam, const int range)
{
    rayXm.push_back(core::line3d<f32>(core::vector3df(pos.X - radius.X, pos.Y, pos.Z), core::vector3df(pos.X - radius.X - range, pos.Y, pos.Z)));
    rayXm.push_back(core::line3d<f32>(core::vector3df(pos.X - radius.X, pos.Y + diam, pos.Z), core::vector3df(pos.X - radius.X - range, pos.Y + diam, pos.Z)));
    rayXm.push_back(core::line3d<f32>(core::vector3df(pos.X - radius.X, pos.Y - diam, pos.Z), core::vector3df(pos.X - radius.X - range, pos.Y - diam, pos.Z)));
    rayXm.push_back(core::line3d<f32>(core::vector3df(pos.X - radius.X, pos.Y, pos.Z + diam), core::vector3df(pos.X - radius.X - range, pos.Y, pos.Z + diam)));
    rayXm.push_back(core::line3d<f32>(core::vector3df(pos.X - radius.X, pos.Y, pos.Z - diam), core::vector3df(pos.X - radius.X - range, pos.Y, pos.Z - diam)));
}

void indie::Laser::setZp(const core::vector3df &pos, const core::vector3df &radius, const float diam, const int range)
{
    rayZp.push_back(core::line3d<f32>(core::vector3df(pos.X, pos.Y, pos.Z + radius.Z), core::vector3df(pos.X, pos.Y, pos.Z + radius.Z + range)));
    rayZp.push_back(core::line3d<f32>(core::vector3df(pos.X, pos.Y + diam, pos.Z + radius.Z), core::vector3df(pos.X, pos.Y + diam, pos.Z + radius.Z + range)));
    rayZp.push_back(core::line3d<f32>(core::vector3df(pos.X, pos.Y - diam, pos.Z + radius.Z), core::vector3df(pos.X, pos.Y - diam, pos.Z + radius.Z + range)));
    rayZp.push_back(core::line3d<f32>(core::vector3df(pos.X + diam, pos.Y, pos.Z + radius.Z), core::vector3df(pos.X + diam, pos.Y, pos.Z + radius.Z + range)));
    rayZp.push_back(core::line3d<f32>(core::vector3df(pos.X - diam, pos.Y, pos.Z + radius.Z), core::vector3df(pos.X - diam, pos.Y, pos.Z + radius.Z + range)));
}

void indie::Laser::setZm(const core::vector3df &pos, const core::vector3df &radius, const float diam, const int range)
{
    rayZm.push_back(core::line3d<f32>(core::vector3df(pos.X, pos.Y, pos.Z - radius.Z), core::vector3df(pos.X, pos.Y, pos.Z - radius.Z - range)));
    rayZm.push_back(core::line3d<f32>(core::vector3df(pos.X, pos.Y + diam, pos.Z - radius.Z), core::vector3df(pos.X, pos.Y + diam, pos.Z - radius.Z - range)));
    rayZm.push_back(core::line3d<f32>(core::vector3df(pos.X, pos.Y - diam, pos.Z - radius.Z), core::vector3df(pos.X, pos.Y - diam, pos.Z - radius.Z - range)));
    rayZm.push_back(core::line3d<f32>(core::vector3df(pos.X + diam, pos.Y, pos.Z - radius.Z), core::vector3df(pos.X + diam, pos.Y, pos.Z - radius.Z - range)));
    rayZm.push_back(core::line3d<f32>(core::vector3df(pos.X - diam, pos.Y, pos.Z - radius.Z), core::vector3df(pos.X - diam, pos.Y, pos.Z - radius.Z - range)));
}

void indie::Laser::dispLaser(irrManager_t &manager)
{
    manager.driver->setTransform(video::ETS_WORLD, mat);
    manager.driver->draw3DLine(rayXp[0].start, endXp, SColor(0, 255, 255, 255));
    manager.driver->draw3DLine(rayXm[0].start, endXm, SColor(0, 255, 255, 255));
    manager.driver->draw3DLine(rayZp[0].start, endZm, SColor(0, 255, 255, 255));
    manager.driver->draw3DLine(rayZm[0].start, endZp, SColor(0, 255, 255, 255));
}


vector<core::line3d<f32>> indie::Laser::getXp()
{
    return (rayXp);
}

vector<core::line3d<f32>>indie::Laser::getXm()
{
    return (rayXm);
}

vector<core::line3d<f32>> indie::Laser::getZp()
{
    return (rayZp);
}

vector<core::line3d<f32>> indie::Laser::getZm()
{
    return (rayZm);
}


void indie::Laser::setEndLaserXp(core::vector3d<f32> &end)
{
    endXp = end;
}

void indie::Laser::setEndLaserXm(core::vector3d<f32> &end)
{
    endXm = end;
}

void indie::Laser::setEndLaserZp(core::vector3d<f32> &end)
{
    endZp = end;
}

void indie::Laser::setEndLaserZm(core::vector3d<f32> &end)
{
    endZm = end;
}
