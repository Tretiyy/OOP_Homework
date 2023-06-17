#include <iostream>
#include <string>

using namespace std;

#pragma region First
/*class String
{
public:
    // default string
    String()
    {
        size = 80;
        str = new char[size + 1];
        strcpy_s(str, size + 1, "");
    }

    // custom string
    String(int newSize)
    {
        size = newSize;
        str = new char[size + 1];
        strcpy_s(str, size + 1, "");
    }

    // user input
    String(const char* input)
    {
        size = strlen(input);
        str = new char[size + 1];
        strcpy_s(str, size + 1, input);
    }

    // copy
    String(const String& other)
    {
        size = other.size;
        str = new char[size + 1];
        strcpy_s(str, size + 1, other.str);
    }

    ~String()
    {
        delete[] str;
    }

    int Length()
    {
        return size;
    }

    char StartWith()
    {
        if (size > 0)
            return str[0];
        else
            return '\0';
    }

    char EndsWith()
    {
        if (size > 0)
            return str[size - 1];
        else
            return '\0';
    }

    bool Equal(const char* other)
    {
        return (strcmp(str, other) == 0);
    }

    // getter
    char* GetStr()
    {
        return str;
    }

    // setter
    void SetStr(const char* newStr)
    {
        delete[] str;

        size = strlen(newStr);
        str = new char[size + 1];
        strcpy_s(str, size + 1, newStr);
    }
private:
    char* str;
    int size;
};*/
#pragma endregion

#pragma region Second (3)
class Person
{
public:
    Person(const char* n)
    {
        size_t length = strlen(n) + 1;
        name = new char[length];
        strcpy_s(name, length, n);
    }

    Person(const Person& other)
    {
        size_t length = strlen(other.name) + 1;
        name = new char[length];
        strcpy_s(name, length, other.name);
    }

    ~Person()
    {
        delete[] name;
    }

    const char* getName()
    {
        return name;
    }
private:
    char* name;
};

class Apartment
{
public:
    Apartment(int size)
    {
        residents = new Person * [size];
        numResidents = 0;
    }

    Apartment(const Apartment& other)
    {
        numResidents = other.numResidents;
        residents = new Person * [numResidents];
        for (int i = 0; i < numResidents; i++)
        {
            residents[i] = new Person(*(other.residents[i]));
        }
    }

    ~Apartment()
    {
        for (int i = 0; i < numResidents; i++) 
        {
            delete residents[i];
        }
        delete[] residents;
    }

    void addResident(const char* name)
    {
        residents[numResidents] = new Person(name);
        numResidents++;
    }

    void printResidents()
    {
        for (int i = 0; i < numResidents; i++)
        {
            cout << residents[i]->getName() << endl;
        }
    }
private:
    Person** residents;
    int numResidents;
};

class House
{
public:
    House(int size)
    {
        apartments = new Apartment * [size];
        numApartments = 0;
    }

    House(const House& other)
    {
        numApartments = other.numApartments;
        apartments = new Apartment * [numApartments];
        for (int i = 0; i < numApartments; i++)
        {
            apartments[i] = new Apartment(*(other.apartments[i]));
        }
    }

    ~House()
    {
        for (int i = 0; i < numApartments; i++)
        {
            delete apartments[i];
        }
        delete[] apartments;
    }

    void addApartment(int size)
    {
        apartments[numApartments] = new Apartment(size);
        numApartments++;
    }

    void addResidentToApartment(int apartmentIndex, const char* name)
    {
        if (apartmentIndex >= 0 && apartmentIndex < numApartments)
            apartments[apartmentIndex]->addResident(name);
        else
            cout << "Invalid apartment index.\n";
    }

    void printResidentsInApartment(int apartmentIndex) const {
        if (apartmentIndex >= 0 && apartmentIndex < numApartments)
        {
            cout << "Residents in apartment " << apartmentIndex << ":" << endl;
            apartments[apartmentIndex]->printResidents();
        }
        else
            cout << "Invalid apartment index.\n";
    }
private:
    Apartment** apartments;
    int numApartments;
};
#pragma endregion

int main()
{
    // FIRST

    /*String defaultString;
    cout << "Default string: " << defaultString.GetStr() << endl;

    String customSizeString(50);
    cout << "Custom size string: " << customSizeString.GetStr() << endl;

    String userInputString;
    char input[100];

    cout << "Enter a string: ";
    cin.getline(input, 100);
    userInputString.SetStr(input);
    cout << "User input string: " << userInputString.GetStr() << endl;

    String copiedString(userInputString);
    cout << "Copied string: " << copiedString.GetStr() << endl;

    cout << "Length of copied string: " << copiedString.Length() << endl;
    cout << "First character of copied string: " << copiedString.StartWith() << endl;
    cout << "Last character of copied string: " << copiedString.EndsWith() << endl;

    char comparisonStr[100];

    cout << "Enter a string for comparison: ";
    cin.getline(comparisonStr, 100);

    bool isEqual = copiedString.Equal(comparisonStr);

    if (isEqual)
        cout << "Copied string is equal to the comparison string.\n";
    else
        cout << "Copied string is not equal to the comparison string.\n";*/

    // SECOND (3)

    House house(2);

    house.addApartment(2);
    house.addResidentToApartment(0, "Mindy Whon");
    house.addResidentToApartment(0, "Jay Mitchy");

    house.addApartment(1);
    house.addResidentToApartment(1, "Laurie Bray");

    house.printResidentsInApartment(0);
    house.printResidentsInApartment(1);

    system("pause");

    return 0;
}