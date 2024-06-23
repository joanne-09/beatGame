//
// Created by Lee Eason on 2024/6/9.
//
#include "MusicSelection.hpp"
#include "UI/Component/MusicBlock.hpp"
#include "Scene/PlayScene.hpp"

std::string PlayScene::difficultyStr;
void MusicSelection::Initialize() {
    cur_tick = 0;
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

    btn = new Engine::ImageButton("ui/arrow.png", "ui/arrow.png", halfW - 950, halfH - 540, 250, 125);
    btn->SetOnClickCallback(std::bind(&MusicSelection::BackOnClick, this));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", font, 40, halfW - 780, halfH / 2 + -665, 255, 255, 255, 255, 0.5, 0.5));

    AddNewObject(MusicGroup = new Engine::Group());

    for (int i = 0; i < 7; ++i) {
        btn = new Engine::ImageButton("music_block.png", "music_block_selected.png", halfW - 900, halfH - 400 + i * 125, 600, 125);
        btn->SetOnClickCallback(std::bind(&MusicSelection::ShowPreview, this, i));
        //MusicGroup->AddNewObject(btn);
        AddNewControlObject(btn);
    }
    block1 = new Engine::ImageButton("black_square.png", "black_square_selected.png", w/2 -200, h/2 - 100, 300, 300);
    block2 = new Engine::ImageButton("black_square.png", "black_square_selected.png", w/2 + 200, h/2 - 100, 300, 300);
    block3 = new Engine::ImageButton("black_square.png", "black_square_selected.png", w/2 + 600, h/2 - 100, 300, 300);
    block1->Visible = false;
    block2->Visible = false;
    block3->Visible = false;
    AddNewControlObject(block1);
    AddNewControlObject(block2);
    AddNewControlObject(block3);

    //init song info
    songs.emplace_back(Song("Perfect Night", false, 136, {1, 4, 7}, 0));
    songs.emplace_back(Song("ASMRZ", false, 130, {2, 5, 10}, 0));
    songs.emplace_back(Song("Bling Bang", false, 157, {1, 4, 7}, 0));
    songs.emplace_back(Song("Magnetic", false, 131, {1, 4, 7}, 0));
    songs.emplace_back(Song("Night Dancer", false, 117, {1, 4, 7}, 0));
    songs.emplace_back(Song("Unforgiven", false, 104, {1, 4, 7}, 0));
    songs.emplace_back(Song("Waiting for Love", false, 128, {1, 4, 7}, 0));
}

void MusicSelection::Update(float deltaTime) {
    IScene::Update(deltaTime);
    cur_tick += 1;
}

