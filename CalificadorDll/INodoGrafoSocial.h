
#pragma once

#include "ILista.h"
#include "IPersona.h"

class INodoGrafoSocial {

public:
	virtual void setPersona(IPersona * actual) = 0;
	virtual IPersona * getPersona() = 0;
	virtual void agregarAmigo(IPersona * nodo) = 0;
	virtual ILista<INodoGrafoSocial *> * getAmigos() = 0;
};

