#pragma once

namespace SYSMA {
	template<class T>
	class Observer {
	public:
		Observer() {}
		virtual ~Observer() {}

		virtual void update(T* subject) = 0;
	};
}