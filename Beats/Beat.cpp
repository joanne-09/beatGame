#include <allegro5/allegro_primitives.h>
#include <allegro5/color.h>
#include <cmath>
#include <random>
#include <string>
#include <vector>
#include "Engine/Headers.hpp"
#include "Scene/PlayScene.hpp"
#include "Beat.hpp"


Beat::Beat(std::string img, float x, float y, float w, float h, float fall, int lane) : Engine::Sprite(img, x, y, w, h, 0.5, 0.5) {
    fallSecond = fall;
    this->lane = lane;
}

PlayScene* Beat::getPlayScene() {
    return dynamic_cast<PlayScene*>(Engine::GameEngine::GetInstance().GetActiveScene());
}

void Beat::Update(float deltaTime) {
    Sprite::Update(deltaTime);
    PlayScene* scene = getPlayScene();
    // update falling time
    this->fallSecond -= deltaTime;

    // check if the beat is out of boundary
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    if (!Engine::Collider::IsRectOverlap(Position - Size / 2, Position + Size / 2, Engine::Point(0, 0), Engine::Point(w, h)))
        getPlayScene()->BeatGroup->RemoveObject(objectIterator);
}
