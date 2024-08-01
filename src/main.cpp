#include "FileLogger.hpp"
#include "Log.hpp"


std::chrono::system_clock::time_point start_time{};


std::string get_log_file_name(int argc, char* argv[]) {
	std::string ret{ "log.txt" };
	std::regex cli_parser("--file=([A-Za-z0-9_-]*)+\\.txt");
	
	if ( argc == 2) {
		// argv[0]  is the program name
		// argv[1] is the inputted param
		// we need to parse it
		ret = argv[1];
		std::string as_str{ ret };
		if (!std::regex_match(as_str, cli_parser)) {
			throw std::invalid_argument(std::format("Invalid file name, with file name {}", as_str));
		}
		static constexpr int first_valid_character = 7;
		ret = ret.substr(first_valid_character,ret.length() - 6);
		
	}
	return ret;

}


int main(int argc,char* argv[]) {
	using enum SeverityLevels;
#ifdef _WIN32
	WinConsoleColor::activateVirtualTerminal();
#endif
	start_time = std::chrono::system_clock::now();
	file_logger = new FileLogger{ get_log_file_name(argc, argv)};
	Log<TRACE>("this is a trace message");
	Log<DEBUG>("this is a debug message");
	Log<INFO>("this is an info message");
	Log<WARNING>("this is a warning message");
	Log<FATAL>("this is a fatal message");

	std::this_thread::sleep_for(1s);
	int limit = 250;
	int actual = 12;
	Log<FATAL>(std::format("Expected value greater than {}: got {}",limit,actual));
	return 0;
}