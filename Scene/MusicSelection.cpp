//
// Created by Lee Eason on 2024/6/9.
//

#include "MusicSelection.hpp"

void MusicSelection::Initialize() {
int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton *btn;
    const std::string font = "orbitron/medium.ttf";
    AddNewObject(new Engine::Label("Music Selection", font, 120, halfW, halfH / 3 + 50, 10, 255, 255, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("ui/button.png", "ui/button_hovered.png", halfW - 900, halfH / 2 + 700, 250, 75);
    btn->SetOnClickCallback(std::bind(&MusicSelection::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", font, 40, halfW - 780, halfH / 2 + 735, 255, 255, 255, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("ui/button.png", "ui/button_hovered.png", halfW + 200, halfH / 2 + 300, 400, 100);
    btn->SetOnClickCallback(std::bind(&MusicSelection::SettingsOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Settings", font, 48, halfW + 400, halfH / 2 + 350, 255, 255, 255, 255, 0.5, 0.5));
}

void MusicSelection::Update(float deltaTime) {
    IScene::Update(deltaTime);
}

void MusicSelection::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("main-menu");
}

void MusicSelection::SettingsOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("settings");

}
void MusicSelection::Terminate() {
    IScene::Terminate();
}