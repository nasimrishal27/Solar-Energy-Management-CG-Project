#include<GL/glut.h>
#include <GL/glu.h>
#include<math.h>
#include <stdlib.h>
#include<stdio.h>

void display1();
void display2();
void stars();
void shouse();
void animateArrow();
GLint a=0,b=0,arrow_x=0,d=1,ss=0,ls=260,lh=260;
float sy=0,sx=0;
GLfloat arrow_y = 250;
GLfloat ar_x=120;
GLfloat a_x=00;
void update(int value)
{
	a+=20.0;
	glutPostRedisplay();
	glutTimerFunc(200,update,0);
}
void drawCircle(float cx, float cy, float radius, int num_segments) {
    // glColor3f(0.94, 0.77, 0.62);
	// glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Center of the circle
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * i / num_segments; // Angle in radians
        float x = radius * cosf(theta); // Calculate the x-coordinate
        float y = radius * sinf(theta); // Calculate the y-coordinate
        glVertex2f(cx + x, cy + y); // Define the vertex
    }
    glEnd();
}
void renderText(float x, float y, const char* text) {
    glRasterPos2f(x, y);

    for (int i = 0; text[i] != '\0'; ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}
void road()
{
	glColor3f(0.1,0.1,0.1); //road
glBegin(GL_POLYGON);
glVertex2f(500,0);
glVertex2f(600,0);
glVertex2f(350,380);
glVertex2f(300,380);
glEnd();

	glColor3f(1,1,1); // h-line
	glLineWidth(6);
	
	glBegin(GL_LINES);
	glVertex2f(550,10);
	glVertex2f(490,110);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(450,180);
	glVertex2f(385,280);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(325,380);
	glVertex2f(360,320);
	glEnd();

	glColor3f(0.329412,0.329412,0.329412);
	glLineWidth(6);
	
	glBegin(GL_LINES);
	glVertex2f(445,100);
	glVertex2f(445,250);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(455,250);
	glVertex2f(443,250);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(360,250);
	glVertex2f(360,390);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(370,390);
	glVertex2f(358,390);
	glEnd();

	glLineWidth(2);
	
	glBegin(GL_LINES);
	glVertex2f(360,390);
	glVertex2f(445,250);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(630,240);
	glVertex2f(445,240);
	glEnd();

	if(ss>=50)
	{
		glColor3f(1,1,0);
		glBegin(GL_POLYGON);
		glVertex2f(450,190);
		glVertex2f(455,250);
		glVertex2f(490,210);
		glEnd();

		glColor3f(1,1,0);
		glBegin(GL_POLYGON);
		glVertex2f(365,330);
		glVertex2f(370,390);
		glVertex2f(405,350);
		glEnd();
	}
}
void house(){

	// grass
        glColor3f(0.6, 0.8, 0.196078);
        glBegin(GL_POLYGON);
        glVertex2f(0, 160);
        glVertex2f(0, 380);
        glVertex2f(1900, 380);
        glVertex2f(1900, 160);
        glEnd();
	
	// Ground
    glColor3f(0.0, 0.3, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(0, 215);
    glVertex2f(1900, 215);
    glVertex2f(1900, 0);
    glEnd();


	glPushMatrix();
	glTranslated(210,210,0);
	shouse();
	glPopMatrix();

	glPushMatrix();
	glTranslated(170,270,0);
	shouse();
	glPopMatrix();

	// glPushMatrix();
	// glTranslated(500,450,0);
	// shouse();
	// glPopMatrix();

	


    glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
	glVertex2i(100, 100);
	glVertex2i(100, 600);
	glVertex2i(300, 600);
	glVertex2i(300, 100);
    glEnd();

   

    //House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(90, 600);
	glVertex2i(90, 610);
	glVertex2i(120, 650);
	glVertex2i(280, 650);
	glVertex2i(310, 610);
	glVertex2i(310, 600);

	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(90, 345);
	glVertex2i(90, 355);
	glVertex2i(310, 345);
	glVertex2i(310, 355);

	glEnd();


    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(170, 100);
	glVertex2i(170, 230);
	glVertex2i(230, 230);
	glVertex2i(230, 100);

	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(120, 230);
	glVertex2i(120, 260);
	glVertex2i(150, 260);
	glVertex2i(150, 230);

	glEnd();

	///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(120, 180);
	glVertex2i(120, 210);
	glVertex2i(150, 210);
	glVertex2i(150, 180);

	glEnd();

	///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(240, 230);
	glVertex2i(240, 260);
	glVertex2i(270, 260);
	glVertex2i(270, 230);

	glEnd();

	///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(240, 180);
	glVertex2i(240, 210);
	glVertex2i(270, 210);
	glVertex2i(270, 180);

	glEnd();

	if(ss>=50)
	{
		glColor3f(1, 1, 0);
		///House_Window1
	glBegin(GL_POLYGON);
	glVertex2i(120, 230);
	glVertex2i(120, 260);
	glVertex2i(150, 260);
	glVertex2i(150, 230);

	glEnd();

	///House_Window2
	glBegin(GL_POLYGON);
	glVertex2i(120, 180);
	glVertex2i(120, 210);
	glVertex2i(150, 210);
	glVertex2i(150, 180);

	glEnd();

	///House_Window1
	glBegin(GL_POLYGON);
	glVertex2i(240, 230);
	glVertex2i(240, 260);
	glVertex2i(270, 260);
	glVertex2i(270, 230);

	glEnd();

	///House_Window2
	glBegin(GL_POLYGON);
	glVertex2i(240, 180);
	glVertex2i(240, 210);
	glVertex2i(270, 210);
	glVertex2i(270, 180);

	glEnd();
	}

	glPushMatrix();
	glTranslated(0,250,0);
	///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(170, 100);
	glVertex2i(170, 230);
	glVertex2i(230, 230);
	glVertex2i(230, 100);

	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(120, 230);
	glVertex2i(120, 260);
	glVertex2i(150, 260);
	glVertex2i(150, 230);

	glEnd();

	///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(120, 180);
	glVertex2i(120, 210);
	glVertex2i(150, 210);
	glVertex2i(150, 180);

	glEnd();

	///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(240, 230);
	glVertex2i(240, 260);
	glVertex2i(270, 260);
	glVertex2i(270, 230);

	glEnd();

	///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(240, 180);
	glVertex2i(240, 210);
	glVertex2i(270, 210);
	glVertex2i(270, 180);


	glEnd();
	if(ss>=50)
	{
		glColor3f(1, 1, 0);
		///House_Window1
	glBegin(GL_POLYGON);
	glVertex2i(120, 230);
	glVertex2i(120, 260);
	glVertex2i(150, 260);
	glVertex2i(150, 230);

	glEnd();

	///House_Window2
	glBegin(GL_POLYGON);
	glVertex2i(120, 180);
	glVertex2i(120, 210);
	glVertex2i(150, 210);
	glVertex2i(150, 180);

	glEnd();

	///House_Window1
	glBegin(GL_POLYGON);
	glVertex2i(240, 230);
	glVertex2i(240, 260);
	glVertex2i(270, 260);
	glVertex2i(270, 230);

	glEnd();

	///House_Window2
	glBegin(GL_POLYGON);
	glVertex2i(240, 180);
	glVertex2i(240, 210);
	glVertex2i(270, 210);
	glVertex2i(270, 180);

	glEnd();
	}
	glPopMatrix();

    
}
void shouse()
{
	///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(.990, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 130);
	glVertex2i(380, 115);
	glVertex2i(380, 105);
	glEnd();

    ///House_Roof_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.890, 0.0, 0.0);
	glVertex2i(285, 105);
	glVertex2i(285, 120);
	glVertex2i(380, 105);
	glVertex2i(380, 105);
	glEnd();

    ///House_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, 1.0, 1.0);
	glVertex2i(290, 70);
	glVertex2i(290, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);
	glEnd();

    ///House_Fence_Shadow
	glBegin(GL_POLYGON);
    glColor3f(.555, 0.924, 0.930);
	glVertex2i(310, 70);
	glVertex2i(350, 104);
	glVertex2i(375, 104);
	glVertex2i(375, 70);
	glEnd();

    ///House_Door
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.41, 0.36);
	glVertex2i(330, 70);
	glVertex2i(330, 100);
	glVertex2i(350, 100);
	glVertex2i(350, 70);
	glEnd();

    ///House_Window1
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(295, 75);
	glVertex2i(295, 90);glColor3f(0.61, 0.52, 0.41);
	glVertex2i(310, 90);
	glVertex2i(310, 75);
	glEnd();

    ///House_Window2
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(312, 75);
	glVertex2i(312, 90);
	glVertex2i(327, 90);
	glVertex2i(327, 75);

	glEnd();

    ///House_Window3
	glBegin(GL_POLYGON);
    glColor3f(0.38, 0.21, 0.26);
	glVertex2i(355, 75);
	glVertex2i(355, 90);
	glVertex2i(370, 90);
	glVertex2i(370, 75);

	glEnd();

    ///House_Small_Roof
	glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
	glVertex2i(250, 90);
	glVertex2i(257, 104);
	glVertex2i(290, 104);
	glVertex2i(290, 90);

	glEnd();

    ///House_Small_Fence
	glBegin(GL_POLYGON);
    glColor3f(.555, .724, .930);
	glVertex2i(255, 70);
	glVertex2i(255, 90);
	glVertex2i(290, 90);
	glVertex2i(290, 70);

	glEnd();

    ///House_Small_Door
	glBegin(GL_POLYGON);
    glColor3f(0.11, 0.23, 0.36);
	glVertex2i(260, 70);
	glVertex2i(260, 80);
	glVertex2i(285, 80);
	glVertex2i(285, 70);

	glEnd();
}
void solar()
{
	glColor3f(0,0,0);
	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex2f(10,10);
	glVertex2f(10,200);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(110,10);
	glVertex2f(110,250);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(210,10);
	glVertex2f(210,280);
	glEnd();

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex2f(0,195);
	glVertex2f(80,250);
	glVertex2f(210,280);
	glVertex2f(130,195);

	glEnd();

	glColor3f(1,1,0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(30,195);
	glVertex2f(100,250);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(55,195);
	glVertex2f(125,260);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(75,195);
	glVertex2f(148,260);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(100,195);
	glVertex2f(173,265);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(20,210);
	glVertex2f(155,220);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(50,230);
	glVertex2f(176,250);
	glEnd();

}
void battery()
{
	///House_Roof
	glBegin(GL_POLYGON);
    glColor3f(.40, 0.4, 0.7);
	glVertex2i(620, 10);
	glVertex2i(750, 10);
	glVertex2i(750, 200);
	glVertex2i(620, 200);
	glEnd();

	glBegin(GL_POLYGON);
    glColor3f(.70, 0.3, 0.2);
	glVertex2i(625, 230);
	glVertex2i(745, 230);
	glVertex2i(760, 180);
	glVertex2i(610, 180);
	glEnd();

	glColor3f(1, 1,1);
	renderText(628,200,"Battery House");

	glColor3f(0,0,0);
	glLineWidth(4);
	
	glBegin(GL_LINES);
	glVertex2f(630,347);
	glVertex2f(630,230);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(650, 15);
	glVertex2i(720, 15);
	glVertex2i(720, 175);
	glVertex2i(650, 175);
	glEnd();
	if (sy>=120 && ss<=230)
	{
		glColor3f(1,1,0);
		glBegin(GL_POLYGON);
	glVertex2i(655, 20);
	glVertex2i(715, 20);
	glVertex2i(715, 30);
	glVertex2i(655, 30);
	glEnd();
	}
	if (sy>=140 && ss<=210)
	{
		glColor3f(1,1,0);
		glBegin(GL_POLYGON);
	glVertex2i(655, 20);
	glVertex2i(715, 20);
	glVertex2i(715, 30);
	glVertex2i(655, 30);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 35);
	glVertex2i(715, 35);
	glVertex2i(715, 45);
	glVertex2i(655, 45);
	glEnd();
	}
	if (sy>=160 && ss<=190)
	{
		glColor3f(1,1,0);
		glBegin(GL_POLYGON);
	glVertex2i(655, 20);
	glVertex2i(715, 20);
	glVertex2i(715, 30);
	glVertex2i(655, 30);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 35);
	glVertex2i(715, 35);
	glVertex2i(715, 45);
	glVertex2i(655, 45);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 50);
	glVertex2i(715, 50);
	glVertex2i(715, 60);
	glVertex2i(655, 60);
	glEnd();
	}

	if (sy>=180 && ss<=170)
	{
		glColor3f(1,1,0);
		glBegin(GL_POLYGON);
	glVertex2i(655, 20);
	glVertex2i(715, 20);
	glVertex2i(715, 30);
	glVertex2i(655, 30);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 35);
	glVertex2i(715, 35);
	glVertex2i(715, 45);
	glVertex2i(655, 45);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 50);
	glVertex2i(715, 50);
	glVertex2i(715, 60);
	glVertex2i(655, 60);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 65);
	glVertex2i(715, 65);
	glVertex2i(715, 75);
	glVertex2i(655, 75);
	glEnd();
	}

	if (sy>=200 && ss<=150)
	{
		glColor3f(1,1,0);
		glBegin(GL_POLYGON);
	glVertex2i(655, 20);
	glVertex2i(715, 20);
	glVertex2i(715, 30);
	glVertex2i(655, 30);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 35);
	glVertex2i(715, 35);
	glVertex2i(715, 45);
	glVertex2i(655, 45);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 50);
	glVertex2i(715, 50);
	glVertex2i(715, 60);
	glVertex2i(655, 60);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 65);
	glVertex2i(715, 65);
	glVertex2i(715, 75);
	glVertex2i(655, 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 80);
	glVertex2i(715, 80);
	glVertex2i(715, 90);
	glVertex2i(655, 90);
	glEnd();
	}

	if (sy>=220 && ss<=130)
	{
		glColor3f(1,1,0);
		glBegin(GL_POLYGON);
	glVertex2i(655, 20);
	glVertex2i(715, 20);
	glVertex2i(715, 30);
	glVertex2i(655, 30);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 35);
	glVertex2i(715, 35);
	glVertex2i(715, 45);
	glVertex2i(655, 45);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 50);
	glVertex2i(715, 50);
	glVertex2i(715, 60);
	glVertex2i(655, 60);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 65);
	glVertex2i(715, 65);
	glVertex2i(715, 75);
	glVertex2i(655, 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 80);
	glVertex2i(715, 80);
	glVertex2i(715, 90);
	glVertex2i(655, 90);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 95);
	glVertex2i(715, 95);
	glVertex2i(715, 105);
	glVertex2i(655, 105);
	glEnd();
	}
	if (sy>=240 && ss<=110)
	{
		glColor3f(1,1,0);
		glBegin(GL_POLYGON);
	glVertex2i(655, 20);
	glVertex2i(715, 20);
	glVertex2i(715, 30);
	glVertex2i(655, 30);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 35);
	glVertex2i(715, 35);
	glVertex2i(715, 45);
	glVertex2i(655, 45);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 50);
	glVertex2i(715, 50);
	glVertex2i(715, 60);
	glVertex2i(655, 60);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 65);
	glVertex2i(715, 65);
	glVertex2i(715, 75);
	glVertex2i(655, 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 80);
	glVertex2i(715, 80);
	glVertex2i(715, 90);
	glVertex2i(655, 90);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 95);
	glVertex2i(715, 95);
	glVertex2i(715, 105);
	glVertex2i(655, 105);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 110);
	glVertex2i(715, 110);
	glVertex2i(715, 120);
	glVertex2i(655, 120);
	glEnd();
	}
	if (sy>=260 && ss<=90)
	{
		glColor3f(1,1,0);
		glBegin(GL_POLYGON);
	glVertex2i(655, 20);
	glVertex2i(715, 20);
	glVertex2i(715, 30);
	glVertex2i(655, 30);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 35);
	glVertex2i(715, 35);
	glVertex2i(715, 45);
	glVertex2i(655, 45);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 50);
	glVertex2i(715, 50);
	glVertex2i(715, 60);
	glVertex2i(655, 60);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 65);
	glVertex2i(715, 65);
	glVertex2i(715, 75);
	glVertex2i(655, 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 80);
	glVertex2i(715, 80);
	glVertex2i(715, 90);
	glVertex2i(655, 90);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 95);
	glVertex2i(715, 95);
	glVertex2i(715, 105);
	glVertex2i(655, 105);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 110);
	glVertex2i(715, 110);
	glVertex2i(715, 120);
	glVertex2i(655, 120);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 125);
	glVertex2i(715, 125);
	glVertex2i(715, 135);
	glVertex2i(655, 135);
	glEnd();
	}

	if (sy>=280 && ss<=70)
	{
		glColor3f(1,1,0);
		glBegin(GL_POLYGON);
	glVertex2i(655, 20);
	glVertex2i(715, 20);
	glVertex2i(715, 30);
	glVertex2i(655, 30);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 35);
	glVertex2i(715, 35);
	glVertex2i(715, 45);
	glVertex2i(655, 45);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 50);
	glVertex2i(715, 50);
	glVertex2i(715, 60);
	glVertex2i(655, 60);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 65);
	glVertex2i(715, 65);
	glVertex2i(715, 75);
	glVertex2i(655, 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 80);
	glVertex2i(715, 80);
	glVertex2i(715, 90);
	glVertex2i(655, 90);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 95);
	glVertex2i(715, 95);
	glVertex2i(715, 105);
	glVertex2i(655, 105);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 110);
	glVertex2i(715, 110);
	glVertex2i(715, 120);
	glVertex2i(655, 120);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 125);
	glVertex2i(715, 125);
	glVertex2i(715, 135);
	glVertex2i(655, 135);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 140);
	glVertex2i(715, 140);
	glVertex2i(715, 150);
	glVertex2i(655, 150);
	glEnd();
	}
	if (sy>=300 && ss<=50)
	{
		glColor3f(1,1,0);
		glBegin(GL_POLYGON);
	glVertex2i(655, 20);
	glVertex2i(715, 20);
	glVertex2i(715, 30);
	glVertex2i(655, 30);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 35);
	glVertex2i(715, 35);
	glVertex2i(715, 45);
	glVertex2i(655, 45);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 50);
	glVertex2i(715, 50);
	glVertex2i(715, 60);
	glVertex2i(655, 60);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 65);
	glVertex2i(715, 65);
	glVertex2i(715, 75);
	glVertex2i(655, 75);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 80);
	glVertex2i(715, 80);
	glVertex2i(715, 90);
	glVertex2i(655, 90);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 95);
	glVertex2i(715, 95);
	glVertex2i(715, 105);
	glVertex2i(655, 105);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 110);
	glVertex2i(715, 110);
	glVertex2i(715, 120);
	glVertex2i(655, 120);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 125);
	glVertex2i(715, 125);
	glVertex2i(715, 135);
	glVertex2i(655, 135);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 140);
	glVertex2i(715, 140);
	glVertex2i(715, 150);
	glVertex2i(655, 150);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2i(655, 155);
	glVertex2i(715, 155);
	glVertex2i(715, 165);
	glVertex2i(655, 165);
	glEnd();
	}

	glColor3f(0.329412,0.329412,0.329412);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2f(630,345);
	glVertex2f(300,345);
	glEnd();
}
void display()
{
    sx-=0.5;
    sy+=2;
	b+=10;
    glClear(GL_COLOR_BUFFER_BIT);
	
	display1();

	if(b>2400)

	{
		d=0;
		// b+=20;
		display2();
	}
	glFlush();
	glutSwapBuffers();
}

