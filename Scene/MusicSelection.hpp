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

class Song{
public:
    std::string name;
    bool preview;
    int bpm;
    std::vector<int> difficulty;
    int high_score;
    Song(std::string name, bool preview, int bpm, std::vector<int> difficulty, int high_score): name(std::move(name)), preview(preview), bpm(bpm), difficulty(difficulty), high_score(high_score){};

};

class MusicSelection final : public Engine::IScene{
private:
    int cur_tick;
    Engine::Group *MusicGroup;
    bool preview = false;
    int DrawId = 0;
    std::vector<Song> songs;
    Engine::ImageButton *block1, *block2, *block3;
public:
    MusicSelection() = default;
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;
    void BackOnClick();
    void BlockOnClick();
    void SettingsOnClick();
    void Draw() const override;
    void ShowPreview(int idx);
    std::vector<int> GenColor() const;
};



#endif //BEAT_GAME_MUSICSELECTION_HPP
