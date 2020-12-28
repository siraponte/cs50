# Made by siraponte

# Import get_int
from cs50 import get_int
    
# Loop to take an input between 1 and 8
while True:
    n = get_int("Height : ")
    if (n > 0 and n < 9):
        break

# Loop to print the pyramid
i = 0
for i in range(1, n + 1):
    spaces = n - i
    hastags = i
    
    # Print left spaces
    print(" " * spaces, end='')
    
    # Print left hastags
    print("#" * hastags, end='')
    
    # Print central spaces
    print("  ", end='')
    
    # Print right hastags
    print("#" * hastags)
