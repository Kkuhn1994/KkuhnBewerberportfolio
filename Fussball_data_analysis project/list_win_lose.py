import requests
import math
import mysql.connector
from bs4 import BeautifulSoup

def table_exists(table_name):
    print(table_name)
    mycursor.execute(f"SHOW TABLES LIKE '{table_name}'")
	
    return mycursor.fetchone() is not None

def sum_of(x):
	sum = 0
	for element in x:
		sum += element[0]
	return sum

def len_of(x):
	i = 0
	for element in x:
		i += 1
	return i

x = '1. FC Köln'
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
	create = f"CREATE TABLE IF NOT EXISTS `{x}` (id INT , season INT, `Tore_{x}` INT, Tore_gegner INT, Tordifferenz INT, number_win INT,  number_lose INT, number_even INT);"
	# SQL-Abfrage, um alle Links aus der Tabelle Links_season zu erhalten
	i = 0
	if table_exists(f'{x}'):
		print(x)
		droptable = f"DROP TABLE `{x}`"
		mycursor.execute(droptable)
	mycursor.execute(create)
	for year in range (1963 ,2024):
		print(x)
		query_win1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' AND Tore_mannschaft > GoalsGegner and season = {year};"
		query_win2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner and season = {year};"
		query_tore_gegner1 = f"SELECT GoalsGegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft > GoalsGegner AND season = {year};"
		query_tore_gegner2 = f"SELECT Tore_mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner AND season = {year};"
		query_season_gegner1 = f"SELECT season FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft > GoalsGegner AND season = {year};"
		query_season_gegner2 = f"SELECT season FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner AND season = {year};"
		query_tore_mannschaft1 = f"SELECT Tore_mannschaft FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft > GoalsGegner AND season = {year};"
		query_tore_mannschaft2 = f"SELECT GoalsGegner FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner AND season = {year};"




		query_lose1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft < GoalsGegner AND season = {year};"
		query_lose2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft > GoalsGegner AND season = {year}"
		query_tore_gegner1_lose = f"SELECT GoalsGegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft < GoalsGegner AND season = {year};"
		query_tore_gegner2_lose = f"SELECT Tore_mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft > GoalsGegner AND season = {year};"
		query_season_gegner1_lose = f"SELECT season FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft < GoalsGegner AND season = {year};"
		query_season_gegner2_lose = f"SELECT season FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft > GoalsGegner AND season = {year};"
		query_tore_mannschaft1_lose = f"SELECT Tore_mannschaft FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft < GoalsGegner AND season = {year};"
		query_tore_mannschaft2_lose = f"SELECT GoalsGegner FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft > GoalsGegner AND season = {year};"




		query_even1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft = GoalsGegner AND season = {year};"
		query_even2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft = GoalsGegner AND season = {year};"
		query_tore_gegner1_even = f"SELECT GoalsGegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft = GoalsGegner AND season = {year};"
		query_tore_gegner2_even = f"SELECT Tore_mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft = GoalsGegner AND season = {year};"
		query_season_gegner1_even = f"SELECT season FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft = GoalsGegner AND season = {year};"
		query_season_gegner2_even = f"SELECT season FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft = GoalsGegner AND season = {year};"
		query_tore_mannschaft1_even = f"SELECT Tore_mannschaft FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft = GoalsGegner AND season = {year};"
		query_tore_mannschaft2_even = f"SELECT GoalsGegner FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft = GoalsGegner AND season = {year};"

		

		mycursor.execute(query_win1)

		Gegner_win = mycursor.fetchall()
		mycursor.execute(query_win2)
		Gegner_win += mycursor.fetchall()
		Gegner_win = len_of(Gegner_win)
		print(Gegner_win)
		mycursor.execute(query_lose1)

		Gegner_lose = mycursor.fetchall()
		mycursor.execute(query_lose2)
		Gegner_lose += mycursor.fetchall()
		lose = len_of(Gegner_lose)
		print(lose)
		mycursor.execute(query_even1)

		Gegner_even = mycursor.fetchall()
		mycursor.execute(query_even2)
		Gegner_even += mycursor.fetchall()
		even = len_of(Gegner_even)
		print(even)
		mycursor.execute(query_tore_gegner1)

		Tore_Gegner = mycursor.fetchall()
		mycursor.execute(query_tore_gegner2)
		Tore_Gegner += mycursor.fetchall()
		mycursor.execute(query_tore_gegner1_lose)
		Tore_Gegner += mycursor.fetchall()
		mycursor.execute(query_tore_gegner2_lose)
		Tore_Gegner += mycursor.fetchall()
		mycursor.execute(query_tore_gegner1_even)
		Tore_Gegner += mycursor.fetchall()
		mycursor.execute(query_tore_gegner2_even)
		Tore_Gegner += mycursor.fetchall()
		Tore_Gegner = sum_of(Tore_Gegner)
		print(Tore_Gegner)
		mycursor.execute(query_tore_mannschaft1)

		Tore_mannschaft = mycursor.fetchall()
		mycursor.execute(query_tore_mannschaft2)
		Tore_mannschaft += mycursor.fetchall()
		mycursor.execute(query_tore_mannschaft1_lose)

		Tore_mannschaft += mycursor.fetchall()
		mycursor.execute(query_tore_mannschaft2_lose)
		Tore_mannschaft += mycursor.fetchall()
		mycursor.execute(query_tore_mannschaft1_even)

		Tore_mannschaft += mycursor.fetchall()
		mycursor.execute(query_tore_mannschaft2_even)
		Tore_mannschaft += mycursor.fetchall()
		Tore_mannschaft = sum_of(Tore_mannschaft)
		print(Tore_mannschaft)
		insert_win = f"INSERT INTO `{x}` (id,season, `Tore_{x}`, Tore_gegner, Tordifferenz, number_win, number_lose, number_even) VALUES (%s, %s, %s, %s, %s, %s, %s, %s)"
		values = (i,year, Tore_mannschaft, Tore_Gegner, abs(Tore_mannschaft - Tore_Gegner), Gegner_win, lose, even)
		mycursor.execute(insert_win, values)
		mydb.commit()
		i += 1
mydb.close()