#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include <spdlog/fmt/ostr.h>

namespace incoG {

	class INCOG_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		

	};

}

// core log macros
#define IG_CORE_TRACE(...)    ::incoG::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define IG_CORE_INFO(...)     ::incoG::Log::GetCoreLogger()->info(__VA_ARGS__)
#define IG_CORE_WARN(...)     ::incoG::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define IG_CORE_ERROR(...)    ::incoG::Log::GetCoreLogger()->error(__VA_ARGS__)
#define IG_CORE_CRITICAL(...) ::incoG::Log::GetCoreLogger()->critical(__VA_ARGS__)

// client log macros
#define IG_TRACE(...)    ::incoG::Log::GetClientLogger()->trace(__VA_ARGS__)
#define IG_INFO(...)     ::incoG::Log::GetClientLogger()->info(__VA_ARGS__)
#define IG_WARN(...)     ::incoG::Log::GetClientLogger()->warn(__VA_ARGS__)
#define IG_CRITICAL(...) ::incoG::Log::GetClientLogger()->critical(__VA_ARGS__)
