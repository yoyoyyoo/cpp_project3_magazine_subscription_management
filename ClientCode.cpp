/*
* COMP333 Assignment3
* Author by: Yanan Liu
* This is a program for a magazine distributor to use a linked list to keep track of its magazine subscriptions.
* Assumptions:
* 1) the original list is empty
* 2) no duplicated name can be added to the list
* 3) no duplicated isbn can be added to the list
* 4) only remove the node while isbn is existed
*/

#include "Subscription.h"

int main()
{
	//create new object on heap with a name
	Subscription* sub1 = new Subscription("New York Times");
	assert(sub1 != NULL);
	cout << "-----------create a new subscription, " << sub1->getDistributorName() << "---------" << endl << endl;
	cout << "Distributor: " << sub1->getDistributorName() << ". Number of Magazine is " << sub1->getNoMagazines() << endl << endl;

	//create new object on heap without a name
	Subscription* sub2 = new Subscription("");
	assert(sub2 != NULL);
	cout << "-----------create a new subscription without a name---------" << endl << endl;
	cout << "Distributor: " << sub2->getDistributorName() << ". Number of Magazine is " << sub2->getNoMagazines() << endl << endl;

	//add new record to an empty list
	cout << "-----------add new record \"dbc\" to the empty list ---------" << endl << endl;
	sub1->addMagazine("dbc", "dd-ttt-1234", 'w');
	sub1->showMagazines(cout);

	//add new record with no data assigned
	cout << "-----------add new record with no data to list ---------" << endl << endl;
	sub1->addMagazine("", "", ' ');
	sub1->showMagazines(cout);

	//add new record, the name is before the first node in list, but with an existed isbn   
	cout << "-----------add \"abc\" to list, smaller than the first one, but with same isbn ---------" << endl << endl;
	sub1->addMagazine("abc", "dd-ttt-1234", 'w');
	sub1->showMagazines(cout);

	//add new record, the name is before the first node in list, but with a new isbn   
	cout << "-----------add \"abc\" to list, smaller than the first one, with different isbn ---------" << endl << endl;
	sub1->addMagazine("abc", "aa-ttt-1234", 'w');
	sub1->showMagazines(cout);

	//add new record to the middle with a new isbn   
	cout << "-----------add \"bbc\" to middle of the list---------" << endl << endl;
	sub1->addMagazine("bbc", "bb-ttt-1234", 'm');
	sub1->showMagazines(cout);

	//add new record to the middle with a new isbn   
	cout << "-----------add \"cbc\" to middle of the list---------" << endl << endl;
	sub1->addMagazine("cbc", "cc-ttt-1234", 'M');
	sub1->showMagazines(cout);

	//add new record to the end with a new isbn   
	cout << "-----------add \"zbc\"to the end of list---------" << endl << endl;
	sub1->addMagazine("zbc", "zz-ttt-1234", 'M');
	sub1->showMagazines(cout);

	//add new record with existed name   
	cout << "-----------add an \"bbc\" existing name record with different isbn to the list---------" << endl << endl;
	sub1->addMagazine("bbc", "bc-ttt-1234", 'M');
	sub1->showMagazines(cout);

	//add new record with existed isbn   
	cout << "-----------add an \"tbc\" with existing isbn record \"dd-ttt-1234\" to the list---------" << endl << endl;
	sub1->addMagazine("tbc", "dd-ttt-1234", 'M');
	sub1->showMagazines(cout);

	//remove a non-existing record
	cout << "-----------remove a non-existing record, \"pp-ttt-1234\", from the list---------" << endl << endl;
	sub1->removeMagazine("pp-ttt-1234");
	sub1->showMagazines(cout);

	//remove an existed record, first node in the list
	cout << "-----------remove first record, \"aa-ttt-1234\", from the list---------" << endl << endl;
	sub1->removeMagazine("aa-ttt-1234");
	sub1->showMagazines(cout);

	//remove an existed record in the middle
	cout << "-----------remove any record,\"cc - ttt - 1234\", from the list---------" << endl << endl;
	sub1->removeMagazine("cc-ttt-1234");
	sub1->showMagazines(cout);

	//remove an existed record, last node in the list
	cout << "-----------remove last record, \"zz - ttt - 1234\", from the list ---------" << endl << endl;
	sub1->removeMagazine("zz-ttt-1234");
	sub1->showMagazines(cout);

	//remove the same one as above
	cout << "----------- remove same record, \"zz - ttt - 1234\", as above ---------" << endl << endl;
	sub1->removeMagazine("zz-ttt-1234");
	sub1->showMagazines(cout);

	delete sub1;
	delete sub2;

	system("pause");

}

