
#pragma once

#include "ILista.h"
#include "INodoLista.h"
#include "NodoLista.h"

template<class T>
class Lista :
	public ILista < T > {

	INodoLista<T> * cabeza, *cola;
	int n;

public:

	Lista() {
		cabeza = NULL;
		cola = NULL;
	}

	~Lista() {
		INodoLista<T> * actual = cabeza;
		while (actual != NULL) {
			delete actual;
			actual = actual->getSiguiente();
		}
	}

	void insertarFinal(T elemento) {
		INodoLista<T> * nodo = new NodoLista<T>();
		nodo->setActual(elemento);
		if (cola == NULL) {
			cabeza = nodo;
			cola = nodo;
		} else {
			cola->setSiguiente(nodo);
			cola = nodo;
		}
		n++;
	}

	void eliminarFinal() {
		if (cabeza == cola) {
			delete cola;
			cabeza = NULL;
			cola = NULL;
		} else {
			INodoLista<T> * actual = cabeza;
			while (actual->getSiguiente() != cola) {
				actual = actual->getSiguiente();
			}
			delete cola;
			cola = actual;
		}
		n--;
	}

	T get(int index) {
		INodoLista<T> * actual = cabeza;
		while (index-- > 0) {
			actual = actual->getSiguiente();
		}
		return actual->getActual();
	}

	int cantidadElementos() {
		return n;
	}

	bool contiene(T elemento) {
		bool contenido = false;
		INodoLista<T> * actual = cabeza;
		for (int i = 0; i < n && !contenido; i++) {
			if (actual->getActual() == elemento) {
				contenido = true;
			}
			actual = actual->getSiguiente();
		}
		return contenido;
	}

};
