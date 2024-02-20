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
		name(name), damage(damage) {}

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
	Character() : weapon(nullptr) {}

	void SetWeapon(unique_ptr<Weapon> weapon)
	{
		this->weapon = move(weapon);
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
	unique_ptr<Weapon> weapon;
};



int main()
{
	Character character1;
	Character character2;

	unique_ptr<Weapon> pistol = make_unique<Pistol>();
	unique_ptr<Weapon> rifle = make_unique<Rifle>();

	character1.SetWeapon(move(pistol));
	character2.SetWeapon(move(rifle));


	character1.WhatWeapon();
	character2.WhatWeapon();

	return 0;
}