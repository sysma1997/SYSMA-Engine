#pragma once

#include <iostream>

#include <Engine.h>
#include <Input.h>

#include <UI/Label.h>

#include "../MainMenu.h"
#include "../Shared/SubjectGame.h"

namespace Pong::Game {
	class ShowWinner : public SYSMA::UI::Label, public SYSMA::Input {
		Shared::SubjectGame& subject;
		SYSMA::Engine& engine;
		SYSMA::Scene& scene;
		bool isPlayerWin;

		void isInputJustPress(int key) override;
	public:
		ShowWinner(SYSMA::Engine& engine, SYSMA::Scene& scene, bool isPlayerWin, 
			Shared::SubjectGame& subject);
	};
}