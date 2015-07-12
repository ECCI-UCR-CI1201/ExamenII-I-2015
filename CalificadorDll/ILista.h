
#pragma once

template<class T>
class ILista {

public:
	virtual void insertarFinal(T elemento) = 0;
	virtual void eliminarFinal() = 0;
	virtual T get(int index) = 0;
	virtual int cantidadElementos() = 0;
	virtual bool contiene(T elemento) = 0;
};

