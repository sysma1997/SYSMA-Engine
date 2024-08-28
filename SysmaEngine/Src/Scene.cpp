#include "../Include/Scene.h"
#include "../Include/Engine.h"

using namespace SYSMA;

Scene::~Scene() {
	if (objects2D.size() > 0) {
		for (auto object2D : objects2D) delete object2D;
		objects2D.clear();
	}
	if (UIs.size() > 0) {
		for (auto UI : UIs) delete UI;
		UIs.clear();
	}
	if (inputs.size() > 0) {
		inputs.clear();
	}
}

void Scene::addObject2D(Object* object2D) {
	objects2D.push_back(object2D);
}
void Scene::addUI(Object* UI) {
	UIs.push_back(UI);
}
void Scene::addInput(Input* input) {
	inputs.push_back(input);
}

void Scene::start() {
	for (int i{ 0 }; i < inputs.size(); i++) {
		for (int key{ 0 }; key < 1025; key++) {
			inputs[i]->isInputPress(key, Engine::KeyPressed(key));

			if (Engine::KeyJustPressed(key)) inputs[i]->isInputJustPress(key);
		}
	}

	for (int i{ 0 }; i < objects2D.size(); i++) {
		Object& object{ *objects2D[i] };

		if (object.isCheckCollision) {
			for (int j{ 0 }; j < objects2D.size(); j++) {
				Object& object2{ *objects2D[j] };
				if (!object2.isCheckCollision) continue;
				if (object.name == object2.name) continue;

				glm::vec2 object1SizeM{ object.size / 2.0f };
				glm::vec2 object2SizeM{ object2.size / 2.0f };
				glm::vec2 object1StartCollision{ object.position - object1SizeM };
				glm::vec2 object1EndCollision{ object.position + object1SizeM };
				glm::vec2 object2StartCollision{ object2.position - object2SizeM };
				glm::vec2 object2EndCollision{ object2.position + object2SizeM };

				glm::vec2 differenceStart{ object1StartCollision - object2StartCollision };
				glm::vec2 differenceEnd{ object1EndCollision - object2EndCollision };

				if (differenceStart.x < object2.size.x && differenceStart.y < object2.size.y &&
					differenceEnd.x > -object2.size.x && differenceEnd.y > -object2.size.y) {
					object.isCollision(object2);
					break;
				}
			}
		}

		object.process();
		object.draw();
	}
	for (int i{ 0 }; i < UIs.size(); i++) {
		if (!pause) UIs[i]->process();
		UIs[i]->draw();
	}
}
void Scene::isPause(bool pause) {
	this->pause = pause;
}
bool Scene::isPause() {
	return pause;
}