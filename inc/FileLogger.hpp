#pragma once
#include "Utils.hpp"

namespace fs = std::filesystem;

class FileLogger {

public:
	FileLogger(fs::path path_to_log_file);
private:
	std::ofstream log_file;
};
