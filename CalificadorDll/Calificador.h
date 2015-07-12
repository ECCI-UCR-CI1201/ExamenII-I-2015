#pragma once

#include "CalificadorDll.h"
#include "IFabrica.h"
#include "ILista.h"
#include "IPersona.h"

#include <string>
using namespace std;

class Calificador {

private:
	static int probarPersona(IFabrica *);
	static int probarListaInt(IFabrica *);
	static int probarListaPersona(IFabrica *);
	static int probarGrafoSocial(IFabrica *);

public:
	static CALIFICADORDLL_API void calificar(IFabrica *);

};

