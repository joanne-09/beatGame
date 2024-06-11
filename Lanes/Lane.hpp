#ifndef BEAT_GAME_LANE_HPP
#define BEAT_GAME_LANE_HPP
#include "Engine/Headers.hpp"
#include "Scene/PlayScene.hpp"
#include "Beats/Beat.hpp"
#include "UI/Component/Image.hpp"

class Lane : public Engine::Image{
private:
    int laneID;
public:
    Lane(int id, std::string img, float x, float y, float w = 250, float h = 1080);
};

#endif //BEAT_GAME_LANE_HPP
