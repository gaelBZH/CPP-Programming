#include <iostream>
#include <string>
using namespace std;

// Create the class Person storing the first name and last name.
// Add the constructor initiating all componentsand method Write to the class.
// Create the class Book consisting of the following elements:
// title, author (type Person) and constructor initiating all components and method Write. 
// Create the class Reader, inheriting from the class Person.
// Additionally, the class Reader should contain the array of objects of the type Book
// (a list of books read by the given reader will be stored in it). The class Reader should have the method WriteBooks
// writing titles of books read by the reader.
// Create the following objects: 5 books, and 3 readers. Assign any 3 selected books to the list of read books
// for each reader. Call the method WriteBooks for each reader.


class Person {
public:
    string FirstName;
    string LastName;

    Person() : FirstName(""), LastName("") {}

    Person(string firstName, string lastName) : FirstName(firstName), LastName(lastName) {}

    virtual void Write()
    {
        cout << FirstName << " " << LastName << endl;
    }
};


class Book
{
public:
    string title;
    Person author;

    Book() : title(""), author("", "") {}

    Book(string t, Person a) : title(t), author(a) {}

    void Write()
    {
        cout << "\"" << title << "\" by ";
        author.Write();
    }
};


class Reader : public Person
{
private:
    Book read[3];

public:
    Reader(string name, string surname, Book b1, Book b2, Book b3) : Person(name, surname)
    {
        read[0] = b1;
        read[1] = b2;
        read[2] = b3;
    }

    void WriteBooks()
    {
        cout << "Books read by " << FirstName << " " << LastName << ":" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << " - ";
            read[i].Write();
            cout << endl;
        }
        cout << "--------------------------" << endl;
    }
};

int main()
{ 
    Person p1("George", "Orwell");
    Person p2("Aldous", "Huxley");
    Person p3("Ray", "Bradbury");

    Book b1("1984", p1);
    Book b2("Animal Farm", p1);
    Book b3("Brave New World", p2);
    Book b4("Fahrenheit 451", p3);
    Book b5("The Martian Chronicles", p3);

    Reader r1("Alice", "Smith", b1, b2, b3);
    Reader r2("Bob", "Jones", b2, b3, b4);
    Reader r3("Charlie", "Brown", b1, b4, b5);

    r1.WriteBooks();
    r2.WriteBooks();
    r3.WriteBooks();

    return 0;
}