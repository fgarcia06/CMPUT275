CC = g++
C_FLAGS = -std=c++11 -Wall -g

both:
	make ws1
	make ws2

ws1: hashtest_ws_sol.cpp hash_table_ws_sol.h dynarray.h linked_list.h
	$(CC) $(C_FLAGS) hashtest_ws_sol.cpp -o ws1

ws2: hashtest_ws_sol2.cpp hash_table_ws_sol.h dynarray.h linked_list.h
	$(CC) $(C_FLAGS) hashtest_ws_sol2.cpp -o ws2

clean:
	-rm ws1 ws2
	-rm *.o
