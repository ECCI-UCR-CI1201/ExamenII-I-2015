
#include "stdafx.h"
#include "Calificador.h"

using namespace std;

void Calificador::calificar(IFabrica * fabrica) {

	cout << "Iniciando calificacion" << endl;
	cout << "Buena suerte!" << endl;

	double puntaje = 0;
	double puntajeMaximo = 205;

	puntaje += probarPersona(fabrica);
	cout << "Nota hasta el momento: " << (puntaje / puntajeMaximo) * 100 << endl;

	puntaje += probarListaInt(fabrica);
	cout << "Nota hasta el momento: " << (puntaje / puntajeMaximo) * 100 << endl;

	puntaje += probarListaPersona(fabrica);
	cout << "Nota hasta el momento: " << (puntaje / puntajeMaximo) * 100 << endl;

	puntaje += probarGrafoSocial(fabrica);
	cout << "Nota hasta el momento: " << (puntaje / puntajeMaximo) * 100 << endl;

	cout << endl << "Fin de las pruebas" << endl;
	cout << "Nota Final: " << (puntaje / puntajeMaximo) * 100 << endl;

	if ((puntaje / puntajeMaximo) * 100 == 100) {
		cout << "Felicidades!" << endl;
	} else {
		cout << "Aun se puede mejorar!" << endl;
	}

	cout << endl;
}

int Calificador::probarPersona(IFabrica * fabrica) {
	cout << endl << "Probando la clase persona..." << endl << endl;
	int puntaje = 0;

	cout << "Creando 2 personas... ";
	IPersona * p1 = fabrica->crearPersona();
	IPersona * p2 = fabrica->crearPersona();

	if (p1 != NULL && p2 != NULL) {

		cout << "Exito +5" << endl;
		puntaje += 5;

		cout << "Asignando IDs" << endl;
		p1->setID(1l);
		p2->setID(2l);

		cout << "Asignando nombres" << endl;

		char * nombre1 = "Juan";
		char * nombre2 = "Juan";

		p1->setNombre(nombre1);
		p2->setNombre(nombre2);

		bool pruebaGetID = p1->getID() == 1l && p2->getID() == 2l;
		bool pruebaGetNombre = p1->getNombre() == nombre1 && p2->getNombre() == nombre2;
		bool pruebaIgualdad = !(*p1 == *p2);
		bool pruebaDesigualdad = *p1 != *p2;

		cout << "Prueba getID() : " << (pruebaGetID ? "Exito +5" : "Fallo") << endl;
		cout << "Prueba getNombre() : " << (pruebaGetNombre ? "Exito +5" : "Fallo") << endl;
		cout << "Prueba == : " << (pruebaIgualdad ? "Exito +5" : "Fallo") << endl;
		cout << "Prueba != : " << (pruebaDesigualdad ? "Exito +5" : "Fallo") << endl;

		puntaje += pruebaGetID ? 5 : 0;
		puntaje += pruebaGetNombre ? 5 : 0;
		puntaje += pruebaIgualdad ? 5 : 0;
		puntaje += pruebaDesigualdad ? 5 : 0;

		fabrica->borrarPersona(p1);
		fabrica->borrarPersona(p2);
		
	} else {
		cout << "Fallo" << endl;
	}

	cout << endl;

	return puntaje;
}

int Calificador::probarListaInt(IFabrica * fabrica) {
	cout << endl << "Probando la clase Lista emplantillada con int..." << endl << endl;
	int puntaje = 0;

	cout << "Creando la lista... ";
	ILista<int> * l = fabrica->crearListaInt();

	if (l != NULL) {
		cout << "Exito +10" << endl;
		puntaje += 10;

		bool pruebaInsercion = true;
		for (int i = 0; i < 10 && pruebaInsercion; i++) {
			l->insertarFinal(i);
			pruebaInsercion = l->cantidadElementos() == i + 1;
		}

		bool pruebaGet = true;
		for (int i = 0; i < 10 && pruebaGet; i++) {
			int j = l->get(i);
			pruebaGet = j == i;
		}

		bool pruebaContiene = l->contiene(5) && !l->contiene(15);

		bool pruebaEliminar = true;
		for (int i = 0; i < 10 && pruebaEliminar; i++) {
			l->eliminarFinal();
			pruebaEliminar = l->cantidadElementos() == (10 - i - 1);
		}

		cout << "Prueba Insercion : " << (pruebaInsercion ? "Exito +10" : "Fallo") << endl;
		cout << "Prueba Get : " << (pruebaGet ? "Exito +10" : "Fallo") << endl;
		cout << "Prueba Contiene : " << (pruebaContiene ? "Exito +10" : "Fallo") << endl;
		cout << "Prueba Eliminacion : " << (pruebaEliminar ? "Exito +10" : "Fallo") << endl;

		puntaje += pruebaInsercion ? 10 : 0;
		puntaje += pruebaGet ? 10 : 0;
		puntaje += pruebaContiene ? 10 : 0;
		puntaje += pruebaEliminar ? 10 : 0;

		fabrica->borrarListaInt(l);

	} else {
		cout << "Fallo" << endl;
	}

	cout << endl;

	return puntaje;
}

