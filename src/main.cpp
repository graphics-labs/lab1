#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void resize(int width, int height) {}

void display(void) {
  glRotatef(30, 0, 40, 100);

  glColor3d(1, 1, 0);
  glViewport(0, 0, 400, 400);
  glutSolidTeapot(2);

  glColor3d(0, 1, 1);
  glViewport(400, 0, 400, 400);
  glutSolidTorus(1, 2, 40, 16);

  glColor3d(1, 0, 1);
  glViewport(400, 400, 400, 400);
  glutSolidCube(3);

  glColor3d(1, 1, 1);
  glViewport(0, 400, 400, 400);
  glutSolidSphere(2, 40, 16);
  glFlush();
}
void init(void) {
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-5.0, 5.0, -5.0, 5.0, 2.0, 12.0);
  gluLookAt(0, 0, 5, 0, 1, 0, 0, 1, 0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(50, 10);
  glutInitWindowSize(800, 800);
  glutCreateWindow("Hello");
  glutReshapeFunc(resize);
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
