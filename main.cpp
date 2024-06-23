// [main.cpp]
// This is the entry point of your game.
// You can register your scenes here, and start the game.
#include "Engine/GameEngine.hpp"
#include "Engine/LOG.hpp"
#include "Scene/MainMenu.hpp"
#include "Scene/MusicSelection.hpp"
#include "Scene/PlayScene.hpp"
#include "Scene/Scoreboard.hpp"
#include "Scene/Settings.hpp"
#include "Scene/WinScene.hpp"
#include<bits/stdc++.h>
#include<cstdlib>
#include<Database/Server.hpp>
int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();
    //Server::Download();
    // TODO: [HACKATHON-1-SCENE] (3/4): Register Scenes here
    game.AddNewScene("main-menu", new MainMenu());
    game.AddNewScene("play", new PlayScene());
    game.AddNewScene("select", new MusicSelection());
    //game.AddNewScene("score", new Scoreboard());
    game.AddNewScene("settings", new Settings());
    game.AddNewScene("win", new WinScene());

	game.Start("main-menu", 60, 1920, 1080);
    //Server::Upload();
	return 0;
}
