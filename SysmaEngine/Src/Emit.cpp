#include "../Include/Emit.h"

using namespace SYSMA;

template<class T>
void Emit<T>::subscribe(std::string name, Signal<T>* signal) {
	std::vector<Signal<T>*>* vector{ &signals[name] };
	vector->push_back(signal);
}
template<class T>
void Emit<T>::emit(std::string name, const T& value) {
	std::vector<Signal<T>*> vector{ signals[name] };
	for (int i{ 0 }; i < vector.size(); i++) {
		Signal<T>* signal{ vector[i] };
		signal->received(value);
	}
}