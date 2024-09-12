#include "ShowWinner.h"

using namespace SYSMA;

Pong::Game::ShowWinner::ShowWinner(Engine& engine, Scene& scene, bool isPlayerWin, Pong::Shared::SubjectResetGame& subject) : 
	UI::Label{ Engine::GetShader("label"), "Assets/Fonts/Robot_Font.otf", 60 }, 
	engine{ engine }, scene{ scene }, 
	isPlayerWin{ isPlayerWin }, 
	subject{ subject } {
	align = UI::Label::Align::CENTER;
	setText((isPlayerWin) ? "You won!" : "You lost!");
	color = glm::vec3{
		(isPlayerWin) ? 0.0f : 1.0f,
		(isPlayerWin) ? 1.0f : 0.0f,
		0.0f
	};
	position = Engine::GetSizeMiddle();
	scene.addUI(this);
	scene.addInput(this);

	scene.isPause(true);
	pauseInput = false;
}

void Pong::Game::ShowWinner::isInputJustPress(int key) {
	if (key == GLFW_KEY_SPACE) {
		scene.isPause(false);
		scene.removeInput(this);
		scene.removeUI(this);
		subject.reset();
		delete this;
	}
	if (key == GLFW_KEY_ESCAPE)
		engine.loadScene(new MainMenu{ engine });
}