fractal: main.o pvector.o fractal.o kochline.o
	g++ $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system

main.o: src/main.cpp include/pvector.h include/fractal.h include/kochline.h
	g++ -Wall -std=c++11 -c $<

pvector.o: src/pvector.cpp include/pvector.h
	g++ -Wall -std=c++11 -c $<

fractal.o: src/fractal.cpp include/fractal.h
	g++ -Wall -std=c++11 -c $<

kochline.o: src/kochline.cpp include/kochline.h
	g++ -Wall -std=c++11 -c $<

clean:
	rm *.o fractal

r: clean fractal