import requests
import math
import mysql.connector
from bs4 import BeautifulSoup
import matplotlib.pyplot as plt
import numpy as np

# Verbindung zur Datenbank herstellen
mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="Hollenthon1!",
    database="Fussball"
)
    # Cursor erstellen
mycursor = mydb.cursor()

Team1 = input("Hier Team 1 eingeben:")
Team2 = input("Hier Team 2 eingeben:")
year = 2020


x = Team1

	#  Vergleich Win - Lose Gesamt
query_win1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' AND Tore_mannschaft > GoalsGegner  and season < {year};"
query_win2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner  and season < {year};"


mycursor.execute(query_win1)
Gegner_besiegt = mycursor.fetchall()
mycursor.execute(query_win2)
Gegner_besiegt += mycursor.fetchall()
Zahl_siege = 0


for y in Gegner_besiegt:
	Zahl_siege += 1

print("Anzahl Siege Gesamt: ")
print(Zahl_siege)
print(x)

query_lose1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft < GoalsGegner and season < {year};"
query_lose2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft > GoalsGegner and season < {year};"
mycursor.execute(query_lose1)
Gegner_verloren = mycursor.fetchall()
mycursor.execute(query_lose2)
Gegner_verloren += mycursor.fetchall()
Zahl_niederlagen = 0

for y in Gegner_verloren:
	Zahl_niederlagen += 1

print("Anzahl Niederlagen Gesamt: ")
print(Zahl_niederlagen)

query_even1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft = GoalsGegner and season < {year};"
query_even2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft = GoalsGegner and season < {year};"
mycursor.execute(query_even1)
Gegner_unentschieden = mycursor.fetchall()
mycursor.execute(query_even2)
Gegner_unentschieden += mycursor.fetchall()
Zahl_unentschiedenn = 0

for y in Gegner_unentschieden:
	Zahl_unentschiedenn += 1

print("Anzahl unentschiedenn Gesamt: ")
print(Zahl_unentschiedenn)

Zahl_gesamt = Zahl_siege + Zahl_niederlagen + Zahl_unentschiedenn
if Zahl_siege != 0:
		win_ = Zahl_gesamt / Zahl_siege
if Zahl_niederlagen != 0:
		lose_ = Zahl_gesamt / Zahl_niederlagen
if Zahl_unentschiedenn != 0:
		even_ = Zahl_gesamt / Zahl_unentschiedenn

# Daten für die Sektoren
sektoren = [win_, lose_, even_]  # Beispielwerte, die die Prozentsätze der Sektoren repräsentieren

# Farben für die Sektoren
farben = ['green', 'red', 'yellow']

# Labels für die Legende
labels = ['win', 'lose', 'even']

plt.subplot(3, 6, 2)
# Erstellen des Pie Charts
plt.pie(sektoren, labels=labels, colors=farben, autopct='%1.1f%%', startangle=140)

# Titel hinzufügen
plt.title(f'win lose {x} Gesamt')

# Legende hinzufügen
plt.legend()



Gegner_besiegt = []
Gegner_unentschieden = []
Gegner_verloren = []

last_year = year - 4
for year in range (last_year, year + 1):
	print(year)
	#  Vergleich Win - Lose Letzten 5 Jahre
	query_win1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' AND Tore_mannschaft > GoalsGegner  and season = {year};"
	query_win2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner  and season = {year};"


	mycursor.execute(query_win1)
	Gegner_besiegt = mycursor.fetchall()
	mycursor.execute(query_win2)
	Gegner_besiegt += mycursor.fetchall()
	Zahl_siege = 0


	for y in Gegner_besiegt:
		Zahl_siege += 1

	print("Anzahl Siege Gesamt: ")
	print(Zahl_siege)
	print(x)

	query_lose1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft < GoalsGegner and season = {year};"
	query_lose2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft > GoalsGegner and season = {year};"
	mycursor.execute(query_lose1)
	Gegner_verloren = mycursor.fetchall()
	mycursor.execute(query_lose2)
	Gegner_verloren += mycursor.fetchall()
	Zahl_niederlagen = 0

	for y in Gegner_verloren:
		Zahl_niederlagen += 1

	print("Anzahl Niederlagen Gesamt: ")
	print(Zahl_niederlagen)

	query_even1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft = GoalsGegner and season = {year};"
	query_even2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft = GoalsGegner and season = {year};"
	mycursor.execute(query_even1)
	Gegner_unentschieden = mycursor.fetchall()
	mycursor.execute(query_even2)
	Gegner_unentschieden += mycursor.fetchall()
	Zahl_unentschiedenn = 0

for i, current_year in enumerate(range(year - 5, year + 1)):
    query_win1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' AND Tore_mannschaft > GoalsGegner  and season = {current_year};"
    query_win2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner  and season = {current_year};"
    if i < 3:
        j = 7
    if i >= 3:
        j = 10
    mycursor.execute(query_win1)
    Gegner_besiegt = mycursor.fetchall()
    mycursor.execute(query_win2)
    Gegner_besiegt += mycursor.fetchall()
    Zahl_siege = len(Gegner_besiegt)
    plt.subplot(3, 6, i + j)
    plt.pie([Zahl_siege, Zahl_niederlagen, Zahl_unentschiedenn], labels=labels, colors=farben, autopct='%1.1f%%', startangle=140)
    plt.title(f'{x} {current_year}')
    






