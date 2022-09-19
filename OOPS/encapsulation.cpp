#include<bits/stdc++.h>
using namespace std;

class Employee
{
  public:
  string Name;
  string Company;
  int Age;

  Employee(string name,string company, int age) {
    Name = name;
    Company = company;
    Age = age;
  }

  void introduceYourself() {
    cout << "Name - " << Name << endl;
    cout << "Company - " << Company << endl;
    cout << "Age - " << Age << endl;

  }
};

int main() {
  Employee * e = new Employee("Surya", "Google", 25);
  // e.Age = 25;
  // e.Company = "Google";
  // e.Name = "Surya";
  e->introduceYourself();
  return 0;
}
