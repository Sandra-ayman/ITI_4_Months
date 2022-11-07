print("-"*(10),"Grocery_shop","-"*(10))
#grocery contents
grocery_elements=["apple","banana","cherry"]
grocery_quantities=[60,70,10]
grocery_costs=[10,5,20]
grocery_shop={
    "elements":grocery_elements,
    "quantities":grocery_quantities,
    "costs":grocery_costs
    }
#customer bill
customer_element=[]
customer_quantity=[]
customer_cost=[]
customer_list={
    "customer elements":customer_element,
    "customer quantity":customer_quantity,
    "customer cost":customer_cost
    }
a=3
#grocery shop modes
print("For user mode please press 1")
print("For owner mode please press 2")
print("To quit please press 0")
press=int(input("Please enter your choice:"))
#if press is one that mean we are in the user mode
main_menu=True
if press==1:
    print("-"*(10),"Welcome","-"*(10))
    while(True):
        print("To show our products press 1")
        print("To buy our products press 2")
        print("To print your bill press 3")
        print("To quit please press 0")
        press=int(input("Please enter your choice:"))
        if press==1:
            print(grocery_shop)
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
                element=str(input("Enter the element type:"))
                for i in range(a):
                    if element==grocery_elements[i]:
                        customer_element.insert(counter,element)
                        quantity=int(input("Enter the element quantity:"))
                        if quantity<=grocery_quantities[i]:
                            customer_quantity.insert(counter,quantity)
                            customer_cost.insert(counter,quantity*grocery_costs[i])
                            grocery_quantities[i]-=quantity
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
            print("Dear customer :)\n","Your bill:")
            print(customer_list)
        elif press==0:
            break
elif press==2:
    password=int(input("Enter your password:"))
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
                element=str(input("Enter the element type:"))
                for i in range(a):
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
                element=str(input("Enter the element type:"))
                for i in range(a):
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
        print("Sorry you are not the owner:(")
        quit()
elif press==0:
    quit()


