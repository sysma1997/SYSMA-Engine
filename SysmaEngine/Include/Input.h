#pragma once

namespace SYSMA {
	struct Input {
		Input();

		virtual void isInputPress(int key, bool isPress) {}
		virtual void isInputJustPress(int key) {}

	protected:
		bool pause;
	};
}