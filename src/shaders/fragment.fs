#version 410 core

// Output to the framebuffer
out vec4 color;


void main(void) {
  color = vec4(
    sin(gl_FragCoord.x * 0.15) * 0.5 + 0.5,
    cos(gl_FragCoord.y * 0.15) * 0.5 + 0.5,
    (sin(gl_FragCoord.x * 0.15) * cos(gl_FragCoord.x*0.15)) * 0.5 + 0.5,
    1.0
  );
}
