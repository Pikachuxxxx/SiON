workspace "SiON"
    configurations { "Debug32", "Release32", "Debug64", "Release64" }

    filter "configurations:*32"
       architecture "x86"

    filter "configurations:*64"
       architecture "x86_64"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SiON"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "source-cpp/si/**.h",
        "source-cpp/si/**.cpp"
    }

    filter "configurations:Debug*"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release*"
        runtime "Release"
        optimize "On"
