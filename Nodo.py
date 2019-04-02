class Nodo:
    
    def __init__(self,nombre,cualidad):
        self.nombre = nombre
        self.cualidad = cualidad
        self.nodoIzquierdo = None
        self.nodoDerecho = None

    def getNombre(self):
        return self.nombre

    def getCualidad(self):
        return self.cualidad

    def setNodoIzquierdo(self,nodo):
        self.nodoIzquierdo = nodo

    def getNodoIzquierdo(self):
        return self.nodoIzquierdo

    def setNodoDerecho(self,nodo):
        self.nodoDerecho = nodo
    
    def getNodoDerecho(self):
        return self.nodoDerecho
    
    
