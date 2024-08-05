#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Shader.h"
#include "Texture.h"
#include "Scene.h"

namespace SYSMA {
	class Engine {
	private:
		static bool Keys[1024];
		static bool KeyProcessed[1024];
		static std::map<std::string, Shader*> Shaders;
		static std::map<std::string, Texture*> Textures;

		GLFWwindow* window;

		float lastFrame;
		int lastWidth, lastHeight;

		Scene* scene;
	public:
		static int Width, Height;
		static float FWidth, FHeight;
		static float DeltaTime;

		Engine(const char* title, int width = 800, int height = 600);
		~Engine();

		static bool KeyPressed(int key);
		static bool KeyJustPressed(int key);
		static glm::vec2 GetSize();
		static glm::vec2 GetSizeMiddle();
		static void AddShader(std::string name, Shader* shader);
		static void RemoveShader(std::string name);
		static Shader* GetShader(std::string name);
		static void AddTexture(std::string name, Texture* texture);
		static void RemoveTexture(std::string name);
		static Texture* GetTexture(std::string name);

		void start();
		void closeLoop();

		void loadScene(Scene* scene);
	};
}