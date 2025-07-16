#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const int SIZE = 100; //set constant integer SIZE to 100 as global variable
string currentUser; //set currentUser as global variable

//list of function prototypes
void menu();
void registerNewUser();
void readUserDetails(string userDetails[][4], int& userNum);
int login(string userDetails[][4], int& userNum, string& username);
void readItemList(string items[], string codes[], double price[], double weight[], int& totalNumber);
void addItemList(string items[], string codes[], double price[], double weight[], int& totalNumber);
void displayItemList(string items[], string codes[], double price[], double weight[], int& totalNumber);
void readTransaction(double& totalAmountTransaction, string date[], double amountSpend[], int& totalTransactionHistory);
void transaction(double& totalAmountTransaction, string date[], double amountSpend[], int& totalTransactionHistory);
void displayTransactionDetails(double& totalAmountTransaction, string date[], double amountSpend[], int& totalTransactionHistory);

int main()
{
	//list of variables used
	int choice = 0, contRL = 0;
	int respond;
	string userDetails[SIZE][4], username;
	int userNum;
	string items[SIZE], codes[SIZE];
	double price[SIZE];
	double weight[SIZE];
	int totalNumber = 0, cont = 1;
	string strselect;
	char arr[1];
	string date[SIZE];
	double amountSpend[SIZE];
	double totalAmountTransaction = 0;
	int totalTransactionHistory = 0;

	do {
		cout << "                                                         *                                         *                    " << endl;
		cout << "                                     *                                                                                  " << endl;
		cout << "                *                               *                             ##  +  ..__.                              " << endl;
		cout << "                               *                              *           _ _  +           #;                           " << endl;
		cout << "          *           _## __ +  ..__.                                       +:.________....--                           " << endl;
		cout << "                   _ |  +           #;                                                                                  " << endl;
		cout << "                   +:.________....--                        *          *                     *                          " << endl;
		cout << "           *                                                                                                            " << endl;
		cout << "                                                    *                                                                   " << endl;
		cout << "                       *                                                          *                                     " << endl;
		cout << "                                         _                       *                                                      " << endl;
		cout << "                                        | |                                                                             " << endl;
		cout << "                                        | |                                                                             " << endl;
		cout << "           --------------------------------------                                                                       " << endl;
		cout << "           |                                    |                                                                       " << endl;
		cout << "           |         JSJK MINI MARKET           |                                                                       " << endl;
		cout << "           |           WELCOME YOU              |                                                                       " << endl;
		cout << "           |                                    |                                                                       " << endl;
		cout << "           --------------------------------------                                                                       " << endl;
		cout << "           |    ------               ------     |                               ____________________________            " << endl;
		cout << "           |   |      |             |      |    |                              |  1. Register New User?     |           " << endl;
		cout << "           |    ------               ------     |                              |                            |           " << endl;
		cout << "           --------------------------------------                              |  2. Login                  |           " << endl;
		cout << "           |                                    |                              |                            |           " << endl;
		cout << "           |                                    |                              |  3. Quit                   |           " << endl;
		cout << "           |            -----------             |               (\\____/)       |_______ ____________________|           " << endl;
		cout << "           |           |     |     |            |                (_o o_)              //                                " << endl;
		cout << "           |           |     |     |            |                   ()                                                  " << endl;
		cout << "           |           |    o|o    |            |                 __| |__           \\)                                 " << endl;
		cout << "           |           |     |     |            |                /       \\   []    /                                   " << endl;
		cout << "           --------------------------------------               /_________\\ /  \\/                                     " << endl;
		cout << "                                                                                                                        " << endl;

		cout << "\a" << endl;

		cout << "Choice: ";
		cin >> choice; //choice is for the activity choose to carry out
		cin.ignore();

		if (choice == 1) {
			registerNewUser(); //calling registerNewUser function

			cout << "Do you want to continue login? (1-yes, 2-no): ";
			cin >> contRL; //contRL is for the choice if the user want to continue login

			if (contRL == 2)
				return 0;
		}
		else if (choice == 2) {

			readUserDetails(userDetails, userNum); //calling readUserDetails function to check the validation of the user to enter the system
			respond = login(userDetails, userNum, username); //calling login function and the name respond is to recieve the value that pass back by the function

			if (respond == 1)
			{
				currentUser = username; //the global variable of currentUser will change to the username who succesfully login to the system
				cout << "Login Successfully!" << endl;
				system("pause");
				break; //if user successfully login to the system, it will directly proceed to the next part which is item part
			}
			else if (respond == 2)
			{
				cout << "Username or Password not correct !" << endl;
				cout << "If you have not registered, please register first! " << endl;
				cout << "Do you want to continue login? (1-yes, 2-no): "; //ask user whether they want to retry to login or quit 
				cin >> contRL;
				cin.ignore();
			}

			if (contRL == 2) {
				system("cls");
				return 0; //quit the system
			}

		}
		else if (choice == 3)
		{
			return 0;
		}

		else
		{
			cout << "Invalid Choice." << endl;
		}

		system("cls");
	} while (contRL == 1);

	readItemList(items, codes, price, weight, totalNumber); //calling readItemList function to read in data in the XX_ItemList.txt

	readTransaction(totalAmountTransaction, date, amountSpend, totalTransactionHistory); //calling readItemList function to read in data in the XX_Transaction.txt

	do
	{
		system("cls");
		cout << setw(75) << "++++++++++++++++++++++++++++++++" << endl;
		cout << setw(75) << "            * MENU *            " << endl;
		cout << setw(75) << "++++++++++++++++++++++++++++++++" << endl << endl;
		cout << ">>  " << "Username: " << currentUser << "  <<" << endl << endl;

		menu();
		cout << endl;
		cout << "Choice: ";
		cin >> strselect; //prompt user to enter their choice based on the options listed in menu

		system("cls");
		cin.ignore();

		bool validateNumber = strselect.length() < 2; //check user's input, string with single character (strselect is declared as string, "\0" has to be taken in consideration, the size of strselect should be < 2)
		arr[0] = strselect[0]; //store the first character into arr[0]

		if (!isalpha(arr[0]) && validateNumber) //check if arr[0] is not alphabet and the boolean (validateNumber) is true
		{
			int select = stoi(strselect); //convert strselect into integer data type
			if (select == 1)
				displayItemList(items, codes, price, weight, totalNumber); //calling displayItemList function
			else if (select == 2)
				addItemList(items, codes, price, weight, totalNumber); //calling addItemList function
			else if (select == 3)
				transaction(totalAmountTransaction, date, amountSpend, totalTransactionHistory); //calling transaction function
			else if (select == 4)
				displayTransactionDetails(totalAmountTransaction, date, amountSpend, totalTransactionHistory); //calling displayTransactionDetails
			else if (select == 5)
				break;
			else
				cout << "Not available" << endl << endl;
		}
		else
			cout << "Not available" << endl << endl;

		system("pause");
		continue;

	} while (cont == 1);
	return 0;
}

