#include <allegro5/allegro_audio.h>
#include <iostream>
#include <functional>
#include <memory>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "Scene/PlayScene.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Component/Slider.hpp"
#include "Settings.hpp"

void Settings::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;

    // button to switch back to main menu
    Engine::ImageButton *btn;
    btn = new Engine::ImageButton("ui/button.png", "ui/button_hovered.png", halfW - 200, halfH + 250, 400, 100);
    btn->SetOnClickCallback(std::bind(&Settings::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", "pirulen.ttf", 48, halfW, halfH + 300, 255, 255, 255, 255, 0.5, 0.5));

    // slider object
    Slider *sliderBGM, *sliderSFX;
    sliderBGM = new Slider(halfW - 550, halfH - 350 - 2, 190, 4);
    sliderBGM->SetOnValueChangedCallback(std::bind(&Settings::BGMSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(sliderBGM);
    AddNewObject(new Engine::Label("BGM: ", "pirulen.ttf", 28, halfW - 60 - 550, halfH - 350, 255, 255, 255, 255, 0.5, 0.5));

    sliderSFX = new Slider(halfW - 550, halfH - 250 - 2, 190, 4);
    sliderSFX->SetOnValueChangedCallback(std::bind(&Settings::SFXSlideOnValueChanged, this, std::placeholders::_1));
    AddNewControlObject(sliderSFX);
    AddNewObject(new Engine::Label("SFX: ", "pirulen.ttf", 28, halfW - 60 - 550, halfH - 250, 255, 255, 255, 255, 0.5, 0.5));

    // Not safe if release resource while playing, however we only free while change scene, so it's fine.
    bgmInstance = AudioHelper::PlaySample("select.ogg", true, AudioHelper::BGMVolume);
    sliderBGM->SetValue(AudioHelper::BGMVolume);
    sliderSFX->SetValue(AudioHelper::SFXVolume);

    // button for key remapping
    keyMapping = {{ALLEGRO_KEY_D, 1}, {ALLEGRO_KEY_F, 2}, {ALLEGRO_KEY_J, 3}, {ALLEGRO_KEY_K, 4}};
    keyButtons.clear();
    keyLabels.clear();
    keyStatus = std::vector(4, false);
    for(int i=1; i<=4; ++i){
        auto btnKey = new Engine::Image("ui/key.png", halfW - 320 + 120 * i, halfH - 350, 100, 100);
        keyButtons.push_back(btnKey);
        AddNewObject(btnKey);

        std::string temp(1, char(FindKeyforLane(i)-ALLEGRO_KEY_A+'A'));
        auto labeltemp = new Engine::Label(temp, "pirulen.ttf", 28, halfW - 320 + 120 * i + 50, halfH - 350 + 50, 255, 255, 255, 255, 0.5, 0.5);
        keyLabels.push_back(labeltemp);
        AddNewObject(labeltemp);
    }
}

void Settings::Terminate() {
    AudioHelper::StopSample(bgmInstance);
    bgmInstance = std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE>();
    IScene::Terminate();
}

void Settings::Update(float deltaTime) {
    IScene::Update(deltaTime);
}

void Settings::OnKeyDown(int keyCode) {
    IScene::OnKeyDown(keyCode);

    UpdateKeyMapping(keyCode);
}

void Settings::BGMSlideOnValueChanged(float value) {
    AudioHelper::ChangeSampleVolume(bgmInstance, value);
    AudioHelper::BGMVolume = value;
}

void Settings::SFXSlideOnValueChanged(float value) {
    AudioHelper::SFXVolume = value;
}

void Settings::UpdateKeyMapping(int keyCode) {
    int lane = CheckKeyClicked();
    if(!lane && keyMapping.find(keyCode) == keyMapping.end()) return;
    if(!lane) lane = keyMapping[keyCode];
    int key = FindKeyforLane(lane);

    keyStatus[lane-1] = !keyStatus[lane-1];
    if(!keyStatus[lane-1] && !KeyExist(keyCode)) {
        keyMapping.erase(key);
        keyMapping.insert({keyCode, lane});
        keyLabels[lane-1]->Text = std::string(1, char(keyCode-ALLEGRO_KEY_A+'A'));
    }
}

bool Settings::KeyExist(int keyCode) {
    return keyMapping.find(keyCode) != keyMapping.end();
}

int Settings::CheckKeyClicked() {
    for(int i=0; i<4; ++i){
        if(keyStatus[i]){
            return i+1;
        }
    }
    return 0;
}

int Settings::FindKeyforLane(int lane) {
    for(auto &i : keyMapping){
        if(i.second == lane){
            return i.first;
        }
    }

    return 0;
}

void Settings::BackOnClick() {
    PlayScene::keyMapping = this->keyMapping;
    Engine::GameEngine::GetInstance().ChangeScene("main-menu");
}