x = Team2
year = 2020

	#  Vergleich Win - Lose Gesamt
query_win1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' AND Tore_mannschaft > GoalsGegner  and season < {year};"
query_win2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner  and season < {year};"


mycursor.execute(query_win1)
Gegner_besiegt = mycursor.fetchall()
mycursor.execute(query_win2)
Gegner_besiegt += mycursor.fetchall()
Zahl_siege = 0


for y in Gegner_besiegt:
	Zahl_siege += 1

print("Anzahl Siege Gesamt: ")
print(Zahl_siege)
print(x)

query_lose1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft < GoalsGegner and season < {year};"
query_lose2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft > GoalsGegner and season < {year};"
mycursor.execute(query_lose1)
Gegner_verloren = mycursor.fetchall()
mycursor.execute(query_lose2)
Gegner_verloren += mycursor.fetchall()
Zahl_niederlagen = 0

for y in Gegner_verloren:
	Zahl_niederlagen += 1

print("Anzahl Niederlagen Gesamt: ")
print(Zahl_niederlagen)

query_even1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft = GoalsGegner and season < {year};"
query_even2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft = GoalsGegner and season < {year};"
mycursor.execute(query_even1)
Gegner_unentschieden = mycursor.fetchall()
mycursor.execute(query_even2)
Gegner_unentschieden += mycursor.fetchall()
Zahl_unentschiedenn = 0

for y in Gegner_unentschieden:
	Zahl_unentschiedenn += 1

print("Anzahl unentschiedenn Gesamt: ")
print(Zahl_unentschiedenn)

Zahl_gesamt = Zahl_siege + Zahl_niederlagen + Zahl_unentschiedenn
if Zahl_siege != 0:
		win_ = Zahl_gesamt / Zahl_siege
if Zahl_niederlagen != 0:
		lose_ = Zahl_gesamt / Zahl_niederlagen
if Zahl_unentschiedenn != 0:
		even_ = Zahl_gesamt / Zahl_unentschiedenn

# Daten für die Sektoren
sektoren = [win_, lose_, even_]  # Beispielwerte, die die Prozentsätze der Sektoren repräsentieren

# Farben für die Sektoren
farben = ['green', 'red', 'yellow']

# Labels für die Legende
labels = ['win', 'lose', 'even']

plt.subplot(3, 6, 5)
# Erstellen des Pie Charts
if (Zahl_gesamt != 0):
	plt.pie(sektoren, labels=labels, colors=farben, autopct='%1.1f%%', startangle=140)

# Titel hinzufügen
plt.title(f'win lose {x} Gesamt')

# Legende hinzufügen
plt.legend()

Gegner_besiegt = []
Gegner_unentschieden = []
Gegner_verloren = []

last_year = year - 4
for year in range (last_year, year + 1):
	print(year)
	#  Vergleich Win - Lose Letzten 5 Jahre
	query_win1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' AND Tore_mannschaft > GoalsGegner  and season = {year};"
	query_win2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner  and season = {year};"


	mycursor.execute(query_win1)
	Gegner_besiegt = mycursor.fetchall()
	mycursor.execute(query_win2)
	Gegner_besiegt += mycursor.fetchall()
	Zahl_siege = 0


	for y in Gegner_besiegt:
		Zahl_siege += 1

	print("Anzahl Siege Gesamt: ")
	print(Zahl_siege)
	print(x)

	query_lose1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft < GoalsGegner and season = {year};"
	query_lose2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft > GoalsGegner and season = {year};"
	mycursor.execute(query_lose1)
	Gegner_verloren = mycursor.fetchall()
	mycursor.execute(query_lose2)
	Gegner_verloren += mycursor.fetchall()
	Zahl_niederlagen = 0

	for y in Gegner_verloren:
		Zahl_niederlagen += 1

	print("Anzahl Niederlagen Gesamt: ")
	print(Zahl_niederlagen)

	query_even1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' and Tore_mannschaft = GoalsGegner and season = {year};"
	query_even2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft = GoalsGegner and season = {year};"
	mycursor.execute(query_even1)
	Gegner_unentschieden = mycursor.fetchall()
	mycursor.execute(query_even2)
	Gegner_unentschieden += mycursor.fetchall()
	Zahl_unentschiedenn = 0

for i, current_year in enumerate(range(year - 5, year + 1)):
    query_win1 = f"SELECT Gegner FROM Tore WHERE Mannschaft = '{x}' AND Tore_mannschaft > GoalsGegner  and season = {current_year};"
    query_win2 = f"SELECT Mannschaft FROM Tore WHERE Gegner = '{x}' and Tore_mannschaft < GoalsGegner  and season = {current_year};"
    if i < 3:
        j = 10
    if i >= 3:
        j = 13
    mycursor.execute(query_win1)
    Gegner_besiegt = mycursor.fetchall()
    mycursor.execute(query_win2)
    Gegner_besiegt += mycursor.fetchall()
    Zahl_siege = len(Gegner_besiegt)

    # Dynamische Berechnung der Subplot-Position basierend auf der Anzahl der Jahre
    plt.subplot(3, 6, i + j) 

    plt.pie([Zahl_siege, Zahl_niederlagen, Zahl_unentschiedenn], labels=labels, colors=farben, autopct='%1.1f%%', startangle=140)
    plt.title(f'{current_year}')
    




	# Das Diagramm anzeigen
plt.show()