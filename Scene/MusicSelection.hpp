//
// Created by Lee Eason on 2024/6/9.
//
#include "Engine/IScene.hpp"
#ifndef BEAT_GAME_MUSICSELECTION_HPP
#define BEAT_GAME_MUSICSELECTION_HPP


class MusicSelection final : public Engine::IScene{
public:
    MusicSelection() = default;
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;
};


#endif //BEAT_GAME_MUSICSELECTION_HPP
