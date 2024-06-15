#include<iostream>
#include<cstdlib>
#include<ctime>

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

	//function to get creature species
	virtual string getSpecies() {
		return "Unknown";
	}

	//function to get creature damage
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
	Human(int newstrength, int newHitpoints) :Creature(newstrength, newHitpoints) {}

	//return species
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
		//10% chance to get double damage
		if ((rand() % 10) == 0)
		{
			cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
			damage = damage * 2;
		}
		return damage;
	}
	//return species
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
		//Demon has 5% chance to inflict 50 additional damage
		if ((rand() % 100) < 5)
		{
			damage = damage + 50;
			cout << "Demonic attack inflicts 50 additional damage points!" << endl;
		}
		return damage;
	}
};

class Cyberdemon :public Demon {
public:
	//constructor
	Cyberdemon() :Demon() {}
	Cyberdemon(int newStrength, int newHitpoints) :Demon(newStrength, newHitpoints) {}

	//return species
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
		//Balrog can cause twice damage
		int damage = Demon::getDamage();
		int damage2 = (rand() % strength) + 1;
		cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
		damage = damage + damage2;
		return damage;
	}

	//return species
	virtual string getSpecies() {
		return "Balrog";
	}
};

void  battleArena(Creature& creature1, Creature& creature2) {
	//output creature1 initial HP
	cout << creature1.getSpecies() << " initial hitpoints: " << creature1.getHitpoints() << endl;
	//output creature2 initial HP
	cout << creature2.getSpecies() << " initial hitpoints: " << creature2.getHitpoints() << endl;

	while (creature1.getHitpoints() > 0 && creature2.getHitpoints() > 0) {
		int damage1;  //creature1 damage point
		damage1 = creature1.getDamage();

		//output creature2 remaining HP
		creature2.setHitpoints(creature2.getHitpoints() - damage1);
		cout << creature2.getSpecies() << " remaining hitpoints: " << creature2.getHitpoints() << endl;

		//If creature2 HP <= 0, creature1 wins
		if (creature2.getHitpoints() <= 0) {
			cout << creature1.getSpecies() << " wins!" << endl;
			break;
		}

		int damage2;  //creature2 damage point
		damage2 = creature2.getDamage();
		creature1.setHitpoints(creature1.getHitpoints() - damage2);
		//output creature1 remaining HP
		cout << creature1.getSpecies() << " remaining hitpoints: " << creature1.getHitpoints() << endl;

		//If creature1 HP <= 0, creature 2 wins
		if (creature1.getHitpoints() <= 0) {
			cout << creature2.getSpecies() << " wins!" << endl;
			break;
		}
		if (creature1.getHitpoints() <= 0 && creature2.getHitpoints() <= 0) {
			cout << "Tie!" << endl;
		}
	}
}

int main() {
	srand(time(NULL));

	//Test
	Human human(15, 20);
	Elf elf(12, 18);
	Cyberdemon cyberdemon(50, 60);
	Balrog balrog(45, 80);

	cout << "Round 1: Human v.s. Elf" << endl;
	battleArena(human, elf);
	cout << "*******************" << endl;
	cout << "Round 2: Cyberdemon v.s. Balrog" << endl;
	battleArena(cyberdemon, balrog);

	return 0;
}