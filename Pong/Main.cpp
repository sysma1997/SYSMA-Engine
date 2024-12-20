#include <iostream>

#include <Engine.h>
#include <UI/Label.h>

#include "Src/MainMenu.h"
#include "Src/Game.h"

using namespace SYSMA;

int main() {
	Engine* engine{ new Engine{"Pong"} };
	
	Shader* shaderDefault{ new Shader{} };
	shaderDefault->link(Object::VERT, Object::FRAG);
	Engine::AddShader("default", shaderDefault);
	
	Shader* shaderUILabel{ new Shader{} };
	shaderUILabel->link(UI::Label::VERT, UI::Label::FRAG);
	Engine::AddShader("label", shaderUILabel);
	
	engine->loadScene("mainMenu", new Pong::MainMenu{ *engine });
	engine->loadScene("game", new Pong::_Game{*engine});
	engine->selectScene("mainMenu");
	engine->start();

	return 0;
}