from time import sleep
from os import system, name
from tkinter import N
def clear():
    if name == 'nt':
        _ = system('cls')
def right_arrow(n):
    print("\n"*(2))
    for i in range(n-1):
        print(" "*(11),end=' ')
        for j in range(i+1):
            print("*",end=' ')
        print()
    print(" "*(7),end=' ')
    for i in range(n+2):
        print("*",end=' ')
    print()
    for i in range(n-1):
        print(" "*(11),end=' ')
        for j in range(i,n-1):
            print("*",end=' ')
        print()
def left_arrow(n):
    print("\n"*(2))
    for i in range(n-1):
        for j in range(i,n-1):
            print(' ',end=' ')
        for j in range(i+1):
            print('*',end=' ')
        print()
    for i in range(n+2):
        print("*",end=' ')
    print()
    for i in range(n-1):
        for j in range(i+1):
            print(' ',end=' ')
        for j in range(i,n-1):
            print('*',end=' ')
        print()
def up_arrow(n):
    for i in range(n):
        print(' '*(2),end='')
        for j in range(i,n):
            print(' ',end=' ')
        for j in range(i+1):
            print('*',end=' ')
        for j in range(i):
            print('*',end=' ')
        print()
    for i in range(n-1):
        print(' '*(7),end=' ')
        print('*'*(1),end=' ')
        print()
def down_arrow(n):
    print("\n"*(4))
    for i in range(n-1):
        print(' '*(7),end=' ')
        print('*'*(1),end=' ')
        print()
    for i in range(n):
        print(' '*(2),end='')
        for j in range(i+1):
            print(' ',end=' ')
        for j in range(i,n-1):
            print('*',end=' ')
        for j in range(i,n):
            print('*',end=' ')
        print()

while(True):
    left_arrow(3)
    sleep(1)
    clear()
    up_arrow(3)
    sleep(1)
    clear()
    down_arrow(3)
    sleep(1)
    clear()
    right_arrow(3)
    sleep(1)
    clear()
        
        
    
        
        


                        