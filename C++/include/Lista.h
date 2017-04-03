#ifndef LISTA_H
#define LISTA_H
#include "Lista.h"
#include "Nodo.h"

class Lista
{
    public:
        Lista();
        virtual ~Lista();
        // metodos publico de la clase
        void setCabeza(Nodo *n);
        Nodo *getCabeza();
        bool validarId(int c);
        Nodo *ultimo();
        int contarNodos();
        void agregarFinal(Nodo *n);
        Nodo *buscarId(int c);
        void ordenarAscendentemente(Nodo *n);
        void ordenarDescendentemente(Nodo *n);
        void cambiar(Nodo *p1, Nodo *p2);
        float promedioGeneral();
        void eliminar(Nodo *n);
        void limpiar();
    protected:

    private:
        // se declara un atributo privado de tipo Nodo llamado cabeza
        Nodo *cabeza;
};

#endif // LISTA_H
