#include <string>
#include <iostream>
#include <vector>

using namespace std;
struct Action
{
	string key;
	void (*action)();
};


class ConsoleApp {
public:
	ConsoleApp(string startSymbol = "->", string stopCommand = "stop") {
		this->startSymbol = startSymbol;
		this->stopCommand = stopCommand;
	}
	void createAction(string key, void(*action)()) {
		actions.push_back({ key, action });
	}
	void run() {
		string command;
		while (true) {
			cout << startSymbol << " ";
			getline(cin, command);
			if (command == stopCommand) {
				break;
			}
			bool isActionsDone = false;
			for (int i = 0; i < actions.size(); i++) {
				if (command == actions[i].key) {
					actions[i].action();
					isActionsDone = true;
				}
			}
			if (!isActionsDone) {
				cout << "Unknown command" << endl;
			}
		}
	}
protected:
	vector<Action> actions;
	string startSymbol;
	string stopCommand;
};