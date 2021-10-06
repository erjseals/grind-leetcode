CPP_SRCS := $(wildcard *.cpp) 
OBJ_SRCS := $(CPP_SRCS:.cpp=.o)

all: prog

# $@ matches the target; $< matches the first dependent
prog: $(OBJ_SRCS) 
	g++ -Wall -g -o $@ $(OBJ_SRCS)

%.o: %.cpp
	g++ -g -Wall -c -o $@ $<

clean:
	rm prog *.o

test: all
	$(MAKE) -C tests/
cleantest:
	$(MAKE) -C tests/ clean


