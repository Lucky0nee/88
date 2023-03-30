#include <iostream>
#include <memory>

using namespace std;

namespace people {
	long g_id = 0;
}

// Клієнт
class People {
protected:
	string name;
	long years;
	long height;
	long id;

public:
	People(string pName, long pYears) {
		name = pName;
		years = pYears;
		id = people::g_id;
		people::g_id++;
	}

	virtual void Show() {
		cout << "\nName: " << name;
		cout << "\nYears: " << years;
		cout << "\nId: " << id;
		cout << "\n";
	}
};

// Адаптований клієнт
class StudentInformation {
public:
	long GetHeight(long id) const {
		return 1600 + rand() % 200;
	}
};

// Адаптер
class Student : public People {
private:
	std::unique_ptr <StudentInformation> pInformation;
public:
	Student(string pName, long pYear) : People(pName, pYear) {
		pInformation = std::make_unique <StudentInformation>();
	}

	void Show() {
		cout << "\n============================\n";
		People::Show();
		height = pInformation->GetHeight(id);
		cout << "\nHeight: " << height << " cm" << endl;
	}
};

int main() {
	std::unique_ptr <People> ptr = std::make_unique<People>("Danya", 46);
	ptr->Show();

	ptr = std::make_unique<Student>("Adolf", 46);
	ptr->Show();

	ptr = std::make_unique<Student>("Anya", 52);
	ptr->Show();

	ptr = std::make_unique<Student>("Sasha", 33);
	ptr->Show();

	return 0;
}

/*
Код, який дозволяє за допомогою адаптера виводити відомості про особу, які оброблює програма.
*/
