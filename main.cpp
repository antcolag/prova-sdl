#include "./src/App.hpp"

int main() {
	App {
		"Good News, Everyone!",
		500,
		300,
		std::make_shared<EventHandler>()
	}.run();
	return 0;
}
