//
// Created by Lee Eason on 2024/6/9.
//
#include "Engine/IScene.hpp"
#ifndef BEAT_GAME_PLAYSCENE_HPP
#define BEAT_GAME_PLAYSCENE_HPP


class PlayScene final : Engine::IScene{
public:
    PlayScene() = default;
    void Initialize() override;
    void Terminate() override;

};


#endif //BEAT_GAME_PLAYSCENE_HPP
