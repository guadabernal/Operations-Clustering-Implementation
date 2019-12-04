#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

const size_t WindowsWidth = 1024;
const size_t WindowsHeight = 512;
bool beginGraphing = false;
bool graphPoints = false;
bool graphSolutions = false;

// repeats 30x per second
void display() {
  glClearColor(1, 1, 1, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();

  int W = WindowsWidth;
  int H = WindowsHeight;
  int WG = W * 0.90;
  int HG = H * 0.90;
  int XOff = 50;
  int YOff = 50;

  // grid
  if (beginGraphing == true ) {
    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(XOff - 5, YOff);
    glVertex2f(XOff + WG, YOff);
    glVertex2f(XOff, YOff - 5);
    glVertex2f(XOff, YOff + HG);
    glEnd();
  }
  glutSwapBuffers();
  glPopMatrix();
}

void init_display() {
  glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
  glLineWidth(0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport(0, 0, WindowsWidth, WindowsHeight);
  glOrtho(0, WindowsWidth, 0, WindowsHeight, -10, 10);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void reshape(int w, int h) {
  init_display();
  display();
}
void normal_keys(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
    printf("exiting program---------\n");
    exit(0);
    break;
  case 32:
    printf("setting begingraphing to true ------\n");
    beginGraphing == true;
    break;
  default:
    break;
  }
}
void init_glut_window(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(WindowsWidth, WindowsHeight);
  glutCreateWindow("Delta Sim");
  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutKeyboardFunc(normal_keys);
  glutReshapeFunc(reshape);
  glutMainLoop();
}

int main(int argc, char *argv[])
{
  init_glut_window(argc, argv);
}
