#include "SubjectBallPosition.h"

using namespace Pong::Shared;

SubjectBallPosition::SubjectBallPosition() : position{ 0.0f } {}

void SubjectBallPosition::change(glm::vec2 position) {
	this->position = position;
	notify();
}
glm::vec2 SubjectBallPosition::get() {
	return position;
}