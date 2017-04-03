
import javax.swing.JOptionPane;

public class Main
{
    // método para llenar un nodo
    public static void llenar(Nodo n, Lista obj)
    {
        int id, sem;
        float nota;
        do
        {
            id = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite identificación:"));
        }
        while(obj.validarId(id) == true);//si validarId() retorna TRUE entonces la id esta utilizada.
        n.setId(id);
        // se pide en pantalla el nombre
        String nom = JOptionPane.showInputDialog(null, "Digite su nombre:");
        // se encapsula la variable nom
        n.setNombre(nom);
        // se pide en pantalla el semetres
        sem = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite su semestre"));
        // se encapsula la variable sem
        n.setSemestre(sem);
        // se itera 3 veces con el ciclo for
        for (int i = 0; i < 3;  i++)
        {
            // se pedira la nota de nuevo si digita una nota menor a 0 ó mayor a 5
            do
            {
                nota = Float.parseFloat(JOptionPane.showInputDialog("Digite la nota " + (i+1)));
            }
            while (nota < 0 || nota > 5);
            // se encapsula en la posicion i el valor de la variable nota
            n.setNotas(i, nota);
        }
    }
    
    // método para mostrar la información de un nodo
    public static void mostrar(Nodo n)
    {
        String datosNodo = "";
        datosNodo += String.valueOf(
            "ID: " + n.getId() + "\n" +
            "Nombre: " + n.getNombre() + "\n" +
            "Semestre: " + n.getSemestre() + "\n" +
            "Nota 1: " + n.getNotas(0) + "\n" +
            "Nota 2: " + n.getNotas(1) + "\n" +
            "Nota 2: " + n.getNotas(2) + "\n" +
            "Promedio: " + n.promedio() + "\n\n");
        JOptionPane.showMessageDialog(null, "=========== INFORMACÓN DE LOS NODOS DE LA LISTA =========== \n"+ datosNodo);
    }
    
    // método para listar la información de todos los nodos de la lista
    public static void listar(Nodo n)
    {
        Nodo temp = n;
        while(temp != null)
        {
            mostrar(temp);
            temp = temp.getSiguiente();
        }
    }
    
    // método para mostrar el menu de opciones
    public static int menu()
    {
        int opcion = 0;
        do
        {
            opcion = Integer.parseInt(JOptionPane.showInputDialog("=========== SELECCIONE UNA OPCIÓN DEL MENÚ =========== \n" +
            "1. Registrar estudiante.\n" +
            "2. Buscar por ID.\n" +
            "3. Mostar estudiantes aprobados ordenados ascendemente por el semestre.\n" +
            "4. Mostar estudiantes con promedio superior al promedio de notas ordenados descendemente por el semestre.\n" +
            "5. Eliminar estudiantes con promedio de notas igual al promedio general.\n" +
            "6. Mostrar toda la lista\n" +
            "7. Salir\n\n" +
            " Seleccione una opción del 1 al 7:"));
        }
        while(opcion < 1 || opcion > 7);
        return opcion;
    }
    
    public static void main(String[] args)
    {
        // se crea un objeto de la clase Lista (Instanciación)
        Lista obj = new Lista();
        // se declaran 2 variables de tipo entero opcion e id
        int opcion, id;
        // se declara una variable de tipo string nombre
        String nombre;
        // se declara una variable de tipo Nodo aux
        Nodo aux;
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
                    obj.agregarFinal(aux);
                    break;
                case 2:
                    id = Integer.parseInt(JOptionPane.showInputDialog("Digite ID del estudiante que quiere agregar: "));
                    aux = obj.buscarId(id);
                    if(aux != null)
                    {
                        mostrar(aux);
                    }
                    else
                    {
                        JOptionPane.showMessageDialog(null, "La ID NO se encuentra en la lista");
                    }
                    break;
                case 3:
                    aux = obj.getCabeza();
                    if(aux == null)
                    {
                        JOptionPane.showMessageDialog(null, "No hay estudiantes matriculados");
                    }
                    else
                    {
                        if(obj.contarNodos() > 1)
                        {
                            aux = obj.getCabeza();
                            obj.ordenarAscendentemente(aux);
                            while(aux != null)
                            {
                                if (aux.promedio() >= 3)
                                {
                                    mostrar(aux);
                                }
                                aux = aux.getSiguiente();
                            }
                        }
                        else
                        {
                            JOptionPane.showMessageDialog(null, "Solo hay un estudiante, agregue por lo menos 1 estudiante mas para ordenar");
                        }
                    }
                    break;
                case 4:
                    aux = obj.getCabeza();
                    if(aux == null)
                    {
                        JOptionPane.showMessageDialog(null, "No hay estudiantes matriculados");
                    }
                    else
                    {
                        if(obj.contarNodos() > 1)
                        {
                            aux = obj.getCabeza();
                            obj.ordenarDescendentemente(aux);
                            while(aux != null)
                            {
                                if (aux.promedio() > obj.promedioGeneral())
                                {
                                    mostrar(aux);
                                }
                                aux = aux.getSiguiente();
                            }
                        }
                        else
                        {
                            JOptionPane.showMessageDialog(null, "Solo hay un estudiante, agregue por lo menos 1 estudiante mas para ordenar");
                        }
                    }
                    break;
                case 5:
                    aux = obj.getCabeza();
                    if(aux == null)
                    {
                        JOptionPane.showMessageDialog(null, "No hay estudiantes matriculados");
                    }
                    else
                    {
                        obj.limpiar();
                    }
                    break;
                case 6:
                    aux = obj.getCabeza();
                    if(aux == null)
                    {
                        JOptionPane.showMessageDialog(null, "No hay estudiantes matriculados");
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
}