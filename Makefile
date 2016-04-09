select:select.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -r select
