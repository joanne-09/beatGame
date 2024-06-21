#ifndef BEAT_GAME_SETTINGS_HPP
#define BEAT_GAME_SETTINGS_HPP
#include <allegro5/allegro_audio.h>
#include <unordered_map>
#include <memory>
#include "Engine/IScene.hpp"

class Settings final : public Engine::IScene{
private:
    std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
    std::unordered_map<int, int> keyMapping;

    int ticks = 0;
    std::vector<Engine::Image*> keyButtons;
    std::vector<Engine::Label*> keyLabels;
    std::vector<bool> keyStatus;
public:
    Settings() = default;
    void Initialize() override;
    void Terminate() override;
    void Update(float deltaTime) override;
    void OnKeyDown(int keyCode) override;
    void BGMSlideOnValueChanged(float value);
    void SFXSlideOnValueChanged(float value);
    void UpdateKeyMapping(int keyCode);
    bool KeyExist(int keyCode);
    int CheckKeyClicked();
    int FindKeyforLane(int lane);
    void BackOnClick();
};


#endif //BEAT_GAME_SETTINGS_HPP
