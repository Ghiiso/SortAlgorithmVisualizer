# compiler
CC := clang

# flags
CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -lm
# header files
HDRS := Vector2.c scene.c sort.c

# source files
SRCS := main.c

# object files
OBJS := $(SRCS:.c=.o)

# name of executable
EXEC := main

# default recipe
all: Vector2 scene sort $(EXEC)
 
showfont: showfont.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

glfont: glfont.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

# recipe for building the final executable
$(EXEC): $(OBJS) $(HDRS) Makefile
	$(CC) -o $@ $(OBJS) $(CFLAGS) $(HDRS)

sort:
	$(CC) -c sort.c

scene:
	$(CC) -c scene.c

Vector2:
	$(CC) -c Vector2.c

# recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
