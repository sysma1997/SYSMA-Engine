#include "../Include/Engine.h"

using namespace SYSMA;

int Engine::Width{ 800 }, Engine::Height{ 600 };
float Engine::FWidth{ 800.0f }, Engine::FHeight{ 600.0f };
bool Engine::Keys[1024];
bool Engine::KeyProcessed[1024];
float Engine::DeltaTime{ 0.0f };

Engine::Engine(const char* title, int width, int height) : lastFrame{ 0.0f }, lastWidth{ 0 }, lastHeight{ 0 } {
	if (!glfwInit()) {
		std::cout << "Error to init GLFW.\n";
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!window) {
		std::cout << "Error to create window with GLFW.\n";
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	
	glewExperimental = true;
	if (glewInit() != GLEW_OK) {
		std::cout << "Error to init GLEW.\n";
		return;
	}

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Width = width;
	Height = height;
	FWidth = static_cast<float>(Width);
	FHeight = static_cast<float>(Height);

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (key > -1 && key < 1025) {
			if (action == GLFW_PRESS) {
				Keys[key] = true;
			}
			if (action == GLFW_RELEASE) {
				Keys[key] = false;
				KeyProcessed[key] = false;
			}
		}
	});
}

bool Engine::KeyPressed(int key) {
	return Keys[key];
}
bool Engine::KeyJustPressed(int key) {
	if (Keys[key] && !KeyProcessed[key]) {
		KeyProcessed[key] = true;
		
		return true;
	}

	return false;
}
glm::vec2 Engine::GetSize() {
	return glm::vec2{ FWidth, FHeight };
}
glm::vec2 Engine::GetSizeMiddle() {
	return glm::vec2{ GetSize() / 2.0f };
}

bool Engine::isLoop() {
	return !glfwWindowShouldClose(window);
}
void Engine::closeLoop() {
	glfwSetWindowShouldClose(window, true);
}
void Engine::newFrame() {
	float currentFrame{ static_cast<float>(glfwGetTime()) };
	DeltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	glfwGetFramebufferSize(window, &Width, &Height);
	glViewport(0, 0, Width, Height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (Width != lastWidth ||
		Height != lastHeight) {
		if (Width != lastWidth) {
			lastWidth = Width;
			FWidth = static_cast<float>(Width);
		}
		if (Height != lastHeight) {
			lastHeight = Height;
			FHeight = static_cast<float>(Height);
		}
	}

	for (int i{ 0 }; i < inputs.size(); i++) {
		for (int key{ 0 }; key < 1025; key++) {
			if (Keys[key])
				inputs[i]->isInputPress(key);
			if (Keys[key] && !KeyProcessed[key]) {
				KeyProcessed[key] = true;
				inputs[i]->isInputJustPress(key);
			}
		}
	}
}
void Engine::renderFrame() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}
void Engine::terminate() {
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Engine::addInput(Input* input) {
	inputs.push_back(input);
}