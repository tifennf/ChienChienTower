
CC= gcc
CFLAGS = -g -Wall -Wextra -pedantic -Wno-unused-parameter
UNITY_ROOT = unity
TEST_ROOT = tests
SRC_ROOT = src

# c files
SRC_FILES = $(wildcard $(SRC_ROOT)/*.c)
UNITY_FILES = $(UNITY_ROOT)/unity.c
TEST_FILES = $(wildcard $(TEST_ROOT)/*.c)
ALL_FILES = $(SRC_FILES) $(UNITY_FILES) $(TEST_FILES)

# obj files
SRC_OBJS = $(SRC_FILES:.c=.o)
UNITY_OBJS = $(UNITY_FILES:.c=.o)
TEST_OBJS = $(TEST_FILES:.c=.o)
ALL_OBJS = $(SRC_OBJS) $(UNITY_OBJS) $(TEST_OBJS)


# target
TEST_TARGET = build/test_runner

.PHONY: all clean

all: test

test: $(TEST_TARGET)
	./$(TEST_TARGET)

# build TEST_TARGET from all obj file
$(TEST_TARGET): $(ALL_OBJS)
	$(CC) $(CFLAGS) -o $@ $(ALL_OBJS)

# pattern to build every obj file from every .c file in the same path
# -o here is for output file name
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(ALL_OBJS) $(TEST_TARGET)
