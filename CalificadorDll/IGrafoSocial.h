
#pragma once

#include "IPersona.h"
#include "ILista.h"

class IGrafoSocial {
public:
	virtual void aleatorizarGrafo() = 0;
	virtual IPersona * getPersonaAleatoria() = 0;
	virtual void agregarPersona(IPersona *) = 0;
	virtual bool sonAmigos(IPersona *, IPersona *) = 0;
	virtual void establecerAmistad(IPersona *, IPersona *) = 0;
};

