#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void addEntry(string);
void searchName(string);
void searchNumber(string);
void DeleteEntry(string, string);
void DisplayContents(string);

int main()
{
    string directory = "TelephoneDirectory.txt"; // file that is inputed
    string Newdirectory = "NewTelephoneDirectory.txt"; // name of new file the is created with DeleteEntry

    cout << "This program is for searching, adding and deleting entries\n\n";

    cout << "Enter 1 for adding an telephone directory entry\n";
    cout << "Enter 2 for looking up an entry by name\n";
    cout << "Enter 3 for reverse number lookup\n";
    cout << "Enter 4 to delete an entry by their phone number\n";
    cout << "Enter 5 to view the entire telephone directory\n";
    cout << "Enter 6 to exit the program\n\n";

    int x;
    cin >> x;
    cout << endl;

    switch (x)
    {
    case 1:
        addEntry(directory);
        break;
    case 2:
        searchName(directory);
        break;
    case 3:
        searchNumber(directory);
        break;
    case 4:
        DeleteEntry(directory, Newdirectory);
        break;
    case 5:
        DisplayContents(directory);
        break;
    case 6:
        return 0;
        break;
    default:
        cout << "Please enter numbers 1 through 5" << endl;
        break;
    }

    cout << endl;
    system("PAUSE");
    cout << endl;
    main();
}

void addEntry(string directory)
{
    string firstName, lastName, phoneNumber, address, state, zipCode;

    ofstream inputFile(directory, ios::app);

    cout << endl;
    cout << "Enter the first name\n";
    cin.ignore();
    getline(cin, firstName);

    cout << "Enter the second name\n";
    getline(cin, lastName);

    cout << "Enter the phone number\n";
    getline(cin, phoneNumber);

    cout << "Enter the address\n";
    getline(cin, address);

    cout << "Enter the state\n";
    getline(cin, state);

    cout << "Please Enter the zipCode\n";
    getline(cin, zipCode);

    inputFile << firstName << "\t" << lastName << "\t" << phoneNumber << "\t"
        << address << "\t" << state << "\t" << zipCode << endl;
    inputFile.close();
}

void searchName(string directory)
{
    string line, name;

    cout << "Enter an Name to search for" << endl;
    cin.ignore();
    getline(cin, name);

    ifstream inputFile(directory);

    bool found = false;
    while (getline(inputFile, line) && !found)
    {
        if (line.find(name) != string::npos)
        {
            cout << line << endl;
            found = true;
        }
    }

    if (!found)
        cout << "NOT FOUND" << endl;

    inputFile.close();
}

void searchNumber(string directory)
{
    string line, number;

    cout << "Enter an phone number to search for" << endl;
    cin.ignore();
    getline(cin, number);

    ifstream inputFile(directory);

    bool found = false;
    while (getline(inputFile, line) && !found)
    {
        if (line.find(number) != string::npos)
        {
            cout << line << endl;
            found = true;
        }
    }

    if (!found)
        cout << "NOT FOUND" << endl;

    inputFile.close();
}

void DeleteEntry(string directory, string Newdirectory)
{
    string DeleteNumber, line, text;
    
    ifstream inputFile(directory);
    ofstream newInputFile(Newdirectory);

    cout << "Enter an phone number to delete" << endl;
    cin.ignore();
    getline(cin, DeleteNumber);
    while (getline(inputFile, line))
    {
        if (line.empty())
            newInputFile << line;
        else if (line.find(DeleteNumber) == string::npos)
            newInputFile << line << endl;
    }

    inputFile.close();
    newInputFile.close();
}

void DisplayContents(string directory)
{
    ifstream inputFile("TelephoneDirectory.txt");
    string line, firstName, lastName, phoneNumber, address, state, zipCode;

    inputFile.peek();
    cin.ignore();
    while (inputFile.good())
    {
       getline(inputFile, firstName, '\t');
       getline(inputFile, lastName, '\t');
       getline(inputFile, phoneNumber, '\t');
       getline(inputFile, address, '\t');
       getline(inputFile, state, '\t');
       getline(inputFile, zipCode, '\n');
       cout << firstName << "\t" << lastName << "\t" << phoneNumber << "\t" << address << "\t" << state << "\t" << zipCode << endl << endl;
       inputFile.peek();
    }
    inputFile.close();
}