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
#include "PlayScene.hpp"
#include <bits/stdc++.h>
std::string PlayScene::userName;

void MainMenu::Initialize() {

    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;

    Engine::ImageButton *btn;

    const std::string font = "orbitron/medium.ttf";
//    auto colors = GenColor();
//    int rand_r = colors[0], rand_g = colors[1], rand_b = colors[2];
//    AddNewObject(new Engine::Label("Beat Game", font, 120, halfW, halfH / 5 + 50, rand_r, rand_g, rand_b, 255, 0.5, 0.5));

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

    btn = new Engine::ImageButton("donate.png", "donate.png", halfW + 600, halfH + 400, 300, 100);
    btn->SetOnClickCallback([this] { DonateOnClick(); });
    AddNewControlObject(btn);
}

void MainMenu::Terminate() {
    IScene::Terminate();
}

void MainMenu::Update(float deltaTime) {
    IScene::Update(deltaTime);
    inputBox->Update(deltaTime);
    cur_tick += 1;
}

void MainMenu::Draw() const {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    IScene::Draw();
    const std::string font = "orbitron/medium.ttf";
    std::vector<int> colors = GenColor();
    int rand_r = colors[0], rand_g = colors[1], rand_b = colors[2];
    auto label = new Engine::Label("Beat Game", font, 120, halfW, halfH / 5 + 50, rand_r, rand_g, rand_b, 255, 0.5, 0.5);
    label->Draw();
}
void MainMenu::StartOnClick() {
    name = inputBox->getName() == "" ? "Player" : inputBox->getName();
    //Engine::GameEngine::GetInstance().ChangeScene("play");
    PlayScene::userName = name;
    Engine::GameEngine::GetInstance().ChangeScene("select");
}

void MainMenu::SettingsOnClick() {
    name = inputBox->getName();
    Engine::GameEngine::GetInstance().ChangeScene("settings");
}

void MainMenu::DonateOnClick() {
    const std::string link = "https://www.paypal.com/ncp/payment/M7RX89GE9Y9ZJ";
#ifdef __APPLE__
    system(("open " + link).c_str());
#elif defined _WIN32
    system(("start " + link).c_str());
#endif
}


std::vector<int> MainMenu::GenColor() const{
    std::vector<std::vector<int>> rainbow = {{
             {255, 0, 0},    // Red
             {255, 127, 0},  // Orange
             {255, 255, 0},  // Yellow
             {0, 255, 0},    // Green
             {255, 0, 255},    // Blue
             {255, 0, 130},   // Indigo
             {143, 187, 255}   // Violet
     }};
    static int rand_r, rand_g, rand_b;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 6);
    if(cur_tick % 5 == 0) {
        rand_r = rainbow[dis(gen)][0];
        rand_g = rainbow[dis(gen)][1];
        rand_b = rainbow[dis(gen)][2];
    }
    return {rand_r, rand_g, rand_b};
}