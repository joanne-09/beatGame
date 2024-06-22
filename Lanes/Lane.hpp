#ifndef BEAT_GAME_LANE_HPP
#define BEAT_GAME_LANE_HPP
#include "Engine/Headers.hpp"
#include "Scene/PlayScene.hpp"
#include "Beats/Beat.hpp"
#include "UI/Component/Image.hpp"

class Lane : public Engine::IObject{
private:
    Engine::Image* background;
    Engine::Image* clickEffect;
    Engine::Image *Miss, *Good, *Perfect, *Rush;
public:
    int laneID;
    bool clicked = false;
    float ticks = 0;
    std::string status = "None";
    Lane(int id, std::string img, float x, float y, float w = 250, float h = 1080);
    void Draw() const override;
    void Update(float deltaTime) override;
    void SetStatus();
};

#endif //BEAT_GAME_LANE_HPP
