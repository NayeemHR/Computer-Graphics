#include<GL/gl.h>
#include<GL/glut.h>
#include<windows.h>
#include<math.h>
#define PI 3.14159265358979323846

void midtellipse(int rx, int ry, int xc , int yc){
    float dx, dy, d1, d2, x, y;
    x =0;
    y =ry;
    //initial decision parameter
    d1 =(ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);

    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    //for region 1
    while(dx<dy){
        //print points based on 4-way symmetry
        glVertex2i(x+xc, y+yc);
        glVertex2i(-x+xc, y+yc);
        glVertex2i(x+xc, -y+yc);
        glVertex2i(-x+xc, -y+yc);

        //checking and updating value of
        //decision parameter based on algorithm

        if(d1 < 0){
            x++;
            dx = dx +(2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }else{
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry*ry);
        }

    }

    //decision parameter of region 2
    d2 = ((ry*ry)*((x+0.5)*(x+0.5)))+((rx*rx)*((y-1) * (y-1))) - (rx*rx*ry*ry);

    //plotting points of region 2
    while(y>= 0){
    //print points based on 4-way symmetry
        glVertex2i(x+xc, y+yc);
        glVertex2i(-x+xc, y+yc);
        glVertex2i(x+xc, -y+yc);
        glVertex2i(-x+xc, -y+yc);

        //checking and updating parameter
        //value based on algorithm

        if(d2>0){
        y--;
        dy = dy - (2*rx*rx);
        d2 = d2 + (rx*rx)-dy;
        }else{
        y--;
        x++;
        dx = dx + (2 * ry * ry);
        dy = dy - (2 * rx * rx);
        d2 = d2 + dx - dy + (rx * rx);

        }
    }
    glEnd();
glFlush();
}

void display(void){
  midtellipse(250,150,0,0);
}


int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,640);
    //glutInitWindowPosition(100,100);
    glutCreateWindow("Shape");
    gluOrtho2D(-600,600,-600,600);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
