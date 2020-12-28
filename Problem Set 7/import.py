# Made by siraponte

from sys import argv
from cs50 import SQL
import csv

# Check if usage is correct
if (len(argv) != 2):
    
    print("Usage: python import.py characters.csv")
    exit()

# Take access to sql database
db = SQL("sqlite:///students.db")

# Open csv file
with open(argv[1]) as characters:
    
    # Save csv file into a list
    char_dictionary = list(csv.reader(characters))
    
# Create sql command
sql = "INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)"

# Create empty char names list
char_names = []
char_name = []

# Loop through characters
for i in range(len(char_dictionary)):
    
    # Split characters' names and save them into char name list
    char_names.append(char_dictionary[i][0].split())

    # Check if character has a middle name
    if (len(char_names[i]) == 2):
        
        # Store names , house and birth into val
        val = (char_names[i][0], None, char_names[i][1], char_dictionary[i][1], char_dictionary[i][2])
        
        # Execute sql query
        db.execute(sql, val)
        
    elif (len(char_names[i]) == 3):
        
        # Store names , house and birth into val
        
        val = (char_names[i][0], char_names[i][1], char_names[i][2], char_dictionary[i][1], char_dictionary[i][2])
        
        # Execute sql query
        db.execute(sql, val)

# Close csv file
characters.close()
