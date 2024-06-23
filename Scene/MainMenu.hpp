//
// Created by Lee Eason on 2024/6/9.
//
#ifndef BEAT_GAME_MAINMENU_HPP
#define BEAT_GAME_MAINMENU_HPP
#include <allegro5/allegro_audio.h>
#include "Engine/IScene.hpp"
#include "Engine/FileIO.hpp"
#include "UI/Component/InputBox.hpp"

class MainMenu final : public Engine::IScene {
private:
    Engine::InputBox* inputBox;
    std::string name;
    int cur_tick;
public:
    explicit MainMenu() = default;
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;
    void Draw() const override;
    void StartOnClick();
    void SettingsOnClick();
    void DonateOnClick();
    std::vector<int> GenColor() const;
    //void ExitOnClick();
};


#endif //BEAT_GAME_MAINMENU_HPP
