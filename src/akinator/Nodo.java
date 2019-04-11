package akinator;

public class Nodo {

    private String nombre;
    private String cualidad;
    private Nodo nodoIzquierdo;
    private Nodo nodoDerecho;

    public Nodo(String nombre, String cualidad) {
        this.nombre = nombre;
        this.cualidad = cualidad;
    }

    public String getNombre() {
        return this.nombre;
    }

    public String getCualidad() {
        return this.cualidad;
    }

    public void setNodoIzquierdo(Nodo nodo) {
        this.nodoIzquierdo = nodo;
    }

    public void setNodoDerecho(Nodo nodo) {
        this.nodoDerecho = nodo;
    }

    public Nodo getNodoIzquierdo() {
        return this.nodoIzquierdo;
    }

    public Nodo getNodoDerecho() {
        return this.nodoDerecho;
    }
}
