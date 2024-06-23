#include <functional>

#include "Engine/AudioHelper.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/Image.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"
#include "PlayScene.hpp"
#include "Engine/Point.hpp"
#include "WinScene.hpp"

PlayScene* WinScene::getPlayScene() {
    return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}

void WinScene::Initialize() {
    ticks = 0;
    finalScore = getPlayScene()->score;
    rushCount = getPlayScene()->rushCount; perfectCount = getPlayScene()->perfectCount;
    goodCount = getPlayScene()->goodCount; missCount = getPlayScene()->missCount;

    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    AddNewObject(new Engine::Label("You Win!", "pirulen.ttf", 48, halfW, halfH / 4 -10, 255, 255, 255, 255, 0.5, 0.5));

    Engine::ImageButton* btn;
    btn = new Engine::ImageButton("ui/button.png", "ui/button_hovered.png", halfW - 200, halfH * 7 / 4 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&WinScene::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", "pirulen.ttf", 48, halfW, halfH * 7 / 4, 255, 255, 255, 255, 0.5, 0.5));

    AddNewObject(new Engine::Label("Final Score: " + std::to_string(finalScore), "pirulen.ttf", 48, halfW, halfH / 2 - 10, 255, 255, 255, 255, 0.5, 0.5));
    AddNewObject(new Engine::Label("Rush: " + std::to_string(rushCount), "pirulen.ttf", 48, halfW, halfH / 2 + 50, 213, 43, 43, 255, 0.5, 0.5));
    AddNewObject(new Engine::Label("Perfect: " + std::to_string(perfectCount), "pirulen.ttf", 48, halfW, halfH / 2 + 110, 63, 218, 63, 255, 0.5, 0.5));
    AddNewObject(new Engine::Label("Good: " + std::to_string(goodCount), "pirulen.ttf", 48, halfW, halfH / 2 + 170, 246, 215, 10, 255, 0.5, 0.5));
    AddNewObject(new Engine::Label("Miss: " + std::to_string(missCount), "pirulen.ttf", 48, halfW, halfH / 2 + 230, 255, 255, 255, 255, 0.5, 0.5));
}

void WinScene::Terminate() {
    IScene::Terminate();
    //AudioHelper::StopBGM(bgmId);
}

void WinScene::Update(float deltaTime) {
    IScene::Update(deltaTime);
}

void WinScene::BackOnClick() {
    // Change to select scene.
    Engine::GameEngine::GetInstance().ChangeScene("stage-select");
}
