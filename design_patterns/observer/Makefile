OBJS = main.o observer.o subject.o

build: $(OBJS)
	g++ $^ && ./a.out

%.o: %.cc
	g++ -c $^ -o $@

.PHONY: clean

clean:
	rm -rf *.o *.out
