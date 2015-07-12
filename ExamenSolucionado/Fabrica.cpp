
#include "stdafx.h"
#include "Fabrica.h"

Fabrica::Fabrica() {
}


Fabrica::~Fabrica() {
}

IPersona * Fabrica::crearPersona() {
	return new Persona();
}

ILista<int> * Fabrica::crearListaInt() {
	return new Lista<int>();
}

ILista<IPersona *> * Fabrica::crearListaPersona() {
	return new Lista<IPersona *>();
}

IGrafoSocial * Fabrica::crearGrafoSocial() {
	return new GrafoSocial();
}

void Fabrica::borrarPersona(IPersona * ptr) {
	delete ptr;
}

void Fabrica::borrarListaInt(ILista<int> * ptr) {
	delete ptr;
}

void Fabrica::borrarListaPersona(ILista<IPersona *> * ptr) {
	delete ptr;
}

void Fabrica::borrarGrafoSocial(IGrafoSocial * ptr) {
	delete ptr;
}