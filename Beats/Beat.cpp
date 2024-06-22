#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>
#include "Engine/Headers.hpp"
#include "Scene/PlayScene.hpp"
#include "Beat.hpp"


Beat::Beat(std::string img, float x, float y, float speed, int lane, float w, float h) : Engine::Sprite(img, x, y, w, h, 0, 0) {
    Velocity = Engine::Point(0, 1) * speed;
    this->speed = speed;
    this->lane = lane;
    this->fallSecond = 1040 / speed;
}

PlayScene* Beat::getPlayScene() {
    return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}

void Beat::Update(float deltaTime) {
    Sprite::Update(deltaTime);
    PlayScene* scene = getPlayScene();

    // update falling time
    this->fallSecond -= deltaTime;

    // check if the beat is hit
    for(auto& it : scene->LaneGroup->GetObjects()) {
        Lane* lane = dynamic_cast<Lane*>(it);
        if (lane->laneID != this->lane || hit) continue;
        if(this->fallSecond > 125.0/speed) continue;

        if(this->fallSecond <= 0) {
            lane->status = "Miss";
        }else if(this->fallSecond <= 40.0/speed && lane->clicked){
            lane->status = "Good";
            scene->UpdateScore(1);
        }else if(this->fallSecond <= 80.0/speed && lane->clicked){
            lane->status = "Perfect";
            scene->UpdateScore(2);
        }else if(this->fallSecond <= 125.0/speed && lane->clicked){
            lane->status = "Rush";
            scene->UpdateScore(1);
        }else continue;

        hit = true;
        lane->ticks = 20;
    }

    // check if the beat is out of boundary
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    if (!Engine::Collider::IsRectOverlap(Position - Size / 2, Position + Size / 2, Engine::Point(0, 0), Engine::Point(w, h)))
        getPlayScene()->BeatGroup->RemoveObject(objectIterator);
}
