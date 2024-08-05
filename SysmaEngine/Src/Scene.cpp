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

	for (int i{ 0 }; i < objects2D.size(); i++)
		objects2D[i]->draw();
	for (int i{ 0 }; i < UIs.size(); i++)
		UIs[i]->draw();
}