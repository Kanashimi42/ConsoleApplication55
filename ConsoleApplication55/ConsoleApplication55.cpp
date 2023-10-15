#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
#include <Windows.h>

using namespace std;

typedef pair<string, string> myPair;

int main() {
	map<string, string> arr;
	int userChoice = 0;
	int index = 1;
	bool flag = true;
	string temp = "";
	string temp1 = "";

	do {
		cout << "Menu: " << endl;
		cout << "1. Add" << endl;
		cout << "2. Delete" << endl;
		cout << "3. Edit" << endl;
		cout << "4. Search" << endl;
		cout << "5. Output" << endl;
		cout << "0. Exit" << endl;
		cout << "> ";
		cin >> userChoice;

		if (userChoice > 5 || userChoice < 0) {
			cout << "You entered an invalid menu item!" << endl << endl;
		}
		else if (userChoice == 0) {
			cout << "Goodbye!" << endl;
			break;
		}
		else {
			if (userChoice == 1) {
				do {
					cout << "Enter the word you want to add (English): ";
					cin >> temp;

					if (temp == "Exit0")
						break;

					cout << "Enter the word you want to add (Russian): ";
					cin >> temp1;

					arr.insert(myPair(temp, temp1));

					if (flag) {
						cout << "To exit, write: Exit0" << endl << endl;
						flag = false;
					}

				} while (temp != "Exit0");
				cout << endl;
			}
			else if (userChoice == 2) {
				cout << "Enter the word you want to delete (English): ";
				cin >> temp;

				if (arr.find(temp) == arr.end())
					cout << "Word not found!" << endl;
				else {
					arr.erase(arr.find(temp));
					cout << "Element deleted" << endl;
				}
			}
			else if (userChoice == 3) {
				cout << "Enter the word you want to edit (English): ";
				cin >> temp;

				if (arr.find(temp) == arr.end())
					cout << "Word not found!" << endl;
				else {
					auto it = arr.find(temp);

					cout << "Enter the new word (Russian): ";
					cin >> temp1;

					it->second = temp1;

					cout << "Element edited" << endl;
				}
			}
			else if (userChoice == 4) {
				cout << "Enter the word you want to find: ";
				cin >> temp;

				if (arr.find(temp) == arr.end())
					cout << "Word not found!" << endl;
				else {
					auto it = arr.find(temp);
					cout << it->first << " - " << it->second << endl;
				}
			}
			else if (userChoice == 5) {
				for (auto it = arr.begin(); it != arr.end(); it++) {
					cout << it->first << " - " << it->second << endl;
				}
				cout << endl;
			}
		}

	} while (userChoice != 0 || userChoice > 5 || userChoice < 0);

	return 0;
}
