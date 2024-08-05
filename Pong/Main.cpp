#include <iostream>

#include <Engine.h>

#include "Src/MainMenu.h"

using namespace SYSMA;

int main() {
	Engine* engine{ new Engine{"Pong"} };
	
	Shader* shaderDefault{ new Shader{} };
	shaderDefault->link(Object::VERT, Object::FRAG);
	Engine::AddShader("default", shaderDefault);

	Shader* shaderUILabel{ new Shader{} };
	shaderUILabel->link(UI::Label::VERT, UI::Label::FRAG);
	Engine::AddShader("label", shaderUILabel);

	engine->loadScene(new Pong::MainMenu{ *engine });

	engine->start();
	return 0;
}