#include <iostream>
#include <string>
using namespace std;

class Transaction
{
public:
    string type;
    double amount;
    void set(string t, double a)
    {
        type = t;
        amount = a;
    }
};

class Account
{
private:
    double balance;
    Transaction *history;
    int size;
    int capacity;

    void grow()
    {
        capacity *= 2;
        Transaction *newHistory = new Transaction[capacity];
        for (int i = 0; i < size; i++)
        {
            newHistory[i] = history[i];
        }
        delete[] history;
        history = newHistory;
    }

public:
    Account()
    {
        balance = 0.0;
        size = 0;
        capacity = 2;
        history = new Transaction[capacity];
    }
    ~Account()
    {
        delete[] history;
    }

    void deposit(double amt)
    {
        if (amt > 0)
        {
            balance += amt;
            if (size == capacity)
                grow();
            history[size++].set("Deposit", amt);
            cout << "-----------------------" << endl;
            cout << "Deposit successful     " << endl;
            cout << "-----------------------" << endl;
        }
    }

    void withdraw(double amt)
    {
        if (amt > 0 && amt <= balance)
        {
            balance -= amt;
            if (size == capacity)
                grow();
            history[size++].set("Withdraw", amt);
            cout << "-----------------------" << endl;
            cout << "Withdrawal successful  " << endl;
            cout << "-----------------------" << endl;
        }
        else
        {
            cout << "-----------------------" << endl;
            cout << "Insufficient funds     " << endl;
            cout << "-----------------------" << endl;
        }
    }

    void display()
    {
        cout << "\n********** Account Details **********" << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "-------------------------------------" << endl;
        cout << "Transaction History:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "- " << history[i].type << ": $" << history[i].amount << endl;
        }
        cout << "*************************************" << endl;
    }
};

class Customer
{
public:
    string name;
    int id;
    Account account;

    void setCustomer(string n, int i)
    {
        name = n;
        id = i;
    }

    void showCustomer()
    {
        cout << "********* Customer Details **********" << endl;
        cout << "Customer Name: " << name << endl;
        cout << "Customer ID  : " << id << endl;
        cout << "*************************************" << endl;

        account.display();
    }
};

int main()
{
    Customer *cust = new Customer();

    cust->setCustomer("Ali", 101);

    int choice = 0;
    double amt = 0;

    cout << "****************************************" << endl;
    cout << "*            Banking System            *" << endl;
    cout << "****************************************" << endl;

    while (true)
    {
        cout << "1. Deposit\n2. Withdraw\n3. View Statement\n4. View Customer\n5. Exit\nChoice: ";
        cin >> choice;
        cout << "----------------------------------------" << endl;

        if (choice == 1)
        {
            cout << "Enter amount: ";
            cin >> amt;
            cust->account.deposit(amt);
        }
        else if (choice == 2)
        {
            cout << "Enter amount: ";
            cin >> amt;
            cust->account.withdraw(amt);
        }
        else if (choice == 3)
        {
            cust->account.display();
        }
        else if (choice == 4)
        {
            cust->showCustomer();
        }
        else if (choice == 5)
        {
            cout << "Exiting...       " << endl;
            cout << "----------------------------------------" << endl;
            break;
        }
    }

    delete cust;
    return 0;
}