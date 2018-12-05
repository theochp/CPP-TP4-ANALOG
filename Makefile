SRC_FILES := $(wildcard *.cpp)
OBJ_FILES := $(patsubst %.cpp,build/%.o,$(SRC_FILES))
GPP_ARGS  := -std=c++11

bin/release: $(OBJ_FILES)
	$(eval OBJ_FILES := $(subst build/main_test.o,,${OBJ_FILES}))
	g++ $(GPP_ARGS) $(OBJ_FILES) -o bin/release

debug: bin/debug
bin/debug: GPP_ARGS += -g -Wall -Werror -pedantic -DMAP
bin/debug: $(OBJ_FILES)
	$(eval OBJ_FILES := $(subst build/main_test.o,,${OBJ_FILES}))
	g++ $(GPP_ARGS) $(OBJ_FILES) -o bin/debug

test: bin/test
bin/test: GPP_ARGS += -g -Wall -Werror -pedantic -DMAP
bin/test: $(OBJ_FILES)
	$(eval OBJ_FILES := $(subst build/main.o,,${OBJ_FILES}))
	g++ $(GPP_ARGS) $(OBJ_FILES) -o bin/test

build/%.o: %.cpp
	g++ -c $(GPP_ARGS) $< -o $@

.PHONY: clean
clean:
	@rm -f build/*.o bin/*
