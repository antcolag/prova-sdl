#include "./src/App.hpp"

int main() {
	App win{"Ciaonee!!", 500, 300};
	win.run().join();
	return 0;
}