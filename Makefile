CPPFILES = $(wildcard *.cpp)
OBJFILES = $(CPPFILES:.cpp=.o)
HEADERS = $(wildcard *.h)
OUT = run

CC = g++

LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

$(OUT): $(OBJFILES)
	$(CC) $^ -o $@ $(LDLIBS)
	./$(OUT)
	
%.o: %.cpp 
	$(CC) -c $^

headers: $(HEADERS)
	$(CC) -c $^

.PHONY: clean
clean:
	rm -f $(OBJFILES) $(OUT)
