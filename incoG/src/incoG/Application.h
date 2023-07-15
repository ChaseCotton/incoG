#pragma once

#include "Core.h"

namespace incoG {

	class INCOG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// defined in client
	Application* CreateApplication();
}
