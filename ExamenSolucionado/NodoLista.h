
#pragma once

#include "INodoLista.h"

template <class T>
class NodoLista :
	public INodoLista < T > {

protected:
	T actual;
	INodoLista<T> * siguiente;

public:

	NodoLista() {
		siguiente = NULL;
	}

	~NodoLista() {
	}

	void setActual(T actual) {
		this->actual = actual;
	}

	T getActual() {
		return actual;
	}

	void setSiguiente(INodoLista<T>* siguiente) {
		this->siguiente = siguiente;
	}

	INodoLista<T>* getSiguiente() {
		return siguiente;
	}
};

