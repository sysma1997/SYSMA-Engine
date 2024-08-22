#pragma once

#include <vector>

#include "Observer.h"

namespace SYSMA {
	template<class T>
	class Subject {
		std::vector<Observer<T>*> observers;
	public:
		Subject() {}
		virtual ~Subject() {}

		void attach(Observer<T>* observer) {
			observers.push_back(observer);
		}
		void notify() {
			for (int i{ 0 }; i < observers.size(); i++) {
				Observer<T>* observer{ observers[i] };

				observer->update(static_cast<T*>(this));
			}
		}
	};
}