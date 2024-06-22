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
    //AddNewObject(new Engine::Label("Music Selection", font, 120, halfW, halfH / 3 + 50, 10, 255, 255, 255, 0.5, 0.5));

    /*btn = new Engine::ImageButton("ui/button.png", "ui/button_hovered.png", halfW - 900, halfH / 2 + 700, 250, 75);
    btn->SetOnClickCallback(std::bind(&MusicSelection::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", font, 40, halfW - 780, halfH / 2 + 735, 255, 255, 255, 255, 0.5, 0.5));*/

    btn = new Engine::ImageButton("ui/arrow.png", "ui/arrow.png", halfW - 950 , halfH - 540, 250, 125);
    btn->SetOnClickCallback(std::bind(&MusicSelection::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", font, 40, halfW - 780, halfH / 2 + -665, 255, 255, 255, 255, 0.5, 0.5));

//    btn = new Engine::ImageButton("ui/button.png", "ui/button_hovered.png", halfW + 200, halfH / 2 + 300, 400, 100);
//    btn->SetOnClickCallback(std::bind(&MusicSelection::SettingsOnClick, this));
//    AddNewControlObject(btn);
//    AddNewObject(new Engine::Label("Settings", font, 48, halfW + 400, halfH / 2 + 350, 255, 255, 255, 255, 0.5, 0.5));


    AddNewObject(MusicGroup = new Engine::Group());

    //std::list<Engine::ImageButton*> music_blocks;
    //MusicBlock musicblock;
    /*for(int i = 0; i < 20; ++i){
        //MusicGroup->AddNewObject(new MusicBlock("music_block.png", "music_block.png", halfW - 800, halfH - 300 + i * 125, 600, 125));
        btn = new Engine::ImageButton("music_block.png", "ui/button.png", halfW - 800, halfH - 300 + i * 125, 600, 125);
        //MusicGroup->AddNewObject(btn);
        //music_blocks.push_back(btn);
        //musicblock.blocks.push_back(btn);
        //btn->SetOnClickCallback(std::bind(&MusicSelection::BackOnClick, this));
        //AddNewControlObject(btn);
    }*/
    //MusicGroup->RemoveObject(MusicGroup->GetObjects().front()->GetObjectIterator());
    for(int i = 0; i < 7; ++i){
        btn = new Engine::ImageButton("music_block.png", "ui/button.png", halfW - 900, halfH - 400 + i * 125, 600, 125);
        MusicGroup->AddNewObject(btn);
        btn->SetOnClickCallback(std::bind(&MusicSelection::ShowPreview, this, i));
        AddNewControlObject(btn);
    }
    //MusicGroup->RemoveObject(MusicGroup->GetObjects().front()->GetObjectIterator());
}

void MusicSelection::Update(float deltaTime) {
    IScene::Update(deltaTime);
}

void MusicSelection::Draw() const {
    const int w = Engine::GameEngine::GetInstance().GetScreenSize().x, h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    IScene::Draw();
    int start = 0, end = 8;
    for(int i = 0; i < 7; ++i){
        auto label = new Engine::Label("Music " + std::to_string(i), "orbitron/medium.ttf", 40, w/2 - 750, h/2-325+i*125, 255, 255, 255, 255, 0.5, 0.5);
        label->Draw();
        //it->second->Position = Engine::Point(Engine::GameEngine::GetInstance().GetScreenSize().x / 2 - 850, Engine::GameEngine::GetInstance().GetScreenSize().y / 2 - 400 + i * 125);
        //it->second->Draw();
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