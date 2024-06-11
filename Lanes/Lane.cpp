#include "Engine/Headers.hpp"
#include "Lane.hpp"

Lane::Lane(int id, std::string img, float x, float y, float w, float h): Engine::Image(img, x, y, w, h), laneID(id) {
    ;
}
