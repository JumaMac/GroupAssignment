# ⭐️ code by JAISMIN

CC = gcc
CFLAGS = -I.
LDFLAGS = -L/opt/homebrew/lib -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
TARGET = theRecipeBox
SRCS = theRecipeBox.c addEditDeleteRecipe.c functions.c allRecipes.c

# Rule to compile the program
$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

# Rule to run the program after compiling
run: $(TARGET)
	./$(TARGET)

# Clean the build
clean:
	rm -f $(TARGET)
