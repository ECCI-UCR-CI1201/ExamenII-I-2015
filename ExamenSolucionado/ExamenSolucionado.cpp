
#include "stdafx.h"

#include "Calificador.h"
#include "Fabrica.h"

int _tmain(int argc, _TCHAR* argv[]) {

	srand((unsigned int) time(NULL));

	// Calificador de examen
	Fabrica * f = new Fabrica();
	Calificador::calificar(f);
	delete f;

	system("pause");
	return 0;
}

