#include "Components.hpp"

enum {ID_IsNotPickable = 0, IDFlag_IsPickable = 1, IDFlag_IsHighlightable = 2};

indie::Components::Components(vector<vector3df> tabVector, float speed, std::string path) {
    if (path != "")
        this->path = path;
    this->speed = speed;
    this->pos = tabVector[1];
    this->Scale = tabVector[0];
    this->rotate = tabVector[2];
}
indie::Components::~Components() {
    this->path.clear();
}

void indie::Components::setAllData(vector<vector3df> tabVector, float speed, std::string path) {
    if (path != "")
        this->path = path;
    this->speed = speed;
    this->pos = tabVector[1];
    this->Scale = tabVector[0];
    this->rotate = tabVector[2];
}

void indie::Components::setPos(vector3df pos) {this->pos = pos;}
void indie::Components::setSpeed(float speed) {this->speed = speed;}
void indie::Components::setPath(std::string path) {this->path = path;}
void indie::Components::setScale(vector3df Scale) {this->Scale = Scale;}
void indie::Components::setRotate(vector3df pos) {this->rotate = rotate;}

void indie::Components::createSelector(WindowHandler &windowhdl, ITriangleSelector **selector) {
    ISceneManager *smgr= windowhdl.getSceneManager();
    IAnimatedMeshSceneNode *node = smgr->addAnimatedMeshSceneNode(smgr->getMesh(path.c_str()), 0, IDFlag_IsPickable | IDFlag_IsHighlightable);

    node->setScale(this->Scale);
    node->setPosition(this->pos);
    node->setRotation(this->rotate);
    node->setAnimationSpeed(this->speed);

    node->getMaterial(0).Lighting = true;
    node->getMaterial(0).NormalizeNormals = true;

    (*selector) = smgr->createTriangleSelector(node);
    node->setTriangleSelector(*selector);
    (*selector)->drop();
}