void MusicSelection::Draw() const {
    const int w = Engine::GameEngine::GetInstance().GetScreenSize().x, h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    IScene::Draw();
    for(int i = 0; i < 7; ++i){
        //auto label = new Engine::Label("Music " + std::to_string(i), "orbitron/medium.ttf", 40, w/2 - 750, h/2-325+i*125, 255, 255, 255, 255, 0.5, 0.5);
        auto img = new Engine::Image("stage-select/"+songs[i].name+".png", w/2 - 900 + 8, h/2 - 400 + i * 125 + 125/2, 110, 110, 0, 0.5);
        auto label = new Engine::Label(songs[i].name, "orbitron/medium.ttf", 40, w/2 - 900 + 130, h/2 - 390 + i*125 + 125/2, 255, 255, 255, 255, 0, 0.5);
        img->Draw();
        label->Draw();
    }
    static int i = 0;
    if(preview){
        block1->Visible = true;
        block2->Visible = true;
        block3->Visible = true;
        auto img = new Engine::Label("Preview" + std::to_string(DrawId), "orbitron/medium.ttf", 40, w/2 + 200, h/2 - 325, 255, 255, 255, 255, 0.5, 0.5);
        auto cur_song = songs[DrawId];
        auto name = new Engine::Label(cur_song.name, "orbitron/medium.ttf", 75, w/2 + 300, h/2 - 375, 255, 255, 255, 255, 0.5, 0.5);
        name->Draw();
        //img->Draw();
        auto label1 = new Engine::Label("Easy", "orbitron/medium.ttf", 60, w/2-50, h/2+130 , 0, 255, 0, 255, 0.5, 0.5);
        auto difficulty1 = new Engine::Label(std::to_string(cur_song.difficulty[0]), "orbitron/medium.ttf", 100, w/2-50, h/2+20 , 0, 255, 0, 255, 0.5, 0.5);
        block1->SetOnClickCallback([this] { BlockOnClick(songs[DrawId], 0); });

        auto label2 = new Engine::Label("Normal", "orbitron/medium.ttf", 60, w/2+350, h/2+130 , 255, 255, 0, 255, 0.5, 0.5);
        auto difficulty2 = new Engine::Label(std::to_string(cur_song.difficulty[1]), "orbitron/medium.ttf", 100, w/2+350, h/2+20 , 255, 255, 0, 255, 0.5, 0.5);
        block2->SetOnClickCallback([this] { BlockOnClick(songs[DrawId], 1); });

        auto label3 = new Engine::Label("Hard", "orbitron/medium.ttf", 60, w/2+750, h/2+130 , 255, 0, 0, 255, 0.5, 0.5);
        auto difficulty3 = new Engine::Label(std::to_string(cur_song.difficulty[2]), "orbitron/medium.ttf", 100, w/2+750, h/2+20 , 255, 0, 0, 255, 0.5, 0.5);
        block3->SetOnClickCallback([this] { BlockOnClick(songs[DrawId], 2); });

        /*block1->Draw();
        block2->Draw();
        block3->Draw();*/
        label1->Draw();
        label2->Draw();
        label3->Draw();
        difficulty1->Draw();
        difficulty2->Draw();
        difficulty3->Draw();

        //high score
        auto colors = GenColor();
        int rand_r = colors[0], rand_g = colors[1], rand_b = colors[2], curdiff;
        if(block1->mouseIn){
            curdiff = 0;
        }else if(block2->mouseIn){
            curdiff = 1;
        }else if(block3->mouseIn){
            curdiff = 2;
        }else{
            curdiff = 0;
        }
        cur_song.high_score = GetHighScoreInfo(curdiff).first;
        std::string username = GetHighScoreInfo(curdiff).second;

        static float anchor = 0, offset = 0.02;
        if(cur_tick%2 == 0){
            anchor += offset;
            if(anchor >= 0.8) offset = -0.02;
            if(anchor <= 0.2) offset = 0.02;
        }

        auto high_score = new Engine::Label("High Score: " + std::to_string(cur_song.high_score), "orbitron/medium.ttf", 60, w/2 + 300, h/2 - 250, rand_r, rand_g, rand_b, 255, anchor, 0.5);
        auto high_score_name = new Engine::Label(username, "orbitron/medium.ttf", 60, w/2 + 300, h/2 - 175 , rand_r, rand_g, rand_b, 255, 0.5, 0.5);
        high_score->Draw();
        high_score_name->Draw();
    }
}

std::vector<int> MusicSelection::GenColor() const {
    std::vector<std::vector<int>> rainbow = {{
     {255, 0, 0},    // Red
     {255, 127, 0},  // Orange
     {255, 255, 0},  // Yellow
     {0, 255, 0},    // Green
     {255, 0, 255},    // Blue
     {255, 0, 130},   // Indigo
     {143, 0, 255}   // Violet
    }};
    static int rand_r, rand_g, rand_b;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 6);
    if(cur_tick % 5 == 0) {
        rand_r = rainbow[dis(gen)][0];
        rand_g = rainbow[dis(gen)][1];
        rand_b = rainbow[dis(gen)][2];
    }
    return {rand_r, rand_g, rand_b};
}
void MusicSelection::BackOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("main-menu");
}

void MusicSelection::BlockOnClick(const Song& song, const int diff) const{
    // transfer song info to play scene
    PlayScene::songName = song.name;
    PlayScene::bpm = song.bpm;
    PlayScene::difficulty = song.difficulty[diff];
    PlayScene::difficultyStr = diff == 0 ? "Easy" : diff == 1 ? "Normal" : "Hard";
    Engine::GameEngine::GetInstance().ChangeScene("play");
}

void MusicSelection::SettingsOnClick() {
    Engine::GameEngine::GetInstance().ChangeScene("settings");
}
void MusicSelection::Terminate() {
    AudioHelper::StopBGM(bgmId);
    IScene::Terminate();
}
void MusicSelection::ShowPreview(int idx) {
    AudioHelper::StopBGM(bgmId);
    bgmId = AudioHelper::PlayAudio("music/" + songs[idx].name + ".ogg");
    preview = true;
    DrawId = idx;
}

std::pair<int, std::string> MusicSelection::GetHighScoreInfo(int diff) const{
    std::string songName = songs[DrawId].name;
    std::string difficultyStr = diff == 0 ? "Easy" : diff == 1 ? "Normal" : "Hard";
    std::string filepath = "../Resource/highscores/" + songName + difficultyStr + ".txt";
    std::ifstream infile(filepath);

    std::string name, song, inscore, curdiff;
    if(infile){
        std::string temp;
        getline(infile, temp);
        std::stringstream ss(temp);
        std::getline(ss, name, ':');
        std::getline(ss, song, ':');
        std::getline(ss, inscore, ':');
        infile.close();
    }else{
        inscore = "0";
    }
    if(inscore.empty()) inscore = "0";
    if(name.empty()) name = "Player";
    return {stoi(inscore), name};
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