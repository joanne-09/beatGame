//
// Created by Lee Eason on 2024/6/9.
//
#include "Engine/IScene.hpp"
#ifndef BEAT_GAME_SCOREBOARD_HPP
#define BEAT_GAME_SCOREBOARD_HPP


class Scoreboard final : public Engine::IScene{
public:
    Scoreboard() = default;
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;
    void BackOnClick();
};


#endif //BEAT_GAME_SCOREBOARD_HPP
