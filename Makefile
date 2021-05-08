CC = gcc
flags = -g -Wall -lm -ldl -fPIC -rdynamic

exec_sorting = sorting.out
sources_sorting = $(wildcard sorting/src/*.c)
objects_sorting = $(sources_sorting:.c=.o)

exec_searching = searching.out
sources_searching = $(wildcard searching/src/*.c)
objects_searching = $(sources_searching:.c=.o)


all: $(objects_sorting)
	$(MAKE) sorting
	$(MAKE) searching

run: $(objects_sorting)
	$(MAKE) all
	./sorting.out
	./searching.out

sorting: $(objects_sorting)
	$(CC) $(objects_sorting) $(flags) -o $(exec_sorting)

searching: $(objects_searching)
	$(CC) $(objects_searching) $(flags) -o $(exec_searching)

%.o: %.c include/%.h
	$(CC) -c $(flags) $< -o $@

info:
	$(info $$sources_sorting is [${sources_sorting}])
	$(info $$sources_searching is [${sources_searching}])

clean:
	-rm *.out
	-rm *.o 
	-rm *.a 
	-rm sorting/src/*.o
	-rm searching/src/*.o

lint:
	clang-tidy sorting/src/*.c searching/src/*.c sorting/src/include/*.h searching/src/include/*.h