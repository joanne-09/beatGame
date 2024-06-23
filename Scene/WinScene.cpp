#include <functional>
#include <allegro5/bitmap.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/color.h>

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

    const std::string font = "orbitron/medium.ttf";

    Engine::ImageButton* btn;
    btn = new Engine::ImageButton("ui/button.png", "ui/button_hovered.png", halfW - 200, halfH * 7 / 4 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&WinScene::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", font, 48, halfW, halfH * 7 / 4, 255, 255, 255, 255, 0.5, 0.5));

    UIsetup(halfW, halfH);
}

void WinScene::Terminate() {
    IScene::Terminate();
    //AudioHelper::StopBGM(bgmId);
}

void WinScene::Update(float deltaTime) {
    IScene::Update(deltaTime);
}

void WinScene::Draw() const {
    IScene::Draw();
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    TimingSetup(w / 2, h / 2);
}

void WinScene::BackOnClick() {
    // Change to select scene.
    Engine::GameEngine::GetInstance().ChangeScene("select");
}

void WinScene::UIsetup(int halfW, int halfH){
    const std::string font = "orbitron/medium.ttf";
    AddNewObject(new Engine::Label("Final Score", font, 60, halfW, halfH / 2 - 40, 255, 255, 255, 255, 0.5, 0.5));
    AddNewObject(new Engine::Label(std::to_string(finalScore), font, 60, halfW, halfH / 2 + 50, 255, 255, 255, 255, 0.5, 0.5));

    int h = halfH / 2 + 200;
    AddNewObject(new Engine::Label("Rush", font, 48, 100, h, 213, 43, 43, 200, 0, 0.5));
    AddNewObject(new Engine::Label(std::to_string(rushCount), font, 48, 350, h, 213, 43, 43, 200, 0, 0.5));

    AddNewObject(new Engine::Label("Perfect", font, 48, 100, h + 70, 63, 218, 63, 200, 0, 0.5));
    AddNewObject(new Engine::Label(std::to_string(perfectCount), font, 48, 350, h + 70, 63, 218, 63, 200, 0, 0.5));

    AddNewObject(new Engine::Label("Good", font, 48, 100, h + 70 * 2, 246, 215, 10, 200, 0, 0.5));
    AddNewObject(new Engine::Label(std::to_string(goodCount), font, 48, 350, h + 70 * 2, 246, 215, 10, 200, 0, 0.5));

    AddNewObject(new Engine::Label("Miss", font, 48, 100, h + 70 * 3, 255, 255, 255, 200, 0, 0.5));
    AddNewObject(new Engine::Label(std::to_string(missCount), font, 48, 350, h + 70 * 3, 255, 255, 255, 200, 0, 0.5));

    GradeSetup(halfW, halfH);
    TimingSetup(halfW, halfH);
}

void WinScene::GradeSetup(int halfW, int halfH) {
    const std::string font = "orbitron/medium.ttf";
    // score total 100000000
    if(finalScore <= 20000000) {
        grade = "F";
        color = {255, 36, 20, 200};
    } else if(finalScore <= 40000000) {
        grade = "C";
        color = {238, 159, 22, 200};
    } else if(finalScore <= 60000000) {
        grade = "B";
        color = {238, 159, 22, 200};
    } else if(finalScore <= 8000000) {
        grade = "A";
        color = {247, 241, 51, 200};
    } else {
        grade = "S";
        color = {247, 241, 51, 200};
    }

    int h = halfH / 2 + 200;
    AddNewObject(new Engine::Image("ui/win.png", halfW, h + 35 * 3, 250, 250, 0.5, 0.5));
    AddNewObject(new Engine::Label(grade, font, 150, halfW, h + 35 * 3 + 20, color[0], color[1], color[2], color[3], 0.5, 0.5));
}

void WinScene::TimingSetup(int halfW, int halfH) const{
    int h = halfH / 2 + 200 + 35 * 3;
    al_draw_line(halfW + 500, h - 100, halfW + 600, h - 100, al_map_rgb(255, 255, 255), 5);
    al_draw_line(halfW + 500, h, halfW + 600, h, al_map_rgb(255, 255, 255), 5);
    al_draw_line(halfW + 500, h + 100, halfW + 600, h + 100, al_map_rgb(255, 255, 255), 5);
    al_draw_line(halfW + 550, h - 100, halfW + 550, h + 100, al_map_rgb(255, 255, 255), 5);

    int total = perfectCount + rushCount + goodCount + missCount;
    int offset = (total == 0 ? 0 : (100 * perfectCount + 200 * rushCount + 50 * goodCount) / total);
    al_draw_line(halfW + 500, h + 100 - offset, halfW + 600, h + 100 - offset, al_map_rgb(250, 25, 75), 5);
}
