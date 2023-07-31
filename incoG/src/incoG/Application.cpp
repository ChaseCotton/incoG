#include "Application.h"

#include "C:\Engine\incoG\incoG\src\incoG\Events\ApplicationEvent.h"
#include "C:\Engine\incoG\incoG\src\incoG\Log.h"

namespace incoG {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		IG_TRACE(e);

		while (true);
	}

}