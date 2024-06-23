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

std::unordered_map<int, int> PlayScene::keyMapping = {{ALLEGRO_KEY_D, 1}, {ALLEGRO_KEY_F, 2},
    {ALLEGRO_KEY_J, 3}, {ALLEGRO_KEY_K, 4}};
int PlayScene::score = 0;
float PlayScene::totalCount = 0, PlayScene::rushCount = 0, PlayScene::perfectCount = 0, PlayScene::goodCount = 0, PlayScene::missCount = 0;

//PlayScene TODO:
// 1. Read bpm from musicselection scene
// 2. Add buffer time for each song
// 3. Store score


void PlayScene::Initialize() {
    width = Engine::GameEngine::GetInstance().GetScreenSize().x;
    height = Engine::GameEngine::GetInstance().GetScreenSize().y;

    songName = "perfect_night_easy";

    // UI score setup
    score = 0;
    UIScore = new Engine::Label(" ", "orbitron/medium.ttf", 48, width - 380, 50, 64, 64, 64, 255, 0, 0.5);

    totalCount = rushCount = perfectCount = goodCount = missCount = 0;
    ReadMapWave();
    // set up lasting time of each beat
    bpm = 136; // bpm was 0
    ticks = 3;
    difficulty = 4;

    // set up lanes
    laneCount = 4;
    AddNewObject(LaneGroup = new Engine::Group());
    for(int i=1; i<=laneCount; i++) {
        LaneGroup->AddNewObject(new Lane(i, "ui/lane.png", width/2 - 750 + i*250, 0));
    }

    AddNewObject(BeatGroup = new Engine::Group());

    // set up music
    songId = AudioHelper::PlayAudio("music/" + songName + ".ogg");
}

void PlayScene::Terminate() {
    AudioHelper::StopBGM(songId);
    IScene::Terminate();
}

void PlayScene::Update(float deltaTime) {
    IScene::Update(deltaTime);

    // add beat to scene
    SetUpBeat(deltaTime);
    UpdateBeat(deltaTime);
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

    LaneEffect(keyCode, true);
    LaneStatus(keyCode);
}

void PlayScene::OnKeyUp(int keyCode) {
    IScene::OnKeyUp(keyCode);

    LaneEffect(keyCode, false);
}

void PlayScene::ReadMapWave() {
    FileIO io("../Resource/beatmaps/" + songName + ".txt");
    beatmapData = io.readBeatmap();

    for(auto& it : beatmapData) {
        auto temp = std::count(it.begin(), it.end(), '1');
        totalCount += temp;
    }
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
    if(beatmapData.empty()) return;

    // reset ticks
    ticks = 60.0 / bpm / 2.0;

    auto cur = beatmapData.front();
    beatmapData.pop_front();

    for(int i=0; i<laneCount; i++) {
        if(cur[i] == '1') {
            Beat* beat = new Beat("ui/beat.png", width/2 - 500 + i*250 + 10, 0, 2.0 * 125.0 * bpm / 60.0, i+1);
            BeatGroup->AddNewObject(beat);
        }
    }
}

void PlayScene::UpdateBeat(float deltaTime) {
    for(auto& beat : BeatGroup->GetObjects()) {
        beat->Update(deltaTime);
    }
}

void PlayScene::LaneEffect(int keyCode, bool type) {
    if(keyMapping.find(keyCode) == keyMapping.end()) return;

    int id = keyMapping[keyCode];
    auto temp = (Lane*)*next(LaneGroup->GetObjects().begin(), id-1);
    temp->effectClicked = type;
}

void PlayScene::LaneStatus(int keyCode) {
    if(keyMapping.find(keyCode) == keyMapping.end()) return;

    int id = keyMapping[keyCode];
    auto temp = (Lane*)*next(LaneGroup->GetObjects().begin(), id-1);
    temp->statusClicked = true;

    temp->statusTicks = 20;
}

void PlayScene::UpdateScore() {
    /// total score 100000000
    /// one perfect: 100000000 / totalCount
    /// one good, one rush: perfect * difficulty / 20

    score = perfectCount * (totalScore / totalCount) + (goodCount + rushCount) * (totalScore / totalCount) * (difficulty / 20.0);
}