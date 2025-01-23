CFLAGS = -I include -I /usr/local/include
LDFLAGS = -L /usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system 

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = tetris

$(TARGET): $(OBJ)
	g++ $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)