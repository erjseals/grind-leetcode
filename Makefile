# $@ matches the target; $< matches the first dependent
prog: main.o
	g++ -o $@ -Wall $<

%.o: %.cpp
	g++ -c -Wall -g $<

clean:
	rm prog main.o




