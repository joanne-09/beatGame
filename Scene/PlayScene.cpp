#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <memory>
#include <sstream>
#include <iomanip>

#include "Engine/GameEngine.hpp"
#include "Engine/AudioHelper.hpp"
#include "Engine/Resources.hpp"
#include "Engine/Group.hpp"
#include "Engine/FileIO.hpp"
#include "Engine/Point.hpp"
#include "UI/Component/Label.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Beat.hpp"
#include "PlayScene.hpp"

void PlayScene::Initialize() {
    width = Engine::GameEngine::GetInstance().GetScreenSize().x;
    height = Engine::GameEngine::GetInstance().GetScreenSize().y;

    // UI score setup
    score = 0;
    UIScore = new Engine::Label(" ", "orbitron/medium.ttf", 48, width - 380, 50, 64, 64, 64, 255, 0, 0.5);

    ReadMapWave();
    // set up lasting time of each beat
    ticks = 60 / bpm;
}

void PlayScene::Terminate() {
    IScene::Terminate();
}

void PlayScene::Update(float deltaTime) {
    IScene::Update(deltaTime);
    SetUpBeat(deltaTime);
}

void PlayScene::Draw() const {
    IScene::Draw();
    DrawUIScore();
}

void PlayScene::OnMouseDown(int button, int mx, int my) {
    IScene::OnMouseDown(button, mx, my);
}

void PlayScene::OnMouseMove(int mx, int my) {
    IScene::OnMouseMove(mx, my);
}

void PlayScene::OnMouseUp(int button, int mx, int my) {
    IScene::OnMouseUp(button, mx, my);
}

void PlayScene::OnKeyDown(int keyCode) {
    IScene::OnKeyDown(keyCode);
}

void PlayScene::ReadMapWave() {
    FileIO io("../Resource/beatmaps/test.txt");
    beatmapData = io.readBeatmap();
}

void PlayScene::DrawUIScore() const {
    al_draw_filled_rectangle(width - 400, 0, width, 100, al_map_rgba(255, 255, 255, 200));
    // set up score text with fixed digit
    std::stringstream scoreText;
    scoreText << std::setfill('0') << std::setw(9) << score;
    UIScore->Text = scoreText.str();
    UIScore->Draw();
}

void PlayScene::SetUpBeat(float deltaTime) {
    ticks -= deltaTime;
    if(ticks > 0) return;

    // reset ticks
    ticks = 60 / bpm;

    auto cur = beatmapData.front();
    beatmapData.pop_front();
}