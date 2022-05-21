#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include <iostream>
#include <Windows.h>
#include "ETSIDI.h"
#include <thread>
#include <chrono>
using std::this_thread::sleep_for;
using namespace std::chrono_literals;



void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo

	t.dibuja(j.getTablero());
		
	/////////////////////////////////////////////
	//BLANCAS

	glPushMatrix();
	glTranslatef(-12.0, 8.0, 5.0);
	glColor3ub(255, 255, 255);
	glScalef(0.004f, 0.004f, 1);
	const char str[] = "Blancas";
	for (int i = 0; i < strlen(str); i++) {
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, str[i]);
	}
	glPopMatrix();
	

	glPushMatrix();
	//TIEMPO BLANCAS
	glTranslatef(-12.0, 7.0, 5.0);
	glColor3ub(255, 255, 255);
	glScalef(0.004f, 0.004f, 1);
	char str2[3];
	sprintf(str2, "%d", j.getMinLeftPlaA());
	for (int i = 0; i < strlen(str2); i++) {
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, str2[i]); //Minutos
	}

	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, ':'); //Separacion

	char str3[3];
	sprintf(str3, "%d", j.getSecLeftPlaA());
	for (int i = 0; i < strlen(str3); i++) {
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, str3[i]); //Segundos
	}

	glPopMatrix();

	//////////////////////////////////////////
	//NEGRAS

	glPushMatrix();
	glTranslatef(9.0, -7.0, 5.0);
	glColor3ub(0, 0, 0);
	glScalef(0.004f, 0.004f, 1);
	const char str4[] = "Negras";
	for (int i = 0; i < strlen(str4); i++) {
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, str4[i]);
	}
	glPopMatrix();


	glPushMatrix();
	//TIEMPO NEGRAS
	glTranslatef(9.0, -8.0, 5.0);
	glColor3ub(0, 0, 0);
	glScalef(0.004f, 0.004f, 1);
	char str5[3];
	sprintf(str5, "%d", j.getMinLeftPlaB());
	for (int i = 0; i < strlen(str4); i++) {
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, str5[i]); //Minutos
	}

	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, ':'); //Separacion

	char str6[3];
	sprintf(str6, "%d", j.getSecLeftPlaB());
	for (int i = 0; i < strlen(str5); i++) {
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, str6[i]); //Segundos
	}

	glPopMatrix();



}



void Mundo::mueve()
{
	t.mueve();
	
	//t.resetColor();
}

void Mundo::inicializa()
{
	x_ojo=0;
	y_ojo=0;
	z_ojo=30;

	t.inicializa();
}

void Mundo::tecla(unsigned char key)
{
	/*
	if (key == 'q')
	{
		//cambia colores esquinas
		t.modifica();
	}
	*/
}

static int origen_f, origen_c, final_f, final_c;

void Mundo::raton(int b, int e, int x, int y) //Boton-estado-posicionx-posiciony
{
	//std::cout << b << " " << e << " " << x << " " << y << endl;
	
	int c = ROW_SIZE * trunc((float)x - 125.0f) / (675.0f - 125.0f);
	int f = COL_SIZE - COL_SIZE * trunc((float)y - 25.0f) / (575.0f - 25.0f);


	if (b == GLUT_LEFT_BUTTON && e == GLUT_UP)
	{
		if (f < ROW_SIZE && f >= 0 && c < COL_SIZE && c >= 0)
		{
			j.movimiento(origen_f, origen_c, f, c);

			pieza_t* selec = &j.getTablero()[f][c];
			t.pintMovPermitidos(j.mov_permitidos(selec, j.get_tablero()));
			origen_f=f;
			origen_c=c;
			
		}
	}
	
}