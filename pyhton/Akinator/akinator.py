from Nodo import Nodo
from Sql import database as DB

def welcome():
    print("-----------------------------")
    print("|Instrucciones              |")
    print("|Verdadero = \'si\' o \'s\'     |")
    print("|Falso = \'no\' o \'n\'         |")
    print("-----------------------------\n")
    print("Piensa en un superheroe\ny yo tratare de adivinar cual es, ¿Estas listo?")

def Victoria():
    print("\n-------------")
    print("|VICTORIA!!!|")
    print("-------------")

def Derrota():
    print("\nMe rindo")
    print("\n¿Dime cual es el nombre de tu superheroe?")
    heroe = input("> ")
    print("\n¿Dime cual es su cualidad?")
    cualidad = input("> ")
    return heroe,cualidad

def StartAgain():
    print("\n¿Quieres jugar otra vez?")
    return input("> ")

def printRecorrido(nodo,size,estado):
    for i in range(size):
        print(nodo.getNombre())
        if nodo.getNodoIzquierdo() != None:
            nodo = nodo.getNodoIzquierdo()
            print("  /")
        else:
            nodo = nodo.getNodoDerecho()
            print("  \\")
    if estado: #if estado = victoria
        print("victoria")
    else:
        print("derrota")


if __name__ == "__main__":
    newGame = True
    while newGame:
        welcome()
        start = input("> ")
        if(start == 'no' or start == 'n'):
            newGame = False
            continue
        
        db = DB()
        datosHeroes = db.getMatriz()

        sizeHeroes = len(datosHeroes)
        sizeArbol = 0

        nodo = Nodo(datosHeroes[0][0],datosHeroes[0][1])
        root = nodo
        victoria = False
        while sizeArbol < sizeHeroes and not victoria:
            sizeArbol += 1
            print(f"\n¿Tu superheroe {nodo.getCualidad()}?")
            respuesta = input("> ")

            if respuesta == 'si' or respuesta == 's':
                print(f"\n¿Tu superheroe es {nodo.getNombre()}?")
                respuesta = input("> ")
                if respuesta == 'si' or respuesta == 's':
                    nodo.setNodoIzquierdo(nodo)
                    Victoria()
                    victoria = True
                else:
                    if sizeArbol == sizeHeroes:
                        datos = Derrota()
                        nodo.setNodoIzquierdo(Nodo(datos[0],datos[1]))
                        nodo = nodo.getNodoIzquierdo()
                        db.insert(datos)
                        continue

                    nodo.setNodoDerecho(Nodo(datosHeroes[sizeArbol][0],datosHeroes[sizeArbol][1]))
                    nodo = nodo.getNodoDerecho()
            else:
                if sizeArbol == sizeHeroes: #if we ran out of heroes
                    datos = Derrota()
                    db.insert(datos)
                    continue
                
                nodo.setNodoDerecho(Nodo(datosHeroes[sizeArbol][0],datosHeroes[sizeArbol][1]))
                nodo = nodo.getNodoDerecho()

        printRecorrido(root,sizeArbol,victoria)
        desicion = StartAgain()
        if desicion == "no" or desicion == "n":
            newGame = False
    
    print("\nGracias por jugar\n")

#C:\Users\ralfr\Desktop\Files\Python\Akinator\akinator.py