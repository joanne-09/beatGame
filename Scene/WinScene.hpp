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
    float finalScore;
    int rushCount, perfectCount, goodCount, missCount;
public:
    explicit WinScene() = default;
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;
    void BackOnClick();
    PlayScene* getPlayScene();
};

#endif //BEAT_GAME_WINSCENE_HPP
