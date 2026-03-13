#include <iostream>
#include <string>
using namespace std;

class Employee
{
    public:
        string firstname;
        string lastname;
        string position;
        int rate;

        Employee() : Employee("Lorem", "Ipsum", "default", 0)
        {}

        Employee(string firstname, string lastname, string position, int rate)
        {
            this->firstname = firstname;
            this->lastname = lastname;
            this->position = position;
            this->rate = rate;
        }
};

class Company
{
    public:
        Employee** employees = new Employee*[100];
        int n = 0;
        string name;

        Company(string name):name(name){}

        void add_employee(Employee *e)
        {
            employees[n] = e;
            n += 1;
        }

        void number_employees()
        {
            cout << n << " employee(s)." << endl;
        }

        void print_employee(int a)
        {
            if (a < n)
                cout << employees[a]->firstname << " " << employees[a]->lastname << " (" << employees[a]->position << ") " << employees[a]->rate << " EUR\n";
        }

        void print_rate(string lastname)
        {
            for (int i = 0; i < n; i++)
                if (employees[i]->lastname == lastname)
                    cout << employees[i]->rate << " EUR\n";
        }
};

int main()
{
    Employee *e1 = new Employee("Luke", "Skywalker", "Jedi Knight", 2750);
    Employee *e2 = new Employee("Bilbo", "Baggins", "Hobbit", 3000);
    Employee *e3 = new Employee("Gandalf", "The White", "Maiar", 5000);
    Employee *e4 = new Employee("Obi-Wan", "Kenobi", "Jedi Master", 4500);
    Employee *e5 = new Employee("Darth", "Vader", "Lord", 5000);
    Employee *e6 = new Employee("Yoda", "", "Grand Master Jedi", 5000);
    Employee *e7 = new Employee("Faramir", "of Gondor", "Captain", 2500);
    Employee *e8 = new Employee("Gollum", "Smeagol", "Slave", 1);
    Employee *e9 = new Employee("Sheev", "Palpatine", "Emperor", 1000000);

    Company *c = new Company("One Company to Rule them All");
    c->add_employee(e1);
    c->add_employee(e2);
    c->add_employee(e3);
    c->add_employee(e4);
    c->add_employee(e5);
    c->add_employee(e6);
    c->add_employee(e7);
    c->add_employee(e8);
    c->add_employee(e9);

    c->number_employees();

    c->print_rate("Kenobi");

    int input = 0;
    while (input >= 0 && input < 100)
    {
        cin >> input;
        c->print_employee(input);
    }
    
    return 0;
}