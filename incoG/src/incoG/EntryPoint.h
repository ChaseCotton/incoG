#pragma once

#ifdef IG_PLATFORM_WINDOWS

extern incoG::Application* incoG::CreateApplication();

int main(int argc, char** argv) {
	incoG::Log::Init();
	IG_CORE_WARN("Initialized Log");
	IG_INFO("Hello");

	auto app = incoG::CreateApplication();
	app->Run();
	delete app;
}

#endif