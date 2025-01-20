import requests
import math
import mysql.connector
from bs4 import BeautifulSoup


# url = 'https://www.sportschau.de/live-und-ergebnisse/fussball/deutschland-bundesliga//live-und-ergebnisse/fussball/deutschland-bundesliga/se5823/2010-2011//live-und-ergebnisse/fussball/deutschland-bundesliga/se51884/2023-2024/ro148505/spieltag/md1/spiele-und-ergebnisse/'


# Verbindung zur Datenbank herstellen
mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="Hollenthon1!",
    database="Fussball"
)

# SQL-Abfrage, um alle Links aus der Tabelle Links_season zu erhalten
query = "SELECT Link FROM Links_all WHERE season >= 2008"
# Cursor erstellen
mycursor = mydb.cursor()
year = "SELECT season FROM Links_all"


# SQL-Abfrage ausführen
mycursor.execute(query)

# Alle Ergebnisse abrufen
links_result = mycursor.fetchall()

mycursor.execute(year)
year_of_match = mycursor.fetchall()

j = 14018
k = 1526

for element in links_result:
	url = f'https://www.sportschau.de/{element[0]}'
	print(url)
	response = requests.get(url)
	soup = BeautifulSoup(response.text, 'html.parser')
	# Listen erstellen
	team_home_list = []
	match_result_home_list = []
	team_away_list = []
	match_result_away_list = []
	matchresultlist = []

	# Die relevanten Elemente mit den entsprechenden Klassen finden
	team_home_elements = soup.find_all(class_='team-name-home')
	print(team_home_elements)
	match_result_elements = soup.find_all(class_='match-result-0')
	team_away_elements = soup.find_all(class_='team-name-away')


	

	# Inhalte in die Listen speichern
	for element in team_home_elements:
		team_home_list.append(element.text.strip()) 

	num_elements = 2 * len(team_home_list)

	for element in match_result_elements:
		matchresultlist.append(element.text.strip())

	print(matchresultlist)


	for element in team_away_elements:
		team_away_list.append(element.text.strip())

	for i in range(0, num_elements):
		if i % 2 == 0:
			match_result_home_list.append(matchresultlist[i])
		else:
			match_result_away_list.append(matchresultlist[i])

		
	select_query = "SELECT id FROM Tore WHERE id = %s"
	mycursor.execute(select_query, (j,))
	existing_record = mycursor.fetchone()

	# Ausgabe der Listen
	print('Team Home:', team_home_list)
	print('Match Result Home:', match_result_home_list)
	print('Team Away:', team_away_list)
	print('Match Result Away:', match_result_away_list)



	insert_query = "INSERT INTO Tore (id, Mannschaft, Gegner, Tore_mannschaft, GoalsGegner, season) VALUES (%s, %s, %s, %s, %s, %s)"

	for i in range (0, int(num_elements / 2 )):
		
	# Cursor erstellen
		mycursor = mydb.cursor()
		print(str(team_home_list[i])+ " : " + str(match_result_home_list[i]) + " :: " + str(match_result_away_list[i]) + " : " + str(team_away_list[i]))	
		print (year_of_match[k][0])
		values = (j, team_home_list[i], team_away_list[i], match_result_home_list[i], match_result_away_list[i][0], year_of_match[k][0])

		
		if existing_record:
			print(f"Datensatz mit id={j} existiert bereits. Überspringen oder aktualisieren?")
		else:
		# Befehl ausführen
			mycursor.execute(insert_query, values)

	# Änderungen in der Datenbank speichern
		mydb.commit()

		j += 1
	k += 1	

	# Verbindung schließen
mydb.close()
		
