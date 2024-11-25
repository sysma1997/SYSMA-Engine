#include "../Include/Audio.h"

using namespace SYSMA;

Audio::Audio() : soloud{ new SoLoud::Soloud } {
	soloud->init();
}
Audio::~Audio() {
	soloud->deinit();
}

void Audio::load(std::string name, std::string path) {
	samples[name] = new SoLoud::Wav{};
	samples[name]->load(path.c_str());
}
SoLoud::handle* Audio::play(std::string name) {
	SoLoud::Wav* wav{ samples[name] };
	if (wav == nullptr) return nullptr;

	SoLoud::handle handle{ soloud->play(*wav) };
	return &handle;
}
SoLoud::handle* Audio::playInLoop(std::string name) {
	SoLoud::Wav* wav{ samples[name] };
	if (wav == nullptr) return nullptr;

	SoLoud::handle handle{ soloud->play(*wav) };
	soloud->setLooping(handle, true);
	return &handle;
}
void Audio::pause(SoLoud::handle* handle, bool isPause) {
	soloud->setPause(*handle, isPause);
}
void Audio::stop(SoLoud::handle* handle) {
	soloud->stop(*handle);
}