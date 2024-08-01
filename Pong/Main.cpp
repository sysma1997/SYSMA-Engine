#include <iostream>

#include <Engine.h>
#include <Scene.h>

#include <2D/Rectangle.h>
#include <2D/Triangle.h>

using namespace SYSMA;

class Pong : public Scene {
	Engine& engine;

	void load() override;
public:
	Pong(Engine& engine) : engine{ engine } {}
};

class Pong2Player : public E2D::Triangle, public Input {
	Engine& engine;

	void isInputJustPress(int key) {
		if (key == GLFW_KEY_SPACE) {
			engine.loadScene(new Pong{ engine });
		}
	}
public:
	Pong2Player(Engine& engine, Scene& scene, Shader* shader) : Triangle{ shader }, engine{ engine } {
		scene.addObject2D(this);
		scene.addInput(this);

		size = glm::vec2{ 60.0f };
		position = Engine::GetSizeMiddle();
		color = glm::vec3{ 0.0f, 0.0f, 1.0f };
	}
};
class Pong2 : public Scene {
	Engine& engine;

	void load() override {
		Shader* sTri{ new Shader{} };
		sTri->link(Object::VERT, Object::FRAG);
		addShader("object2D", sTri);

		E2D::Triangle* tri{ new E2D::Triangle{getShader("object2D")} };
	}
public:
	Pong2(Engine& engine) : engine{engine} {}
};

class PongPlayer : public E2D::Rectangle, public Input {
	Engine& engine;

	void isInputJustPress(int key) {
		if (key == GLFW_KEY_SPACE) {
			engine.loadScene(new Pong2{ engine });
		}
	}

public:
	PongPlayer(Engine& engine, Scene& scene, Shader* shader) : Rectangle{ shader }, engine{ engine } {
		scene.addObject2D(this);
		scene.addInput(this);

		size = glm::vec2{ 60.0f };
		position = Engine::GetSizeMiddle();
		color = glm::vec3{ 0.0f, 1.0f, 0.0f };
	}
};

void Pong::load() {
	Shader* shaderRectangle{ new Shader{} };
	shaderRectangle->link(Object::VERT, Object::FRAG);
	addShader("rectangle", shaderRectangle);

	PongPlayer* player{ new PongPlayer{engine, *this, getShader("rectangle")} };
}

int main() {
	Engine* engine{ new Engine{"Pong"} };
	
	engine->loadScene(new Pong{*engine});

	engine->loop();
	return 0;
}