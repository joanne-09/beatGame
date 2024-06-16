#ifndef BEAT_GAME_LANE_HPP
#define BEAT_GAME_LANE_HPP
#include "Engine/Headers.hpp"
#include "Scene/PlayScene.hpp"
#include "Beats/Beat.hpp"
#include "UI/Component/Image.hpp"

class Lane : public Engine::IObject{
private:
    int laneID;
    Engine::Image* background;
    Engine::Image* clickEffect;
public:
    bool clicked = false;
    Lane(int id, std::string img, float x, float y, float w = 250, float h = 1080);
    void Draw() const override;
};

#endif //BEAT_GAME_LANE_HPP