void display1()
{
	glClearColor(1,1,1,1);

	glColor3f(1,0,0);
	renderText(800,600,"Solar Plant");
	glPushMatrix();
	glColor3f(1,1,0);
	glTranslated(100-sx,sy,0);
	drawCircle(400,350,40,100);
	glPopMatrix();

	house();
	road();
	glPushMatrix();
	glTranslated(700,300,0);
	solar();
	glPopMatrix();

	glPushMatrix();
	glTranslated(650,200,0);
	solar();
	glPopMatrix();

	glPushMatrix();
	glTranslated(800,200,0);
	solar();
	glPopMatrix();

	glPushMatrix();
	glTranslated(850,300,0);
	solar();
	glPopMatrix();

	if(sy>=100)
   {
	if(d)
	{
    glPushMatrix();
    glTranslatef(270, arrow_y, 0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(382, 100); // Starting position (windmill)
    glVertex2f(382, 120); // Ending position (house)
    glEnd();
	glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(395, 100); // Starting position (windmill)
    glVertex2f(395, 120); // Ending position (house)
    glEnd();
    glPopMatrix();
    animateArrow();
	}
	
	
   }
	battery();

}
void animateArrow()
{
    // Update the arrow position based on the animation logic
    // Adjust the speed as needed
    arrow_y -= 15; // Adjust the speed as needed
    ar_x +=10;

    // Check if the arrow has reached the destination
    if ( arrow_y <= 100)
    {
        // Reset the arrow position
        // arrow_x = 0;
        arrow_y = 250;
    }
    if(ar_x>=220)
    {
        ar_x=120;
    }
    if(ls<=80)
    {
        ls=220;
    }
	if(lh<=-50)
    {
        lh=220;
    }
}
void display2()
{
	ss+=2;
	ls-=15;
	lh-=15;
	glClearColor(0,0,0,1);
	stars();

	if(ss<=235)
	{
	glPushMatrix();
    glTranslatef(240, ar_x, 0);
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(382, 100); // Starting position (windmill)
    glVertex2f(382, 120); // Ending position (house)
    glEnd();
    glPopMatrix();
    animateArrow();

	if(ss>=30)
   {
    glPushMatrix();
    glTranslatef(ls, 190, 0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(382, 50); // Starting position (windmill)
    glVertex2f(400, 50); // Ending position (house)
    glEnd();
    glPopMatrix();
    animateArrow();

	glPushMatrix();
    glTranslatef(lh, 290, 0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(382, 50); // Starting position (windmill)
    glVertex2f(400, 50); // Ending position (house)
    glEnd();
    glPopMatrix();
    animateArrow();
   }
	}

}
void stars()
{
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
	glPointSize(2.0f); // Set point size for stars

	glBegin(GL_POINTS);
	glVertex2f(100.0f, 400.0f); 
	glVertex2f(200.0f, 450.0f);
    glVertex2f(300.0f, 500.0f); 
	glVertex2f(400.0f, 650.0f);
    glVertex2f(500.0f, 700.0f); 
	glVertex2f(600.0f, 450.0f);
    glVertex2f(700.0f, 800.0f); 
	glVertex2f(750.0f, 850.0f);
    glVertex2f(650.0f, 600.0f); 
	glVertex2f(550.0f, 650.0f);
    glVertex2f(150.0f, 700.0f); 
	glVertex2f(250.0f, 950.0f);
    glVertex2f(350.0f, 500.0f); 
	glVertex2f(450.0f, 850.0f);

    glVertex2f(1000.0f, 400.0f); 
	glVertex2f(900.0f, 750.0f);
    glVertex2f(800.0f, 600.0f); 
	glVertex2f(850.0f, 650.0f);
    glVertex2f(570.0f, 700.0f); 
	glVertex2f(880.0f, 450.0f);
    glVertex2f(990.0f, 800.0f); 
	glVertex2f(790.0f, 850.0f);
    glVertex2f(950.0f, 600.0f); 
	glVertex2f(1000.0f, 650.0f);
    glVertex2f(960.0f, 700.0f); 
	glVertex2f(900.0f, 950.0f);
    glVertex2f(940.0f, 500.0f); 
	glVertex2f(890.0f, 850.0f);

	glEnd();
}

void myinit()
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,999.0,0.0,799.0);
}

int main(int argc, char* argv[])

{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1900.0,1900.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Solar");
	glutDisplayFunc(display);
	myinit();
	glutTimerFunc(100,update,0);
	glutMainLoop();
	return 0;
}
