#ifndef BEAT_GAME_WINSCENE_HPP
#define BEAT_GAME_WINSCENE_HPP
#include <allegro5/allegro_audio.h>
#include "Scene/PlayScene.hpp"
#include "Engine/IScene.hpp"

class PlayScene;
class WinScene final : public Engine::IScene {
private:
    float ticks;
    ALLEGRO_SAMPLE_ID bgmId;
    int finalScore;
    int rushCount, perfectCount, goodCount, missCount;

    std::string grade;
    std::vector<int> color;
public:
    explicit WinScene() = default;
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;
    void Draw() const override;
    void BackOnClick();
    PlayScene* getPlayScene();
    void UIsetup(int halfW, int halfH);
    void GradeSetup(int halfW, int halfH);
    void TimingSetup(int halfW, int halfH) const;
};

#endif //BEAT_GAME_WINSCENE_HPP
