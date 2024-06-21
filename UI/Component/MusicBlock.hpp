//
// Created by Lee Eason on 2024/6/10.
//

#ifndef BEAT_GAME_MUSICBLOCK_HPP
#define BEAT_GAME_MUSICBLOCK_HPP
#include "Engine/Headers.hpp"
#include<bits/stdc++.h>

class PlayScene;
class MusicBlock : public Engine::Sprite{
public:
    MusicBlock(std::string baseimg, std::string profileimg, float x, float y, float width, float height);
};


#endif //BEAT_GAME_MUSICBLOCK_HPP
