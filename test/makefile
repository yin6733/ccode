src = $(wildcard *.c)
obj = $(patsubst %.c, %.o, $(src))

ALL: bubble

bubble: $(obj)
	gcc $(obj) -o bubble
$(obj): $(src)
	gcc -c $(src) -o $(obj)
clean:
	-rm -rf $(obj)
