/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** Laser
*/

#ifndef LASER_HPP_
#define LASER_HPP_

#include <vector>
#include "manager.h"

namespace indie
{
    class Laser
    {
    public:
        Laser();
        Laser(const core::vector3df &pos, const core::vector3df &radius, const float diam, const int range);
        Laser &operator=(const Laser &to_cmp);
        ~Laser();
        void setXp(const core::vector3df &pos, const core::vector3df &radius, const float diam, const int range);
        void setXm(const core::vector3df &pos, const core::vector3df &radius, const float diam, const int range);
        void setZp(const core::vector3df &pos, const core::vector3df &radius, const float diam, const int range);
        void setZm(const core::vector3df &pos, const core::vector3df &radius, const float diam, const int range);
        void setEndLaserXp(core::vector3d<f32> &end);
        void setEndLaserXm(core::vector3d<f32> &end);
        void setEndLaserZp(core::vector3d<f32> &end);
        void setEndLaserZm(core::vector3d<f32> &end);
        vector<core::line3d<f32>> getXp();
        vector<core::line3d<f32>> getXm();
        vector<core::line3d<f32>> getZp();
        vector<core::line3d<f32>> getZm();
        void dispLaser(irrManager_t &manager);

    protected:
    private:
        core::matrix4 mat;
        vector<core::line3d<f32>> rayXp;
        vector<core::line3d<f32>> rayXm;
        vector<core::line3d<f32>> rayZp;
        vector<core::line3d<f32>> rayZm;
        core::vector3d<f32> endXp;
        core::vector3d<f32> endXm;
        core::vector3d<f32> endZp;
        core::vector3d<f32> endZm;
    };
} // namespace indie

#endif /* !LASER_HPP_ */
