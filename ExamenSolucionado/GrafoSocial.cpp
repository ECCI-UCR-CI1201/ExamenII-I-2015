#include "stdafx.h"
#include "GrafoSocial.h"


GrafoSocial::GrafoSocial() {
	personas = new Lista<INodoGrafoSocial*>();
}


GrafoSocial::~GrafoSocial() {
	INodoGrafoSocial * actual = NULL;
	for (int i = 0; i < personas->cantidadElementos(); i++) {
		actual = personas->get(i);
		delete actual->getPersona();
		delete actual;
	}
	delete personas;
}

void GrafoSocial::aleatorizarGrafo() {

	char * nombres[5] = {"Fulgencio", "Ruperto", "Perico de los Palotes", "Ricardo", "Alejandra"};
	IPersona * personasV[5];
	for (int i = 0; i < 5; i++) {
		personasV[i] = new Persona();
		personasV[i]->setID(i);
		personasV[i]->setNombre(nombres[i]);
		agregarPersona(personasV[i]);
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; i < i; i++) {
			int i = rand();
			if (i < RAND_MAX / 2) {
				establecerAmistad(personasV[i], personasV[j]);
			}
		}
	}
}

IPersona * GrafoSocial::getPersonaAleatoria() {
	int a = rand() % personas->cantidadElementos();
	return personas->get(a)->getPersona();
}

void GrafoSocial::agregarPersona(IPersona * persona) {
	INodoGrafoSocial * nodo = new NodoGrafoSocial();
	nodo->setPersona(persona);
	personas->insertarFinal(nodo);
}

bool GrafoSocial::sonAmigos(IPersona * a, IPersona * b) {
	INodoGrafoSocial * nodoA = getNodo(a);
	INodoGrafoSocial * nodoB = getNodo(b);
	bool amistad = false;
	if (nodoA != NULL && nodoB != NULL) {
		amistad = nodoA->getAmigos()->contiene(nodoB) && nodoB->getAmigos()->contiene(nodoA);
	}
	return amistad;
}

INodoGrafoSocial * GrafoSocial::getNodo(IPersona * persona) {
	INodoGrafoSocial * actual = NULL;
	for (int i = 0; i < personas->cantidadElementos(); i++) {
		actual = personas->get(i);
		if (*actual->getPersona() == *persona) {
			i = personas->cantidadElementos();
		}
	}
	return actual;
}

void GrafoSocial::establecerAmistad(IPersona * a, IPersona * b) {
	INodoGrafoSocial * nodoA = getNodo(a);
	INodoGrafoSocial * nodoB = getNodo(b);
	if (nodoA != NULL && nodoB != NULL) {
		nodoA->getAmigos()->insertarFinal(nodoB);
		nodoB->getAmigos()->insertarFinal(nodoA);
	}
}
