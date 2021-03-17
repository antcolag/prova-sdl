debug: main.o ./src/App.o
	g++ -lSDL2 -lpthread -latomic -g -Wall -m64 -std=c++20 -o debug *.o ./src/*.o

release: main.o ./src/App.o
	g++ -lSDL2 -lpthread -latomic -O3 -std=c++20 -o release *.o ./src/*.o

clean:
	rm main.o ./src/App.o