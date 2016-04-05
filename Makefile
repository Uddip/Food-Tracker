CXX = gcc

STD = -std=c99 #-Wall

INC = -I"include"

CXXFLAGS = $(INC) $(STD) $(DEBUG)

EXEC = tracker

OBJ = src/main.o	\
		src/parser.o\
		src/linkedList.o\
		src/tracker.o\

$(EXEC): $(OBJ)
		$(CXX) $(CXXFLAGS) $^ -o $@ -g

%.o : %.c
		$(CXX) $(CXXFLAGS) -c $< -o $@ -o $@ -g

clean:
		rm -rf src/*.o ${EXEC}