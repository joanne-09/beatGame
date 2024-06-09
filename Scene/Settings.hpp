//
// Created by Lee Eason on 2024/6/9.
//
#include "Engine/IScene.hpp"
#ifndef BEAT_GAME_SETTINGS_HPP
#define BEAT_GAME_SETTINGS_HPP


class Settings final : Engine::IScene{
public:
    Settings() = default;
    void Initialize() override;
    void Terminate() override;

};


#endif //BEAT_GAME_SETTINGS_HPP
