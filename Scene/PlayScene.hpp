#ifndef BEAT_GAME_PLAYSCENE_HPP
#define BEAT_GAME_PLAYSCENE_HPP
#include <allegro5/allegro_audio.h>
#include <list>
#include <memory>
#include <utility>
#include <vector>
#include <unordered_map>
#include "Engine/Headers.hpp"
#include "UI/Component/Image.hpp"
#include "UI/Component/Label.hpp"
//#include "Beats/Beat.hpp" // This is a circular dependency
#include "Lanes/Lane.hpp"
class Lane;
class PlayScene final : public Engine::IScene{
private:
    float Speed, delay, ticks;
    int width, height, laneCount;
    int bpm, score;
public:
    std::list<std::string> beatmapData;
    std::unordered_map<int, int> keyMapping;

    std::vector<Lane*> lanes;
    Engine::Group* BeatGroup;
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
    void SetUpBeat(float deltaTime);
    void LaneEffect(int keyCode);
};


#endif //BEAT_GAME_PLAYSCENE_HPP
