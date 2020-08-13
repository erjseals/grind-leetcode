# $@ matches the target; $< matches the first dependent
prog: main.o
	g++ -o $@ $<

main.o: main.cpp
	g++ -c $<

clean:
	rm prog main.o