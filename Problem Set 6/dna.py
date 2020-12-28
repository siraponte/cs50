# Made by siraponte

from sys import argv
import csv

# Check if usage is correct
if (len(argv) != 3):
    
    print("Usage: python dna.py database.csv sequence.txt")

# Open sequence txt 
with open(argv[2]) as sequence_data:
    
    # Copy the sequence into 'sequence'
    sequence_reader = csv.reader(sequence_data)
    for row in sequence_reader:
        sequence = row

# Create a patients' list and a STRs' list
patients_dictionary = []
STR = []
# i for all loops
i = 0

# Open database csv 
with open(argv[1]) as database_data:
    
    # Copy database into patients' list
    patients_dictionary = list(csv.reader(database_data))

# Copy all STRs into STRs' list
for i in range(len(patients_dictionary[0])):
    
    STR.append(patients_dictionary[0][i])
    i += 1

# List to contain a match counter 
STR_counter = []

# List to contain max consecutive matches
STR_max_consecutive = []

# Loop through STRs
for i in range(len(STR)):
    
    # Jump first member of STRs' list ('name')
    if (i < 1):
        i += 1
    
    # To compare STR's with each gruop of letters of the string
    left = 0
    right = len(STR[i])
    
    # To keep track of matches
    count = 0
    consecutive_count = 0
    max_consecutive = 0
    
    # Loop though string's letters (The number of letters in equal to STR's length)
    for x in range(len(sequence[0])):
        
        # Check if STR is equal to first group of letters
        if (STR[i] == sequence[0][left:right]):
            
            # Jump to next group of letters
            count += 1
            left += len(STR[i])
            right += len(STR[i])
            
            consecutive_count = 1
            
            # Keep track of consecutive counts
            while (STR[i] == sequence[0][left:right]):
                
                count += 1
                consecutive_count += 1
                left += len(STR[i])
                right += len(STR[i])
            
            # Save new consecutive counts if it's greater than older
            if (consecutive_count > max_consecutive):
              
                max_consecutive = consecutive_count
                consecutive_count = 0
               
            else:
              
                consecutive_count = 0
        
        # If STR isn't equal to first group of letters , go forward only 1 letter   
        else:
            
            left += 1
            right += 1
    
    # Save count and max consecutive into two lists 
    STR_counter.append(count)
    STR_max_consecutive.append(max_consecutive)
    
# Loop through patients's dictionary
for i in range(len(patients_dictionary)):
    
    # Jump first row of the dictionary ('name' 'STR1' 'STR2'...)
    if (i == 0):
        
        continue
    
    # To keep track of matches
    match = 0
    
    # Loop through member of each dictionary's rows
    for j in range(len(STR)):
        
        # Jump first member of row ('Name of the patient')
        if (j == 0):
            
            continue
        
        # Check if STR max is equal to patient's DNA STR
        if (int(STR_max_consecutive[j]) == int(patients_dictionary[i][j])):
            
            match += 1
            j += 1
           
        # If isn't , go on 
        else:
            
            j += 1
          
        # If all STR fit together 
        if (match == (len(STR) - 1)):
            
            # Print patienr's name and return 
            print(patients_dictionary[i][0])
            exit()
         
# Else say no match
print("No match")
exit()
