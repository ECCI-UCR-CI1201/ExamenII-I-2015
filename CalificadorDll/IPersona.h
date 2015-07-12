
#pragma once

#include <string>

using namespace std;

class IPersona {

public:
	virtual void setID(long) = 0;
	virtual long getID() = 0;
	virtual void setNombre(char *) = 0;
	virtual char * getNombre() = 0;
	virtual bool operator==(IPersona&) = 0;
	virtual bool operator!=(IPersona&) = 0;
};

