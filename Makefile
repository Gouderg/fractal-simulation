fractal: main.o pvector.o
	g++ $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system

main.o: src/main.cpp include/pvector.h
	g++ -Wall -std=c++11 -c $<

pvector.o: src/pvector.cpp include/pvector.h
	g++ -Wall -std=c++11 -c $<

clean:
	rm *.o fractal

r: clean fractal