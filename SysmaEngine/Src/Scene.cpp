#include "../Include/Scene.h"

using namespace SYSMA;

Scene::~Scene() {
	for (auto const& [key, value] : shaders) delete value;
	for (auto const& [key, value] : textures) delete value;
	for (auto const& it : objects2D) delete it;
	for (auto const& it : UIs) delete it;

	shaders.clear();
	textures.clear();
	objects2D.clear();
	UIs.clear();
	inputs.clear();
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