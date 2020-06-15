/*
** EPITECH PROJECT, 2020
** IndieStudio
** File description:
** WindowHandler
*/

#include <irrlicht.h>
#include "WindowHandler.hpp"

indie::WindowHandler::WindowHandler(std::string name, int width, int heigh)
{
    this->device = createDevice(video::EDT_OPENGL, dimension2d<u32>(width, heigh), 16, false, false, true);
    this->music_activated = true;

    try {
        this->music = make_shared<sf::Music>();
    }
    catch (std::bad_alloc &e) {
        throw(Exception("can't create shared_ptr for Music"));
    }

    if (!device)
        throw(Exception("can't create device"));
    this->driver = this->device->getVideoDriver();
    this->smgr = this->device->getSceneManager();
    this->camera = this->smgr->addCameraSceneNode();
    this->guienv = this->device->getGUIEnvironment();
    this->device->setResizable(false);
    this->music->openFromFile("resources/music/bomberman_music.ogg");
    if (music == NULL)
        throw(Exception("can't load music"));
    this->music->play();
    this->music->setLoop(true);
    this->music->setVolume(0);

    this->setName(name);
    this->camera->setPosition(vector3df(0, -100, -10));
    this->camera->setTarget(vector3df(0, -100, 0));
    if (this->getVideoDriver()->getTexture("resources/cube/floor.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/cube/iron.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/cube/wood.png") == NULL)
        throw(Exception("can't load map texture"));
    if (this->getVideoDriver()->getTexture("resources/Images/logo_game_title_screen.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/Images/logo_game_white.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/Images/win.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/Images/logo_game_black.png") == NULL)
        throw(Exception("can't load menu image"));
    if (this->getVideoDriver()->getTexture("resources/particle/particle_red.bmp") == NULL ||
        this->getVideoDriver()->getTexture("resources/particle/particle_white.bmp") == NULL ||
        this->getVideoDriver()->getTexture("resources/particle/particle_green.jpg") == NULL)
        throw(Exception("can't load particule"));
    if (this->getVideoDriver()->getTexture("resources/buttons/play.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/play_on.jpg") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/options.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/options_on.jpg") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/quit.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/quit_on.jpg") == NULL)
        throw(Exception("can't load menu button"));
    if (this->getVideoDriver()->getTexture("resources/buttons/particules.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/particules_on.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/back.jpg") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/back_on.jpg") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/flame.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/flame_on.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/snow.png") == NULL||
        this->getVideoDriver()->getTexture("resources/buttons/snow_on.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/rain.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/rain_on.png") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/replay.jpg") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/replay_on.jpg") == NULL)
        throw(Exception("can't load particule button"));
    if (this->getVideoDriver()->getTexture("resources/buttons/start.jpg") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/start_on.jpg") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/multi.jpg") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/multi_on.jpg") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/solo.jpg") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/solo_on.jpg") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/load.jpg") == NULL ||
        this->getVideoDriver()->getTexture("resources/buttons/load_on.jpg") == NULL)
        throw(Exception("can't load game button"));
    if (this->getVideoDriver()->getTexture("resources/Character/texture/BlackBombermanTextures.png") == NULL ||
        this->getSceneManager()->getMesh("./resources/Character/model/Bomberman.MD3") == NULL ||
        this->getSceneManager()->getMesh("resources/bomb/bomb.obj") == NULL ||
        this->getVideoDriver()->getTexture("resources/bomb/ag-square.png") == NULL ||
        this->getSceneManager()->getMesh("./resources/powerUp/estrellica.obj") == NULL ||
        this->getSceneManager()->getMesh("./resources/powerUp/Dynamite/dinamite.obj") == NULL ||
        this->getSceneManager()->getMesh("./resources/powerUp/9mm.obj") == NULL ||
        this->getVideoDriver()->getTexture("./resources/powerUp/Dynamite/D.png") == NULL ||
        this->getVideoDriver()->getTexture("./resources/powerUp/9mm_texture.jpg") == NULL)
        throw(Exception("can't load character texture"));
    this->volume = 50;
    this->backgroundColor = SColor(0, 50, 50, 50);
    this->particle_activated = true;
    this->particle_type = PARTICLE_TYPE::RAIN;
}

indie::WindowHandler::~WindowHandler()
{
    this->music->stop();
    this->device->drop();
}

indie::WindowHandler &indie::WindowHandler::operator=(const WindowHandler &to_cmp)
{
    if (this == &to_cmp)
        return (*this);
    device = to_cmp.device;
    driver = to_cmp.driver;
    smgr = to_cmp.smgr;
    camera = to_cmp.camera;
    this->camera->setPosition(vector3df(0, 0, -10));
    return (*this);
}

