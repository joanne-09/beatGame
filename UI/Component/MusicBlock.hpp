//
// Created by Lee Eason on 2024/6/10.
//

#ifndef BEAT_GAME_MUSICBLOCK_HPP
#define BEAT_GAME_MUSICBLOCK_HPP
#include "Engine/Headers.hpp"
#include "ImageButton.hpp"
#include<bits/stdc++.h>

class PlayScene;
class MusicBlock{
    friend class MusicSelection;
private:
    std::list<Engine::ImageButton*> blocks;
public:
    void DrawRange(int start, int end);
};

#endif //BEAT_GAME_MUSICBLOCK_HPP
