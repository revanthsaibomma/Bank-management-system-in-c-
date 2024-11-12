#include <iostream>
#include <string>
using namespace std;
class Bank
{
    string name, address;
    char acc_type;
    float balance;
public:
    void open_account();
    void deposit_money();
    void withdraw_money();
    void display_account();
    void change_account_details();
    void check_balance();
    void transfer_money(Bank &recipient);
    void close_account();
};
void Bank::open_account() 
{
    cout << "Enter your full name: ";
    getline(cin, name);
    cout << "Enter your address: ";
    getline(cin, address);
    cout << "What type of account would you like to open? Saving (S) or Current (C): ";
    cin >> acc_type;
    cout << "Enter the amount you would like to deposit: ";
    cin >> balance;
    cout << "Account Created Successfully\n";
}
void Bank::deposit_money()
{
    float amount;
    cout << "Enter the amount you want to deposit: ";
    cin >> amount;
    if (amount > 0)
    {
        balance += amount;
        cout << "\nDeposit Successful. Available Balance: Rs." << balance << endl;
    }
    else 
    {
        cout << "\nInvalid amount entered.\n";
    }
}
void Bank::withdraw_money()
{
    float amount;
    cout << "Enter the amount you want to withdraw: ";
    cin >> amount;
    if (amount > 0 && amount <= balance) 
    {
        balance -= amount;
        cout << "\nWithdrawal Successful. Available Balance: Rs." << balance << endl;
    } 
    else 
    {
        cout << "\nInsufficient balance or invalid amount.\n";
    }
}
void Bank::display_account()
{
    cout << "\nAccount Details:\n";
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Account Type: " << (acc_type == 'S' ? "Saving" : "Current") << endl;
    cout << "Balance: Rs." << balance << endl;
}
void Bank::change_account_details() 
{
    cout << "Enter new address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Change account type? Saving (S) or Current (C): ";
    cin >> acc_type;
    cout << "Account details updated.\n";
}
void Bank::check_balance()
{
    cout << "Available Balance: Rs." << balance << endl;
}

void Bank::transfer_money(Bank &recipient) 
{
    float amount;
    cout << "Enter the amount to transfer: ";
    cin >> amount;
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        recipient.balance += amount;
        cout << "Transfer Successful. Your Available Balance: Rs." << balance << endl;
    } 
    else 
    {
        cout << "Transfer failed: insufficient balance or invalid amount.\n";
    }
}
void Bank::close_account() 
{
    cout << "Closing your account...\n";
    name = address = "";
    acc_type = '\0';
    balance = 0;
    cout << "Account closed successfully.\n";
}
int main() 
{
    Bank customer1, customer2;
    int choice;
    do
    {
        cout << "\n--- Bank System Menu ---\n";
        cout << "1) Open Account\n";
        cout << "2) Deposit Money\n";
        cout << "3) Withdraw Money\n";
        cout << "4) Display Account Details\n";
        cout << "5) Change Account Details\n";
        cout << "6) Check Balance\n";
        cout << "7) Transfer Money\n";
        cout << "8) Close Account\n";
        cout << "9) Exit\n";
        cout << "Select an option: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
            case 1:
                customer1.open_account();
                break;
            case 2:
                customer1.deposit_money();
                break;
            case 3:
                customer1.withdraw_money();
                break;
            case 4:
                customer1.display_account();
                break;
            case 5:
                customer1.change_account_details();
                break;
            case 6:
                customer1.check_balance();
                break;
            case 7:
                cout << "Transferring money to another customer...\n";
                customer1.transfer_money(customer2);
                break;
            case 8:
                customer1.close_account();
                break;
            case 9:
                cout << "Thank you for using the banking system. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }
    while (choice != 9);
    return 0;
}
