#include <iostream>
#include <vector>
#include <glm/glm.hpp>

#include "Include/Engine.h"
#include "Include/Shader.h"
#include "Include/2D/Rectangle.h"
#include "Include/2D/Collision.h"

using namespace SYSMA;

class Subject {
private:
	std::vector<E2D::Collision*> collisions;
	E2D::Object* object;

public:
	void attach(E2D::Collision* collision) {
		collisions.push_back(collision);
	}
	void detach(E2D::Collision* collision) {
		std::vector<E2D::Collision*>::iterator it = std::find(collisions.begin(), collisions.end(), collision);
		if (it != collisions.end())
			collisions.erase(it);
	}
	void notify() {
		for (int i = 0; i < collisions.size(); i++) {
			collisions[i]->onCollision(*object);
		}
	}

	void CheckCollision(E2D::Object* object) {
		this->object = object;
		notify();
	}
};

class Cube : public E2D::Rectangle, public E2D::Collision {
public:
	Cube(Subject& subject, Shader* shader) : Rectangle{shader} {
		subject.attach(this);
	}

	void onCollision(const Object& object) override {
		std::cout << "Collision with " << object.name << '\n';
	}
};

glm::vec3 addColor() {
	int r{ rand() % 2 };
	int g{ rand() % 2 };
	int b{ rand() % 2 };
	if (r == 0 && g == 0 && b == 0)
		return addColor();

	return glm::vec3{ r, g, b };
}

int main() {
	Engine* engine{ new Engine{"Test"} };

	Shader* shader{ new Shader{} };
	shader->link(E2D::Rectangle::VERT, E2D::Rectangle::FRAG);

	Subject* subject{ new Subject{} };
	Cube* cube{ new Cube{*subject, shader} };
	cube->size = glm::vec2{ 30.0f };
	cube->position = Engine::GetSizeMiddle() - (cube->size / 2.0f);

	while (engine->isLoop()) {
		engine->newFrame();

		if (Engine::KeyPressed(GLFW_KEY_LEFT) ||
			Engine::KeyPressed(GLFW_KEY_RIGHT)) {
			float move = 160.0f * Engine::DeltaTime;
			if (Engine::KeyPressed(GLFW_KEY_LEFT))
				move *= -1;
			cube->position.x += move;
		}
		if (Engine::KeyPressed(GLFW_KEY_UP) ||
			Engine::KeyPressed(GLFW_KEY_DOWN)) {
			float move = 160.0f * Engine::DeltaTime;
			if (Engine::KeyPressed(GLFW_KEY_UP))
				move *= -1;
			cube->position.y += move;
		}

		cube->draw();

		engine->renderFrame();
	}

	engine->terminate();

	return 0;
}