void menu()
{
	cout << "(1) Display Item List" << endl;
	cout << "(2) Add Item List" << endl;
	cout << "(3) Perform Transaction" << endl;
	cout << "(4) Display Transaction History" << endl;
	cout << "(5) Quit" << endl;
}

void readUserDetails(string userDetails[][4], int& userNum) //4 is for name, gender, dob and password of the customer
{
	userNum = 0; //initialize the user number as 0, since the array index is start from 0
	ifstream inFile("user.txt"); //open file to read

	if (inFile.fail())
	{
		cout << "Unable to open the file." << endl;
	}
	else
	{
		while (!inFile.eof()) //read each user's details from the file, each loop only read for one user's details
		{
			getline(inFile, userDetails[userNum][0]);
			getline(inFile, userDetails[userNum][1]);
			inFile >> userDetails[userNum][2];
			inFile >> userDetails[userNum][3];
			inFile.ignore();

			userNum++; //continue looping until end of file by incrementing the user number

		}
		inFile.close();
	}
}

void registerNewUser()
{

	string username, password, gender, dateofbirth;
	ofstream outFile;
	outFile.open("user.txt", ios::app); //so that the previous file information retain

	//get some required infomation from user to create an account for them
	if (outFile.is_open())
	{
		cout << "Username: ";
		getline(cin, username);
		cout << "Password: ";
		cin >> password;
		cout << "Gender: ";
		cin >> gender;
		cin.ignore();
		cout << "Date of Birth: ";
		cin.ignore();
		getline(cin, dateofbirth);

		record the infomation from the user in our system file
			outFile << username << endl;
		outFile << dateofbirth << endl;
		outFile << gender << " " << password << endl;

		outFile.close();
	}
	else
	{
		cout << "Unable open file." << endl;
	}

}

