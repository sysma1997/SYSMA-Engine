#include "../Include/Scene.h"
#include "../Include/Engine.h"

using namespace SYSMA;

Scene::Scene() : removePosObject2D{ -1 }, removePosUI{ -1 }, removePosInput{ -1 }, removeAll{ false }, pause{ false }, isLoad{ false } {}
Scene::~Scene() {
	removeAll = true;

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
void Scene::removeObject2D(Object* object2D) {
	auto it{ std::find(objects2D.begin(), objects2D.end(), object2D) };
	if (it != objects2D.end()) 
		removePosObject2D = std::distance(objects2D.begin(), it);
}
void Scene::addUI(Object* UI) {
	UIs.push_back(UI);
}
void Scene::removeUI(Object* UI) {
	auto it{ std::find(UIs.begin(), UIs.end(), UI) };
	if (it != UIs.end())
		removePosUI = std::distance(UIs.begin(), it);
}
void Scene::addInput(Input* input) {
	inputs.push_back(input);
}
void Scene::removeInput(Input* input) {
	auto it{ std::find(inputs.begin(), inputs.end(), input) };
	if (it != inputs.end())
		removePosInput = std::distance(inputs.begin(), it);
}

void Scene::start() {
	if (removeAll) return;

	if (removePosInput != -1) {
		auto it{ std::find(inputs.begin(), inputs.end(), inputs[removePosInput]) };
		if (it != inputs.end()) inputs.erase(it);
		
		removePosInput = -1;
	}
	for (int i{ 0 }; i < inputs.size(); i++) {
		for (int key{ 0 }; key < 1025; key++) {
			if (inputs[i]->isPauseInput()) continue;
			
			inputs[i]->isInputPress(key, Engine::KeyPressed(key));
			if (Engine::KeyJustPressed(key)) inputs[i]->isInputJustPress(key);
		}
	}

	if (removePosObject2D != -1) {
		auto it{ std::find(objects2D.begin(), objects2D.end(), objects2D[removePosObject2D]) };
		if (it != objects2D.end()) objects2D.erase(it);

		removePosObject2D = -1;
	}
	for (int i{ 0 }; i < objects2D.size(); i++) {
		Object& object{ *objects2D[i] };

		if (!pause) {
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
		}

		object.draw();
	}

	if (removePosUI != -1) {
		auto it{ std::find(UIs.begin(), UIs.end(), UIs[removePosUI]) };
		if (it != UIs.end()) UIs.erase(it);

		removePosUI = -1;
	}
	for (int i{ 0 }; i < UIs.size(); i++) {
		if (!pause) UIs[i]->process();
		UIs[i]->draw();
	}
}
void Scene::isPause(bool pause) {
	this->pause = pause;
	for (int i{ 0 }; i < inputs.size(); i++) {
		Input* input{ inputs[i] };
		input->isPauseInput(pause);
	}
}
bool Scene::isPause() {
	return pause;
}