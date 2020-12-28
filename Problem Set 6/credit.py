# Made by siraponte

from cs50 import get_string

# Take card number as string to highligt digits easly
n = get_string("Credit Card Number: ")

# Check if credit card number's length is right
if (int(n) != 13 or int(n) != 15 or int(n) != 16):
    
    print("INVALID")

# Sum_ to take sum of digits
sum_ = 0

# To jump between odd and even digits
# Even and odd refer to position , starting from the right 
jump_ = 0

# Loop through digits
for i in range(len(n) + 1):
    
    # Takes and multiply even digits
    double = int(n[-i]) * 2
    
    # Takes odd digits
    not_double = int(n[-i])
    
    # Check if i is equal 1 (With 0 can't take last digits cause -0 does not exist)
    if i > 0:
        
        # If jump is equal 0 then the digit is odd
        if jump_ == 0:
            
            # Adds the digit to sum
            sum_ += not_double
            
            # After an odd digit , comes an even digit
            jump_ = 1
            
        # Else is even
        else:
            
            # Check if the double of the digit has 1 or 2 digits
            if double > 9:
                
                # If it has 2 digits , take double as string to separate them easly
                s_double = str(double)
                
                # And adds to sum the separate digits es.(12 -> 1 + 2)
                sum_ += int(s_double[0]) + int(s_double[1])
                
                # After an even digit , comes an odd digit
                jump_ = 0
                
            else:
                
                # If it has 1 digit , adds to sum
                sum_ += double
                
                # After an even digit , comes an odd digit
                jump_ = 0

# Check if final digit of sum is 0
if ((sum_ % 10) == 0):
    
    # Check for credit card number's length
    if len(n) == 13:
        
        # Check if card's number start with 4 
        if (int(n[0]) == 4):
            
            print("VISA")
            
        else:
            
            print("INVALID")
    
    elif len(n) == 15:
        
        # Check if card's number start with 34 or 37
        if (int(n[0:2]) == 34 or int(n[0:2]) == 37):
            
            print("AMEX")
            
        else:
            
            print("INVALID")
    
    elif len(n) == 16:
        
        # Check if card's number start with 4
        if (int(n[0]) == 4):
            
            print("VISA")
        
        # Check if card's number start with 51,52,53,54 or 55
        elif (int(n[0:2]) == 51 or int(n[0:2]) == 52 or int(n[0:2]) == 53 or int(n[0:2]) == 54 or int(n[0:2]) == 55):
            
            print("MASTERCARD")
        
        else:
            
            print("INVALID")
