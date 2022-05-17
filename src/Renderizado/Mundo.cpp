#include "Mundo.h"
#include "freeglut.h"
#include <math.h>
#include <iostream>
#include <Windows.h>


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
	std::cout <<"Jugador 1 " << j.getMinLeftPlaA() <<":" << j.getSecLeftPlaA() << std::endl;
	std::cout << "Jugador 2 " << j.getMinLeftPlaB() << ":" << j.getSecLeftPlaB() << std::endl;
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
	if (key == 'q')
	{
		//cambia colores esquinas
		t.modifica();
	}
}

static int origen_f, origen_c, final_f, final_c;

void Mundo::raton(int b, int e, int x, int y) //Boton-estado-posicionx-posiciony
{
	//std::cout << b << " " << e << " " << x << " " << y << endl;
	
	int c = ROW_SIZE * trunc((float)x - 125.0f) / (675.0f - 125.0f);
	int f = COL_SIZE - COL_SIZE * trunc((float)y - 25.0f) / (575.0f - 25.0f);


	if (b == 0 && e == 0)
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