lsdl_flags = -lSDL2 -lSDL2main -lSDL2_image -lpthread -latomic -pedantic

program_parts = main.o ./src/App.o ./src/EventHandler.o

debug: $(program_parts)
	g++ $(lsdl_flags) -std=c++20 -m64 -g -Wall -o debug *.o ./src/*.o

profile: $(program_parts)
	g++ $(lsdl_flags) -std=c++20 -m64 -p -Wall -o debug *.o ./src/*.o

release: $(program_parts)
	g++ $(lsdl_flags) -std=c++20 -m64 -O3 -o release *.o ./src/*.o

clean:
	rm -f $(program_parts)