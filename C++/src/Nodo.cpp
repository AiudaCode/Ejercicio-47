#include "Nodo.h"

Nodo::Nodo()
{
    // le asignamos valores por defecto a los atributos de la clase en el constructor
    id = 0;
    nombre = "";
    semestre = 0;
    notas = new float[3];
    siguiente = NULL;
}

Nodo::~Nodo()
{
    //dtor
}

// metodos Setters y Getters
void Nodo::setId(int val)
{
    id = val;
}

int Nodo::getId()
{
    return id;
}

void Nodo::setNombre(string val)
{
    nombre = val;
}

string Nodo::getNombre()
{
    return nombre;
}

void Nodo::setSemestre(int val)
{
    semestre = val;
}

int Nodo::getSemestre()
{
    return semestre;
}

void Nodo::setNotas(int pos, float val)
{
    notas[pos] = val;
}

float Nodo::getNotas(int pos)
{
    return notas[pos];
}

void Nodo::setSiguiente(Nodo *val)
{
    siguiente = val;
}

Nodo *Nodo::getSiguiente()
{
    return siguiente;
}

// método para copiar la información de un nodo
void Nodo::copiar(Nodo *nd)
{
    id = nd->getId();
    nombre = nd->getNombre();
    semestre = nd->getSemestre();
    for (int i = 0; i < 3; i++)
    {
        notas[i] = nd->getNotas(i);
    }
}

// método para calcular el promedio
float Nodo::promedio()
{
    float suma = 0;
    for (int i = 0; i < 3; i++)
    {
        suma += getNotas(i);
    }
    return suma/3;
}
