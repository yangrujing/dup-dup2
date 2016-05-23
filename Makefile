dup:dup.c
	gcc -o dup dup.c
.PHONY:clean
clean:
	rm -rf dup file
