#pragma once

#include <glm/glm.hpp>

#include "Object.h"

namespace SYSMA {
	namespace E2D {
		class Collision {
		public:
			virtual ~Collision() {}

			virtual void onCollision(const Object& object) = 0;
		};
	}
}