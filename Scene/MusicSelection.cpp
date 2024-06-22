//
// Created by Lee Eason on 2024/6/9.
//

#include "MusicSelection.hpp"
#include "UI/Component/MusicBlock.hpp"

void MusicSelection::Initialize() {
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;
    //Engine::Image background("background.png", 0, 0, 0, 0, 0, 0);
    auto *background = new Engine::Image("dark_blue.png", 0, 0, 0, 0, 0, 0);
    Engine::IScene::Draw();
    background->Draw();
    AddNewObject(background);

    Engine::ImageButton *btn;
    const std::string font = "orbitron/medium.ttf";

    btn = new Engine::ImageButton("ui/arrow.png", "ui/arrow.png", halfW - 950 , halfH - 540, 250, 125);
    btn->SetOnClickCallback(std::bind(&MusicSelection::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", font, 40, halfW - 780, halfH / 2 + -665, 255, 255, 255, 255, 0.5, 0.5));

    AddNewObject(MusicGroup = new Engine::Group());

    for(int i = 0; i < 7; ++i){
        btn = new Engine::ImageButton("music_block.png", "ui/button.png", halfW - 900, halfH - 400 + i * 125, 600, 125);
        btn->SetOnClickCallback(std::bind(&MusicSelection::ShowPreview, this, i));
        //MusicGroup->AddNewObject(btn);
        AddNewControlObject(btn);
    }
}

void MusicSelection::Update(float deltaTime) {
    IScene::Update(deltaTime);
}

void MusicSelection::Draw() const {
    const int w = Engine::GameEngine::GetInstance().GetScreenSize().x, h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    IScene::Draw();
    for(int i = 0; i < 7; ++i){
        auto label = new Engine::Label("Music " + std::to_string(i), "orbitron/medium.ttf", 40, w/2 - 750, h/2-325+i*125, 255, 255, 255, 255, 0.5, 0.5);
        label->Draw();
    }
    static int i = 0;
    if(preview){
        auto img = new Engine::Label("Preview" + std::to_string(DrawId), "orbitron/medium.ttf", 40, w/2 + 200, h/2 - 325, 255, 255, 255, 255, 0.5, 0.5);
        img->Draw();
    }

}
void MusicSelection::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("main-menu");
}

void MusicSelection::SettingsOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("settings");
}
void MusicSelection::Terminate() {
    IScene::Terminate();
}
void MusicSelection::ShowPreview(int idx) {
    preview = true;
    DrawId = idx;
}

/*
Drawing:
On the left side of the screen, preview will show on the right, play at the bottom of preview
Treat each "music" as a sprite
Every music has an activation area
Use a container to store all music
Draw a given range in the container, (with offset)
Use arrow keys to navigate
Preview:
Displays information about a music (high score, difficulty, BPM...)
*/