
#pragma once

template <class T>
class INodoLista {

public:
	virtual void setActual(T actual) = 0;
	virtual T getActual() = 0;
	virtual void setSiguiente(INodoLista<T>* siguiente) = 0;
	virtual INodoLista<T>* getSiguiente() = 0;
};

