#include "Engine/Headers.hpp"
#include "Lane.hpp"

Lane::Lane(int id, std::string img, float x, float y, float w, float h): laneID(id), Engine::IObject(x, y, w, h) {
    clicked = false;
    background = new Engine::Image(img, x, y, w, h);
    clickEffect = new Engine::Image("ui/gradient_lane.png", x, y, w, h);
}

void Lane::Draw() const {
    background->Draw();
    al_draw_line(Position.x, Size.y - 40, Position.x + Size.x, Size.y - 40, al_map_rgb(124, 173, 247), 7);

    if(clicked) clickEffect->Draw();
}
