#pragma once
#include "Utils.hpp"

namespace fs = std::filesystem;

class FileLogger {

public:
	FileLogger(fs::path path_to_log_file);
	void write(std::string& msg);
private:
	std::ofstream log_file;
};

extern FileLogger* file_logger;
