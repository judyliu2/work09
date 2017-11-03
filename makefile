app: dir.o
	@gcc dir.o -o app

dir.o: dir.c
	@gcc -c dir.c

run: app
	@./app

clean:
	@rm *.o
