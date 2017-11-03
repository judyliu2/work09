app: dir.o
	@gcc dir.o -o app

app_debug: dir_debug.o
	@gcc dir_debug.o -o app_debug

dir.o: dir.c
	@gcc -c dir.c

dir_debug.o: dir.c
	@gcc -g -c dir.c -o dir_debug.o

run: app
	@./app

clean:
	@rm *.o

debug: app_debug
	@valgrind --leak-check=yes ./app_debug
