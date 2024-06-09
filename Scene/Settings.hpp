#ifndef BEAT_GAME_SETTINGS_HPP
#define BEAT_GAME_SETTINGS_HPP
#include <allegro5/allegro_audio.h>
#include <memory>
#include "Engine/IScene.hpp"

class Settings final : public Engine::IScene{
private:
    std::shared_ptr<ALLEGRO_SAMPLE_INSTANCE> bgmInstance;
public:
    Settings() = default;
    void Initialize() override;
    void Terminate() override;
    void BGMSlideOnValueChanged(float value);
    void SFXSlideOnValueChanged(float value);
    void BackOnClick();

};


#endif //BEAT_GAME_SETTINGS_HPP
