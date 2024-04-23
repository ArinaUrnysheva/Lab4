#include "Header1.h"

#include <vector>
#include <list>
#include <algorithm>
#include <fstream>

void SaveToFile(const string& filename, const Kredit& k1) { //функция сохранения данных типа Kredit в файл
	ofstream file(filename, ios::app);
	if (file.is_open()) {
		file << k1 << endl;
		cout << k1 << endl;
		file.close();
	}
	else cerr << "Can't open this file :(" << endl;
}

void SaveToFile(const string& filename, const string& s) { //перегрузка функции для сохранения в файл данных типа string
	ofstream file(filename, ios::app);
	if (file.is_open()) {
		file << s << endl;
		cout << s << endl;
		file.close();
	}
	else cerr << "Can't open this file :(" << endl;
}

int main() {
	ofstream clear("output.txt");
	clear.close();
	ifstream input("input.txt");

	int n;
	list<Kredit>K1; //создание двусвязного списка 
	cout << "Enter amount of kredits: ";
	cin >> n;
	cout << endl;

	for (size_t i = 0; i < n; ++i) {
		Kredit k;
		input >> k;
		K1.push_back(k);
	}

	string s = "Before sort: ";
	SaveToFile("output.txt", s);

	for (const auto e : K1) SaveToFile("output.txt", e);

	s = "After sort";

	K1.sort(); //сортировка двусвязного списка 

	SaveToFile("output.txt", s);
	for (const auto e : K1) SaveToFile("output.txt", e);

	s = "Vector from list: ";
	SaveToFile("output.txt", s);

	vector<Kredit>K2;

	copy(K1.begin(), K1.end(), back_inserter(K2));

	for (const auto e : K2) SaveToFile("output.txt", e);

	return 0;
}
