#include <iostream>
#include <functional>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <glm/glm.hpp>

#include "Include/Engine.h"
#include "Include/Shader.h"
#include "Include/2D/Rectangle.h"

using namespace SYSMA;

glm::vec3 addColor() {
	int r{ rand() % 2 };
	int g{ rand() % 2 };
	int b{ rand() % 2 };
	if (r == 0 && g == 0 && b == 0)
		return addColor();

	return glm::vec3{ r, g, b };
}

int main() {
	srand(time(NULL));
	Engine* engine{ new Engine{"Test"} };

	Shader* shader{ new Shader{} };
	shader->link(E2D::Rectangle::VERT, E2D::Rectangle::FRAG);

	std::vector<E2D::Object*> vectors;

	auto addRandValue = [](int limit) {
		return static_cast<float>(rand() % limit);
	};

	E2D::Rectangle* rectangle{ new E2D::Rectangle{ shader } };

	while (engine->isLoop()) {
		engine->newFrame();

		if (Engine::KeyJustPressed(GLFW_KEY_ESCAPE)) engine->closeLoop();
		if (Engine::KeyPressed(GLFW_KEY_SPACE)) {
			rectangle->size = glm::vec2{ 50.0f };
			rectangle->position = glm::vec2{ addRandValue(Engine::Width), addRandValue(Engine::Height)};
			rectangle->color = addColor();

			vectors.push_back(rectangle);
		}
		if (Engine::KeyJustPressed(GLFW_KEY_P)) {
			std::cout << "Num cubes: " << vectors.size() << '\n';
		}

		for (int i{ 0 }; i < vectors.size(); i++) {
			vectors[i]->draw();
		}

		engine->renderFrame();
	}

	engine->terminate();

	return 0;
}