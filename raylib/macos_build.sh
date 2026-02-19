eval cc $1 -framework IOKit -framework Cocoa -framework OpenGL $(pkg-config --libs --cflags raylib) -o $2
./$2
