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
#include "UI/Component/ImageButton.hpp"
#include "Lanes/Lane.hpp"
class Lane;
class PlayScene final : public Engine::IScene{
private:
    ALLEGRO_SAMPLE_ID songId;
    float Speed, ticks, endTicks = -1;
    int width, height, laneCount;
    int totalScore = 100000000;
protected:
    int SpeedMult;
public:
    static std::string userName;
    static std::string songName, difficultyStr;
    static float bpm, difficulty;

    static int score;
    static float totalCount, rushCount, perfectCount, goodCount, missCount;

    std::list<std::string> beatmapData;
    static std::unordered_map<int, int> keyMapping;

    Engine::Group* BeatGroup;
    Engine::Group* LaneGroup;
    Engine::Label* UIScore;
    Engine::ImageButton* Pause;

    explicit PlayScene() = default;
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;
    void Draw() const override;
    void OnMouseDown(int button, int mx, int my) override;
    void OnMouseMove(int mx, int my) override;
    void OnMouseUp(int button, int mx, int my) override;
    void OnKeyDown(int keyCode) override;
    void OnKeyUp(int keyCode) override;
    void ReadMapWave();
    void DrawUIScore() const;
    void SetUpBeat(float deltaTime);
    void UpdateBeat(float deltaTime);
    void LaneEffect(int keyCode, bool type);
    void LaneStatus(int keyCode);
    void UpdateScore();
    void WriteScore();
};


#endif //BEAT_GAME_PLAYSCENE_HPP
