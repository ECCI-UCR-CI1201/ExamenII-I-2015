
#pragma once

#include "INodoGrafoSocial.h"
#include "IPersona.h"
#include "ILista.h"
#include "Lista.h"

class NodoGrafoSocial :
	public INodoGrafoSocial {

	IPersona * persona;
	ILista<INodoGrafoSocial *> * amigos;

public:
	NodoGrafoSocial();
	~NodoGrafoSocial();

	void setPersona(IPersona * actual);
	IPersona * getPersona();
	void agregarAmigo(IPersona * nodo);
	ILista<INodoGrafoSocial *> * getAmigos();
};

