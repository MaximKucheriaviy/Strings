namespace app {
	vector<Person> arr;
	void loadPersons() {
		arr = loadArrFromFile("./DataBase.txt");
		cout << "Loaded..." << endl;
	}
	void showPersons() {
		showArr(arr);
	}
	void addPerson() {
		Person newPerson;
		cout << "Enter name: ";
		getline(cin, newPerson.name);
		cout << "Enter sername: ";
		getline(cin, newPerson.sername);
		cout << "Enter age: ";
		getline(cin, newPerson.age);
		arr.push_back(newPerson);
	}
	void saveArr() {
		saveArrToFile(arr, "./DataBase.txt");
	}
}