CC = g++
C_FLAGS = -std=c++11 -Wall -g

# I've been forgetting to add the .h to the dependencies.
# But remembered here.
lws: listtest_ws_sol.cpp linked_list_ws_sol.h
	$(CC) $(C_FLAGS) listtest_ws_sol.cpp -o lws

clean:
	-rm lws
	-rm *.o
