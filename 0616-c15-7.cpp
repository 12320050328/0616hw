#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Dice {
public:
	//constructor
	Dice();
	Dice(int numSides);
	
	virtual int rollDice()const;  //roll the dice and return point between 1 and numSides
protected:
	int numSides;
};
//constructor
Dice::Dice() {
	numSides = 6;
	srand(time(NULL));
}
//constructor
Dice::Dice(int numSides) {
	this->numSides = numSides;
	srand(time(NULL));
}
//roll the dice and return point between 1 and numSides
int Dice::rollDice()const {
	return (rand() % numSides) + 1;
}
//Function to roll two dices and return their sum
int rollTwoDice(const Dice& die1, const Dice& die2) {
	return die1.rollDice() + die2.rollDice();
}
//Derived class LoadedDice inheriting from Dice
class LoadedDice :public Dice {
public:
	//constructor
	LoadedDice():Dice(){}
	LoadedDice(int numSides):Dice(numSides){}

	virtual int rollDice() const override {
		//50% chance to return the maximum value(numSides)
		if (rand() % 2 == 0) {
			return numSides;
		}
		else {
			return Dice::rollDice();
		}
	}
};

int main() {
	//Creature two LoadedDice objects
	LoadedDice die1(6), die2(10);

	//Roll the dice 10 times and print the results
	for (int i = 0; i < 10; i++) {
		int sum = rollTwoDice(die1, die2);
		cout << "Roll " << i + 1 <<": " << sum << endl;
	}
	return 0;
}
