CC= g++
LFLAGS=
CFLAGS= -O2 -Wall -std=c++11
OBJS=expr_eval.o
PROJ=expr_eval

$(PROJ): expr_eval.o
	g++ expr_eval.o -o $(PROJ) $(CFLAGS)

expr_eval.o: expr_eval.cpp
	g++ expr_eval.cpp -o expr_eval.o -c $(CFLAGS)

# runs the 3 given tests, if one causes the program to terminate
# abnormally (i.e. not return 0), the remaining will not run
test: $(PROJ)
	@echo
	@echo "Running test1.txt"
	@./$(PROJ) < test1.txt
	@echo

	@echo "Running test2.txt"
	@./$(PROJ) < test2.txt
	@echo

	@echo "Running test3.txt"
	@./$(PROJ) < test3.txt
	@echo

clean:
	@rm -f $(OBJS) $(PROJ)
