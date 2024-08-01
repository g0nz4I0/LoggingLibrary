#pragma once

#include "Utils.hpp"
#include "SeverityLevels.hpp"
#include "ConsoleColors.hpp"
#include "FileLogger.hpp"

extern std::chrono::system_clock::time_point start_time;

std::string format_time_point(std::chrono::system_clock::time_point current_time_point) {
	auto time_elapsed_since_start = current_time_point - start_time;
	auto us = std::chrono::duration_cast<std::chrono::microseconds>(time_elapsed_since_start).count();
	auto ms = us / 1000;
	us %= 1000;
	auto seconds = ms / 1000;
	ms %= 1000;
	auto minutes = seconds / 60;
	seconds %= 60;
	auto hours = minutes / 60;
	minutes %= 60;
	return std::format("[{}:{}:{}:{}:{}us]",hours,minutes,seconds,ms,us);
	
}
template<SeverityLevels T>
class Log{
	using enum  COLORS;
public:
	Log(std::string msg) {
		std::string severity_level{};
		if constexpr (T == SeverityLevels::TRACE)
		{
			ConsoleColor<WHITE> c;
			severity_level = "\n[TRACE]";
			std::cout<< std::left << std::setw(12) << severity_level;
		}
		else if constexpr (T == SeverityLevels::DEBUG)
		{
			ConsoleColor<MAGENTA> c;
			severity_level = "\n[DEBUG]";
			std::cout << std::left << std::setw(12) << severity_level;
		}
		else if constexpr (T == SeverityLevels::INFO)
		{
			ConsoleColor<GREEN> c;
			severity_level = "\n[INFO]";
			std::cout << std::left << std::setw(12) << severity_level;
		}
		else if constexpr (T == SeverityLevels::WARNING)
		{
			ConsoleColor<YELLOW> c;
			severity_level = "\n[WARNING]";
			std::cout << std::left << std::setw(12) << severity_level;
		}
		else if constexpr (T == SeverityLevels::FATAL)
		{
			ConsoleColor<RED> c;
			severity_level = "\n[FATAL]";
			std::cout <<std::left<< std::setw(12) << severity_level;
		}
		// here destructor of ConsoleColor is called and therefore resets the console color
		auto formatted_time = format_time_point(std::chrono::system_clock::now());
		std::string to_log = formatted_time  + msg;
		std::cout << std::left<<std::setw(20)<<formatted_time;
		std::cout << msg;
		file_logger->write(severity_level.append(to_log));
	}
};
