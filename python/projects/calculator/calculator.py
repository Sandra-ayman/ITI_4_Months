#This project for a calculator in programmer mode and standard mode
print("For programmer mode press 1")
print("For standard mode press 2")
press=int(input("Enter your choice:"))
#if press==1 this means we are in a programmer mode and every number prints in binary
if(press==1):
    while(True):
        print("To Add two numbers press 1")
        print("To Sub two numbers press 2")
        print("For number conversion press 3")
        print("To AND two numbers press 4")
        print("To OR two numbers press 5")
        print("To XOR two numbers press 6")
        print("To Complement a number press 7")
        print("For number shifting press 8")
        press=int(input("Enter your choice:"))
        if press==1:
            number_1 = int(input("Enter the first number in binary representation:"),2)
            number_2 = int(input("Enter the second number in binary representation:"),2)
            result = number_1 + number_2
            print(bin(number_1)," + ",bin(number_2)," = ",bin(result))
        elif press==2:
            number_1 = int(input("Enter the first number in binary representation:"),2)
            number_2 = int(input("Enter the second number in binary representation:"),2)
            result = number_1 - number_2
            print(bin(number_1)," - ",bin(number_2)," = ",bin(result))
        elif press==3 :
            print("To convert from binary to decimal press 1")
            print("To convert from binary to octal press 2")
            print("To convert from binary to hex press 3")
            print("To convert from decimal to binary press 4")
            print("To convert from octal to binary press 5")
            print("To convert from hex to binary press 6")
            print("To convert from decimal to octal press 7")
            print("To convert from decimal to hex press 8")
            print("To convert from octal to decimal press 9")
            print("To convert from hex to decimal press 10")
            print("To convert from octal to hex press 11")
            print("To convert from hex to octal press 12")
            press=int(input("Enter your choice:"))
            if press==1:
                number_1 = int(input("Enter the first number in binary representation:"),2)
                print("Dec: ",int(number_1))
            elif press==2:
                number_1 = int(input("Enter the first number in binary representation:"),2)
                print("Oct: ",oct(number_1))
            elif press==3:
                number_1 = int(input("Enter the first number in binary representation:"),2)
                print("Hex: ",hex(number_1))
            elif press==4:
                number_1 = int(input("Enter a number in decimal representation:"))
                print("Bin: ",bin(number_1))
            elif press==5:
                number_1 = int(input("Enter a number in octal representation:"),8)
                print("Bin: ",bin(number_1))
            elif press==6:
                number_1 = int(input("Enter a number in hex representation:"),16)
                print("Bin: ",bin(number_1))
            elif press==7:
                number_1 = int(input("Enter a number in decimal representation:"))
                print("Oct: ",oct(number_1))
            elif press==8:
                number_1 = int(input("Enter a number in decimal representation:"))
                print("Hex: ",hex(number_1))
            elif press==9:
                number_1 = int(input("Enter a number in octal representation:"),8)
                print("Dec: ",int(number_1))
            elif press==10:
                number_1 = int(input("Enter a number in hex representation:"),16)
                print("Dec: ",int(number_1))
            elif press==11:
                number_1 = int(input("Enter a number in octal representation:"),8)
                print("Hex: ",hex(number_1))
            elif press==12:
                number_1 = int(input("Enter a number in hex representation:"),16)
                print("Oct: ",oct(number_1))
            else:
                print("Wrong choice\n")
        elif press==4:
            number_1 = int(input("Enter the first number in binary representation:"),2)
            number_2 = int(input("Enter the second number in binary representation:"),2)
            result = number_1 & number_2
            print(bin(number_1)," & ",bin(number_2)," = ",bin(result))
        elif press==5:
            number_1 = int(input("Enter the first number in binary representation:"),2)
            number_2 = int(input("Enter the second number in binary representation:"),2)
            result = number_1 | number_2
            print(bin(number_1)," | ",bin(number_2)," = ",bin(result))
        elif press==6:
            number_1 = int(input("Enter the first number in binary representation:"),2)
            number_2 = int(input("Enter the second number in binary representation:"),2)
            result = number_1 ^ number_2
            print(bin(number_1)," ^ ",bin(number_2)," = ",bin(result))
        elif press==7:
            number_1 = int(input("Enter the first number in binary representation:"),2)
            result=~(number_1)
            print("~(",bin(number_1),")= ",bin(result))
        elif press==8:
            print("To shift right press 1")
            print("To shift left press 2")
            press=int(input("Enter your choice:"))
            if press==1:
                number_1 = int(input("Enter the first number in binary representation:"),2)
                number_bits=int(input("Enter the numebr of bits to shift:"))
                result=number_1>>number_bits
                print(bin(number_1),">>",number_bits," = ",bin(result))
            elif press==2:
                number_1 = int(input("Enter the first number in binary representation:"),2)
                number_bits=int(input("Enter the numebr of bits to shift:"))
                result=number_1<<number_bits
                print(bin(number_1),"<<",number_bits," = ",bin(result))
            else:
                print("Wrong choice\n")
        else:
            print("Wrong choice!\n","please try again\n")
        #check the user need another opertion or not
        print("Do you want anything else(please enter 1 for yes and 2 for no):")
        press=int(input())
        if press==1:
            continue
        elif press==2:
            break
        else:
            print("Wrong choice\n")
            break
#if press==2 this means we are in a standard mode
elif press==2:
    while(True):
        print("To Add two numbers press 1")
        print("To Sub two numbers press 2")
        print("To Multiply two numbers press 3")
        print("To Divide two numbers press 4")
        press=int(input("Enter your choice:"))
        if press==1:
            number_1 = int(input("Enter the first number:"))
            number_2 = int(input("Enter the second number:"))
            result = number_1 + number_2
            print(number_1," + ",number_2," = ",result)
        elif press==2:
            number_1 = int(input("Enter the first number:"))
            number_2 = int(input("Enter the second number:"))
            result = number_1 - number_2
            print(number_1," - ",number_2," = ",result)
        elif press==3 :
            number_1 = int(input("Enter the first number:"))
            number_2 = int(input("Enter the second number:"))
            result = number_1 * number_2
            print(number_1," * ",number_2," = ",result)
        elif press==4 :
            number_1 = int(input("Enter the first number:"))
            number_2 = int(input("Enter the second number:"))
            #check it gets infinity number or not
            if number_2==0:
                print("can not do this operation")
            else:
                result =number_1 / number_2
                print(number_1," / ",number_2," = ",result)
        else:
            print("Wrong choice!\n","please try again\n")
        #casting here because the binary can't print as a float number
        print("Do you want anything else(please enter 1 for yes and 2 for no):")
        press=int(input())
        if press==1:
            continue
        elif press==2:
            break
        else:
            print("Wrong choice\n")
            break
