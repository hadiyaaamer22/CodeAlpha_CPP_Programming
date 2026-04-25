#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isUsernameTaken(string username)
{
    string *u = new string;
    string *p = new string;
    ifstream file("database.txt");
    if (!file.is_open())
    {
        delete u;
        delete p;
        return false;
    }

    while (file >> *u >> *p)
    {
        if (*u == username)
        {
            file.close();
            delete u;
            delete p;
            return true;
        }
    }
    file.close();
    delete u;
    delete p;
    return false;
}

void registerUser()
{
    string username = "";
    string password = "";

    cout << "\n********** Registration **********" << endl;
    cout << "Username: ";
    cin >> username;

    if (isUsernameTaken(username))
    {   
        cout << "-----------------------" << endl;
        cout << "Username already exists" << endl;
        cout << "-----------------------" << endl;
        return;
    }

    cout << "Password: ";
    cin >> password;

    ofstream file("database.txt", ios::app);
    if (file.is_open())
    {
        file << username << " " << password << endl;
        file.close();
        cout << "-----------------------" << endl;
        cout << "Registered successfully" << endl;
        cout << "-----------------------" << endl;
    }
}

bool loginUser()
{
    string inputU = "";
    string inputP = "";
    string storedU = "";
    string storedP = "";

    cout << "\n********** Login **********" << endl;
    cout << "Username: ";
    cin >> inputU;
    cout << "Password: ";
    cin >> inputP;

    ifstream file("database.txt");
    bool found = false;
    if (file.is_open())
    {
        while (file >> storedU >> storedP)
        {
            if (storedU == inputU && storedP == inputP)
            {
                found = true;
                break;
            }
        }
        file.close();
    }

    return found;
}

int main()
{
    int choice = 0;
    cout << "****************************************" << endl;
    cout << "*    Login and Registration System     *" << endl;
    cout << "****************************************" << endl;
    while (true)
    {
        cout << "1. Register\n2. Login\n3. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1)
        {
            registerUser();
        }
        else if (choice == 2)
        {
            if (loginUser())
            {
                cout << "-----------------" << endl;
                cout << "Login successfull" << endl;
                cout << "-----------------" << endl;
            }
            else
            {   
                cout << "-------------------" << endl;
                cout << "Invalid credentials" << endl;
                cout << "-------------------" << endl;
            }
        }
        else if (choice == 3)
        {   
            cout << "-----------------" << endl;
            cout << "Exiting..." << endl;
            cout << "-----------------" << endl;
            break;
        }
    }
    return 0;
}