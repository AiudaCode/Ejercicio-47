public class Nodo
{
    // se declaran los atributos privados de la clase
    private int id;
    private String nombre;
    private int semestre;
    private float [] notas;
    private Nodo siguiente;
    
    public Nodo()
    {
        // le asignamos valores por defecto a los atributos de la clase en el constructor
        id = 0;
        nombre = "";
        semestre = 0;
        notas = new float[3];
        siguiente = null;
    }
    
    // metodos Setters y Getters
    public void setId(int val)
    {
        id = val;
    }
    
    public int getId()
    {
        return id;
    }
    
    public void setNombre(String val)
    {
        nombre = val;
    }
    
    public String getNombre()
    {
        return nombre;
    }
    
    public void setSemestre(int val)
    {
        semestre = val;
    }
    
    public int getSemestre()
    {
        return semestre;
    }
    
    public void setNotas(int pos, float val)
    {
        notas[pos] = val;
    }
    
    public float getNotas(int pos)
    {
        return notas[pos];
    }
    
    public void setSiguiente(Nodo val)
    {
        siguiente = val;
    }
    
    public Nodo getSiguiente()
    {
        return siguiente;
    }
    
    // método para copiar la información de un nodo
    public void copiar(Nodo nd)
    {
        id = nd.getId();
        nombre = nd.getNombre();
        semestre = nd.getSemestre();
        for (int i = 0; i < 3; i++)
        {
            notas[i] = nd.getNotas(i);
        }
    }
    
    // método para calcular el promedio
    public float promedio()
    {
        float suma = 0;
        for (int i = 0; i < 3; i++)
        {
            suma += getNotas(i);
        }
        return suma/3;
    }
}