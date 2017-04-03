#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

class Nodo
{
    public:
        Nodo();
        virtual ~Nodo();
        // metodos publico de la clase
        void setId(int val);
        int getId();
        void setNombre(string val);
        string getNombre();
        void setSemestre(int val);
        int getSemestre();
        void setNotas(int pos, float val);
        float getNotas(int pos);
        void setSiguiente(Nodo *val);
        Nodo *getSiguiente();
        void copiar(Nodo *nd);
        float promedio();
    protected:

    private:
        // se declaran los atributos privados de la clase
        int id;
        string nombre;
        int semestre;
        float *notas;
        Nodo *siguiente;
};

#endif // NODO_H
