#include <GL/glut.h>

int px, py;

void drawPlayer()
{
    glColor3f(0.45, 0.8, 0);
    glPointSize(8);
    glBegin(GL_TRIANGLES);
    glVertex2i(px, py);
    glVertex2i(px + 10, py + 10);
    glVertex2i(px + 5, py + 15);
    glEnd();
}

void buttons(unsigned char key, int x, int y)
{
 if (key == 'a') { px -= 5; }
 if (key == 'd') { px += 5; }
 if (key == 'w') { py -= 5; }
 if (key == 's') { py += 5; }
 glutPostRedisplay();
}

void init()
{
    glClearColor(0.3, 0.3, 0.3, 0);
    gluOrtho2D(0, 1024, 512, 0);
    px = 0;
    py = 0;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawPlayer();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1024, 512);
    glutCreateWindow("Raycaster");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(buttons);
    glutMainLoop();
}
