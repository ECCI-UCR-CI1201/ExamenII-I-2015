
#pragma once

#include "IGrafoSocial.h"
#include "INodoGrafoSocial.h"
#include "ILista.h"
#include "Lista.h"
#include "Persona.h"
#include "NodoGrafoSocial.h"

class GrafoSocial :
	public IGrafoSocial {

protected:
	ILista<INodoGrafoSocial *> * personas;

	INodoGrafoSocial * getNodo(IPersona *);

public:
	GrafoSocial();
	~GrafoSocial();

	void aleatorizarGrafo();
	IPersona * getPersonaAleatoria();
	void agregarPersona(IPersona *);
	bool sonAmigos(IPersona *, IPersona *);
	void establecerAmistad(IPersona *, IPersona *);
};

