app: dir.o
	@gcc dir.o -o app
dir.o:
	@gcc -c dir.c
run: app
	@./app
clean:
	@rm *.o
