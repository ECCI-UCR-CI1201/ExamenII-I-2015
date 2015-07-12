
#pragma once

#include "IPersona.h"

class Persona :
	public IPersona {

private:
	long id;
	char * nombre;

public:
	Persona();
	~Persona();

	void setID(long);
	long getID();
	void setNombre(char *);
	char * getNombre();
	bool operator==(IPersona&);
	bool operator!=(IPersona&);
};

