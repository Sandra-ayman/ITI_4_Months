from time import sleep
from os import system, name
def clear():
    if name == 'nt':
        _ = system('cls')
while(True):
    #drawing the up arrow
    a=1
    #drawing the head of the arrow
    for i in range(6,0,-1):
        for j in range(0,i+4,1):
            print(" ",end="")
        for k in range(0,a,1):
            print("*",end="")
        a=a+2
        print("\n")
    #drawing the body of the arrow
    for i in range(0,6,1):
        for j in range(0,10,1):
            print(" ",end="")
        for k in range(0,1):
            print("*",end="")
        print("\n")
    sleep(2)
    clear()
    #drawing the right arrow
    #drawing the head of the arrow
    for i in range(0,6,1):
        for j in range(0,16,1):
            print(" ",end="")
        for k in range(0,i,1):
            print("*",end="")
        print("\n")
    #drawing the body of the arrow
    print(" "*11,end="")
    print("*"*11,end="")
    print("\n")
    for i in range(6,0,-1):
        for j in range(0,16,1):
            print(" ",end="")
        for k in range(i-1,0,-1):
            print("*",end="")
        print("\n")
    sleep(2)
    clear()
    #drawing the down arrow
    #drawing the body of the arrow
    for i in range(0,11,1):
        print(" ",end="\n")
    for i in range(0,6,1):
        for j in range(0,10,1):
            print(" ",end="")
        for k in range(0,1):
            print("*",end="")
        print("\n")
    #drawing the head of the arrow
    for i in range(0,6,1):
        for j in range(0,i+5,1):
            print(" ",end="")
        for k in range(0,a-2,1):
            print("*",end="")
        a=a-2
        print("\n")
    sleep(2)
    clear()
    #drawing the left arrow
    #drawing the head of the arrow
    for i in range(6,0,-1):
        for j in range(0,i,1):
            print(" ",end="")
        for k in range(0,6-i,1):
            print("*",end="")
        print("\n")
    #drawing the body of the arrow
    print("*"*11,end="\n")
    for i in range(6,0,-1):
        for j in range(0,6-i,1):
            print(" ",end="")
        for k in range(0,i,1):
            print("*",end="")
        print("\n")
    sleep(2)
    clear()
        
    
        
    

