import requests
import mysql.connector
from bs4 import BeautifulSoup

url = 'https://www.sportschau.de//live-und-ergebnisse/fussball/deutschland-bundesliga/se39227/2021-2022/spiele-und-ergebnisse/'

# Anfrage an die Webseite senden
response = requests.get(url)

# BeautifulSoup verwenden, um den HTML-Code zu analysieren
soup = BeautifulSoup(response.text, 'html.parser')

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="Hollenthon1!",
    database="Fussball"
)

# Alle value-Attribute der option-Elemente sammeln
season_values = []

# Nach allen select-Elementen mit der Klasse season-navigation suchen
select_elements = soup.find_all('select', class_='season-navigation')

insert_query = "INSERT INTO Links_season (id, Link, Season) VALUES (%s, %s, %s)"
i = 0
# Iteriere durch die gefundenen select-Elemente
for select_element in select_elements:
    mycursor = mydb.cursor()
    
    # Extrahiere die value-Attribute der option-Elemente und füge sie zu season_values hinzu
    season_values.extend([option['value'] for option in select_element.find_all('option')])

season = 1963
    
for select_element in season_values:
    mycursor = mydb.cursor()
    values = (i, season_values[i], season)
    mycursor.execute(insert_query, values)
    mydb.commit()
    i += 1
    season += 1

# Verbindung schließen
mydb.close()

# Drucke alle gefundenen value-Attribute
for value in season_values:

    print(value)

