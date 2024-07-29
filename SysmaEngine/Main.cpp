#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
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

	void checkCollision(E2D::Object* object) {
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
		glm::vec2 diff{ 
			position - 
			object.position
		};

		std::cout << "diff x: " << diff.x << ", y: " << diff.y << '\n';
		position += diff;
	}
};

int main() {
	srand(time(NULL));
	Engine* engine{ new Engine{"Test"} };

	Shader* shader{ new Shader{} };
	shader->link(E2D::Rectangle::VERT, E2D::Rectangle::FRAG);

	Subject* subject{ new Subject{} };
	Cube* cube{ new Cube{*subject, shader} };
	cube->name = "cube";
	cube->size = glm::vec2{ 30.0f };
	cube->position = Engine::GetSizeMiddle() - cube->size;

	std::vector<E2D::Object*> objects;
	objects.push_back(cube);
	
	for (int i = 0; i < 100; i++) {
		E2D::Rectangle rectangle{ shader };
		rectangle.name = "cube" + std::to_string(i + 1);
		rectangle.size = cube->size;
		rectangle.position = glm::vec2{
			static_cast<float>(rand() % Engine::Width),
			static_cast<float>(rand() % Engine::Height)
		};
		rectangle.color = glm::vec3{ 1.0f, 0.0f, 0.0f };
		objects.push_back(new E2D::Rectangle{ rectangle });
	}

	while (engine->isLoop()) {
		engine->newFrame();

		if (Engine::KeyPressed(GLFW_KEY_A) ||
			Engine::KeyPressed(GLFW_KEY_D)) {
			float move{ 160.0f * Engine::DeltaTime };
			if (Engine::KeyPressed(GLFW_KEY_A))
				move *= -1;
			cube->position.x += move;
		}
		if (Engine::KeyPressed(GLFW_KEY_W) ||
			Engine::KeyPressed(GLFW_KEY_S)) {
			float move{ 160.0f * Engine::DeltaTime };
			if (Engine::KeyPressed(GLFW_KEY_W))
				move *= -1;
			cube->position.y += move;
		}

		for (int i{ 0 }; i < objects.size(); i++) {
			E2D::Object* object{ objects[i] };

			if (object->name != "cube") {
				glm::vec2 object1StartCollision{ cube->position - (cube->size / 2.0f) };
				glm::vec2 object1EndCollision{ cube->position + (cube->size / 2.0f) };
				glm::vec2 object2StartCollision{ object->position - (object->size / 2.0f) };
				glm::vec2 object2EndCollision{ object->position + (object->size / 2.0f) };

				glm::vec2 differenceStart{ object1StartCollision - object2StartCollision };
				glm::vec2 differenceEnd{ object1EndCollision - object2EndCollision };

				if (differenceStart.x < object->size.x && differenceStart.y < object->size.y &&
					differenceEnd.x > -object->size.x && differenceEnd.y > -object->size.y)
					subject->checkCollision(object);
			}

			object->draw();
		}

		engine->renderFrame();
	}

	engine->terminate();

	return 0;
}