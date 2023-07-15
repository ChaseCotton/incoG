#include <incoG.h>

class Creative : public incoG::Application {

public:
	Creative() {

	}

	~Creative() {

	}
};

incoG::Application* incoG::CreateApplication() {
	return new Creative();
}