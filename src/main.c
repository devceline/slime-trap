#include <stdio.h>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/freeglut.h>

// Init functions
void initalize(int*, char*[]);
void initializeWindow(int*, char*[]);
void initializeGlew();
void onResizeWindow(int, int);

// Render function
void render(void);

// Geometry function
void drawRectangle();

const char* windowTitle = "Some title";
short int windowWidth = 500;
short int windowHeight = 500;
short int windowX = 0;
short int windowY = 0;

int main(int argc, char **argv) {
  initalize(&argc, argv);

  glutMainLoop();
  
  return 0;
}


void drawRectangle() {
  float vertices[] = {
     0.0f,  0.5f,
     0.5f, -0.5f,
    -0.5f, -0.5f,
  };    

  GLuint vbo;
  glGenBuffers(1, &vbo);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);

  glBufferData(GL_ARRAY_BUFFER, sizeof(0.0f) * 6, vertices, GL_STATIC_DRAW); 
}




void initalize(int* argc, char** argv) {
  initializeWindow(argc, argv);
  initializeGlew();
}

void initializeGlew() {
  if(glewInit() != GLEW_OK) {
    printf("Failed to initialize OpenGL.\n");
  }
}

void initializeWindow(int* argc, char** argv) {
  glutInit(argc, argv);

  glutInitWindowSize(windowWidth, windowHeight);
  glutInitWindowPosition(windowX, windowY);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitContextVersion(4, 0);
  glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
  glutInitContextProfile(GLUT_CORE_PROFILE);

  glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

  const int windowId = glutCreateWindow(windowTitle);

  if(windowId < 1) {
    printf("Failed to create window using glut.\n");
  }

  glutReshapeFunc(onResizeWindow);
  glutDisplayFunc(render);
}

void onResizeWindow(int width, int height) {
  windowWidth = width;
  windowHeight = height;
  glViewport(0, 0, windowWidth, windowHeight);
}

void render(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER);

  glutSwapBuffers();
  glutPostRedisplay();
}
