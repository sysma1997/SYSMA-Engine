#include <iostream>

#include <Engine.h>
#include <Scene.h>

#include <2D/Rectangle.h>

using namespace SYSMA;

class Pong : public Scene {
	void load() override {
		Shader* shaderRectangle{ new Shader{} };
		shaderRectangle->link(E2D::Rectangle::VERT, E2D::Rectangle::FRAG);

	}
};

int main() {
	Engine* engine{ new Engine{"Pong"} };
	
	engine->loop();
	return 0;
}