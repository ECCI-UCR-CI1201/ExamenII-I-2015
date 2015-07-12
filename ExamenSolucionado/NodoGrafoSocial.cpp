#include "stdafx.h"
#include "NodoGrafoSocial.h"


NodoGrafoSocial::NodoGrafoSocial() {
	persona = NULL;
	amigos = new Lista<INodoGrafoSocial *>();
}


NodoGrafoSocial::~NodoGrafoSocial() {
	for (int i = 0; i < amigos->cantidadElementos(); i++) {
		delete amigos->get(i);
	}
	delete amigos;
}

void NodoGrafoSocial::setPersona(IPersona * persona) {
	this->persona = persona;
}

IPersona * NodoGrafoSocial::getPersona() {
	return persona;
}

void NodoGrafoSocial::agregarAmigo(IPersona * persona) {
	INodoGrafoSocial * nodo = new NodoGrafoSocial();
	nodo->setPersona(persona);
	this->amigos->insertarFinal(nodo);
}

ILista<INodoGrafoSocial *> * NodoGrafoSocial::getAmigos() {
	return amigos;
}
