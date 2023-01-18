#include "Subscription.h"

//implementation file

//non-default constructor with new subscription name passed in
Subscription::Subscription(string newName)
{
	distributorName = (newName != "") ? newName : "unknown";
	nbrOfMagazine = 0;
	firstPtr = NULL;
}

//destructor
Subscription::~Subscription()
{
	Magazine* walker;
	while (firstPtr != NULL)
	{
		walker = firstPtr;
		cout << "delete " << walker->name << endl;
		firstPtr = firstPtr->link;
		delete walker;
	}
}

//show function to print out the subscription and magazine information
void Subscription::showMagazines(ostream& out) const
{
	Magazine* walker = firstPtr;

	out << "Distributor Name: " << distributorName << endl;
	out << setw(20) << "Magazine Name" << setw(30) << "ISBN" << setw(20) << "Delivery Type" << endl;

	if (firstPtr == NULL)
		out << "There is no magazine in the list." << endl << endl;
	else
	{
		while (walker != NULL)
		{
			string deliveryType = (walker->delivery == 'D') ? "Daily" : ((walker->delivery == 'W') ? "Weekly" : ((walker->delivery == 'M') ? "Monthly" : "Unknown"));
			out << setw(20) << walker->name << setw(30) << walker->isbn << setw(20) << deliveryType << endl;
			walker = walker->link;
		}
		out << "# of Magazines = " << nbrOfMagazine << endl << endl;
	}
}


//add new magazine, same name or same isbn will no be added
void Subscription::addMagazine(string newName, string newISBN, char newDelivery)
{
	Magazine* walker = firstPtr;
	Magazine* stalker = walker;
	Magazine* builder = new Magazine;
	assert(builder != NULL);
	builder->name = (newName != "") ? newName : "unknown";
	builder->isbn = (newISBN != "") ? newISBN : "unknown";
	builder->delivery = toupper((newDelivery != NULL) ? newDelivery : 'U');
	builder->link = NULL;

	if (firstPtr != NULL)//check if the list is not empty, else add to the first
	{
		while (walker != NULL)
		{
			//the name or isbn exist, break
			if (walker->isbn == builder->isbn || walker->name == builder->name)
			{
				string outMsg = (walker->isbn == builder->isbn) ? "ISBN" : "name";
				cout << "*******The magazine's " << outMsg << " is alreay exists.*******" << endl << endl;
				break;
			}
			//the new name is smaller than the first node in the list, add to beginning
			if (firstPtr->name > builder->name)
			{
				firstPtr = builder;
				builder->link = walker;
				nbrOfMagazine++;
				cout << "New Record " << builder->name << " is added successfully." << endl << endl;
				break;
			}

			if (walker->name > builder->name)
			{
				//new name is smaller than the walker->name
				stalker->link = builder;
				builder->link = walker;
				nbrOfMagazine++;
				cout << "New Record " << builder->name << " is added successfully." << endl << endl;
				break;
			}
			else
			{
				//new name is bigger than the walker->name
				stalker = walker;
				walker = walker->link;
			}

			//newName bigger than the end one
			if (walker == NULL)
			{
				stalker->link = builder;
				cout << "New Record " << builder->name << " is added successfully." << endl << endl;
				nbrOfMagazine++;
			}
		}
	}
	else //the list is empty, add to the list as the first
	{
		firstPtr = builder;
		nbrOfMagazine++;
		cout << "New Record " << builder->name << " is added successfully." << endl << endl;
	}
}

//remove any node from the list
void Subscription::removeMagazine(string delISBN)
{
	Magazine* walker = firstPtr;
	Magazine* stalker = walker;

	if (firstPtr == NULL) //empty list
		cout << "This is an empty list" << endl << endl;
	else if (firstPtr->isbn == delISBN)//if the target isbn is the first in the list
	{
		firstPtr = firstPtr->link;
		nbrOfMagazine--;
		cout << firstPtr->name << " is deleted successfully." << endl << endl;
		delete walker;
	}
	else
	{
		while (walker != NULL)
		{
			if (walker->isbn == delISBN) //find the target one
			{
				//find the one existed in list
				stalker->link = walker->link;
				nbrOfMagazine--;
				cout << walker->name << " is deleted successfully." << endl << endl;
				delete walker;
				break;
			}

			//not find, keep walking to the next
			stalker = walker;
			walker = walker->link;
		}
		// not find
		if (walker == NULL)
			cout << "*******No matched record find, the list doesn't change*******" << endl << endl;
	}
}


