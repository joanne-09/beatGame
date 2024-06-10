//
// Created by Lee Eason on 2024/6/9.
//
#include <functional>
#include <string>
#include "MainMenu.hpp"
#include "Engine/GameEngine.hpp"
#include "Engine/AudioHelper.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "Engine/Point.hpp"
#include "Engine/Resources.hpp"

void MainMenu::Initialize() {

    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    Engine::ImageButton *btn;

    const std::string font = "orbitron/medium.ttf";
    AddNewObject(new Engine::Label("Beat Game", font, 120, halfW, halfH / 5 + 50, 10, 255, 255, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("ui/button.png", "ui/button_hovered.png", halfW - 800, halfH + 250, 400, 100);
    btn->SetOnClickCallback(std::bind(&MainMenu::StartOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Start", font, 48, halfW - 600, halfH + 300, 255, 255, 255, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("ui/button.png", "ui/button_hovered.png", halfW + 400, halfH + 250, 400, 100);
    btn->SetOnClickCallback(std::bind(&MainMenu::SettingsOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Settings", font, 48, halfW + 600, halfH + 300, 255, 255, 255, 255, 0.5, 0.5));

    inputBox = new Engine::InputBox(halfW, halfH / 3 + 200);
    inputBox->setName(name);
    inputBox->Draw();
    AddNewControlObject(inputBox);
}

void MainMenu::Terminate() {
    IScene::Terminate();
}

void MainMenu::Update(float deltaTime) {
    IScene::Update(deltaTime);
    inputBox->Update(deltaTime);
}

void MainMenu::StartOnClick() {
    name = inputBox->getName() == "" ? "Player" : inputBox->getName();
    //Engine::GameEngine::GetInstance().ChangeScene("select");
    Engine::GameEngine::GetInstance().ChangeScene("play");
}

void MainMenu::SettingsOnClick() {
    name = inputBox->getName();
    Engine::GameEngine::GetInstance().ChangeScene("settings");
}