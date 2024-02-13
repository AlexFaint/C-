#include <iostream>

using namespace std;

class Buildings
{
public:
	Buildings(int _Id = 0, int _MaxAge = 0, int _InitialCost = 0, int _CurrentAge = 0)
		: Id { _Id }, MaxAge{ _MaxAge }, InitialCost{ _InitialCost } , CurrentAge{ _CurrentAge }
	{

	}

public:	
	int GetCost()
	{
		if (CurrentAge >= MaxAge)
		{
			return 0;
		}
		else if (CurrentAge >= MaxAge / 2)
		{
			return InitialCost / 2;
		}
		else
		{
			return InitialCost - (InitialCost * CurrentAge) / MaxAge;
		}
	}

	void ToAge(int years)
	{
		CurrentAge += years;
		if (CurrentAge >= MaxAge)
		{
			Destroy();
		}
	}

	void Destroy()
	{
		cout << "Building with ID " << Id << " has been destroy." << endl;
	}

private:
	int Id = 0;
	int MaxAge = 0;
	int InitialCost = 0;
	int CurrentPrice = 0;
	int CurrentAge = 0;
};

int main()
{	
	Buildings buildings(1, 50, 100000);
	cout << "Initital cost of building : $" << buildings.GetCost() << endl;
	buildings.ToAge(25);
	cout << "Cost of buil;ding after 25 years: $" << buildings.GetCost() << endl;
	buildings.ToAge(45);

	return 0;
}