workspace "incoG"
	architecture "x64"
	startproject "Creative"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "incoG"
	location "incoG"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "igpch.h"
	pchsource "incoG/src/igpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++14"
		staticruntime "On"
		systemversion "latest"

		defines {
			"IG_PLATFORM_WINDOWS",
			"IG_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Creative")
		}

	filter "configurations:Debug"
		defines "IG_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "IG_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "IG_DIST"
		symbols "On"

project "Creative"
	location "Creative"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
 	}

	includedirs{
		"incoG/vendor/spdlog/include",
		"incoG/src"
	}

	links {
		"incoG"
	}

	filter "system:windows"
		cppdialect "C++14"
		staticruntime "On"
		systemversion "latest"

		defines {
			"IG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "IG_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "IG_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "IG_DIST"
		symbols "On"