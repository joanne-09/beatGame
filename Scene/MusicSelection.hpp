//
// Created by Lee Eason on 2024/6/9.
//
#include "Engine/IScene.hpp"
#include <allegro5/allegro_audio.h>
#include "Engine/IScene.hpp"
#include "Engine/FileIO.hpp"
#include "UI/Component/InputBox.hpp"
#include <functional>
#include <string>
#include "MainMenu.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/AudioHelper.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"
#ifndef BEAT_GAME_MUSICSELECTION_HPP
#define BEAT_GAME_MUSICSELECTION_HPP


class MusicSelection final : public Engine::IScene{
private:
    Engine::Group *MusicGroup;
public:
    MusicSelection() = default;
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;
    void BackOnClick();
    void SettingsOnClick();
};


#endif //BEAT_GAME_MUSICSELECTION_HPP
