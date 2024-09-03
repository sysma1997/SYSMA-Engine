#pragma once

namespace SYSMA {
	struct Input {
		Input();

		virtual void isInputPress(int key, bool isPress) {}
		virtual void isInputJustPress(int key) {}

		void isPauseInput(bool pauseInput);
		bool isPauseInput();

	protected:
		bool pauseInput;
	};
}