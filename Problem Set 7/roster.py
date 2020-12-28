# Made by siraponte

from sys import argv
from cs50 import SQL

# Check if usage is correct
if (len(argv) != 2):
    
    print("Usage: python roster.py house")
    exit()
    
# Take access to sql database
db = SQL("sqlite:///students.db")

# Create sql command
sql = "SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first"

# Store house name into val
val = argv[1]

# Store characters list into a dictionary
char_list = db.execute(sql, val)

# Loop through characters
for i in range(len(char_list)):
    
    # Check if character has a midde name
    if (char_list[i].get("middle") == None):
        
        # Print name
        print(char_list[i].get("first"), char_list[i].get("last"), end='')
    
    else:
        
        # Print name
        print(char_list[i].get("first"), char_list[i].get("middle"), char_list[i].get("last"), end='')
    
    # Print birth
    print(", born " + str(char_list[i].get("birth")))
