#pragma once

namespace SYSMA {
	class Input {
	public:
		virtual void isInputPress(int key, bool isPress) {}
		virtual void isInputJustPress(int key, bool isPress) {}
	};
}