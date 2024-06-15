#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class UniversityStaff
{
public:
	//constructor
	UniversityStaff() :name("") {}
	UniversityStaff(string theName) :name(theName) {}
	UniversityStaff(const UniversityStaff& theObject) :name(theObject.name) {}

	//accessor function
	string getName() const { return name; }

	UniversityStaff& operator=(const UniversityStaff& rtSide) {
		if (this != &rtSide) {
			name = rtSide.name;
		}
		return *this;
	}
	friend istream& operator >>(istream& inStream, UniversityStaff& staffObject);
	friend ostream& operator <<(ostream& outStream, const UniversityStaff& staffObject);
private:
	string name;
};
istream& operator >>(istream& inStream, UniversityStaff& staffObject) {
	inStream >> staffObject.name;
	return inStream;
}
ostream& operator <<(ostream& outStream, const UniversityStaff& staffObject) {
	outStream << staffObject.name;
	return outStream;
}

class Student : public UniversityStaff {
public:
	//constructor
	Student() :universityName(""), regNumber(0), proctor("") {}
	Student(string universityName, int regNumber, UniversityStaff proctor) :universityName(universityName), regNumber(regNumber), proctor(proctor) {}
	Student(const Student& theObject) :universityName(theObject.universityName), regNumber(theObject.regNumber), proctor(theObject.proctor) {}

	//accessor function
	string getUniversityName() { return universityName; }
	int getRegNumber() { return regNumber; }
	UniversityStaff getProctor() { return proctor; }
	//mutator function
	void setUniversityName(string theUniversityName) { universityName = theUniversityName; }
	void setRegNumber(int theRegNumber) { regNumber = theRegNumber; }
	void setProctor(UniversityStaff theProctor) { proctor = theProctor; }

	//output the result
	void print() {
		cout << "University name: " << getUniversityName() << endl;
		cout << "Registration number: " << getRegNumber() << endl;
		cout << "Proctor: " << getProctor().getName() << endl;
	}

	Student& operator=(const Student& other) {
		if (this != &other) {
			universityName = other.universityName;
			regNumber = other.regNumber;
			proctor = other.proctor;
		}
		return *this;
	}

protected:
	string universityName;
	int regNumber;
	UniversityStaff proctor;
};

class ScienceStudent :public Student {
public:
	//constructor
	ScienceStudent() :Student(), discipline(""), courseLevel("") {}
	ScienceStudent(string universityName, int regNumber, UniversityStaff proctor, string discipline, string courseLevel)
		:Student(universityName, regNumber, proctor), discipline(discipline), courseLevel(courseLevel) {}
	ScienceStudent(const ScienceStudent& other) :Student(other), discipline(other.discipline), courseLevel(other.courseLevel) {}

	//accessor function
	string getDiscipline() { return discipline; }
	string getCourseLevel() { return courseLevel; }

	//mutator function
	void setDiscipline(string theDiscipline) { discipline = theDiscipline; }
	void setCourseLevel(string theCourseLevel) { courseLevel = theCourseLevel; }

	//output the result
	void print() {
		Student::print();
		cout << "Properties science discipline: " << getDiscipline() << endl;
		cout << "Course level(undergraduate or postgraduate): " << getCourseLevel() << endl;
	}

	ScienceStudent& operator=(const ScienceStudent& other) {
		if (this != &other) {
			Student::operator=(other);
			discipline = other.discipline;
			courseLevel = other.courseLevel;
		}
		return *this;
	}
protected:
	string discipline;
	string courseLevel;
};

int main() {
	//Test
	UniversityStaff proctor("Bob");
	ScienceStudent student("NUTN", 123, proctor, "science", "undergraduate");

	//print the result on the screen
	student.print();

	return 0;
}