# Made by siraponte

from cs50 import get_string

# Gets string from user
txt = get_string("Text :")

# l = letters, w = words, s = sentences, L = Letters for 100 words, S = Sentences for 100 words, index = Coleman-Lieun index
l = float(0)
w = float(1)
s = float(0)
L = float(0)
S = float(0)
index = float(0)

# Loop through characters
for i in range(len(txt)):
    
    # Looks for letters
    if txt[i].isalpha():
        
        l += 1
    
    # Looks for words
    elif txt[i] == ' ':
        
        w += 1
    
    # Looks for sentences
    elif (txt[i] == '.' or txt[i] == '?' or txt[i] == '!'):
        
        s += 1
# Proportions 
L = 100 * l / w 
S = 100 * s / w

# Calculate the index
index = round((0.0588 * L) - (0.296 * S) - 15.8)

# Print text's difficulty grade
if 0 < int(index) < 16:
    
    print(f"Grade {index}")
    
elif int(index) >= 16:
    
    print("Grade 16+")
    
elif int(index) < 1:
    
    print("Before Grade 1")
