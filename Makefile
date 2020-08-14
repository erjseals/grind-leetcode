# $@ matches the target; $< matches the first dependent
prog: main.o
	g++ -o $@ -Wall $<

main.o: main.cpp
	g++ -c -Wall -g $<

clean:
	rm prog main.o