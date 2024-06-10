#ifndef BEAT_GAME_PLAYSCENE_HPP
#define BEAT_GAME_PLAYSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <list>
#include <memory>
#include <utility>
#include <vector>
#include "Engine/IScene.hpp"
#include "Engine/Point.hpp"

class PlayScene final : public Engine::IScene{
private:
    float Speed, delay;
    int width, height;
    int bpm;
    int score;
public:
    std::list<std::string> beatmapData;

    Engine::Label* UIScore;

    explicit PlayScene() = default;
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;
    void Draw() const override;
    void OnMouseDown(int button, int mx, int my) override;
    void OnMouseMove(int mx, int my) override;
    void OnMouseUp(int button, int mx, int my) override;
    void OnKeyDown(int keyCode) override;
    void ReadMapWave();
    void DrawUIScore() const;
};


#endif //BEAT_GAME_PLAYSCENE_HPP
