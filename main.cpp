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
#include<bits/stdc++.h>
#include<cstdlib>
#include<Database/Server.hpp>
int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	//Engine::GameEngine& game = Engine::GameEngine::GetInstance();
    Server::Upload();
    // TODO: [HACKATHON-1-SCENE] (3/4): Register Scenes here
    /*game.AddNewScene("start", new StartScene());
	game.AddNewScene("settings", new SettingsScene());
	game.AddNewScene("play", new PlayScene());
	game.AddNewScene("lose", new LoseScene());
	game.AddNewScene("win", new WinScene());
    game.AddNewScene("stage-select", new StageSelectScene());
    game.AddNewScene("scoreboard", new ScoreBoardScene());*/


    // TODO: [HACKATHON-1-SCENE] (4/4): Change the start scene
//	game.Start("stage-select", 60, 1600, 832);
	//game.Start("start", 60, 1600, 832);
	return 0;
}