/*output
-----------create a new subscription, New York Times---------

Distributor: New York Times. Number of Magazine is 0

-----------create a new subscription without a name---------

Distributor: unknown. Number of Magazine is 0

-----------add new record "dbc" to the empty list ---------

New Record dbc is added successfully.

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 dbc                   dd-ttt-1234              Weekly
# of Magazines = 1

-----------add new record with no data to list ---------

New Record unknown is added successfully.

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 dbc                   dd-ttt-1234              Weekly
			 unknown                       unknown             Unknown
# of Magazines = 2

-----------add "abc" to list, smaller than the first one, but with same isbn ---------

*******The magazine's ISBN is alreay exists.*******

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 dbc                   dd-ttt-1234              Weekly
			 unknown                       unknown             Unknown
# of Magazines = 2

-----------add "abc" to list, smaller than the first one, with different isbn ---------

New Record abc is added successfully.

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 abc                   aa-ttt-1234              Weekly
				 dbc                   dd-ttt-1234              Weekly
			 unknown                       unknown             Unknown
# of Magazines = 3

-----------add "bbc" to middle of the list---------

New Record bbc is added successfully.

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 abc                   aa-ttt-1234              Weekly
				 bbc                   bb-ttt-1234             Monthly
				 dbc                   dd-ttt-1234              Weekly
			 unknown                       unknown             Unknown
# of Magazines = 4

-----------add "cbc" to middle of the list---------

New Record cbc is added successfully.

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 abc                   aa-ttt-1234              Weekly
				 bbc                   bb-ttt-1234             Monthly
				 cbc                   cc-ttt-1234             Monthly
				 dbc                   dd-ttt-1234              Weekly
			 unknown                       unknown             Unknown
# of Magazines = 5

-----------add "zbc"to the end of list---------

New Record zbc is added successfully.

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 abc                   aa-ttt-1234              Weekly
				 bbc                   bb-ttt-1234             Monthly
				 cbc                   cc-ttt-1234             Monthly
				 dbc                   dd-ttt-1234              Weekly
			 unknown                       unknown             Unknown
				 zbc                   zz-ttt-1234             Monthly
# of Magazines = 6

-----------add an "bbc" existing name record with different isbn to the list---------

*******The magazine's name is alreay exists.*******

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 abc                   aa-ttt-1234              Weekly
				 bbc                   bb-ttt-1234             Monthly
				 cbc                   cc-ttt-1234             Monthly
				 dbc                   dd-ttt-1234              Weekly
			 unknown                       unknown             Unknown
				 zbc                   zz-ttt-1234             Monthly
# of Magazines = 6

-----------add an "tbc" with existing isbn record "dd-ttt-1234" to the list---------

*******The magazine's ISBN is alreay exists.*******

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 abc                   aa-ttt-1234              Weekly
				 bbc                   bb-ttt-1234             Monthly
				 cbc                   cc-ttt-1234             Monthly
				 dbc                   dd-ttt-1234              Weekly
			 unknown                       unknown             Unknown
				 zbc                   zz-ttt-1234             Monthly
# of Magazines = 6

-----------remove a non-existing record, "pp-ttt-1234", from the list---------

*******No matched record find, the list doesn't change*******

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 abc                   aa-ttt-1234              Weekly
				 bbc                   bb-ttt-1234             Monthly
				 cbc                   cc-ttt-1234             Monthly
				 dbc                   dd-ttt-1234              Weekly
			 unknown                       unknown             Unknown
				 zbc                   zz-ttt-1234             Monthly
# of Magazines = 6

-----------remove first record, "aa-ttt-1234", from the list---------

bbc is deleted successfully.

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 bbc                   bb-ttt-1234             Monthly
				 cbc                   cc-ttt-1234             Monthly
				 dbc                   dd-ttt-1234              Weekly
			 unknown                       unknown             Unknown
				 zbc                   zz-ttt-1234             Monthly
# of Magazines = 5

-----------remove any record,"cc - ttt - 1234", from the list---------

cbc is deleted successfully.

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 bbc                   bb-ttt-1234             Monthly
				 dbc                   dd-ttt-1234              Weekly
			 unknown                       unknown             Unknown
				 zbc                   zz-ttt-1234             Monthly
# of Magazines = 4

-----------remove last record, "zz - ttt - 1234", from the list ---------

zbc is deleted successfully.

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 bbc                   bb-ttt-1234             Monthly
				 dbc                   dd-ttt-1234              Weekly
			 unknown                       unknown             Unknown
# of Magazines = 3

----------- remove same record, "zz - ttt - 1234", as above ---------

*******No matched record find, the list doesn't change*******

Distributor Name: New York Times
	   Magazine Name                          ISBN       Delivery Type
				 bbc                   bb-ttt-1234             Monthly
				 dbc                   dd-ttt-1234              Weekly
			 unknown                       unknown             Unknown
# of Magazines = 3

delete bbc
delete dbc
delete unknown
Press any key to continue . . .

F:\Yanan\SLC\semester3\Comp333\ass3\ass3\Debug\ass3.exe (process 12744) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/