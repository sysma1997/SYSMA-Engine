#include <iostream>

#include <Engine.h>
#include <Shader.h>
#include <Input.h>

#include <Input.h>
#include <2D/Sprite.h>
#include <2D/Triangle.h>
#include <2D/Rectangle.h>
#include <UI/Label.h>

using namespace SYSMA;

int main() {
	Engine* engine{ new Engine{"Pong"} };
	
	Shader* shaderRect{ new Shader{} };
	shaderRect->link(Object::VERT, Object::FRAG);
	Shader* shaderLabel{ new Shader{} };
	shaderLabel->link(UI::Label::VERT, UI::Label::FRAG);

	UI::Label* label{ new UI::Label{shaderLabel, "Assets/Fonts/Robot_font.otf", 30} };
	label->setText("test");
	label->position = glm::vec2{ 5.0f, (label->size.y / 2.0f) + 5.0f };
	UI::Label* label2{ new UI::Label{shaderLabel, "Assets/Fonts/Robot_font.otf", 30} };
	label2->setText("CENTER UP");
	label2->align = UI::Label::Aling::CENTER;
	label2->position = glm::vec2{ Engine::GetSizeMiddle().x, (label2->size.y / 2.0f) + 5.0f };
	label2->color = glm::vec3{ 0.0f, 1.0f, 0.0f };
	UI::Label* label3{ new UI::Label{shaderLabel, "Assets/Fonts/Robot_font.otf", 30} };
	label3->setText("Finish");
	label3->align = UI::Label::Aling::RIGHT;
	label3->position = glm::vec2{ Engine::GetSize().x - 5.0f, (label2->size.y / 2.0f) + 5.0f };
	label3->color = glm::vec3{ 0.0f, 0.0f, 1.0f };

	E2D::Triangle* triangle{ new E2D::Triangle{shaderRect} };
	triangle->size = glm::vec2{ 60.0f };
	triangle->position = glm::vec2{ 100.0f };

	Shader* shaderSprite{ new Shader{} };
	shaderSprite->link(E2D::Sprite::VERT, E2D::Sprite::FRAG);
	Texture* texture{ new Texture{"Assets/Images/gameover.png", true} };
	E2D::Sprite* go{ new E2D::Sprite{shaderSprite, texture} };
	go->size = glm::vec2{ 300.0f, 120.0 };
	go->position = Engine::GetSizeMiddle();

	float velocity{ 0 };
	while (engine->isLoop()) {
		engine->newFrame();

		if (Engine::KeyPressed(GLFW_KEY_SPACE)) {
			velocity += 50.0f;
			if (velocity > 500.0f)
				velocity = 500.0f;
		}

		triangle->position += velocity * Engine::DeltaTime;

		velocity -= 10.0f;
		if (velocity < 0.0f) velocity = 0.0f;

		triangle->draw();
		go->draw();
		
		label->draw();
		label2->draw();
		label3->draw();

		engine->renderFrame();
	}

	engine->terminate();
	return 0;
}