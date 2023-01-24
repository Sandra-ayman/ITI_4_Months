from tkinter import*
from tkinter import ttk
import tkinter.messagebox

class atm:
    def __init__(self,startWindow):
        self.startWindow = startWindow
        self.startWindow.title(100*" "+ "ATM MACHINE")
        self.startWindow.geometry("811x710+280+0")
        self.startWindow.configure(bg='gainsboro')
        #--------------------Frames--------------------
        mainFrame = Frame(self.startWindow,bd=20,width=784,height=700,relief=RIDGE)
        mainFrame.grid()
        interFrame1 = Frame(mainFrame,bd=7,width=734,height=300,relief=RIDGE)
        interFrame1.grid(row=0, column=0, padx=8)
        interFrame2 = Frame(mainFrame,bd=7,width=734,height=300,relief=RIDGE)
        interFrame2.grid(row=1, column=0, padx=8)
        interFrame1Left = Frame(interFrame1,bd=5,width=190,height=300,relief=RIDGE)
        interFrame1Left.grid(row=0, column=0, padx=8)
        interFrame1Mid = Frame(interFrame1,bd=5,width=200,height=300,relief=RIDGE)
        interFrame1Mid.grid(row=0, column=1, padx=8)
        interFrame1Right = Frame(interFrame1,bd=5,width=190,height=300,relief=RIDGE)
        interFrame1Right.grid(row=0, column=2, padx=8)
        #--------------------Functions--------------------
        passwords = ["1397","3179","7931","9713"]
        def Enter_Pin_Number():
            pinNumber = self.txtReceipt.get("1.0","end-1c")
            if pinNumber in passwords:
                self.txtReceipt.delete("1.0",END)
                self.txtReceipt.insert(END,'\t                ATM MACHINE' + "\n")
                self.txtReceipt.insert(END,'Withdraw cash\t\t\t\t         Loan' + "\n"*5)
                self.txtReceipt.insert(END,'Cash with Receipt\t\t\t\t  Deposit' + "\n"*5)
                self.txtReceipt.insert(END,'Balance \t\t\t      Request New Pin' + "\n"*5)
                self.txtReceipt.insert(END,'Mini statement \t\t\t        Print statement' + "\n\n")
                #--------------------Enable the buttons in two sides--------------------
                #--------------------Buttons in inter frame one left side--------------------
                self.leftArrowImage = PhotoImage(file = "rightarrow.png")
                self.leftArrowButton1 = Button(interFrame1Left, width = 160, height=60, state = NORMAL, image = self.leftArrowImage, command = Withdraw_cash)
                self.leftArrowButton1.grid(row = 0, column = 0, padx = 2, pady = 2)
                self.leftArrowButton2 = Button(interFrame1Left, width = 160, height=60, state = NORMAL, image = self.leftArrowImage, command = Withdraw_cash)
                self.leftArrowButton2.grid(row = 1, column = 0, padx = 2, pady = 2)
                self.leftArrowButton3 = Button(interFrame1Left, width = 160, height=60, state = NORMAL, image = self.leftArrowImage, command = Balance)
                self.leftArrowButton3.grid(row = 2, column = 0, padx = 2, pady = 2)
                self.leftArrowButton4 = Button(interFrame1Left, width = 160, height=60, state = NORMAL, image = self.leftArrowImage, command = Statement)
                self.leftArrowButton4.grid(row = 3, column = 0, padx = 2, pady = 2)
                #--------------------Buttons in inter frame one right side--------------------
                self.rightArrowImage = PhotoImage(file = "leftarrow.png")
                self.rightArrowButton1 = Button(interFrame1Right, width = 160, height=60, state = NORMAL, image = self.rightArrowImage, command = Loan)
                self.rightArrowButton1.grid(row = 0, column = 0, padx = 2, pady = 2)
                self.rightArrowButton2 = Button(interFrame1Right, width = 160, height=60, state = NORMAL, image = self.rightArrowImage, command = Deposite)
                self.rightArrowButton2.grid(row = 1, column = 0, padx = 2, pady = 2)
                self.rightArrowButton3 = Button(interFrame1Right, width = 160, height=60, state = NORMAL, image = self.rightArrowImage, command = Request_New_Pin)
                self.rightArrowButton3.grid(row = 2, column = 0, padx = 2, pady = 2)
                self.rightArrowButton4 = Button(interFrame1Right, width = 160, height=60, state = NORMAL, image = self.rightArrowImage, command = Statement)
                self.rightArrowButton4.grid(row = 3, column = 0, padx = 2, pady = 2)
            else:
                self.txtReceipt.delete("1.0",END)
                self.txtReceipt.insert(END,'Invalid Pin Number')
        def Clear_Screen():
            self.txtReceipt.delete("1.0",END)
            #--------------------Disable the buttons in two sides--------------------
            #--------------------Buttons in inter frame one left side--------------------
            self.leftArrowImage = PhotoImage(file = "rightarrow.png")
            self.leftArrowButton1 = Button(interFrame1Left, width = 160, height=60, state = DISABLED, image = self.leftArrowImage, command = Withdraw_cash)
            self.leftArrowButton1.grid(row = 0, column = 0, padx = 2, pady = 2)
            self.leftArrowButton2 = Button(interFrame1Left, width = 160, height=60, state = DISABLED, image = self.leftArrowImage, command = Withdraw_cash)
            self.leftArrowButton2.grid(row = 1, column = 0, padx = 2, pady = 2)
            self.leftArrowButton3 = Button(interFrame1Left, width = 160, height=60, state = DISABLED, image = self.leftArrowImage, command = Balance)
            self.leftArrowButton3.grid(row = 2, column = 0, padx = 2, pady = 2)
            self.leftArrowButton4 = Button(interFrame1Left, width = 160, height=60, state = DISABLED, image = self.leftArrowImage, command = Statement)
            self.leftArrowButton4.grid(row = 3, column = 0, padx = 2, pady = 2)
            #--------------------Buttons in inter frame one right side--------------------
            self.rightArrowImage = PhotoImage(file = "leftarrow.png")
            self.rightArrowButton1 = Button(interFrame1Right, width = 160, height=60, state = DISABLED, image = self.rightArrowImage, command = Loan)
            self.rightArrowButton1.grid(row = 0, column = 0, padx = 2, pady = 2)
            self.rightArrowButton2 = Button(interFrame1Right, width = 160, height=60, state = DISABLED, image = self.rightArrowImage, command = Deposite)
            self.rightArrowButton2.grid(row = 1, column = 0, padx = 2, pady = 2)
            self.rightArrowButton3 = Button(interFrame1Right, width = 160, height=60, state = DISABLED, image = self.rightArrowImage, command = Request_New_Pin)
            self.rightArrowButton3.grid(row = 2, column = 0, padx = 2, pady = 2)
            self.rightArrowButton4 = Button(interFrame1Right, width = 160, height=60, state = DISABLED, image = self.rightArrowImage, command = Statement)
            self.rightArrowButton4.grid(row = 3, column = 0, padx = 2, pady = 2)
        def Cancel_Button():
            cancel = tkinter.messagebox.askyesno("ATM MACHINE","Confirm if you want to cancel")
            if cancel > 0:
                self.startWindow.destroy()
                return
        def Withdraw_cash():
            Enter_Pin_Number()
            self.txtReceipt.delete("1.0",END)
            self.txtReceipt.focus_set()
        def Loan():
            Enter_Pin_Number()
            self.txtReceipt.delete("1.0",END)
            self.txtReceipt.insert(END,'Loan $')
            self.txtReceipt.focus_set()
        def Deposite():
            Enter_Pin_Number()
            self.txtReceipt.delete("1.0",END)
            self.txtReceipt.focus_set()
        def Request_New_Pin():
            Enter_Pin_Number()
            self.txtReceipt.delete("1.0",END)
            self.txtReceipt.insert(END,'\t\t Welcome to our Bank\n')
            self.txtReceipt.insert(END,'New pin will be send to your home address\n')
            self.txtReceipt.insert(END,'\t\t Thanks for using our Bank\n')
            self.txtReceipt.insert(END,'Withdraw cash\t\t\t\t         Loan' + "\n"*5)
            self.txtReceipt.insert(END,'Cash with Receipt\t\t\t\t  Deposit' + "\n"*5)
            self.txtReceipt.insert(END,'Balance \t\t\t      Request New Pin' + "\n"*5)
            self.txtReceipt.insert(END,'Mini statement \t\t\t        Print statement' + "\n\n")
        def Balance():
            self.txtReceipt.delete("1.0",END)
            self.txtReceipt.insert(END,'\t Welcome to our Bank\n')
            self.txtReceipt.insert(END,'\t 1296$' + "\n")
            self.txtReceipt.insert(END,'\t Thanks for using our Bank\n')
            self.txtReceipt.insert(END,'Withdraw cash\t\t\t\t         Loan' + "\n"*5)
            self.txtReceipt.insert(END,'Cash with Receipt\t\t\t\t  Deposit' + "\n"*5)
            self.txtReceipt.insert(END,'Balance \t\t\t      Request New Pin' + "\n"*5)
            self.txtReceipt.insert(END,'Mini statement \t\t\t        Print statement' + "\n\n")
        def Statement():
            pinNo1 = str(self.txtReceipt.get("1.0","end-1c"))
            pinNo2 = str(pinNo1)
            pinNo3 = float(pinNo2)
            pinNo4 = float(1296 - (pinNo3))
            self.txtReceipt.delete("1.0",END)
            self.txtReceipt.insert(END,'\n\t' + str(pinNo4) + "\t\t")
            self.txtReceipt.insert(END,'\t\t\t\n\n   Account Balance $' + str(pinNo4) +"\n\n")
            self.txtReceipt.insert(END,'Rent \t\t\t\t 1200$'+ "\n\n")
            self.txtReceipt.insert(END,'Tesco \t\t\t\t 79.36$'+ "\n\n")
            self.txtReceipt.insert(END,'Rent \t\t\t\t 1200$'+ "\n\n")
            self.txtReceipt.insert(END,'Sainsburys \t\t\t\t 53.87$'+ "\n\n")
            self.txtReceipt.insert(END,'Student Loan \t\t\t\t 69.72$'+ "\n\n")
            self.txtReceipt.insert(END,'Poundland \t\t\t\t 19.00$'+ "\n\n")
        def Insert_Zero():
            zeroNumber = 0
            self.txtReceipt.insert(END,zeroNumber)
        def Insert_One():
            oneNumber = 1
            self.txtReceipt.insert(END,oneNumber)
        def Insert_Two():
            twoNumber = 2
            self.txtReceipt.insert(END,zerotwoNumber)
        def Insert_Three():
            threeNumber = 3
            self.txtReceipt.insert(END,threeNumber)
        def Insert_Four():
            fourNumber = 4
            self.txtReceipt.insert(END,fourNumber)
        def Insert_Five():
            fiveNumber = 5
            self.txtReceipt.insert(END,fiveNumber)
        def Insert_Six():
            sixNumber = 6
            self.txtReceipt.insert(END,sixNumber)
        def Insert_Seven():
            sevenNumber = 7
            self.txtReceipt.insert(END,sevenNumber)
        def Insert_Eight():
            eightNumber = 8
            self.txtReceipt.insert(END,eightNumber)
        def Insert_Nine():
            nineNumber = 9
            self.txtReceipt.insert(END,nineNumber)
        #--------------------widgets--------------------
        self.txtReceipt = Text(interFrame1Mid, height = 17, width = 42, bd = 12, font = ('arial',9,'bold'))
        self.txtReceipt.grid(row = 0, column = 0)
        #--------------------Buttons in inter frame one left side--------------------
        self.leftArrowImage = PhotoImage(file = "rightarrow.png")
        self.leftArrowButton1 = Button(interFrame1Left, width = 160, height=60, state = DISABLED, image = self.leftArrowImage, command = Withdraw_cash)
        self.leftArrowButton1.grid(row = 0, column = 0, padx = 2, pady = 2)
        self.leftArrowButton2 = Button(interFrame1Left, width = 160, height=60, state = DISABLED, image = self.leftArrowImage, command = Withdraw_cash)
        self.leftArrowButton2.grid(row = 1, column = 0, padx = 2, pady = 2)
        self.leftArrowButton3 = Button(interFrame1Left, width = 160, height=60, state = DISABLED, image = self.leftArrowImage, command = Balance)
        self.leftArrowButton3.grid(row = 2, column = 0, padx = 2, pady = 2)
        self.leftArrowButton4 = Button(interFrame1Left, width = 160, height=60, state = DISABLED, image = self.leftArrowImage, command = Statement)
        self.leftArrowButton4.grid(row = 3, column = 0, padx = 2, pady = 2)
        #--------------------Buttons in inter frame one right side--------------------
        self.rightArrowImage = PhotoImage(file = "leftarrow.png")
        self.rightArrowButton1 = Button(interFrame1Right, width = 160, height=60, state = DISABLED, image = self.rightArrowImage, command = Loan)
        self.rightArrowButton1.grid(row = 0, column = 0, padx = 2, pady = 2)
        self.rightArrowButton2 = Button(interFrame1Right, width = 160, height=60, state = DISABLED, image = self.rightArrowImage, command = Deposite)
        self.rightArrowButton2.grid(row = 1, column = 0, padx = 2, pady = 2)
        self.rightArrowButton3 = Button(interFrame1Right, width = 160, height=60, state = DISABLED, image = self.rightArrowImage, command = Request_New_Pin)
        self.rightArrowButton3.grid(row = 2, column = 0, padx = 2, pady = 2)
        self.rightArrowButton4 = Button(interFrame1Right, width = 160, height=60, state = DISABLED, image = self.rightArrowImage, command = Statement)
        self.rightArrowButton4.grid(row = 3, column = 0, padx = 2, pady = 2)
        #--------------------Buttons in inter frame two(pin number) row one--------------------
        self.oneImage = PhotoImage(file = "one_button.png")
        self.oneButton = Button(interFrame2, width = 100, height=73, image = self.oneImage, command = Insert_One)
        self.oneButton.grid(row = 2, column = 0, padx = 4, pady = 4)
        self.twoImage = PhotoImage(file = "two_button.png")
        self.twoButton = Button(interFrame2, width = 100, height=73, image = self.twoImage, command = Insert_Two)
        self.twoButton.grid(row = 2, column = 1, padx = 4, pady = 4)
        self.threeImage = PhotoImage(file = "three_button.png")
        self.threeButton = Button(interFrame2, width = 100, height=73, image = self.threeImage, command = Insert_Three)
        self.threeButton.grid(row = 2, column = 2, padx = 4, pady = 4)
        self.cancelImage = PhotoImage(file = "cancel.png")
        self.cancelButton = Button(interFrame2, width = 118, height=74, image = self.cancelImage, command = Cancel_Button)
        self.cancelButton.grid(row = 2, column = 3, padx = 4, pady = 4)
        #--------------------Buttons in inter frame two(pin number) row two--------------------
        self.fourImage = PhotoImage(file = "four_button.png")
        self.fourButton = Button(interFrame2, width = 100, height=73, image = self.fourImage, command = Insert_Four)
        self.fourButton.grid(row = 3, column = 0, padx = 4, pady = 4)
        self.fiveImage = PhotoImage(file = "five_button.png")
        self.fiveButton = Button(interFrame2, width = 100, height=73, image = self.fiveImage, command = Insert_Five)
        self.fiveButton.grid(row = 3, column = 1, padx = 4, pady = 4)
        self.sixImage = PhotoImage(file = "six.png")
        self.sixButton = Button(interFrame2, width = 100, height=73, image = self.sixImage, command = Insert_Six)
        self.sixButton.grid(row = 3, column = 2, padx = 4, pady = 4)
        self.correctImage = PhotoImage(file = "correct.png")
        self.correctButton = Button(interFrame2, width = 118, height=74, image = self.correctImage,command = Clear_Screen)
        self.correctButton.grid(row = 3, column = 3, padx = 4, pady = 4)
        #--------------------Buttons in inter frame two(pin number) row three--------------------
        self.sevenImage = PhotoImage(file = "seven.png")
        self.sevenButton = Button(interFrame2, width = 100, height=73, image = self.sevenImage, command = Insert_Seven)
        self.sevenButton.grid(row = 4, column = 0, padx = 4, pady = 4)
        self.eightImage = PhotoImage(file = "eight.png")
        self.eightButton = Button(interFrame2, width = 100, height=73, image = self.eightImage, command = Insert_Eight)
        self.eightButton.grid(row = 4, column = 1, padx = 4, pady = 4)
        self.nineImage = PhotoImage(file = "nine.png")
        self.nineButton = Button(interFrame2, width = 100, height=73, image = self.nineImage, command = Insert_Nine)
        self.nineButton.grid(row = 4, column = 2, padx = 4, pady = 4)
        self.okImage = PhotoImage(file = "ok.png")
        self.okButton = Button(interFrame2, width = 118, height=74, image = self.okImage,command = Enter_Pin_Number)
        self.okButton.grid(row = 4, column = 3, padx = 4, pady = 4)
         #--------------------Buttons in inter frame two(pin number) row four--------------------
        self.spaceImage = PhotoImage(file = "space.png")
        self.spaceButton1 = Button(interFrame2, width = 100, height=73, state = DISABLED, image = self.spaceImage)
        self.spaceButton1.grid(row = 5, column = 0, padx = 4, pady = 4)
        self.zeroImage = PhotoImage(file = "zero.png")
        self.zeroButton = Button(interFrame2, width = 100, height=73, image = self.zeroImage, command = Insert_Zero)
        self.zeroButton.grid(row = 5, column = 1, padx = 4, pady = 4)
        self.spaceButton2 = Button(interFrame2, width = 100, height=73, state = DISABLED, image = self.spaceImage)
        self.spaceButton2.grid(row = 5, column = 2, padx = 4, pady = 4)
        self.spaceButton3 = Button(interFrame2, width = 118, height=74, state = DISABLED, image = self.spaceImage)
        self.spaceButton3.grid(row = 5, column = 3, padx = 4, pady = 4)
if __name__=='__main__':
    startWindow = Tk()
    app= atm(startWindow)
    startWindow.mainloop()

