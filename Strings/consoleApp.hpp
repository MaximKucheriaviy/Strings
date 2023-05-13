#include <string>
#include <iostream>
using namespace std;

struct Action
{
	string key;
	void(*action)();
};


class ConsoleApp {
public:
	ConsoleApp(string comandMarker = "-> ", string stopCommand = "stop") {
		this->comandMarker = comandMarker;
		this->stopCommand = stopCommand;
	}
	void runApp() {
		while (true)
		{
			string command;
			cout << comandMarker;
			getline(cin, command);
			if (stopCommand == command) {
				break;
			}
			bool isUnknown = true;
			for (int i = 0; i < actions.size(); i++) {
				if (command == actions[i].key) {
					actions[i].action();
					isUnknown = false;
				}
			}
			if (isUnknown) {
				cout << "Unknown command" << endl;
			}
			cout << endl << endl;
			system("pause");
			system("cls");
		}
	}
	void createAction(string key, void(*action)()) {
		actions.push_back({ key, action });
	}
protected:
	string comandMarker;
	vector<Action> actions;
	string stopCommand;
};