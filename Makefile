TARGET = ./key.out
INCLUDE = resources
SRCS = program/main.c \
		program/dfc.c \
		program/adj_matr.c\
		program/other_matr.c\
		program/additional.c

.PHONY: all build test clean

all: clean build

$(TARGET): $(SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(INCLUDE) -o $(TARGET) $(SRCS)

build: $(TARGET)

test: $(TARGET)
	$(TARGET)

clean:
	rm -rf $(TARGET)