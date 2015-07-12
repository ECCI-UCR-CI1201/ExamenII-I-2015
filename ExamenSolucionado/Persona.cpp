#include "stdafx.h"
#include "Persona.h"

Persona::Persona() {
}

Persona::~Persona() {
}

void Persona::setID(long id) {
	this->id = id;
}

long Persona::getID() {
	return id;
}

void Persona::setNombre(char * nombre) {
	this->nombre = nombre;
}

char * Persona::getNombre() {
	return nombre;
}

bool Persona::operator==(IPersona & otra) {
	return this->getID() == otra.getID();
}

bool Persona::operator!=(IPersona & otra) {
	return this->getID() != otra.getID();
}
