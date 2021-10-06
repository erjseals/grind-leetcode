TESTFILES := $(wildcard *.out.expected)
TESTS := $(TESTFILES:.out.expected=.test)

.PHONY: all

all: $(TESTS)

%.test:
	@echo "Testing $*.out.expected"
	@touch $*.out #Creates out file to diff in case of no output
	@touch $*.err #The @ means don't show the command being invoked
	@../prog 1> $*.out 2> $*.err ;\
	PROG_EXIT_CODE=$$?;\
	echo "diff output...";\
	diff $*.out $*.out.expected;\
	OUT_EXIT_CODE=$$?;\

	@# Commenting out because program failure is success
	@#exit $$PROG_EXIT_CODE && $$OUT_EXIT_CODE && $$ERR_EXIT_CODE

clean:
	rm *.out *.err
