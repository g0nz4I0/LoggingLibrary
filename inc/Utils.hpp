#pragma once

#include <iostream>
#include <fstream>
#include <format>
#include <regex>
#include <cstdint>
#include <filesystem>
#include <exception>


#ifdef _WIN32



#else
	#define COLOR_RED     "\x1b[31m"
	#define COLOR_GREEN   "\x1b[32m"
	#define COLOR_YELLOW  "\x1b[33m"
	#define COLOR_BLUE    "\x1b[34m"
	#define COLOR_MAGENTA "\x1b[35m"
	#define COLOR_CYAN    "\x1b[36m"
	#define COLOR_RESET   "\x1b[0m" 
#endif
