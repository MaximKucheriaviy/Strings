#include <string>
#include <vector>
#include <fstream>

using namespace std;


struct Person {
	string name = "";
	string sername = "";
	string age = "";
};

fstream file;

void saveArrToFile(vector<Person> arr, string fileName) {
	file.open(fileName, ios_base::out);
	for (int i = 0; i < arr.size(); i++) {
		file << arr[i].name << "%" << arr[i].sername << "%" << arr[i].age;
		if (i + 1 != arr.size()) {
			file << endl;
		}
	}
	file.close();
}

Person setringToPerson(string line) {
	Person result;
	int firstIndex = line.find("%");
	int seccondIndex = line.find("%", firstIndex + 1);
	result.name = line.substr(0, firstIndex);
	result.sername = line.substr(firstIndex + 1, seccondIndex - firstIndex - 1);
	result.age = line.substr(seccondIndex + 1);
	return result;
}

vector<Person> loadArrFromFile(string fileName) {
	vector<Person> result;
	file.open(fileName, ios_base::in);
	if (file.is_open()) {
		while (!file.eof()) {
			string input;
			getline(file, input);
			result.push_back(setringToPerson(input));
		}
		file.close();
	}
	else {
		cout << "file open error" << endl;
	}
	return result;
}

void showArr(vector<Person> arr) {
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].name << " " << arr[i].sername << " " << arr[i].age << endl;
	}
}