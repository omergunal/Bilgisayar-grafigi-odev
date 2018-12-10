#include <GL/glut.h>
#include <iostream>
// g++ main.cpp -o a.out -lGL -lGLU -lglut
#include <typeinfo>
#include <iomanip>
#include <time.h>

using namespace std;
float X = -1;
float Y = 0.001;
float hedefKonum = 0.7;
float hedefYon = 0.0;
float yukariGeldi = 0.78716669559478759765625;
float yukariGeldi2 = 0.8;
float asagiGeldi = -1.00014126300811767578125;
float asagiGeldi2 = -1.1;

float sabitHiz = 0.0002;
float konum = 0.0;

float mermiX = +1.9;
float mermiY = 0;



int i =0;



void mermi(void)
{
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);

    glVertex2f(0.0+hedefKonum,0.1 );
    glVertex2f(0.0+hedefKonum,0.0);
    glVertex2f(0.05+hedefKonum,0.0);

    glVertex2f(0.0+hedefKonum,0.1);
    glVertex2f(0.05+hedefKonum,0.1);
    glVertex2f(0.05+hedefKonum,0.0);
  glEnd();
  glFlush();


}


void hedef(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    konum += sabitHiz;
    if((konum >= yukariGeldi) && (konum <= yukariGeldi2) || (konum >= asagiGeldi2) && (konum <= asagiGeldi))
    {
      sabitHiz *= -1;
    }

    //cout<<setprecision(100)<<(konum)<<"\n";
    mermiX += 0.0009;

//mermi
  glColor3f(1.0,1.0,0.0);

    glBegin(GL_TRIANGLES);
      glVertex2f(0.0+mermiX,0.05 +mermiY);
      glVertex2f(0.0+mermiX,0.0+mermiY);
      glVertex2f(0.05+mermiX,0.0+mermiY);

      glVertex2f(0.0+mermiX,0.05+mermiY);
      glVertex2f(0.05+mermiX,0.05+mermiY);
      glVertex2f(0.05+mermiX,0.0+mermiY);
    glEnd();

    glColor3f(0.0,1.0,1.0);

//hedef
    glBegin(GL_TRIANGLES);

      glVertex2f(0.0+hedefKonum,0.19 +konum);
      glVertex2f(0.0+hedefKonum,0.0+konum);
      glVertex2f(0.05+hedefKonum,0.0+konum);

      glVertex2f(0.0+hedefKonum,0.19+konum);
      glVertex2f(0.05+hedefKonum,0.19+konum);
      glVertex2f(0.05+hedefKonum,0.0+konum);
    glEnd();

//silah
    glColor3f(0.0,1.0,0.0);

    glBegin(GL_TRIANGLES);
      glVertex2f(0.0+X,0.1+Y);
      glVertex2f(0.1+X,0.0+Y);
      glVertex2f(0.0+X,-0.1+Y);
    glEnd();


    srand(time(0));
    float r = ((float)rand() / RAND_MAX) -0.5 ;

    if ( (0.0+mermiY) <= (0.19 +konum) && (0.0+mermiY) >= (0.0+konum) && (0.025+mermiX) >= 0.0+hedefKonum && (0.025+mermiX) <= (0.05+hedefKonum) )
    {
      i += 1;
      cout<<"Skor: "<<i<<"\n";
      konum = r;
    //  mermiY = 1.1;
    //  mermiX = 1.1;
    }

    glFlush();


}

void keyboard(unsigned char key, int x ,int y)
{
    switch (key) {
      case 'w':
        Y += 0.07;
        break;
      case 's':
        Y -= 0.07;
        break;
      case 'f':
        mermiX = -0.9;
        mermiY = Y;
        break;


    }

}


/*void ucgenfff(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(-0.1, -0.1, 0.0);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(-0.1, 0.1, 0.0);
        //glVertex3f(0.0, 0.0, 0.5);

    glEnd();
    glFlush();
}*/





int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    //glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
  //  glMatrixMode(GL_PROJECTION);
    //glLoadIdentitiy();
    //gluOrtho2d(0,400,0,600);
    //glutInitWindowPosition(100, 100);

    glutCreateWindow("OZEL NOKTADAN VURURSAN 55 PUAN GELIR!!!");

    glutKeyboardFunc(keyboard);

  //  glutDisplayFunc(silah);
    //glutIdleFunc(silah);
    glutDisplayFunc(hedef);
    glutIdleFunc(hedef);
    glutMainLoop();
    return 1;
}
