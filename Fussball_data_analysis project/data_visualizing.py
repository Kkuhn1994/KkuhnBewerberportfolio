import requests
import math 
import matplotlib.pyplot as plt
import numpy as np
import mysql.connector

x = '1. FC Köln'

mydb = mysql.connector.connect(
    host="localhost",
    user="root",
    password="Hollenthon1!",
    database="Fussball"
)

    # Cursor erstellen
mycursor = mydb.cursor()
query_season = f"SELECT season FROM `{x}`;"
mycursor.execute(query_season)
season = mycursor.fetchall()
season = [item[0] for item in season]
print(season)
query_win = f"SELECT number_win FROM `{x}`;"
mycursor.execute(query_win)
win = mycursor.fetchall()
win = [item[0] for item in win]
print(win)
query_lose = f"SELECT number_lose FROM `{x}`;"
mycursor.execute(query_lose)
lose = mycursor.fetchall()
lose = [item[0] for item in lose]
print(lose)
query_even = f"SELECT number_even FROM `{x}`;"
mycursor.execute(query_even)
even = mycursor.fetchall()
even = [item[0] for item in even]
print(even)
mydb.close()
plt.plot(season, win)
plt.plot(season, lose)
plt.plot(season, even)
plt.show()
