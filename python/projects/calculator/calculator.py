from pickle import FALSE, TRUE


print("For programmer mode press 1")
print("For standard mode press 2")
press=int(input("Enter your choice:"))
out=True
if(press==1):
    number_1 = int(input("Enter the first number:"))
    number_2 = int(input("Enter the second number:"))
    while(out!=False):
        print("To Add two numbers press 1")
        print("To Sub two numbers press 2")
        print("To Multiply two numbers press 3")
        print("To Divide two numbers press 4")
        print("To AND two numbers press 5")
        print("To OR two numbers press 6")
        print("To XOR two numbers press 7")
        print("To Complement a number press 8")
        press=int(input("Enter your choice:"))
        if press==1:
            result = number_1 + number_2
            print(bin(number_1)," + ",bin(number_2)," = ",bin(result))
        elif press==2:
            result = number_1 - number_2
            print(bin(number_1)," - ",bin(number_2)," = ",bin(result))
        elif press==3 :
            result = number_1 * number_2
            print(bin(number_1)," * ",bin(number_2)," = ",bin(result))
        elif press==4 :
            if number_2==0:
                print("can not do this operation")
            else:
                result = int(number_1 / number_2)
                print(bin(number_1)," / ",bin(number_2)," = ",bin(result))
        elif press==5:
            result = number_1 & number_2
            print(bin(number_1)," & ",bin(number_2)," = ",bin(result))
        elif press==6:
            result = number_1 | number_2
            print(bin(number_1)," | ",bin(number_2)," = ",bin(result))
        elif press==7:
            result = number_1 ^ number_2
            print(bin(number_1)," ^ ",bin(number_2)," = ",bin(result))
        elif press==8:
            print("Which number do you want to complement (1: first number,2: second number):")
            press=int(input("Enter your choice:"))
            if press==1:
                result = ~(number_1)
                print("~(",bin(number_1),")= ",bin(result))
            elif press==2:
                result = ~(number_2)
                print("~(",bin(number_2),")= ",bin(result))
            else:
                print("Wrong choice!")
        else:
            print("Wrong choice!\n","please try again\n")
        print("Do you want anything else(please enter 1 for yes and 2 for no):")
        press=int(input())
        if press==1:
            out=True
        elif press==2:
            out=False
        else:
            print("Wrong choice!\n","please try again later\n")
            out=False
elif press==2:
    number_1 = int(input("Enter the first number:"))
    number_2 = int(input("Enter the second number:"))
    while(out!=False):
        print("To Add two numbers press 1")
        print("To Sub two numbers press 2")
        print("To Multiply two numbers press 3")
        print("To Divide two numbers press 4")
        press=int(input("Enter your choice:"))
        if press==1:
            result = number_1 + number_2
            print(number_1," + ",number_2," = ",result)
        elif press==2:
            result = number_1 - number_2
            print(number_1," - ",number_2," = ",result)
        elif press==3 :
            result = number_1 * number_2
            print(number_1," * ",number_2," = ",result)
        elif press==4 :
            if number_2==0:
                print("can not do this operation")
            else:
                result =number_1 / number_2
                print(number_1," / ",number_2," = ",result)
        else:
            print("Wrong choice!\n","please try again\n")
        print("Do you want anything else(please enter 1 for yes and 2 for no):")
        press=int(input())
        if press==1:
            out=True
        elif press==2:
            out=False
        else:
            print("Wrong choice!\n","please try again later\n")
            out=False
