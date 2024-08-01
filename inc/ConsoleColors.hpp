#include "Utils.hpp"

#ifdef _WIN32
	#include "Windows.h"
	#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
	#define DISABLE_NEWLINE_AUTO_RETURN  0x0008
enum class COLORS {
	NC = -1,
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
};
enum STYLE {

};
namespace WinConsoleColor {
	void activateVirtualTerminal()
	{
		HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD consoleMode;
		GetConsoleMode(handleOut, &consoleMode);
		consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		consoleMode |= DISABLE_NEWLINE_AUTO_RETURN;
		SetConsoleMode(handleOut, consoleMode);
	}
}

#else
	#define COLOR_RED     "\x1b[31m"
	#define COLOR_GREEN   "\x1b[32m"
	#define COLOR_YELLOW  "\x1b[33m"
	#define COLOR_BLUE    "\x1b[34m"
	#define COLOR_MAGENTA "\x1b[35m"
	#define COLOR_CYAN    "\x1b[36m"
	#define COLOR_RESET   "\x1b[0m" 
#endif

template<COLORS color>
class ConsoleColor {


public:
	ConsoleColor() {
		
		std::cout << colorize(static_cast<int>(color));
	}
	//lets take advantage of the destructor to reset the output
	~ConsoleColor() {
		std::cout << colorize(static_cast<int>(COLORS::NC));
	}

	/**
* Colorize terminal colors ANSI escape sequences.
*
* @param font font color (-1 to 7), see COLORS enum
* @param back background color (-1 to 7), see COLORS enum
* @param style font style (1==bold, 4==underline)
**/
	const char* colorize(int font, int back = -1, int style = -1) {
		static char code[20];

		if (font >= 0)
			font += 30;
		else
			font = 0;
		if (back >= 0)
			back += 40;
		else
			back = 0;

		if (back > 0 && style > 0) {
			sprintf(code, "\033[%d;%d;%dm", font, back, style);
		}
		else if (back > 0) {
			sprintf(code, "\033[%d;%dm", font, back);
		}
		else {

			sprintf(code, "\033[%dm", font);
		}

		return code;
	}


};