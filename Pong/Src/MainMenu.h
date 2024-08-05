#pragma once

#include <vector>

#include <Engine.h>
#include <Scene.h>
#include <Object.h>
#include <Input.h>

#include <UI/Label.h>

namespace Pong {
	class MainMenu : public SYSMA::Scene, public SYSMA::Input {
		Engine& engine;

		std::vector<SYSMA::UI::Label*> options;
		int option;

		void load() override;
		void isInputJustPress(int key) override;

	public:
		MainMenu(Engine& engine);
	};
}