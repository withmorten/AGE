workspace "AGE"
	configurations
	{
		"Debug",
		"Release",
	}

	startproject "AGE"

	location "build"

	characterset ("Unicode")
	toolset ("v143")

	defines { "WIN32", "_CRT_SECURE_NO_WARNINGS", "_CRT_NONSTDC_NO_DEPRECATE", "_CRT_NONSTDC_NO_WARNINGS" }
	flags { "MultiProcessorCompile" }

	staticruntime "on"
	conformancemode "on"

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "full"
		optimize "off"
		runtime "debug"

	filter { "configurations:Release" }
		defines { "NDEBUG" }
		runtime "release"
		symbols "on"
		optimize "speed"
		inlining "auto"
		flags { "LinkTimeOptimization" }

project "AGE"
	kind "WindowedApp"
	language "C++"
	targetname "AdvancedGenieEditor3"
	targetdir "bin/%{cfg.buildcfg}"
	targetextension ".exe"
	dpiawareness "HighPerMonitor"

	files { "../AGE.rc" }
	files { "../AppIcon.ico" }

	includedirs { "../../vendor/win-iconv" }

	includedirs { "../../vendor/wxWidgets-3.1.4/include" }
	includedirs { "../../vendor/wxWidgets-3.1.4/include/msvc" }
	includedirs { "../../vendor/wxWidgets-3.1.4/lib/vc_lib/mswu" }
	libdirs { "../../vendor/wxWidgets-3.1.4/lib/vc_lib" }

	includedirs { "../../vendor/SFML/include" }
	libdirs { "../../vendor/SFML/lib" }

	includedirs { "../../vendor/boost_1_80_0" }
	libdirs { "../../vendor/boost_1_80_0/lib32-msvc-14.3" }

	dependson { "genieutils" }
	libdirs { "build/obj/%{cfg.buildcfg}/genieutils" }
	links { "genieutils" }
	includedirs { "../../genieutils/include" }

	includedirs { ".." }

	files { "../*.h" }
	files { "../*.hpp" }
	files { "../*.cpp" }
	files { "../AGE_Frame/*.cpp" }
	files { "../Licenses/*.h" }

	removefiles { "../rmcc.cpp" }

	includedirs { "../Precompile" }
	files { "../Precompile/Common.*" }
	pchheader "Common.h"
	pchsource "../Precompile/Common.cpp"

	filter "configurations:Debug"
		links { "sfml-audio-d", "sfml-system-d" }

	filter "configurations:Release"
		links { "sfml-audio", "sfml-system" }

project "genieutils"
	kind "StaticLib"
	language "C++"
	targetname "genieutils"
	targetdir "build/obj/%{cfg.buildcfg}/genieutils"
	targetextension ".lib"

	includedirs { "../../vendor/win-iconv" }
	files { "../../vendor/win-iconv/win_iconv.c" }

	includedirs { "../../vendor" }
	files { "../../vendor/pcrio/pcrio.c" }

	includedirs { "../../vendor/boost_1_80_0" }

	includedirs { "../../vendor/lz4/lib" }
	files { "../../vendor/lz4/lib/lz4.h" }
	files { "../../vendor/lz4/lib/lz4frame.h" }
	files { "../../vendor/lz4/lib/lz4frame_static.h" }
	files { "../../vendor/lz4/lib/lz4hc.h" }
	files { "../../vendor/lz4/lib/xxhash.h" }
	files { "../../vendor/lz4/lib/lz4.c" }
	files { "../../vendor/lz4/lib/lz4frame.c" }
	files { "../../vendor/lz4/lib/lz4hc.c" }
	files { "../../vendor/lz4/lib/xxhash.c" }

	includedirs { "../../genieutils/include" }

	files { "../../genieutils/include/genie/**.h" }
	files { "../../genieutils/src/**.cpp" }

	removefiles { "../../genieutils/src/tools/**.cpp" }
