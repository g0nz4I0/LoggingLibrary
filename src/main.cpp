#include "FileLogger.hpp"

std::string parse_cli_arguments(int argc, char* argv[]) {
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

	FileLogger file_logger{ parse_cli_arguments(argc, argv) };


	return 0;
}