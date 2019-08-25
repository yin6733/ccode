src = $(wildcard ./resource/*.c)
obj = $(patsubst ./resource/%.c, ./obj/%.o, $(src))

ALL: comp

comp: $(obj)
	gcc $(obj) -o comp
$(obj):./obj/%.o:./resource/%.c
	gcc -c $< -o $@ -I ./inc

clean: 
	-rm -rf $(obj)

.PHONY: clean ALL
	
