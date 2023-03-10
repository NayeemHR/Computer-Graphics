#include<windows.h>
//#include<stdio.h>
#include<GL/glut.h>
//#include<math.h>
//#include<conio.h>
//#include<stdlib.h>

//center of the circle = (320,240)
int xc=320,yc=240;

//Plot eight points using circle's symmetrical property
void plot_point(int x, int y){
    glBegin(GL_POINTS);
        glVertex2i(xc+x, yc+y);
        glVertex2i(xc+x, yc-y);
        glVertex2i(xc+y, yc+x);
        glVertex2i(xc+y, yc-x);
        glVertex2i(xc-x, yc-y);
        glVertex2i(xc-y, yc-x);
        glVertex2i(xc-x, yc+y);
        glVertex2i(xc-y, yc+x);
    glEnd();
}

void bresenaham_circle(int r){
    int x=0,y=r;
    float pk=3-2*r;
    plot_point(x,y);
    int k;

    while(x<y){
        x=x+1;
        if(pk<0){
            pk = pk + 2*x+1;
        }else{
            y=y-1;
            pk = pk + 2*(x-y)+1;
        }
        plot_point(x,y);
    }
    glFlush();
}

void dispaly(void){
    glClear(GL_COLOR_BUFFER_BIT);
    int radius1 = 100, radius2 = 200;
    bresenaham_circle(radius1);
}
void init(){
    glClearColor(1.0,1.0,1.0,0);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(0,640,0,480);
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("Bresenham_circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
