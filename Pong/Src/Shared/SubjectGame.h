#pragma once

#include <glm/glm.hpp>

#include <Subject.h>

namespace Pong::Shared {
	class SubjectGame : public SYSMA::Subject<SubjectGame> {
	public:
		enum Method {
			BALL_POSITION, 
			ASSIGN_POINT, 
			RESET_GAME
		};
		enum Assign {
			PLAYER,
			OPPONENT
		};
	private:
		Method method;
		
		Assign assign;
		glm::vec2 position;

	public:
		Method getMethod() const;

		void setAssign(Assign assign);
		Assign getAssign() const;
		void setPosition(glm::vec2 position);
		glm::vec2 getPosition() const;

		void reset();
	};
}