import requests
import mysql.connector
from bs4 import BeautifulSoup

mydb = mysql.connector.connect(
		host="localhost",
		user="root",
		password="Hollenthon1!",
		database="Fussball"
	)

# Cursor erstellen
mycursor = mydb.cursor()

# SQL-Abfrage, um alle Links aus der Tabelle Links_season zu erhalten
query = "SELECT Link FROM Links_season"

# SQL-Abfrage ausführen
mycursor.execute(query)

# Alle Ergebnisse abrufen
links_result = mycursor.fetchall()



# Jetzt kannst du die URLs verwenden, z.B. drucken
for link in links_result:
    print(link[0])
i = 0
year = 1963
for element in links_result:
	url = f'https://www.sportschau.de{element[0]}'
	print(url)
	# Anfrage an die Webseite senden
	response = requests.get(url)

	# BeautifulSoup verwenden, um den HTML-Code zu analysieren
	soup = BeautifulSoup(response.text, 'html.parser')



	# Alle value-Attribute der option-Elemente sammeln
	season_values = []

	# Nach allen select-Elementen mit der Klasse season-navigation suchen
	select_elements = soup.find_all('select', class_='round-navigation')

	insert_query = "INSERT INTO Links_all (id, Link, season) VALUES (%s, %s, %s)"
	
	# Iteriere durch die gefundenen select-Elemente
	for select_element in select_elements:

		
		# Extrahiere die value-Attribute der option-Elemente und füge sie zu season_values hinzu
		season_values.extend([option['value'] for option in select_element.find_all('option')])

	j = 0
	for element in season_values:
		mycursor = mydb.cursor()
		print(year)
		values = (i, season_values[j], year)
		mycursor.execute(insert_query, values)
		mydb.commit()
		i += 1
		j += 1
	year += 1




	# Verbindung schließen
mydb.close()

	# Drucke alle gefundenen value-Attribute
