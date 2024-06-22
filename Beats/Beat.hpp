#ifndef BEAT_GAME_BEAT_HPP
#define BEAT_GAME_BEAT_HPP
#include "Engine/Headers.hpp"
#include "Lanes/Lane.hpp"
#include "Scene/PlayScene.hpp"
#include "Scene/MainMenu.hpp"
#include "UI/Component/Image.hpp"

class PlayScene; //forward declaration
class Beat : public Engine::Sprite{
private:
    float fallSecond, speed;
    int lane;
    bool hit = false;
protected:
    PlayScene* getPlayScene();
public:
    Beat(std::string img, float x, float y, float speed, int lane ,float w = 230, float h = 125);
    void Update(float deltaTime) override;
};

#endif //BEAT_GAME_BEAT_HPP
