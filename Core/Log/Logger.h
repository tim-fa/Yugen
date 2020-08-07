//
// Created by Tim on 06.08.2020.
//
#ifndef LOGGER_H
#define LOGGER_H

// STL
#include <string>

// Libraries
#include <fmt/format.h>

namespace Core
{
	class Logger
	{
		public:
			enum LogLevel
			{
				error,
				info,
				warn,
				debug
			};

			explicit Logger(const std::string& name);

			template<class ... Args>
			void i(const std::string& msg, Args ... args)
			{
				log(LogLevel::info, fmt::format(msg, args...));
			}

			template<class ... Args>
			void w(const std::string& msg, Args ... args)
			{
				log(LogLevel::warn, fmt::format(msg, args...));
			}

			template<class ... Args>
			void e(const std::string& msg, Args ... args)
			{
				log(LogLevel::error, fmt::format(msg, args...));
			}

			template<class ... Args>
			void d(const std::string& msg, Args ... args)
			{
				log(LogLevel::debug, fmt::format(msg, args...));
			}

			void setName(const std::string& name);

			static void setMaxLoglevel(LogLevel level);

		private:
			static std::string getLogLevelStr(LogLevel level);
			void log(LogLevel level, const std::string& msg);
			std::string addPadding(const std::string& msg, int len);

			std::string name;
	};
}

#endif