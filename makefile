lsdl_flags = -lSDL2 -lSDL2main -lSDL2_image -lpthread -latomic -pedantic

program_parts = main.o ./src/App.o ./src/EventHandler.o ./src/Entity.o

debug_flag = -g

CXXFLAGS = -std=c++20 -Wall -m64

debug: init_debug $(program_parts)
	g++ $(lsdl_flags) -o debug *.o ./src/*.o

profile: CXXFLAGS += -p
profile: init_debug $(program_parts)
	g++ $(lsdl_flags) -o profile *.o ./src/*.o

release: CXXFLAGS += -O3
release: $(program_parts)
	g++ $(lsdl_flags) -o release *.o ./src/*.o

clean:
	rm -f $(program_parts)

init_debug:
	$(eval CXXFLAGS += $(debug_flag))