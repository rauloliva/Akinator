import mysql.connector as mysql

class database:
    def __init__(self):
        nombre = ""
        cualidad = ""
        self.mydb = mysql.connect(
            host="localhost",
            user="root",
            passwd="raulito10",
            database="tree"
        )
        self.mycursor = self.mydb.cursor()
    
    def insert(self,datos):
        sql = "INSERT INTO heroes (nombre, cualidades) VALUES (%s, %s)"
        val = (datos[0],datos[1])
        self.mycursor.execute(sql, val)
        self.mydb.commit()

    def getMatriz(self):
        self.mycursor.execute('SELECT nombre,cualidades from heroes')
        datosHeroes = self.mycursor.fetchall()
        return datosHeroes