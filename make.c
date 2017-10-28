hello: hello.c
	gcc -g -Wall -Werror -o hello hello.c
	
.PHONY: clean

clean:
	$(RM) hello