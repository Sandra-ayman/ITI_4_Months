import tkinter as tk
import csv
from tabulate import tabulate
from PIL import ImageTk, Image
bill = 0
#function to count and calculate total cost for small cup
def smallCup_quantity():
    global bill
    smallCup_quantity.counter+=1
    smallCup_quantity.cost=smallCup_quantity.counter*5
    bill+=smallCup_quantity.cost
    label4.config(text="Total cost: "+str(bill))
smallCup_quantity.counter=0
smallCup_quantity.cost=0
#function to count and calculate total cost for medium cup
def mediumCup_quantity():
    global bill
    mediumCup_quantity.counter+=1
    mediumCup_quantity.cost=mediumCup_quantity.counter*6
    bill+=mediumCup_quantity.cost
    label4.config(text="Total cost: "+str(bill))
mediumCup_quantity.counter=0
mediumCup_quantity.cost=0
#function to count and calculate total cost for large cup
def largeCup_quantity():
    global bill
    largeCup_quantity.counter+=1
    largeCup_quantity.cost=largeCup_quantity.counter*7
    bill+=largeCup_quantity.cost
    label4.config(text="Total cost: "+str(bill))
largeCup_quantity.counter=0
largeCup_quantity.cost=0
#create window
window_1 = tk.Tk()
window_1.title("Sugar cane shop")
window_1.geometry('800x800')
global label4
#back ground
my_bg = Image.open('background_sugarCane.png')
resized_image = my_bg.resize((800,800),Image.ANTIALIAS)
bg = ImageTk.PhotoImage(resized_image)
label_5 = tk.Label(window_1,image=bg)
label_5.place(x=0,y=0,relwidth=1,relheight=1)

#create images
smallphoto = tk.PhotoImage(file='sugar_cane_cup.png')
smallphoto = smallphoto.subsample(5,5)
mediumphoto = tk.PhotoImage(file='sugar_cane_cup.png')
mediumphoto = mediumphoto.subsample(4,4)
largephoto = tk.PhotoImage(file='sugar_cane_cup.png')
largephoto = largephoto.subsample(3,3)
#create labels at the top of window
my_font=('Times',14,'bold')
label1=tk.Label(window_1 , text = "Small cup (5 L.E) ",font=my_font,bg='#FFFFFF',fg='#8B8B1A')
label1.grid(row=1, column=0,pady=25,padx=25)
label2=tk.Label(window_1 , text = "Medium cup (6 L.E) ",font=my_font,bg='#FFFFFF',fg='#8B8B1A')
label2.grid(row=1, column=1,pady=25,padx=25)
label3=tk.Label(window_1 , text = "Large cup (7 L.E) ",font=my_font,bg='#FFFFFF',fg='#8B8B1A')
label3.grid(row=1, column=2,pady=25,padx=25)
#make photo as a button to count the number of cups 
B1=tk.Button(window_1 , text = "Small cup (5 L.E) " ,bd = '5' ,image=smallphoto, command = smallCup_quantity)
B1.grid(row=2, column=0,pady=25,padx=25)
B2=tk.Button(window_1 , text = "Medium cup (6 L.E) " ,bd = '5' ,image=mediumphoto, command = mediumCup_quantity)
B2.grid(row=2, column=1,pady=25,padx=25)
B3=tk.Button(window_1 , text = "Large cup (7 L.E) " ,bd = '5' ,image=largephoto, command = largeCup_quantity)
B3.grid(row=2, column=2,pady=25,padx=25)
#label for total cost
label4 =tk.Label(window_1 , text = " ",font=my_font,bg='#CDCD00',fg='#47473C')
label4.grid(row=3,column=1,pady=25,padx=25)
window_1.mainloop()
labels = [' ','Small cup','Medium cup','Large cup']
sugar_cane_cost=['Cost','5','6','7']
sugar_cane_quantity=['Quantity',smallCup_quantity.counter,mediumCup_quantity.counter,largeCup_quantity.counter]
sugar_cane_list=[sugar_cane_cost,sugar_cane_quantity]
total_cost=smallCup_quantity.cost + mediumCup_quantity.cost + largeCup_quantity.cost
#write the order in csv file
with open('sugar_cane.csv','w',newline='') as sc_csv:
    sc_writer = csv.writer(sc_csv)
    sc_writer.writerow(labels)
    sc_writer.writerow(sugar_cane_cost)
    sc_writer.writerow(sugar_cane_quantity)
#print the bill in txt file
with open('Sugar_cane_bill.txt','w') as sc_bill:
    sc_bill.write("Sugar cane SHOP Fatora\n")
    sc_bill.write(tabulate(sugar_cane_list, headers=labels, tablefmt="grid"))
    sc_bill.write("\nTotal cost = "+str(total_cost))