#include <iostream>
#include <string>

using namespace std;

class Weapon
{
public:
	Weapon(const string& name) : name(name){}

	string GetName() const
	{
		return name;
	}

private:
	string name;
};

class Character
{
public:
	Character() : weapon(nullptr){}

	void SetWeapon(Weapon* weapon)
	{
		this->weapon = weapon;
	}

	void WhatWeapon() const 
	{
		if (weapon != nullptr)
		{
			cout << "Weapon: " << weapon->GetName() << endl;
		}
		else
		{
			cout << "You haw no weapon." << endl;
		}
	}
	
private:

	Weapon* weapon;
};

int main()
{
	Character character1;

	Weapon gun("gun");

	character1.SetWeapon(&gun);

	character1.WhatWeapon();

	return 0;
}