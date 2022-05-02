

// Test unitario:
/*
Juego a;
cout << a.print();
*/

#include "Pieza.h"
#include <sstream>
using namespace std;

#ifndef _CHESSPULES_H_
#define _CHESSPULES_H_


// Puntero a las piezas de la partida
typedef  pieza_t** tablero_t;



// CRITERIO DEL TABLERO:

/*
T C A D R A C T  // Piezas negras
P P P P P P P P
- - - - - - - -
- - - - - - - -
- - - - - - - -
P P P P P P P P
T C A D R A C T  // Piezas blancas
*/

// Primera dimensión = Filas
// Segunda dimensión = Columnas
// EJ: El rey blanco está en [7][4]



class Juego {


public:

	// Constructor y destructor:
	Juego();
	~Juego();

	string print(); // Temporal

	// Movimientos de las piezas:
	tablero_info_t get_mov_permitidos(pieza_t* a, tablero_t tab);
	bool haz_movimiento(int row_o, int col_o, int row_f, int col_f);
	ostream& notacion_ulimo_moviento();

	// Servicios
	bool tablas();
	bool jaque_mate();
	bool tablas_por_repeticiones_de_posicion();
	bool tablas_por_rey_ahogado();
	bool jaque_playerA();
	bool jaque_playerB();
	bool jaque_mate_playerA();
	bool jaque_mate_playerB();

	int score_playerA();
	int score_playerB();


private:
	tablero_t tab;

	// Informacion del enrroque
	bool playerA_enroque_permitido;
	bool playerB_enroque_permitido;

	// Tablas por repeticion de movimiento:
	tablero_t* historial;
	int numero_mov;
	bool anade_movimiento_historial(tablero_t posicion);
	bool tableros_iguales(tablero_t* t1, tablero_t* t2);

	// Tablas por rey ahogado
	bool tablas_por_rey_ahogado(color_pieza_t color);
	bool jaque_player(color_pieza_t color, tablero_t mat);
	bool jaque_mate_player(color_pieza_t color, tablero_t mat);

	// Auxiliar movimiento:
	void aux_detectar_jaques_a_la_descubierta(tablero_info_t& matriz, pieza_t** tab, int row, int col);
	bool analisis_mov;

	// Notacion del movimietno
	ostringstream mov;
	char row_to_char(int row);
	char col_to_char(int col);

	// Temporal:
	void tablero_inicio_normal();

};




#endif

