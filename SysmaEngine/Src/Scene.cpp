#include "../Include/Scene.h"

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
		for (auto input : inputs) delete input;
		inputs.clear();
	}

	if (shaders.size() > 0) {
		std::map<std::string, Shader*>::iterator itS;
		for (itS = shaders.begin(); itS != shaders.end(); itS++) delete itS->second;
		shaders.clear();
	}
	if (textures.size() > 0) {
		std::map<std::string, Texture*>::iterator itT;
		for (itT = textures.begin(); itT != textures.end(); itT++) delete itT->second;
		textures.clear();
	}
}

void Scene::addShader(std::string name, Shader* shader) {
	shaders[name] = shader;
}
Shader* Scene::getShader(std::string name) {
	return shaders[name];
}
void Scene::addTexture(std::string name, Texture* texture) {
	textures[name] = texture;
}
Texture* Scene::getTexture(std::string name) {
	return textures[name];
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