#include "./src/App.hpp"

int main() {
	App win{
		"Good News, Everyone!",
		500,
		300,
		std::make_shared<EventHandler>()
	};
	win.run().join();
	return 0;
}
