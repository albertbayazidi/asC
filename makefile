cc := gcc
src := src
lib := lib
obj := $(src)/obj
project_name := main

inc := -I$(lib) -lm
exsternalInc := -Ihome/albert/git/software/stb
totInc := $(inc) $(exsternalInc)

cflags := -Wall -O1

src_files := $(wildcard $(src)/*.c)

obj_files := $(wildcard $(src)/%.c, $(obj)/%.o, $(src_files))

all: $(project_name)

$(project_name): $(obj_files)
	$(cc) $(cflags) $(totInc) -o $@ $^

$(obj)/%.o: $(src)/%.c
	$(cc) $(cflags) $(totInc) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(project_name) $(obj)/*.o
