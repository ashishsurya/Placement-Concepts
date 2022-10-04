/*
Making the data members private and adding getters/setters.
*/
#include<bits/stdc++.h>
using namespace std;

class AbstractEmployee {
  virtual void askForPromotion() = 0;
};

class Employee : AbstractEmployee
{
  private:
  string Name;
  string Company;
  int Age;

  public:
  Employee(string name,string company, int age) {
    Name = name;
    Company = company;
    Age = age;
  }

  void setName(string name) {
    Name = name;
  }

  void setCompany(string company) {
    Company = company;
  }

  void setAge(int age) {
    Age = age;
  }

  string getName() {
    return Name;
  }

  string getCompany() {
    return Company;
  }

  int getAge() {
    return Age;
  }

  void introduceYourself() {
    cout << "Name - " << Name << endl;
    cout << "Company - " << Company << endl;
    cout << "Age - " << Age << endl;

  }

  void askForPromotion() {
    if(Age > 30) {
      cout << Name << " got promoted" << endl;
    }
  }
};

int main() {
  Employee * e = new Employee("Surya", "Google", 25);
  // e.Age = 25;
  // e.Company = "Google";
  // e.Name = "Surya";
  e->askForPromotion();
  e->introduceYourself();

  e->setAge(35);
  e->askForPromotion();
  e->introduceYourself();
  return 0;
}
