#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

class Creature {
public:
	//constructor
	Creature() :strength(10), hitpoints(10) {}
	Creature(int newStrength, int newHitpoints) :strength(newStrength), hitpoints(newHitpoints) {}

	//accessor function
	int getStrength() { return strength; }
	int getHitpoints() { return hitpoints; }

	//mutator function
	void setStrength(int newStrength) { strength = newStrength; }
	void setHitpoints(int newHitpoints) { hitpoints = newHitpoints; }

	//function to return creature species
	virtual string getSpecies() {
		return "Unknown";
	}

	//function to return creature damage point
	virtual int getDamage() {
		int damage = (rand() % strength) + 1;
		cout << getSpecies() << " attacks for " << damage << " points!" << endl;
		return damage;
	}
protected:
	int strength;
	int hitpoints;
};

class Human :public Creature {
public:
	//constructor
	Human() :Creature() {}
	Human(int newStrength, int newHitpoints) :Creature(newStrength, newHitpoints) {}

	//function to return species
	virtual string getSpecies() {
		return "Human";
	}
};

class Elf :public Creature {
public:
	//constructor
	Elf() :Creature() {}
	Elf(int newStrength, int newHitpoints) :Creature(newStrength, newHitpoints) {}

	virtual int getDamage() {
		int damage = Creature::getDamage();

		//10% chance to cause double additional damage
		if ((rand() % 10) == 0) {
			cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
			damage = damage * 2;
		}
		return damage;
	}

	//function to return species
	virtual string getSpecies() {
		return "Elf";
	}
};

class Demon :public Creature {
public:
	//constructor
	Demon() :Creature() {}
	Demon(int newStrength, int newHitpoints) :Creature(newStrength, newHitpoints) {}

	virtual int getDamage() {
		int damage = Creature::getDamage();

		//Demon has 5% chance which can cause 50 additional damage points
		if ((rand() % 100) < 5)
		{
			damage = damage + 50;
			cout << "Demonic attack inflicts 50  additional damage points!" << endl;
		}
		return damage;
	}
};

class Cyberdemon :public Demon {
public:
	//constructor
	Cyberdemon() :Demon() {}
	Cyberdemon(int newStrength, int newHitpoints) :Demon(newStrength, newHitpoints) {}

	//function to return species
	virtual string getSpecies() {
		return "Cyberdemon";
	}
};

class Balrog :public Demon {
public:
	//constructor
	Balrog() :Demon() {}
	Balrog(int newStrength, int newHitpoints) :Demon(newStrength, newHitpoints) {}

	virtual int getDamage() {
		int damage = Demon::getDamage();
		//Balrog can cause twice damage 
		int damage2 = (rand() % strength) + 1;
		cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
		damage = damage + damage2;
		return damage;
	}

	//function to return species
	virtual string getSpecies() {
		return "Balrog";
	}
};

int main() {
	srand(time(NULL));
	//Test
	Human human(15, 20);
	Elf elf(20, 30);
	Cyberdemon cyberdemon(50, 60);
	Balrog balrog(75, 80);

	//output result
	cout << human.getSpecies() << " total damage: " << human.getDamage() << endl;
	cout << "***" << endl;
	cout << elf.getSpecies() << " total damage: " << elf.getDamage() << endl;
	cout << "***" << endl;
	cout << cyberdemon.getSpecies() << " total damage: " << cyberdemon.getDamage() << endl;
	cout << "***" << endl;
	cout << balrog.getSpecies() << " total damage: " << balrog.getDamage() << endl;

	return 0;
}