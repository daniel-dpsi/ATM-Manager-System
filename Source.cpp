#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <random>
#include <Windows.h>
using namespace std;

class Account {
private:
	string Name; // initializing object(account) properties
	int AccountNumber;
	string AccountType;
	double AccountBalance;

public:
	Account(const string& name = "", int accountnumber = 0, const string& accounttype = "", double accountbalance = 0) : 
		Name{ name }, AccountNumber{ accountnumber }, AccountType{ accounttype }, AccountBalance{accountbalance} {} // another instance of initialization (private -> public)

	string getName() { return Name; } // getter calls for all account properties
	int getAccNumber() { return AccountNumber; }
	string getAccType() { return AccountType; }
	double getAccBalance() { return AccountBalance; }

	void setName(string name = "") {
		this->Name = name; //setter methods for initialization of account properties
	}
	void setAccNumber(int accountnumber = 0) {
		this->AccountNumber = accountnumber; // use of this-> pointers only for better visual overview (optional use)
	}
	void setAccType(string accounttype = "") {
		this->AccountType = accounttype; 
	}
	void setAccBalance(double accountbalance = 0) {
		this->AccountBalance = accountbalance; 
	}

};

int main() {
	Account acc; // declaring the object account -> acc

	string Name; // declaring all properties for use in setter methods
	int AccountNumber;
	string AccountType;
	double AccountBalance;

	cout << "ATM Account Configuration intializing..." << endl; // start of the ATM program
	Sleep(5000);
	cout << endl;

	cout << "Enter your first name: " << endl;
	cin >> Name;
	acc.setName(Name); // using a setter method to set the users name property


	cout << "\nChoose an account type: " << endl; // available account type properties
	cout << "1.) Checking account." << endl;
	cout << "\n2.) Savings account." << endl;
	cout << "\n3.) Money Market account." << endl;
	cout << "\n4.) Pre-paid account." << endl;

	int acctype = 0; // gets the users type property selection
	cin >> acctype;

	if (acctype == 1) { // creates and assigns a custom number to an account property depending on the users selection
		Sleep(2000);
		system("cls"); // clears console screen for better visual overview (again use is optional)
		AccountNumber = rand() % 654321 + 123456; // initializes a random account number in the specified range
		acc.setAccNumber(AccountNumber);

		acc.setAccType("Checking"); // assigning account type property (Checking,Savings,Money market or Prepaid)

		cout << acc.getAccType() << " account with number: " << acc.getAccNumber() << " created successfully." << endl; 

	}

	if (acctype == 2) {
		Sleep(2000);
		system("cls");
		AccountNumber = rand() % 654322 + 223456;
		acc.setAccNumber(AccountNumber);

		acc.setAccType("Savings");

		cout << acc.getAccType() << " account with number: " << acc.getAccNumber() << " created successfully." << endl;

	}

	if (acctype == 3) {
		Sleep(2000);
		system("cls");
		AccountNumber = rand() % 654322 + 223456;
		acc.setAccNumber(AccountNumber);

		acc.setAccType("Money market");

		cout << acc.getAccType() << " account with number: " << acc.getAccNumber() << " created successfully." << endl;

	}

	if (acctype == 4) {
		Sleep(2000);
		system("cls");
		AccountNumber = rand() % 654321 + 123456;
		acc.setAccNumber(AccountNumber);

		acc.setAccType("Prepaid");

		cout << acc.getAccType() << " account with number: " << acc.getAccNumber() << " created successfully." << endl;

	}

	cout << "\n" << "Account nr. " << acc.getAccNumber() << " has a balance of : $" << acc.getAccBalance() << "." << endl; // checks the account status
	if (acc.getAccBalance() == 0.00 || acc.getAccBalance() == 0.0 || acc.getAccBalance() <= 0) { // automatically assigns a starting balance if balance is <= to 0
		cout << "\nBalance of 0 detected. Automatic starting balance assigned." << endl;
	}

	double startingbal = rand() % 654421 + 213426; // initializes a random starting balance within the specified range
	acc.setAccBalance(startingbal); // passing in a value to a setter


	cout << "\nNew account balance of " << acc.getAccNumber() << " is now $" << acc.getAccBalance() << "." << endl;

	Sleep(13000);
	system("cls");

	bool atm = true; // a bool with a infinite loop to keep the program running (selecting exit switches it the loop off thus terminating the program)
	while(atm) {

	cout << "Good evening " << acc.getName() << ". Select an option." << endl; // user selection of a function property
	cout << "\n1.)Make a deposit." << endl;
	cout << "\n2.)Make a withdrawal." << endl;
	cout << "\n3.)Check account status." << endl;
	cout << "\n4.)Exit ATM machine." << endl;

	int option = 0;
	cin >> option;

	if (option == 1 && acc.getAccType() != "Prepaid") { // depending on the users selection program initializes a function (deposit,withdrawal,account status or exit function)
		Sleep(2000);
		system("cls");
		cout << "Deposit initialized. Please insert the amount you'd like to deposit." << endl;
		double damount = 0;
		cin >> damount;

		acc.setAccBalance(acc.getAccBalance() + damount); // gets the current acc balance and adds the amount that was specified by the user
        
		cout << "\nDeposit successful new " << acc.getAccType() << " account balance is now: $" << acc.getAccBalance() << endl;
		cout << endl;
	}

	if (option == 2) {
		Sleep(2000);
		system("cls");
		cout << "Withdrawal initialized. Please insert the amount you'd like to withdraw." << endl;
		cout << "Amount available for withdrawal: $" << acc.getAccBalance() << endl;
		double wamount = 0;
		cin >> wamount;

		if (wamount > acc.getAccBalance()) { // if the chosen withdrawal amount if greater than that of available balance - throws an exception indicating the issue
			Sleep(2000);
			system("cls");
			cout << "Insufficient funds for withdrawal." << endl;
		}
		else {
			Sleep(2000);
			system("cls");
			acc.setAccBalance(acc.getAccBalance() - wamount); // gets the current acc balance and subtracts the amount that was specified by the user
			cout << "Withdrawal successful new " << acc.getAccType() << " account balance is now: $" << acc.getAccBalance() << endl;
			cout << endl;
		}
	 }

	if (option == 3) {
		Sleep(2000);
		system("cls");
		cout << acc.getAccType() << " account with nr. " << acc.getAccNumber() << " has a current status of $" << acc.getAccBalance() << endl; // checks the current account status
		cout << endl;
	}

	if (acc.getAccType() == "Prepaid" && option == 1) { // a filter to prevent deposits to a prepaid account type
		Sleep(2000);
		system("cls");
		cout << "Transaction failed. Cannot make a deposit to a prepaid account." << endl;
		cout << endl;
	}

	if (option == 4) { // an exit function - will stop the loop thus exiting the program (atm machine)
		Sleep(2000);
		system("cls");
		cout << "Exiting ATM..." << endl;
		Sleep(3000);
		atm = !atm; // switches the bool from true->false which disables the infinite loop
	}

	}
}