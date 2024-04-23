#include "Header1.h"

#include <vector>
#include <list>
#include <algorithm>
#include <fstream>

void ReadFromFile(const string& filename, Kredit& k1) { //функция чтения данных типа Kredit из файла
	ifstream file(filename);
	if (file.is_open()) {
		file >> k1;
		file.close();
	}
	else cerr << "Can't open this file :(" << endl;
}

void SaveToFile(const string& filename, const Kredit& k1) { //функция сохранения данных типа Kredit в файл
	ofstream file(filename);
	if (file.is_open()) {
		file << k1;
		cout << k1;
		file.close();
	}
	else cerr << "Can't open this file :(" << endl;
}

void SaveToFile(const string& filename, const string& s) { //перегрузка функции для сохранения в файл данных типа string
	ofstream file(filename);
	if (file.is_open()) {
		file << s;
		cout << s;
		file.close();
	}
	else cerr << "Can't open this file :(" << endl;
}

void SaveToFile(const string& filename, int& st) { //перегрузка фугкции для сохранения в файл данных типа int
	ofstream file(filename);
	if (file.is_open()) {
		file << st;
		cout << st;
		file.close();
	}
	else cerr << "Can't open this file :(";
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
	/*for (int i = 0; i < n; ++i) { //цикл для чтения из файла "input.txt" данных типа Kredit
		Kredit k;
		ReadFromFile("input.txt", k);
		K1.push_back(k);
	}*/

	for (size_t i = 0; i < n; ++i) {
		Kredit k;             // Создание временного объекта Bank_deposit
		input>>k;            // Чтение данных из файла и инициализация объекта
		K1.push_back(k);    // Добавление объекта в конец вектора
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