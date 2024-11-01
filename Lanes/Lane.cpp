#include "Engine/Headers.hpp"
#include "Lane.hpp"

Lane::Lane(int id, std::string img, float x, float y, float w, float h): laneID(id), Engine::IObject(x, y, w, h) {
    effectClicked = false;
    background = new Engine::Image(img, x, y, w, h);
    clickEffect = new Engine::Image("ui/gradient_lane.png", x, y, w, h);
    Miss = new Engine::Image("ui/miss.png", x + w/2, 900, 239, 78, 0.5);
    Good = new Engine::Image("ui/good.png", x + w/2, 900, 239, 78, 0.5);
    Perfect = new Engine::Image("ui/perfect.png", x + w/2, 900, 239, 78, 0.5);
    Rush = new Engine::Image("ui/rush.png", x + w/2, 900, 239, 78, 0.5);
}

void Lane::Draw() const {
    background->Draw();
    al_draw_line(Position.x, Size.y - 40, Position.x + Size.x, Size.y - 40, al_map_rgb(124, 173, 247), 7);

    if(effectClicked) clickEffect->Draw();
    SetStatus();
}

void Lane::Update(float deltaTime) {
    Engine::IObject::Update(deltaTime);

    if(ticks) ticks--;
    if(!ticks) status = "None";

    if(statusTicks) statusTicks--;
    if(!statusTicks) statusClicked = false;
}

void Lane::SetStatus() const {
    if(status == "Miss") {
        Miss->Draw();
    }else if(status == "Good"){
        Good->Draw();
    }else if(status == "Perfect") {
        Perfect->Draw();
    }else if(status == "Rush"){
        Rush->Draw();
    }
}