int login(string userDetails[][4], int& userNum, string& username)
{
	string password;
	int respond = 0;
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);


	for (int i = 0; i < userNum; i++) //check whether the infomation enter by the customer is exist and correct or not
	{
		//set to check the specific user's name and password only, each loop only check for one user's details
		if (username == userDetails[i][0] && password == userDetails[i][3])
		{
			respond = 1;
			break;
		}
		else if (username == userDetails[i][0] && password != userDetails[i][3])
		{
			respond = 2;
		}
		else if (username != userDetails[i][0] && password == userDetails[i][3])
		{
			respond = 2;
		}
		else
		{
			respond = 2;
		}

	}
	return respond; //pass back the value of respond to where the fucntion called in main function
}

void readItemList(string items[], string codes[], double price[], double weight[], int& totalNumber)
{
	string filename = currentUser + "_ItemList.txt";
	ifstream inFile;
	inFile.open(filename, ios::in); //open the file to read in all the data and store into array of specific parameters
	if (inFile.is_open())
	{
		int i = 0;
		while (!inFile.eof() && i < SIZE) //continue looping when no end of file and i < SIZE
		{
			if (getline(inFile, items[i]) && items[i].length() != 0) //check if there is data in items[i] after reading in
			{
				inFile >> codes[i];
				inFile >> price[i];
				inFile >> weight[i];
				inFile.ignore();
				i++;
			}
			else
				totalNumber = i; //if there is no data in items[i], value of i is assigned to totalNumber
		}
		inFile.close();
	}
	else
	{
		ofstream outFile;
		outFile.open(filename); //create and open the file when it does not exist
		outFile.close();
	}
}

void addItemList(string items[], string codes[], double price[], double weight[], int& totalNumber)
{
	cout << setw(75) << "+*******************************+" << endl;
	cout << setw(75) << "        > ADD NEW ITEMS <        " << endl;
	cout << setw(75) << "+*******************************+" << endl << endl;

	string filename = currentUser + "_ItemList.txt";
	ofstream outFile;
	outFile.open(filename, ios::app); //open the file to append
	if (outFile.is_open())
	{
		int choice = 0;
		cout << "<  " << "Add new items?" << "  > " << "(1 - yes, 2 - no): ";
		cin >> choice; //prompt user to enter their choice
		cin.ignore();

		int i = totalNumber; //i is initialised to totalNumber to continue the numbering of the array
		while (choice == 1 && i < SIZE) //enter the while loop when choice equal to 1 and i < SIZE
		{
			cout << "=========================================" << endl << endl;

			cout << "New Item's Name               : ";
			getline(cin, items[i]);

			cout << "New Items's Code              : ";
			cin >> codes[i];

			cout << "Price of New Item per KG (RM) : ";
			cin >> price[i];

			cout << "Purchasing Weight (KG)        : ";
			cin >> weight[i];

			outFile << items[i] << endl;
			outFile << codes[i] << endl;
			outFile << showpoint << fixed << setprecision(2) << price[i] << " " << weight[i] << endl;

			i++;
			cout << endl << endl;

			cout << "<  " << "Add new items?" << "  > " << "(1 - yes, 2 - no): ";
			cin >> choice; //prompt user to enter their choice
			cin.ignore();
		}
		totalNumber = i; //value of i is set to totalNumber
		outFile.close();
	}
	else
		cout << "Error: Unable to open file for appending" << endl; //display "Error: Unable to open file for appending" when unable to open the file to append

	cout << "=========================================" << endl << endl;
	cout << endl;
}

void displayItemList(string items[], string codes[], double price[], double weight[], int& totalNumber)
{
	cout << setw(75) << "+*******************************+" << endl;
	cout << setw(75) << "        > DISPLAY ITEMS <        " << endl;
	cout << setw(75) << "+*******************************+" << endl << endl;

	if (totalNumber > 0) //totalNumber must be greater than 0
	{
		for (int i = 0; i < totalNumber; i++) //for loop is used to display all the items
		{
			cout << "/////////////////////////////////////" << endl << endl;

			cout << "Item " << (i + 1) << endl;

			cout << "Name              : " << items[i] << endl;

			cout << "Code              : " << codes[i] << endl;

			cout << "Price per KG      : RM" << showpoint << fixed << setprecision(2) << price[i] << endl;

			cout << "Purchasing Weight : " << showpoint << fixed << setprecision(2) << weight[i] << "KG" << endl << endl << endl;
		}
		cout << "/////////////////////////////////////" << endl << endl;
	}
	else
		cout << setw(68) << "No item added yet!" << endl; //display "No item added yet!" when totalNumber is 0

	cout << endl;
}

