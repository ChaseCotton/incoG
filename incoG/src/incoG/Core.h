#pragma once

#ifdef IG_PLATFORM_WINDOWS
	#ifdef IG_BUILD_DLL
		#define INCOG_API __declspec(dllexport)
	#else
		#define INCOG_API __declspec(dllimport)
	#endif
#else
	#error incoG only supports Windows 64x
#endif

#define BIT(x) (1 << x)