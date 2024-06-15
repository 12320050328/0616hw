#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class SalariedEmployee {
public:
	//constructor
	SalariedEmployee() :name(""), ssn(""), salary(0) {}
	SalariedEmployee(string theName, string theSsn, double theSalary) :name(theName), ssn(theSsn), salary(theSalary) {}

	//Enter the employee's data
	void inputData() {
		cout << "Enter the employee's name=>" << endl;
		cin >> name;
		cout << "Enter the employee's number=>" << endl;
		cin >> ssn;
		cout << "Enter the salary=>" << endl;
		cin >> salary;
	}

	//Function to check the data
	void printCheck() {
		cout << "\n________________________________________________\n";
		cout << "Pay to the order of " << name << endl;
		cout << "_________________________________________________\n";
		cout << "Check Stub NOT NEGOTIABLE \n";
		cout << "Employee Number: " << ssn << endl;
		cout << "Salaried Employee. Regular Pay: " << salary << endl;
		cout << "_________________________________________________\n";
	}
protected:
	string name;
	string ssn;
	double salary;
};

class Administrator :public SalariedEmployee {
public:
	//constructor
	Administrator() :SalariedEmployee(), title(""), areaOfResponsibility(""), supervisor("") {}
	Administrator(string theName, string theSsn, double theSalary, string theTitle, string theAreaOfResponsibility, string theSupervisor) :SalariedEmployee(theName, theSsn, theSalary), title(theTitle), areaOfResponsibility(theAreaOfResponsibility), supervisor(theSupervisor) {}

	//accessor function
	string getSupervisor() { return supervisor; }
	
	//mutator function
	void setSupervisor(string newSupervisor) { supervisor = newSupervisor; }

	//Enter the data
	void inputData() {
		SalariedEmployee::inputData();
		cout << "Enter the administrator・s title(such as Director or Vice President)=>" << endl;
		cin >> title;
		cout << "Enter the company area of responsibility (such as Production, Accounting, or Personnel)=>" << endl;
		cin >> areaOfResponsibility;
		cout << "Enter the name of this administrator・s immediate supervisor=>" << endl;
		cin >> supervisor;
	}

	//Print the data on the screen
	void print() {
		cout << "**********************" << endl;
		cout << "The administrator・s title: " << title << endl;
		cout << "The company area of responsibility: " << areaOfResponsibility << endl;
		cout << "The name of this administrator・s immediate supervisor: " << supervisor << endl;
	}

	//Check the data
	void printCheck() {
		SalariedEmployee::printCheck();
		cout << "Administrator・s title: " << title << endl;
		cout << "Company area of responsibility: " << areaOfResponsibility << endl;
		cout << "Name of this administrator・s immediate supervisor: " << supervisor << endl;
	}
protected:
	string title;
	string areaOfResponsibility;
	string  supervisor;
};

int main() {
	//Test
	Administrator admin;

	admin.inputData();
	admin.print();
	admin.printCheck();

	return 0;
}