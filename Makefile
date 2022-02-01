### If you wish to use extra libraries (math.h for instance),
### add their flags here (-lm in our case) in the "LIBS" variable.

LIBS = -lm

###
CFLAGS  = -std=c99
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -pedantic
CFLAGS += -Werror
CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64
CFLAGS += -DDEBUG_PRINT_CODE
CFLAGS += -DDEBUG_TRACE_EXECUTION

ASANFLAGS  = -fsanitize=address
ASANFLAGS += -fno-common
ASANFLAGS += -fno-omit-frame-pointer

SRC_FILES = $(filter-out src/main.c, $(wildcard src/*.c))

.PHONY: build
build: src/*.c src/*.h
	@$(CC) $(CFLAGS) src/*.c -o clox.out $(LIBS)

.PHONY: clean
clean:
	rm -rf *.o *.out *.out.dSYM

.PHONY: memcheck
memcheck: test/*.c src/*.c src/*.h
	@echo Compiling $@
	@$(CC) $(ASANFLAGS) $(CFLAGS) $(SRC_FILES) test/vendor/unity.c test/*.c -o memcheck.out $(LIBS)
	@./memcheck.out
	@echo "Memory check passed"

.PHONY: test
test: tests.out
	@./tests.out

tests.out: test/*.c src/*.c src/*.h
	@echo Compiling $@
	@$(CC) $(CFLAGS) $(SRC_FILES) test/vendor/unity.c test/*.c -o tests.out $(LIBS)
