#pragma once

#include <glm/glm.hpp>

#include <Subject.h>

namespace Pong::Shared {
	class SubjectBallPosition : public SYSMA::Subject<SubjectBallPosition> {
		glm::vec2 position;

	public:
		SubjectBallPosition();
		~SubjectBallPosition() {}

		void change(glm::vec2 position);
		glm::vec2 get();
	};
}