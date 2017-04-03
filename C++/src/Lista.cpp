#include "Lista.h"

Lista::Lista()
{
    // le asignamos un valor por defecto al atributo de la clase en el constructor
    cabeza = NULL;
}

Lista::~Lista()
{
    //dtor
}

// método set y get del atributo de la clase
void Lista::setCabeza(Nodo *n)
{
    cabeza = n;
}

Nodo *Lista::getCabeza()
{
    return cabeza;
}

// método para validar si un ID no se ha repetido
bool Lista::validarId(int c)
{
    // se inicializa una variable de tipo Nodo y se le asigna la cabeza
    Nodo *temp = cabeza;
    // se inicializa una variable de tipo booleana y se le asigna false
    bool igual = false;
    // mientras haya un nodo en la lista
    while(temp != NULL)
    {
        // si el id del nodo temporal es igual al valor de la variable c pasada como parametro
        if(temp->getId() == c)
        {
            // entonces se le asigna a igual el valor de true
            igual = true;
            // se rompe el ciclo
            break;
        }
        // se salta al siguiente nodo de temp
        temp = temp->getSiguiente();
    }
    // se retorna el valor de la variable igual
    return igual;
}

// método para retornar el ultimo nodo de la lista
Nodo *Lista::ultimo()
{
    // se inicializa una variable de tipo Nodo en la cabeza
    Nodo *temp = cabeza;
    // mientras haya un nodo en la lista
    while(temp != NULL)
    {
        // entonces, si el siguiente nodo de temp es igual a null
        if (temp->getSiguiente() == NULL)
        {
            // entonces, se rompe el ciclo
            break;
        }
        else
        {
            // sino, se salta al siguiente nodo del temp
            temp = temp->getSiguiente();
        }
    }
    // se retorna el nodo temp
    return temp;
}

// método para contar los nodos de la lista
int Lista::contarNodos()
{
    // se inicializa la variable de tipo Nodo temp en la cabeza
    Nodo *temp = cabeza;
    // se inicializa la variable de tipo entero contador en 0
    int contador = 0;
    // mientras haya un nodo en la lista
    while(temp != NULL)
    {
        // se incrementara la variable contador
        contador++;
        // y se salta al siguiente nodo de temp
        temp = temp->getSiguiente();
    }
    // se retorna el valor de la variable contador
    return contador;
}

// método para agregar nodos por el final
void Lista::agregarFinal(Nodo *n)
{
    // si la cabeza es igual a null
    if(cabeza == NULL)
    {
        // entonces la la cabeza ahora sera el nodo n
        setCabeza(n);
    }
    else
    {
        // sino el ultimo nodo apuntara al nodo n
        ultimo()->setSiguiente(n);
    }
}

// método para buscar por ID
Nodo *Lista::buscarId(int c)
{
    // se inicializa la variable de tipo Nodo temp en la cabeza
    Nodo *temp = cabeza;
    // mientras haya un nodo en la lista
    while(temp != NULL)
    {
        // si el id del nodo actual es igual al valor de la variable c pasada como parametro
        if(temp->getId() == c)
        {
            // se rompe el ciclo
            break;
        }
        // se salta al siguiente nodo de temp
        temp = temp->getSiguiente();
    }
    // se retorna el nodo temp
    return temp;

}

// método para ordenar ascendentemente
void Lista::ordenarAscendentemente(Nodo *n)
{
    // se declaran dos variables de tipo Nodo
    Nodo *actual;
    Nodo *siguiente;
    // se le asigna a la variable actual el valor de n
    actual = n;
    // mientras el siguiente nodo del nodo actual sea diferente a null
    while(actual->getSiguiente() != NULL)
    {
        // el nodo siguiente saltara al siguiente nodo del nodo actual
        siguiente = actual->getSiguiente();
        // mientras el nodo siguiente sea diferente a null
        while(siguiente != NULL)
        {
            // si el semestre del nodo actual es mayor al semestre del nodo siguiente
            if(actual->getSemestre() > siguiente->getSemestre())
            {
                // entonces se cambiara al nodo actual con el siguiente
                cambiar(actual, siguiente);
            }
            // el nodo siguiente saltara a su siguiente nodo
            siguiente = siguiente->getSiguiente();
        }
        // el nodo actual saltara a su siguiente nodo
        actual = actual->getSiguiente();
    }
}

