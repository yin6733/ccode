src = $(wildcard *.c)
obj = $(patsubst %.c, %.o, $(src))
tar = $(patsubst %.o, %.out, $(obj))

ALL: $(tar)

%.out: %.o
	gcc $< -o $@
%.o: %.c
	gcc -c $< -o $@

clean:
	-rm -rf ./*.o
