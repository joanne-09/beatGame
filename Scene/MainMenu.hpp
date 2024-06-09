//
// Created by Lee Eason on 2024/6/9.
//
#include "Engine/IScene.hpp"
#ifndef BEAT_GAME_MAINMENU_HPP
#define BEAT_GAME_MAINMENU_HPP


class MainMenu final : Engine::IScene {
public:
    MainMenu() = default;
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;
    void StartOnClick();
    void MusicOnClick();
    void SettingsOnClick();
    void ExitOnClick();
};


#endif //BEAT_GAME_MAINMENU_HPP
