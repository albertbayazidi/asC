cc := clang
src := src
lib := lib
obj := $(src)/obj
project_name := asC

cflags := -Wall -I$(lib)
ldflags := -lm 

cflags_release := $(cflags) -O3
cflags_debug   := $(cflags) -O0 -g -fsanitize=address

src_files := $(wildcard $(src)/*.c)
obj_files := $(patsubst $(src)/%.c,$(obj)/%.o,$(src_files))
obj_files_debug := $(patsubst $(src)/%.c,$(obj)/%_debug.o,$(src_files))

all: release

release: $(obj_files)
	$(cc) -o $(project_name) $^ $(ldflags)

debug: $(obj_files_debug)
	$(cc) -o $(project_name)_debug $^ $(ldflags)

$(obj)/%.o: $(src)/%.c | $(obj)
	$(cc) $(cflags_release) -c $< -o $@

$(obj)/%_debug.o: $(src)/%.c | $(obj)
	$(cc) $(cflags_debug) -c $< -o $@

$(obj):
	mkdir -p $(obj)

.PHONY: clean
clean:
	rm -rf $(project_name) $(project_name)_debug $(obj)/*.o $(obj)/*_debug.o
