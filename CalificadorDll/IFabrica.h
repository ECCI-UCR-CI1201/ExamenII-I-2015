
#pragma once

#include "IPersona.h"
#include "ILista.h"
#include "IGrafoSocial.h"

class IFabrica {

public:
	virtual IPersona * crearPersona() = 0;
	virtual ILista<int> * crearListaInt() = 0;
	virtual ILista<IPersona *> * crearListaPersona() = 0;
	virtual IGrafoSocial * crearGrafoSocial() = 0;

	virtual void borrarPersona(IPersona *) = 0;
	virtual void borrarListaInt(ILista<int> *) = 0;
	virtual void borrarListaPersona(ILista<IPersona *> *) = 0;
	virtual void borrarGrafoSocial(IGrafoSocial *) = 0;
};
