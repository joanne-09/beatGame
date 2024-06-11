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
#include "PlayScene.hpp"

void PlayScene::Initialize() {
    width = Engine::GameEngine::GetInstance().GetScreenSize().x;
    height = Engine::GameEngine::GetInstance().GetScreenSize().y;

    // UI score setup
    score = 0;
    UIScore = new Engine::Label(" ", "orbitron/medium.ttf", 48, width - 380, 50, 64, 64, 64, 255, 0, 0.5);

    // set up key mapping
    keyMapping = {{ALLEGRO_KEY_D, 1}, {ALLEGRO_KEY_F, 2}, {ALLEGRO_KEY_J, 3}, {ALLEGRO_KEY_K, 4}};

    ReadMapWave();
    // set up lasting time of each beat
    bpm = 10; // bm was 0
    ticks = 60 / bpm;

    // set up lanes
    laneCount = 4;
    lanes.clear();
    for(int i=1; i<=laneCount; i++) {
        lanes.push_back(new Lane(i, "ui/lane.png", width/2 - 750 + i*250, 0));
    }
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

    for(int i=0; i<laneCount; i++) {
        lanes[i]->Draw();
    }
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

void PlayScene::LaneEffect(int keyCode) {
    if(keyMapping.find(keyCode) == keyMapping.end()) return;

}