int Calificador::probarListaPersona(IFabrica * fabrica) {
	cout << endl << "Probando la clase Lista emplantillada con IPersona..." << endl << endl;
	int puntaje = 0;

	cout << "Creando la lista... ";
	ILista<IPersona *> * l = fabrica->crearListaPersona();

	if (l != NULL) {
		cout << "Exito +10" << endl;
		puntaje += 10;

		bool pruebaInsercion = true;
		for (int i = 0; i < 10 && pruebaInsercion; i++) {

			IPersona * p = fabrica->crearPersona();
			p->setID(i);

			l->insertarFinal(p);
			pruebaInsercion = l->cantidadElementos() == i + 1;
		}

		bool pruebaGet = true;
		for (int i = 0; i < 10 && pruebaGet; i++) {
			IPersona * j = l->get(i);
			pruebaGet = j->getID() == i;

		}

		IPersona * prueba = fabrica->crearPersona();
		prueba->setID(15);
		bool pruebaContiene = l->contiene(l->get(0)) && !l->contiene(prueba);
		fabrica->borrarPersona(prueba);
		
		bool pruebaEliminar = true;
		for (int i = 0; i < 10 && pruebaEliminar; i++) {
			IPersona * p = l->get(10 - i - 1);
			l->eliminarFinal();
			fabrica->borrarPersona(p);
			pruebaEliminar = l->cantidadElementos() == (10 - i - 1);
		}

		cout << "Prueba Insercion : " << (pruebaInsercion ? "Exito +10" : "Fallo") << endl;
		cout << "Prueba Get : " << (pruebaGet ? "Exito +10" : "Fallo") << endl;
		cout << "Prueba Contiene : " << (pruebaContiene ? "Exito +10" : "Fallo") << endl;
		cout << "Prueba Eliminacion : " << (pruebaEliminar ? "Exito +10" : "Fallo") << endl;

		puntaje += pruebaInsercion ? 10 : 0;
		puntaje += pruebaGet ? 10 : 0;
		puntaje += pruebaContiene ? 10 : 0;
		puntaje += pruebaEliminar ? 10 : 0;

		fabrica->borrarListaPersona(l);

	} else {
		cout << "Fallo" << endl;
	}

	cout << endl;

	return puntaje;
}

int Calificador::probarGrafoSocial(IFabrica * fabrica) {
	cout << endl << "Probando el Grafo Social..." << endl << endl;
	int puntaje = 0;

	cout << "Creando el grafo... ";
	IGrafoSocial * grafo = fabrica->crearGrafoSocial();

	if (grafo != NULL) {
		cout << "Exito +20" << endl;
		puntaje += 20;

		bool pruebaAleatorioA = true;
		grafo->aleatorizarGrafo();
		for (int i = 0; i < 5; ++i) {
			IPersona * persona = grafo->getPersonaAleatoria();
			cout << "ID Persona Aleatoria = " << persona->getID() << endl;
		}

		cout << "Obteniendo 10000 personas aleatorias" << endl;
		bool pruebaAleatorioB = true;
		int sumaA = 0;
		int sumaB = 0;
		for (int i = 0; i < 10000; i++) {	
			if (i % 2 == 0) {
				sumaA += grafo->getPersonaAleatoria()->getID();
			} else {
				sumaB += grafo->getPersonaAleatoria()->getID();
			}
		}
		pruebaAleatorioB = sumaA != sumaB;

		IPersona * a = fabrica->crearPersona();
		IPersona * b = fabrica->crearPersona();
		IPersona * c = fabrica->crearPersona();
		a->setID(-5);
		b->setID(-15);
		c->setID(-25);
		grafo->agregarPersona(a);
		grafo->agregarPersona(b);
		grafo->agregarPersona(c);
		grafo->establecerAmistad(a, b);
		grafo->establecerAmistad(b, c);
		bool pruebaAmistad = grafo->sonAmigos(a, b) && grafo->sonAmigos(b, c) && !grafo->sonAmigos(a, c);

		cout << "Prueba Aleatorio A : " << (pruebaAleatorioA ? "Exito +20" : "Fallo") << endl;
		cout << "Prueba Aleatorio B : " << (pruebaAleatorioB ? "Exito +20" : "Fallo") << endl;
		cout << "Prueba Amistad : " << (pruebaAmistad ? "Exito +20" : "Fallo") << endl;

		puntaje += pruebaAleatorioA ? 20 : 0;
		puntaje += pruebaAleatorioB ? 20 : 0;
		puntaje += pruebaAmistad ? 20 : 0;

		fabrica->borrarGrafoSocial(grafo);

	} else {
		cout << "Fallo" << endl;
	}

	cout << endl;

	return puntaje;
}
