#version 410 core

// Output the colour at this vertex.
out vec4 vs_colour;


void main(void) {
  const vec4 vertices[3] = vec4[3](
    vec4(0.5, -0.5, 0.5, 1.0),
    vec4(-0.5, -0.5, 0.5, 1.0),
    vec4(0, 0.5, 0.5, 1.0)
  );

  const vec4 colours[] = vec4[3](
    vec4(1.0, 0.0, 0.0, 1.0),
    vec4(0, 1, 0, 1),
    vec4(0, 0, 1, 1)
  );

  // Lookup this vertex's position.
  gl_Position = vertices[gl_VertexID];

  // Output a colour value depending on our vertex.
  vs_colour = colours[gl_VertexID];
}
