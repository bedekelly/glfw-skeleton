all:
	clang++ src/skeleton_utils.cpp src/main.cpp -o build/main.out -framework OpenGl -I/usr/local/include -lglfw3 -framework Cocoa -framework IOKit -framework CoreVideo -Iinclude
