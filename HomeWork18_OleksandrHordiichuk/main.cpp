#include <iostream>
#include <string>

using namespace std;

class Weapon
{
public:
	virtual ~Weapon() {}

	virtual float GetDamage() const
	{
		return damage;
	}

	virtual string GetName() const
	{
		return name;
	}

protected:
	Weapon(const string& name, float damage) : 
		name(name), damage(damage){}

private:
	string name;
	float damage;
};

class Pistol : public Weapon
{

public:		
	Pistol() : Weapon("Pistol", 15) {}
	

};

class Rifle : public Weapon
{
public:
	Rifle() : Weapon("Rifle", 35) {}
};

class Sword : public Weapon
{
public:
	Sword() : Weapon("Sword", 100) {}
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
	Character character2;
		
	Pistol pistol;
	Rifle rifle;

	character1.SetWeapon(&pistol);
	character2.SetWeapon(&rifle);

	character1.WhatWeapon();
	character2.WhatWeapon();

	return 0;
}