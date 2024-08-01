#include "FileLogger.hpp"

FileLogger* file_logger;

FileLogger::FileLogger(fs::path path_to_log_file)
	
{
	if (!fs::exists(path_to_log_file)) {
		std::cout << std::format("Log file {} doesn't exist, creating one...", path_to_log_file.generic_string());
	}
	else {
		std::cout << std::format("Log file {} already exists, trucating ...",path_to_log_file.generic_string());
	}
	log_file = std::ofstream{ path_to_log_file, log_file.trunc | log_file.in };
}
void FileLogger::write(std::string& msg) {

	log_file.write(msg.c_str(), msg.length());
}
