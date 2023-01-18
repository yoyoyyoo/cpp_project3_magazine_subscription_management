#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>

//specification file

using namespace std;

//struct Magazine
struct Magazine
{
	string name;
	string isbn;
	char delivery;
	Magazine *link;
};

//class Subscription
class Subscription
{
public:
	Subscription(string/*name*/);
	~Subscription();
	void showMagazines(ostream&/*fout or cout*/) const;
	void addMagazine(string /*name*/, string /*isbn*/, char/*delivery*/);
	void removeMagazine(string/*isbn*/);
	int getNoMagazines()const { return nbrOfMagazine; }
	string getDistributorName() const { return distributorName; }

private:
	Magazine *firstPtr;
	string distributorName;
	int nbrOfMagazine;
};