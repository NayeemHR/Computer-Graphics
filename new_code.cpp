#include<stdio.h>
#include<GL/gl.h>
#include<GL/glut.h>

void display(void){

}

void init(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(10.0,10.0,10.0,10.0,-1.0,1.0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500.500);
    glutInitWindowPosition(100,100);
    glutCreateWindow('Hello World');
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
