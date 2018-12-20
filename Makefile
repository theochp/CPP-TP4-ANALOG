SRC_FILES := $(wildcard *.cpp)
H_FILES := $(wildcard *.h)
OBJ_FILES := $(patsubst %.cpp,build/%.o,$(SRC_FILES))
GPP_ARGS  := -std=c++11 -Wall -Werror -pedantic

bin/analog: $(OBJ_FILES) $(H_FILES)
	g++ $(GPP_ARGS) $(OBJ_FILES) -o $@

debug: bin/debug
bin/debug: GPP_ARGS += -g -DMAP
bin/debug: $(OBJ_FILES) $(H_FILES)
	g++ $(GPP_ARGS) $(OBJ_FILES) -o $@

build/%.o: %.cpp
	g++ -c $(GPP_ARGS) $< -o $@

.PHONY: clean
clean:
	@rm -f build/*.o bin/*
