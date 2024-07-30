#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "Input.h"
#include "Shader.h"

namespace SYSMA {
	class Engine {
	private:
		static bool Keys[1024];
		static bool KeyProcessed[1024];

		GLFWwindow* window;

		float lastFrame;
		int lastWidth, lastHeight;

		std::vector<Input*> inputs;
	public:
		static int Width, Height;
		static float FWidth, FHeight;
		static float DeltaTime;

		Engine(const char* title, int width = 800, int height = 600);

		static bool KeyPressed(int key);
		static bool KeyJustPressed(int key);
		static glm::vec2 GetSize();
		static glm::vec2 GetSizeMiddle();

		bool isLoop();
		void closeLoop();
		void newFrame();
		void renderFrame();
		void terminate();

		void addInput(Input* input);
	};
}