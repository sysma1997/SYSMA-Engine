#pragma once

#include <iostream>
#include <string>
#include <map>
#include <SoLoud/soloud.h>
#include <SoLoud/soloud_wav.h>

namespace SYSMA {
	class Audio {
	private:
		SoLoud::Soloud* soloud;
		std::map<std::string, SoLoud::Wav*> samples;
		SoLoud::Wav sample;

	public:
		Audio();
		~Audio();

		void load(std::string name, std::string path);

		SoLoud::handle* play(std::string name);
		SoLoud::handle* playInLoop(std::string name);
		void pause(SoLoud::handle* handle, bool isPause);
		void stop(SoLoud::handle* handle);
	};
}