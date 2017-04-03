#include <iostream>
#include "Nodo.h"
#include "Lista.h"
#include "stdlib.h"

using namespace std;

// método para llenar un nodo
void llenar(Nodo *n, Lista *obj)
{
    int id, sem;
    float nota;
    do
    {
        cout << "Digite identificacion" << endl;
        cout << ">> ";
        cin >> id;
    }
    while(obj->validarId(id) == true);//si validarId() retorna TRUE entonces la id esta utilizada.
    n->setId(id);
    // se pide en pantalla el nombre
    string nom;
    cout << "Digite su nombre" << endl;
    cout << ">> ";
    cin >> nom;
    // se encapsula la variable nom
    n->setNombre(nom);
    // se pide en pantalla el semetres
    cout << "Digite su semestre" << endl;
    cout << ">> ";
    cin >> sem;
    // se encapsula la variable sem
    n->setSemestre(sem);
    // se itera 3 veces con el ciclo for
    for (int i = 0; i < 3;  i++)
    {
        // se pedira la nota de nuevo si digita una nota menor a 0 ó mayor a 5
        do
        {
            cout << "Digite la nota " << (i+1) << endl;
            cout << ">> ";
            cin >> nota;
        }
        while (nota < 0 || nota > 5);
        // se encapsula en la posicion i el valor de la variable nota
        n->setNotas(i, nota);
    }
}

// método para mostrar la información de un nodo
void mostrar(Nodo *n)
{
    cout << "ID: " << n->getId() << endl;
    cout << "Nombre: " << n->getNombre() << endl;
    cout << "Semestre: " << n->getSemestre() << endl;
    cout << "Nota 1: " << n->getNotas(0) << endl;
    cout << "Nota 2: " << n->getNotas(1) << endl;
    cout << "Nota 2: " << n->getNotas(2) << endl;
    cout << "Promedio: " << n->promedio() << endl << endl;
}

// método para listar la información de todos los nodos de la lista
void listar(Nodo *n)
{
    Nodo *temp = n;
    while(temp != NULL)
    {
        mostrar(temp);
        temp = temp->getSiguiente();
    }
}

// método para mostrar el menu de opciones
int menu()
{
    int opcion = 0;
    do
    {
        cout << "=========== SELECCIONE UNA OPCION DEL MENU ===========" << endl;
        cout << "1. Registrar estudiante." << endl;
        cout << "2. Buscar por ID." << endl;
        cout << "3. Mostar estudiantes aprobados ordenados ascendemente por el semestre." << endl;
        cout << "4. Mostar estudiantes con promedio superior al promedio de notas ordenados descendemente por el semestre." << endl;
        cout << "5. Eliminar estudiantes con promedio de notas igual al promedio general." << endl;
        cout << "6. Mostrar toda la lista." << endl;
        cout << "7. Salir" << endl << endl;
        cout << ">> ";
        cin >> opcion;
        system("cls");
    }
    while(opcion < 1 || opcion > 7);
    return opcion;
}

int main(void)
{
    // se crea un objeto de la clase Lista (Instanciación)
    Lista *obj = new Lista();
    // se declaran 2 variables de tipo entero opcion e id
    int opcion, id;
    // se declara una variable de tipo string nombre
    string nombre;
    // se declara una variable de tipo Nodo aux
    Nodo *aux;
    do
    {
        // se le asigna a la variable opcion el valor que retorne el metodo menu
        opcion = menu();
        // dependiendo del valor de la variable opcion se escogera un caso
        switch(opcion)
        {
            case 1:
                aux = new Nodo();
                llenar(aux, obj);
                obj->agregarFinal(aux);
                break;
            case 2:
                cout << "Digite ID del estudiante que quiere agregar" << endl;
                cout << ">> ";
                cin >> id;
                aux = obj->buscarId(id);
                if(aux != NULL)
                {
                    mostrar(aux);
                }
                else
                {
                    cout << "La ID NO se encuentra en la lista" << endl;
                }
                break;
            case 3:
                aux = obj->getCabeza();
                if(aux == NULL)
                {
                    cout << "No hay estudiantes matriculados" << endl;
                }
                else
                {
                    if(obj->contarNodos() > 1)
                    {
                        aux = obj->getCabeza();
                        obj->ordenarAscendentemente(aux);
                        while(aux != NULL)
                        {
                            if (aux->promedio() >= 3)
                            {
                                mostrar(aux);
                            }
                            aux = aux->getSiguiente();
                        }
                    }
                    else
                    {
                        cout << "Solo hay un estudiante, agregue por lo menos 1 estudiante mas para ordenar" << endl;
                    }
                }
                break;
            case 4:
                aux = obj->getCabeza();
                if(aux == NULL)
                {
                    cout << "No hay estudiantes matriculados" << endl;
                }
                else
                {
                    if(obj->contarNodos() > 1)
                    {
                        aux = obj->getCabeza();
                        obj->ordenarDescendentemente(aux);
                        while(aux != NULL)
                        {
                            if (aux->promedio() > obj->promedioGeneral())
                            {
                                mostrar(aux);
                            }
                            aux = aux->getSiguiente();
                        }
                    }
                    else
                    {
                        cout << "Solo hay un estudiante, agregue por lo menos 1 estudiante mas para ordenar" << endl;
                    }
                }
                break;
            case 5:
                aux = obj->getCabeza();
                if(aux == NULL)
                {
                    cout << "No hay estudiantes matriculados" << endl;
                }
                else
                {
                    obj->limpiar();
                }
                break;
            case 6:
                aux = obj->getCabeza();
                if(aux == NULL)
                {
                    cout << "No hay estudiantes matriculados" << endl;
                }
                else
                {
                    listar(aux);
                }
            default:
                break;
        }
    }
    while(opcion != 7);
}
