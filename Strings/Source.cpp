#include <iostream>
#include <string>
#include <iostream>
#include "CohsoleApp.hpp"

using namespace std;

void sayHello() {
	cout << "Hello form app" << endl;
}
void getInfo() {
	cout << "This is info" << endl;
}


int main()
{
	ConsoleApp app;
	app.createAction("hello", &sayHello);
	app.createAction("info", &getInfo);
	app.run();
	return 0;

}