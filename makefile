$HEADERS = set.c bmp_header.h

build:
	gcc -Wall 2.c -o 2
run_task1:
	./2 1
run_task2:
	./2 2
run_task3:
	./2 3
run_task4:
	./2 4
run_bonus:
	./2 b
	./2 3
clear:
	rm -f 2
