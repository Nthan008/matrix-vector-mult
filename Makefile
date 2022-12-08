all: mylib.o
	gcc -o main.out main_test.c mylib.o

mylib.o:
	gcc -o mylib.o -c mylib/mylib.c
	
clear:
	rm -rf *.out
	rm -rf *.o

time: mylib.o 
	gcc -o main_b_time.out main_b_time.c mylib.o

space: mylib.o
	gcc -o main_b_space.exe main_b_space.c mylib.o

