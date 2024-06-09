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

    AddNewObject(
            new Engine::Label("Beat Game", "pirulen.ttf", 120, halfW, halfH / 3 + 50, 10, 255, 255, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH / 2 + 200, 400,
                                  100);
    btn->SetOnClickCallback(std::bind(&MainMenu::StartOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Start", "pirulen.ttf", 48, halfW, halfH / 2 + 250, 0, 0, 0, 255, 0.5, 0.5));

    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH * 5 / 2 - 300,
                                  400, 100);
    btn->SetOnClickCallback(std::bind(&MainMenu::SettingsOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Settings", "pirulen.ttf", 48, halfW, halfH * 5 / 2 - 250, 0, 0, 0, 255, 0.5, 0.5));

    inputBox = new Engine::InputBox(halfW, halfH * 5 / 2 - 100, 500, 80);
    AddNewControlObject(inputBox);
}

void MainMenu::Terminate() {
    IScene::Terminate();
}

void MainMenu::Update(float deltaTime) {
    IScene::Update(deltaTime);
}

void MainMenu::StartOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("select");
}

void MainMenu::SettingsOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("settings");
}