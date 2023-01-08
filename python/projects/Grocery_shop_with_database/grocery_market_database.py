import csv
from tabulate import tabulate
print("-"*(10),"Grocery_shop","-"*(10))
labels = ['Elements','Quantity','Price']
with open("grocery_market.csv","r") as f:
    reader_file = csv.reader(f)
    grocery_list = list(zip(*reader_file))
#grocery contents
grocery_elements=[]
grocery_quantities=[]
grocery_costs=[]
grocery_shop=[
    grocery_elements,
    grocery_quantities,
    grocery_costs
]
#customer bill
customer_element=[]
customer_quantity=[]
customer_cost=[]
customer_list=[
    customer_element,
    customer_quantity,
    customer_cost
]
a=len(grocery_list[0])
total_cost=0
#grocery shop modes
print("For user mode please press 1")
print("For owner mode please press 2")
print("To quit please press 0")
press=int(input("Please enter your choice:"))
#if press is one that mean we are in the user mode
main_menu=True
if press==1:
    #convert csv to list of lists to use it in the programe
    grocery_shop =[list(i) for i in grocery_list]
    grocery_elements = grocery_shop[0]
    #pop element 0 which is the label of elements
    grocery_elements.pop(0)
    grocery_quantities = grocery_shop[1]
    #pop element 0 which is the label of quantity
    grocery_quantities.pop(0)
    grocery_quantities = [eval(i) for i in grocery_quantities]
    grocery_costs = grocery_shop[2]
    #pop element 0 which is the label of cost
    grocery_costs.pop(0)
    grocery_costs = [eval(i) for i in grocery_costs]
    grocery_shop=[grocery_elements,grocery_quantities,grocery_costs]
    print("-"*(10),"Welcome","-"*(10))
    while(True):
        print("To show our products press 1")
        print("To buy our products press 2")
        print("To print your bill press 3")
        print("To quit please press 0")
        press=int(input("Please enter your choice:"))
        if press==1:
            #show the products
            for i in grocery_shop:
                print(*i)
            print("Do you want any thing else:")
            print("Press 1 to continue shopping")
            print("Press 2 to exit")
            press=int(input("Please enter your choice:"))    
            if press==1:
                main_menu=True
            elif press==2:
                main_menu=False   
            else:
                print("Wrong choice\n")
                main_menu=False
        elif press==2:
            counter=0
            print("Our grocery shop contains:")
            print(grocery_shop)
            while(main_menu==True):
                #buy products and check if he wants anything else
                element=str(input("Enter the element type:"))
                for i in range(len(grocery_elements)):
                    if element==grocery_elements[i]:
                        customer_element.insert(counter,element)
                        quantity=int(input("Enter the element quantity:"))
                        if quantity<=grocery_quantities[i]:
                            customer_quantity.insert(counter,quantity)
                            customer_cost.insert(counter,quantity*grocery_costs[i])
                            total_cost +=quantity*grocery_costs[i]
                            grocery_quantities[i]-=quantity
                            with open("customer.csv",'w',newline='') as file_2:
                                file1_writer = csv.writer(file_2)
                                file1_writer.writerow(labels)
                                file1_writer.writerows(zip(*customer_list))
                        else:
                            print("Sorry we have not enough quantity")
                if not customer_element:
                    print("Sorry the element is not exist")
                print("Do you want any thing else:")
                print("Press 1 to continue shopping")
                print("Press 2 to exit")
                press=int(input("Please enter your choice:"))
                if press==1:
                    main_menu=True
                    counter+=1
                elif press==2:
                    main_menu=False
                else:
                    print("Wrong choice\n")
                    main_menu=False
        elif press==3:
            #print to the user his bill
            with open('ITI_Bill.txt','w') as bill:
                bill.write("ITI SHOP Fatora\n")
                bill.write(tabulate(zip(*customer_list), headers=labels, tablefmt="grid"))
                bill.write("\nTotal cost ="+str(total_cost))
        elif press==0:
            break
#if press is two that means we are in the owner mode
elif press==2:
    password=int(input("Enter your password:"))
    #convert csv to list of lists to use it in the programe
    grocery_shop =[list(i) for i in grocery_list]
    grocery_elements = grocery_shop[0]
    #pop element 0 which is the label of elements
    grocery_elements.pop(0)
    grocery_quantities = grocery_shop[1]
    #pop element 0 which is the label of quantity
    grocery_quantities.pop(0)
    grocery_quantities = [eval(i) for i in grocery_quantities]
    grocery_costs = grocery_shop[2]
    #pop element 0 which is the label of cost
    grocery_costs.pop(0)
    grocery_costs = [eval(i) for i in grocery_costs]
    grocery_shop=[grocery_elements,grocery_quantities,grocery_costs]
    #check the user is the owner or not
    if password==1234:
        print("-"*(10),"Welcome","-"*(10))
        while(True):
            print("Press 1 to add new product")
            print("Press 2 to show our products")
            print("Press 3 to add quantity in such a product")
            print("Press 4 to change cost in such a product")
            print("Press 0 to exit")
            press=int(input("Please enter your choice:"))
            if press==1:
                #add a new product with all its information
                element=str(input("Enter the element type:"))
                grocery_elements.insert(a,element)
                quantity=int(input("Enter the element quantity:"))
                grocery_quantities.insert(a,quantity)
                cost=int(input("Enter the price:"))
                grocery_costs.insert(a,cost)
                a+=1
                print("Do you want any thing else:")
                print("Yes:press 1")
                print("No:press 2")
                press=int(input("Please enter your choice:"))
                if press==1:
                    continue
                elif press==2:
                    break
                else:
                    print("Wrong choice\n")
                    break
            elif press==2:
                #show the products
                print(grocery_shop)
                print("Do you want any thing else:")
                print("Yes:press 1")
                print("No:press 2")
                press=int(input("Please enter your choice:"))
                if press==1:
                    continue
                elif press==2:
                    break
                else:
                    print("Wrong choice\n")
                    break
            elif press==3:
                #change the quantity or add quantity in such a product
                element=str(input("Enter the element type:"))
                for i in range(len(grocery_elements)):
                    if element==grocery_elements[i]:
                        quantity=int(input("Enter the element quantity:"))
                        grocery_quantities[i]=quantity
                print("Do you want any thing else:")
                print("Yes:press 1")
                print("No:press 2")
                press=int(input("Please enter your choice:"))
                if press==1:
                    continue
                elif press==2:
                    break
                else:
                    print("Wrong choice\n")
                    break
            elif press==4:
                #change the price in such a product
                element=str(input("Enter the element type:"))
                for i in range(len(grocery_elements)):
                    if element==grocery_elements[i]:
                        cost=int(input("Enter the price:"))
                        grocery_costs[i]=cost
                print("Do you want any thing else:")
                print("Yes:press 1")
                print("No:press 2")
                press=int(input("Please enter your choice:"))
                if press==1:
                    continue
                elif press==2:
                    break
                else:
                    print("Wrong choice\n")
                    break
            elif press==0:
                break
    else:
        #this means that it is not the owner and the system is locked
        print("Sorry you are not the owner:(")
        quit()
elif press==0:
    quit()
with open("grocery_market.csv",'w',newline='') as file_1:
    file_writer = csv.writer(file_1)
    file_writer.writerow(labels)
    file_writer.writerows(zip(*grocery_shop))

