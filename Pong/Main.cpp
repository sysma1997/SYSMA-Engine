#include <iostream>

#include <Engine.h>

#include "Src/MainMenu.h"

using namespace SYSMA;

int main() {
	Engine* engine{ new Engine{"Pong"} };
	
	Shader* shaderDefault{ new Shader{} };
	shaderDefault->link(Object::VERT, Object::FRAG);
	Engine::AddShader("default", shaderDefault);
	Shader* shaderDefault3V{ new Shader{} };
	shaderDefault3V->load("Assets/vertCircle.vert", "Assets/fragCircle.frag");
	Engine::AddShader("default3V", shaderDefault3V);

	Shader* shaderUILabel{ new Shader{} };
	shaderUILabel->link(UI::Label::VERT, UI::Label::FRAG);
	Engine::AddShader("label", shaderUILabel);

	engine->loadScene(new Pong::Game{ *engine });

	engine->start();
	return 0;
}