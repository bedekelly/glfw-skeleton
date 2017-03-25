#ifndef MAIN_H
#define MAIN_H


typedef struct {
  GLuint vao;
  GLuint program;
} gldata;


GLuint compileShaders();
void render(double, gldata);
gldata glSetup();
void glTearDown(gldata);

#endif
