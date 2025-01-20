import requests
import math
import mysql.connector
from bs4 import BeautifulSoup


# Überprüfen, ob die Tabelle existiert
def table_exists(table_name):
    print(table_name)
    mycursor.execute(f"SHOW TABLES LIKE '{table_name}'")
    return mycursor.fetchone() is not None

# Verbindung zur Datenbank herstellen
mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="Hollenthon1!",
    database="Fussball"
)
    # Cursor erstellen
mycursor = mydb.cursor()
Mannschaften ="SELECT Mannschaft FROM Tore"
mycursor.execute(Mannschaften)
teams = set(mycursor.fetchall())
teams = list(teams)
print(teams)

for x in teams:
    x = x[0]
    print("x=" + x)
    create_win = f"CREATE TABLE `{x}_win` (id INT , Gegner VARCHAR(255), Tore_Köln INT, Tore_gegner INT, Tordifferenz INT, season INT);"
    create_lose = f"CREATE TABLE `{x}_lose` (id INT , Gegner VARCHAR(255), Tore_Köln INT, Tore_gegner INT, Tordifferenz INT, season INT);"
    create = f"CREATE TABLE `{x}_even` (id INT , Gegner VARCHAR(255), Tore_Köln INT, Tore_gegner INT, Tordifferenz INT, season INT);"
    if table_exists(f'{x}_win'):
        print(x)
        print(f"DROP TABLE {x}_win")
        droptable = f"DROP TABLE `{x}_win`"
        print(x)
        mycursor.execute(droptable)
        print(x)
    if table_exists(f'{x}_lose'):
        droptable = f"DROP TABLE `{x}_lose`"
        mycursor.execute(droptable)
    if table_exists(f"{x}_even"):
        droptable = f"DROP TABLE `{x}_even`"
        mycursor.execute(droptable)
    mycursor.execute(create_win)
    mycursor.execute(create_lose)
    mycursor.execute(create)
    i = 0
    ii = 0
    iii = 0
    for year in range (1963, 2024):
        print(x)
        # SQL-Abfrage, um alle Links aus der Tabelle Links_season zu erhalten
        query_win1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' AND Tore_mannschaft > GoalsGegner  and season = {year};"
        query_win2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner  and season = {year};"
        query_tore_gegner1 = f"SELECT GoalsGegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft > GoalsGegner  and season = {year};"
        query_tore_gegner2 = f"SELECT Tore_mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner  and season = {year};"
        query_season_gegner1 = f"SELECT season FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft > GoalsGegner  and season = {year};"
        query_season_gegner2 = f"SELECT season FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner  and season = {year};"
        query_tore_mannschaft1 = f"SELECT Tore_mannschaft FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft > GoalsGegner  and season = {year};"
        query_tore_mannschaft2 = f"SELECT GoalsGegner FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner  and season = {year};"




        query_lose1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft < GoalsGegner and season = {year};"
        query_lose2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft > GoalsGegner and season = {year};"
        query_tore_gegner1_lose = f"SELECT GoalsGegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft < GoalsGegner and season = {year};"
        query_tore_gegner2_lose = f"SELECT Tore_mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft > GoalsGegner and season = {year};"
        query_season_gegner1_lose = f"SELECT season FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft < GoalsGegner and season = {year};"
        query_season_gegner2_lose = f"SELECT season FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft > GoalsGegner and season = {year};"
        query_tore_mannschaft1_lose = f"SELECT Tore_mannschaft FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft < GoalsGegner and season = {year};"
        query_tore_mannschaft2_lose = f"SELECT GoalsGegner FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft > GoalsGegner and season = {year};"




        query_even1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft = GoalsGegner and season = {year};"
        query_even2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft = GoalsGegner and season = {year};"
        query_tore_gegner1_even = f"SELECT GoalsGegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft = GoalsGegner and season = {year};"
        query_tore_gegner2_even = f"SELECT Tore_mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft = GoalsGegner and season = {year};"
        query_season_gegner1_even = f"SELECT season FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft = GoalsGegner and season = {year};"
        query_season_gegner2_even = f"SELECT season FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft = GoalsGegner and season = {year};"
        query_tore_mannschaft1_even = f"SELECT Tore_mannschaft FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft = GoalsGegner and season = {year};"
        query_tore_mannschaft2_even = f"SELECT GoalsGegner FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft = GoalsGegner and season = {year};"



        # SQL-Abfrage ausführen

        mycursor.execute(query_win1)

        Gegner_win = mycursor.fetchall()
        mycursor.execute(query_win2)
        Gegner_win += mycursor.fetchall()
        print(Gegner_win)
        mycursor.execute(query_tore_gegner1)

        Tore_Gegner = mycursor.fetchall()
        mycursor.execute(query_tore_gegner2)
        Tore_Gegner += mycursor.fetchall()
        print(Tore_Gegner)
        mycursor.execute(query_tore_mannschaft1)

        Tore_mannschaft = mycursor.fetchall()
        mycursor.execute(query_tore_mannschaft2)
        Tore_mannschaft += mycursor.fetchall()
        print(Tore_mannschaft)
        mycursor.execute(query_season_gegner1)
        season = mycursor.fetchall()
        mycursor.execute(query_season_gegner2)
        season += mycursor.fetchall()


        j = 0
        for element in Gegner_win:
            insert_win = f"INSERT INTO `{x}_win` (id, Gegner, Tore_Köln, Tore_gegner, Tordifferenz, season) VALUES (%s, %s, %s, %s, %s, %s)"
            values = (i, element[0], Tore_mannschaft[j][0], Tore_Gegner[j][0], abs(Tore_mannschaft[j][0] - Tore_Gegner[j][0]), season[j][0] )
            mycursor.execute(insert_win, values)
            i += 1
            # Änderungen in der Datenbank speichern
            mydb.commit()

    
        mycursor.execute(query_lose1)
        Gegner_lose = mycursor.fetchall()
        mycursor.execute(query_lose2)
        Gegner_lose += mycursor.fetchall()
        print(Gegner_lose)
        mycursor.execute(query_tore_gegner1_lose)

        Tore_Gegner = mycursor.fetchall()
        mycursor.execute(query_tore_gegner2_lose)
        Tore_Gegner += mycursor.fetchall()
        print(Tore_Gegner)
        mycursor.execute(query_tore_mannschaft1_lose)

        Tore_mannschaft = mycursor.fetchall()
        mycursor.execute(query_tore_mannschaft2_lose)
        Tore_mannschaft += mycursor.fetchall()
        print(Tore_mannschaft)
        mycursor.execute(query_season_gegner1)
        season = mycursor.fetchall()
        mycursor.execute(query_season_gegner2)
        season += mycursor.fetchall()


        j = 0
        for element in Gegner_lose:
            insert_lose = f"INSERT INTO `{x}_lose` (id, Gegner, Tore_Köln, Tore_gegner, Tordifferenz, season) VALUES (%s, %s, %s, %s, %s, %s)"
            values = (ii, element[0], Tore_mannschaft[j][0], Tore_Gegner[j][0], abs(Tore_mannschaft[j][0] - Tore_Gegner[j][0]), season[j][0] )
            mycursor.execute(insert_lose, values)
            ii += 1
            # Änderungen in der Datenbank speichern
            mydb.commit()

        mycursor.execute(query_even1)
        Gegner_even = mycursor.fetchall()
        mycursor.execute(query_even2)
        Gegner_even += mycursor.fetchall()
        print(Gegner_even)
        mycursor.execute(query_tore_gegner1_even)

        Tore_Gegner = mycursor.fetchall()
        mycursor.execute(query_tore_gegner2_even)
        Tore_Gegner += mycursor.fetchall()
        print(Tore_Gegner)
        mycursor.execute(query_tore_mannschaft1_even)

        Tore_mannschaft = mycursor.fetchall()
        mycursor.execute(query_tore_mannschaft2_even)
        Tore_mannschaft += mycursor.fetchall()
        print(Tore_mannschaft)
        mycursor.execute(query_season_gegner1_even)
        season = mycursor.fetchall()
        mycursor.execute(query_season_gegner2_even)
        season += mycursor.fetchall()
        mycursor.execute(query_season_gegner1)
        season = mycursor.fetchall()
        mycursor.execute(query_season_gegner2)
        season += mycursor.fetchall()

        j = 0
        for element in Gegner_even:
            insert_even = f"INSERT INTO `{x}_even` (id, Gegner, Tore_Köln, Tore_gegner, Tordifferenz, season) VALUES (%s, %s, %s, %s, %s, %s)"
            values = (iii, element[0], Tore_mannschaft[j][0], Tore_Gegner[j][0], abs(Tore_mannschaft[j][0] - Tore_Gegner[j][0]), season[j][0] )
            mycursor.execute(insert_even, values)
            iii += 1
            # Änderungen in der Datenbank speichern
            mydb.commit()

mydb.close()