// método para ordenar descendentemente
void Lista::ordenarDescendentemente(Nodo *n)
{
    // se declaran dos variables de tipo Nodo
    Nodo *actual;
    Nodo *siguiente;
    // se le asigna a la variable actual el valor de n
    actual = n;
    // mientras el siguiente nodo del nodo actual sea diferente a null
    while(actual->getSiguiente() != NULL)
    {
        // el nodo siguiente saltara al siguiente nodo del nodo actual
        siguiente = actual->getSiguiente();
        // mientras el nodo siguiente sea diferente a null
        while(siguiente != NULL)
        {
            // si el semestre del nodo actual es menor al semestre del nodo siguiente
            if(actual->getSemestre() < siguiente->getSemestre())
            {
                // entonces se cambiara al nodo actual con el siguiente
                cambiar(actual, siguiente);
            }
            // el nodo siguiente saltara a su siguiente nodo
            siguiente = siguiente->getSiguiente();
        }
        // el nodo actual saltara a su siguiente nodo
        actual = actual->getSiguiente();
    }
}

// método para cambiar los nodos
void Lista::cambiar(Nodo *p1, Nodo *p2)
{
    // creo un nuevo nodo para poder realizar la copia
    Nodo *temp = new Nodo();
    // le asigno al nodo temp los datos del nodo actual (p1)
    temp->copiar(p1);
    // le asigno al nodo p1 los datos del nodo siguiente (p2)
    p1->copiar(p2);
    // le asigno al nodo p2 los datos del temp
    p2->copiar(temp);
}

// método para calcular el promedio general
float Lista::promedioGeneral()
{
    // se inicializa la variable de tipo Nodo temp en la cabeza
    Nodo *temp = cabeza;
    // se inicializa una variable de tipo float en 0
    float suma = 0;
    // mientras haya un nodo en la lista
    while(temp != NULL)
    {
        // se le acumulara a la variable suma el valor de suma mas el valor del promedio del nodo temp
        suma += temp->promedio();
        // se salta al siguiente nodo de temp
        temp = temp->getSiguiente();
    }
    // se retorna el valor de la variable suma entre el total de nodos
    return suma/contarNodos();
}

// método para eliminar nodo
void Lista::eliminar(Nodo *n)
{
    // se declara una variable de tipo Nodo llamada anterior
    Nodo *anterior;
    // si promedio del nodo n es igual al promedio general
    if(n->promedio() == promedioGeneral())
    {
        // si el nodo nd es igual a la cabeza
        if(n  == cabeza)
        {
            // entonces, la cabeza saltara a su siguiente (saltaria a null)
            cabeza = cabeza->getSiguiente();
        }
        else
        {
            // sino, el nodo anterior tendra el valor de la cabeza
            anterior = cabeza;
            // mientras el siguiente nodo del anterior sea difente al nodo nd
            while(anterior->getSiguiente() != n)
            {
                // entonces se salta al siguiente nodo del anterior
                anterior = anterior->getSiguiente();
            }
            // el siguiente del anterior ahora sera el siguiente nodo de nd
            anterior->setSiguiente(n->getSiguiente());
        }
        // el anterior del siguiente nodo de nd ahora sera el nodo anterior
        n->setSiguiente(NULL);
    }
}

// método para limpiar toda la lista
void Lista::limpiar()
{
    // mientras haya un nodo en la lista
    while(cabeza != NULL)
    {
        // se elimina la cabeza
        eliminar(cabeza);
    }
}