void indie::WindowHandler::setName(std::string name)
{
    stringw str = L"";

    str += name.c_str();
    this->device->setWindowCaption(str.c_str());
}

void indie::WindowHandler::drawing(bool one, bool two, SColor color)
{
    this->driver->beginScene(one, two, color);
    this->smgr->drawAll();
}


IrrlichtDevice *indie::WindowHandler::getDevice()
{
    if (this->device == nullptr)
        return NULL;
    else if (this->device == NULL)
        return NULL;
    return (this->device);
}

void indie::WindowHandler::playNewMusic(const std::string filename)
{
    this->music->stop();
    this->music->openFromFile(filename);
    this->music->play();
    this->music->setLoop(true);
}

void indie::WindowHandler::clearGuiEnv() {
    const core::list<IGUIElement *> &list_elem = guienv->getRootGUIElement()->getChildren();

    while (!list_elem.empty())
        (*list_elem.getLast())->remove();
}

void indie::WindowHandler::clearSmgr() {
    const core::list<ISceneNode *> &list_elem = smgr->getRootSceneNode()->getChildren();

    while (!list_elem.empty())
        (*list_elem.getLast())->remove();
}

void indie::WindowHandler::setVolume(float new_volume) {
    this->volume = new_volume;
    this->music->setVolume(this->volume);
}

void indie::WindowHandler::addParticule(shared_ptr<Particle> &particle) {
    this->particles.push_back(particle);
    if (this->particle_activated == false)
        particle->setVisible(false);
}

void indie::WindowHandler::addParticuleExplosion(shared_ptr<Particle> &particle) {
    this->particles_explosion.push_back(particle);
    if (this->particle_activated == false)
        particle->setVisible(false);
}

void indie::WindowHandler::activateParticle() {
    int size = this->particles.size();

    this->particle_activated = true;
    for (int i = 0; i < size; i++)
        this->particles[i]->setVisible(true);
}

void indie::WindowHandler::desactivateParticle() {
    int size = this->particles.size();

    this->particle_activated = false;
    for (int i = 0; i < size; i++)
        this->particles[i]->setVisible(false);
}

void indie::WindowHandler::clearParticle()
{
    this->particles.clear();
}

void indie::WindowHandler::clearParticleExplosion()
{
    this->particles_explosion.clear();
}

bool indie::WindowHandler::getParticleActivated() const
{
    return (this->particle_activated);
}

indie::PARTICLE_TYPE indie::WindowHandler::getParticleType() const
{
    return (this->particle_type);
}

void indie::WindowHandler::setParticleType(PARTICLE_TYPE type)
{
    this->particle_type = type;
}

void indie::WindowHandler::checkParticleExplosion()
{
    int size = this->particles_explosion.size();
    u32 time = this->device->getTimer()->getTime();

    for (int i = 0; i < size; i++) {
        if (this->particles_explosion[i]->getLifeTime() < time) {
            this->particles_explosion.erase(this->particles_explosion.begin() + i);
        }
    }
}

void indie::WindowHandler::addExplosionSound()
{
    irrManager_t man;

    man.device = getDevice();
    man.smgr = getSceneManager();
    man.driver = getVideoDriver();
    try {
        this->explosion_sound.push_back(std::make_shared<SoundEffect>("resources/bomb/explosion_sound.ogg", 2000, man));
    }
    catch (std::bad_alloc &e) {
        throw(Exception("can't create shared_ptr for Music"));
    }
}

void indie::WindowHandler::checkExplosionMusic()
{
    for (int i = 0; i < explosion_sound.size(); i++) {
        if (this->explosion_sound[i]->timePassed() == 1) {
            this->explosion_sound.erase(this->explosion_sound.begin() + i);
            return;
        }
    }
}

void indie::WindowHandler::clearExplosionMusic()
{
    this->explosion_sound.clear();
}

void indie::WindowHandler::endScene() {this->driver->endScene();}
float indie::WindowHandler::getVolume(void) const {return (this->volume);}
IGUIEnvironment *indie::WindowHandler::getGuiEnv() {return (this->guienv);}
ICameraSceneNode *indie::WindowHandler::getCamera() {return (this->camera);}
ISceneManager *indie::WindowHandler::getSceneManager() {return (this->smgr);}
IVideoDriver *indie::WindowHandler::getVideoDriver() {return (this->driver);}
bool indie::WindowHandler::musicIsActivated() const {return (this->music_activated);}
SColor indie::WindowHandler::getBackgroundColor() const {return (this->backgroundColor);}
void indie::WindowHandler::setBackgroundColor(SColor color) {this->backgroundColor = color;}