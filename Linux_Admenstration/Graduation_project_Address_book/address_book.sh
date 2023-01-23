#!bin/bash
create()
{
	echo "Enter address book name: "
	read addressBookName
	result=`ls | grep $addressBookName | wc -w`
	#check if we have any address book or not 
	#the grep will search for the address book and wc will count the number of characters 
	if [ $result -gt 0 ]
	then
		echo "The file is already exist"
	else
		touch $addressBookName
		echo "Address Book has been created successfully"
	fi
}
display()
{
	echo "Enter address book name: "
	read addressBookName
	result=`ls | grep $addressBookName | wc -w`
	if [ $result -gt 0 ]
	then
		cat $addressBookName
	else
		echo "The file is not existing"
	fi
}
insert()
{
	echo "Enter address book name: "
	read addressBookName
	result=`ls | grep $addressBookName | wc -w`
	#check if we have any address book or not 
	if [ $result -gt 0 ]
	then
		echo "Enter the email: "
		read email
		len=`cat $addressBookName |grep $email | wc -w`
		#check if we have any email or not 
		if [ $len -gt 0 ]
		then
			echo "The email is already exist"
		else
			echo "Enter Full name and phone number: "
			read firstName lastName phoneNumber
			record=`echo $email $firstName $lastName $phoneNumber`
			echo $record >> $addressBookName
			echo "The record has been inserted sucessfully"
		fi
	else
		echo "The file is not existing"
	fi
}
modify()
{
	echo "Enter address book name: "
	read addressBookName
	result=`ls | grep $addressBookName | wc -w`
	#check if we have any address book or not 
	if [ $result -gt 0 ]
	then
		echo "Enter the email: "
		read email
		len=`cat $addressBookName |grep $email | wc -w`
		#check if we have any email or not 
		if [ $len -gt 0 ]
		then
			echo "Enter modified full name and the phone number: "
			read firstName lastName phoneNumber
			modified=`echo $email $firstName $lastName $phoneNumber`
			oldRecord=`cat $addressBookName | grep $email`
			sed -i "s/$oldRecord/$modified/gi" $addressBookName
			echo "The record has been modified successfully"
		else
			echo "The email is not existing"
		fi
	else
		echo "The file is not existing"
	fi
}
delete()
{
	echo "Enter address book name: "
	read addressBookName
	result=`ls | grep $addressBookName | wc -w`
	#check if we have any address book or not 
	if [ $result -gt 0 ]
	then
		echo "Enter the email you want to delete it: "
		read email
		len=`cat $addressBookName |grep $email | wc -w`
		#check if we have any email or not 
		if [ $len -gt 0 ]
		then
			Record=`cat $addressBookName | grep $email`
			sed -i "s/$Record//gi" $addressBookName
			sed -i "/^$/d" $addressBookName
			echo "The record has been deleted successfully"
		else
			echo "The email is not existing"
		fi
	else
		echo "The file is not existing"
	fi
}
search()
{
	echo "Enter address book name: "
	read addressBookName
	result=`ls | grep $addressBookName | wc -w`
	#check if we have any address book or not 
	if [ $result -gt 0 ]
	then
		echo "Enter the email you want to search for it: "
		read email
		len=`cat $addressBookName |grep $email | wc -w`
		#check if we have any email or not 
		if [ $len -gt 0 ]
		then
			Record=`cat $addressBookName | grep $email`
			echo "The record you search for: $Record"
		else
			echo "The email is not existing"
		fi
	else
		echo "The file is not existing"
	fi
}
while :
do
	echo "----------Address Book Menu----------"
	echo "1. Create a new address book"
	echo "2. Display the address book"
	echo "3. Insert a record in address book"
	echo "4. Modify a record in address book"
	echo "5. Delete a record in address book"
	echo "6. Search for address book"
	echo "7. Exit the Menu"
	echo "Please enter your choice: "
	read choice
	case $choice in
		1) create ;;

		2) display ;;

		3) insert ;;
		
		4) modify ;;

		5) delete ;;

		6) search ;;

		7) exit ;;

		*) echo "Wrong choice" ;;
	esac
done
