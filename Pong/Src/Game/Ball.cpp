#include "Ball.h"

using namespace SYSMA;

Pong::Game::Ball::Ball(Scene& scene, 
	Pong::Shared::SubjectGame& subject) : E2D::Circle{ Engine::GetShader("default"), 14 }, 
	subject{ subject }, 
	unapplyCollision{ false }, seconds{ 0.0f }, speed{ 300.0f }, audio{ } {
	srand(time(NULL));
	name = "ball";
	isCheckCollision = true;
	size = glm::vec2{ Engine::GetSizeMiddle().x * 0.07f };
	position = Engine::GetSizeMiddle();

	assignDirection();
	scene.addObject2D(this);

	audio.load("collision", "Assets/Sounds/ballCollision.wav");
	audio.load("boo", "Assets/Sounds/boo.mp3");
	audio.load("cellebration", "Assets/Sounds/cellebration.mp3");
}

void Pong::Game::Ball::process() {
	if (unapplyCollision) {
		seconds += Engine::DeltaTime;
		if (seconds > 0.2f) {
			unapplyCollision = false;
			seconds = 0.0f;
		}
	}

	position += direction * speed * Engine::DeltaTime;
	
	if (position.y < size.y || 
		position.y > Engine::GetSize().y - (size.y / 2.0f))
		direction.y *= -1.0f;

	if (position.x < 0.0f || position.x > Engine::FWidth) {
		float direction{ (position.x < 0.0f) ? 1.0f : -1.0f };
		reset(direction);
		Pong::Shared::SubjectGame::Assign assign{
			(direction == 1.0f) ?
				Pong::Shared::SubjectGame::OPPONENT :
				Pong::Shared::SubjectGame::PLAYER
		};
		subject.setAssign(assign);

		audio.play((direction == 1.0f) ? "boo" : "cellebration");
	}

	subject.setPosition(position);
}
void Pong::Game::Ball::isCollision(Object& object) {
	if (unapplyCollision) return;

	unapplyCollision = true;
	direction.x *= -1.0f;
	speed += 15.0f;
	audio.play("collision");
}
void Pong::Game::Ball::reset(float direction) {
	assignDirection(direction);
	position = Engine::GetSizeMiddle();
}
void Pong::Game::Ball::assignDirection(float leftRight) {
	direction = glm::vec2{
		((rand() % 2) == 0) ? -1.0f : 1.0f,
		((rand() % 2) == 0) ? -1.0f : 1.0f
	};
	if (leftRight != 0.0f) direction.x = leftRight;
}

void Pong::Game::Ball::update(Pong::Shared::SubjectGame* subject) {
	auto method = subject->getMethod();
	if (method != Pong::Shared::SubjectGame::Method::RESET_GAME) return;

	reset(0.0f);
}