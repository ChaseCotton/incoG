#pragma once

#ifdef IG_PLATFORM_WINDOWS

extern incoG::Application* incoG::CreateApplication();

int main(int argc, char** argv) {
	auto app = incoG::CreateApplication();
	app->Run();
	delete app;
}

#endif