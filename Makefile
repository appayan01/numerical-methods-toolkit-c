CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = numerical_toolkit

SRC = src/main.c \
      src/bisection.c \
      src/newton.c \
      src/secant.c \
      src/regula_falsi.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
