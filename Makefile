CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = numerical_toolkit
TEST_TARGET = test_methods

SRC = src/main.c \
      src/bisection.c \
      src/newton.c \
      src/secant.c \
      src/regula_falsi.c

TEST_SRC = tests/test_methods.c \
           src/bisection.c \
           src/newton.c \
           src/secant.c \
           src/regula_falsi.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

test:
	$(CC) $(CFLAGS) $(TEST_SRC) -lm -o $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)
