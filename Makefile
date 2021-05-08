CC = gcc
flags = -g -Wall -lm -ldl -fPIC -rdynamic

exec_sorting = sorting.out
sources_sorting = $(wildcard sorting/src/*.c)
objects_sorting = $(sources_sorting:.c=.o)

exec_searching = searching.out
sources_searching = $(wildcard searching/src/*.c)
objects_searching = $(sources_searching:.c=.o)

exec_clustering = clustering.out
sources_clustering = $(wildcard clustering/src/*.c)
objects_clustering = $(sources_clustering:.c=.o)

all: $(objects_sorting)
	$(MAKE) sorting
	$(MAKE) searching
	$(MAKE) clustering

run: $(objects_sorting)
	$(MAKE) all
	./sorting.out
	./searching.out
	./clustering.out

sorting: $(objects_sorting)
	$(CC) $(objects_sorting) $(flags) -o $(exec_sorting)

searching: $(objects_searching)
	$(CC) $(objects_searching) $(flags) -o $(exec_searching)

clustering: $(objects_clustering)
	$(CC) $(objects_clustering) $(flags) -o $(exec_clustering)

%.o: %.c include/%.h
	$(CC) -c $(flags) $< -o $@

info:
	$(info $$sources_sorting is [${sources_sorting}])
	$(info $$sources_searching is [${sources_searching}])
	$(info $$sources_clustering is [${sources_clustering}])

clean:
	-rm *.out
	-rm *.o 
	-rm *.a 
	-rm sorting/src/*.o
	-rm searching/src/*.o
	-rm clustering/src/*.o

lint:
	clang-tidy sorting/src/*.c searching/src/*.c clustering/src/*.c sorting/src/include/*.h searching/src/include/*.h clustering/src/include/*.h