void readTransaction(double& totalAmountTransaction, string date[], double amountSpend[], int& totalTransactionHistory)
{
	cout << setw(75) << "+*******************************+" << endl;
	cout << setw(75) << "       > READ TRANSACTION <      " << endl;
	cout << setw(75) << "+*******************************+" << endl << endl;

	string filename = currentUser + "_transaction.txt";
	ifstream readTransaction;
	readTransaction.open(filename); //open the XX_transaction.txt to read all the data inside the file

	if (readTransaction.is_open())
	{
		int i = 0;
		readTransaction >> totalAmountTransaction; //reads data from the file and stores it into totalAmountTransaction
		while (!readTransaction.eof() && i < SIZE) //continue looping when no end of file and i < SIZE
		{
			if (readTransaction >> date[i] && date[i].size() != 0) //stores data in array of date and size of the string not equal to 0
				readTransaction >> amountSpend[i]; //store the data into array of amountSpend
			i++;
		}
	else
		totalTransactionHistory = i;
	}
	readTransaction.close(); //close the file
}
	else
	{
		ofstream readTransaction; //write data into the file
		readTransaction.open(filename);
		readTransaction.close(); //close the file
		}
}

void transaction(double& totalAmountTransaction, string date[], double amountSpend[], int& totalTransactionHistory)
{
	cout << setw(75) << "+*******************************+" << endl;
	cout << setw(75) << "     > PERFORM TRANSACTION <     " << endl;
	cout << setw(75) << "+*******************************+" << endl << endl;

	string filename = currentUser + "_transaction.txt";
	ofstream transaction;
	transaction.open(filename, ios::out); //open the file to write the data

	if (transaction.is_open()) //open the file
	{
		int i = totalTransactionHistory;
		int cont = 0;

		do
		{
			cout << "Available Balance: RM " << fixed << setprecision(2) << totalAmountTransaction << endl << endl;

			cout << "Amount of Transaction: RM ";
			cin >> amountSpend[i];

			cout << "Date of Transaction (DD/MM/YYYY): ";
			cin >> date[i];

			totalAmountTransaction += amountSpend[i];
			i++;

			cout << "Continue? (1-yes, 2-no): "; //choose 1 as continue the looping, choose 2 as out of the looping
			cin >> cont;
			cout << endl;
		} while (cont == 1); //if continue equal to 1, enter the looping again

		transaction << totalAmountTransaction << endl; //write the data to the output file

		for (int x = 0; x < i; x++)
		{
			transaction << date[x] << " " << amountSpend[x] << endl;
		}
		totalTransactionHistory = i;

		cout << "Transaction recorded successfully." << endl;
	}
	else
	{
		cout << "Error: Unable to record the transaction." << endl; //display when unable to open file
	}
}

void displayTransactionDetails(double& totalAmountTransaction, string date[], double amountSpend[], int& totalTransactionHistory)
{
	cout << setw(75) << "+*******************************+" << endl;
	cout << setw(75) << " > DISPLAY TRANSACTION HISTORY < " << endl;
	cout << setw(75) << "+*******************************+" << endl << endl;

	if (totalTransactionHistory == 0)
	{
		cout << "No transaction history available." << endl;
	}
	else
	{
		cout << "Available balance: RM " << fixed << setprecision(2) << totalAmountTransaction << endl << endl;

		Display the transaction history
			for (int i = 0; i < totalTransactionHistory; i++)
			{
				cout << "Transaction " << i + 1 << endl;
				cout << "Date: " << date[i] << endl;

				Determine if it's a top-up or spending
					if (amountSpend[i] < 0)
					{
						cout << "Spent Amount: RM " << fixed << setprecision(2) << amountSpend[i] << endl;
					}
					else
					{
						cout << "Top Up Amount: RM " << fixed << setprecision(2) << amountSpend[i] << endl;
					}
				cout << endl;
			}
	}
}