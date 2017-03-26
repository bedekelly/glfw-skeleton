# Mac GL

I'm working through the OpenGL SuperBible v.7, using GLFW version 3 on MacOS and making any changes where necessary.

I couldn't get the example code working -- probably something to do with different OpenGL versions. So I'm writing my own utility code using GLFW's timers etc.

Every discrete example of an application in the book gets its own branch in this repository. Here's what I have so far:

1. [Opening a window and setting the clear colour](https://github.com/bedekelly/mac-gl/tree/base)
2. [Making a colour fade with a GLFW timer](https://github.com/bedekelly/mac-gl/tree/fading-colour)
3. [Drawing a point using shaders](https://github.com/bedekelly/mac-gl/tree/shaders)
4. [Drawing a triangle to the screen](https://github.com/bedekelly/mac-gl/tree/triangle)
5. [Moving the triangle using "in" variables](https://github.com/bedekelly/mac-gl/tree/triangle-offset)
6. [Passing data from the Vertex Shader to the Fragment Shader](https://github.com/bedekelly/mac-gl/tree/passing-data)
7. [Loading fragment and vertex shaders from disk](https://github.com/bedekelly/mac-gl/tree/load-shaders-from-file)

Just hit `make` to build the project. The binary is `build/main.out`.

**System specs**

* 15" rMBP, mid 2015
* Intel Iris Pro 1536 MB
* Sierra 10.12.3
