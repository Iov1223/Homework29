#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// Задача 2. Проверка на существование файла, если да то перезапись.
bool overwrite(string way, string line) {
	ifstream in(way);
	if (!in.is_open()) {
		in.close();
		return false;
	}
	else {
		ofstream out;
		out.open(way);
		if (out.is_open()) {
			out << line;
			out.close();
			return true;
		}
	}
	
}


int main() {
	setlocale(LC_ALL, "Russian");
	string path = "word.txt";
	string str;
	

	// Задача 1.
	cout << "\tЗадача 1.\n";
	fstream fs;
	fs.open(path, ios::in | ios::app);
	if (fs.is_open()) {
		cout << "Файл открыт.\nВведите текст (для завершения введите \"end\"):\n";
		do {
			getline(cin, str);
			fs << str + "\n";
		} while (str != "end");
		cout << "\nЗапись добавлена в файл.\n\n";
		fs.seekg(0, ios::beg);
		char sym;
		cout << "Содержимоное файла:\n";
		while (fs.get(sym))
			cout << sym;
		fs.close();
	}
	else
		cout << "Ошибка открытия файла!\n";
	fs.close();
	cout << "\n";
	system("pause");
	remove("word.txt");
	cout << "Файл удалён.\n\n";

	// Задача 1.1
	/*cout << "\tЗадача 1.1\n";
	ofstream out;
	out.open(path);
	if (out.is_open()) {
		cout << "Файл открыт.\nВведите текст (для завершения введите \"end\"):\n";
		do {
			getline(cin, str);
			out << str + "\n";
		} while (str != "end");
		cout << "\nЗапись добавлена в файл.\n\n";
	}
	else
		cout << "Ошибка открытия файла.\n";
	out.close();

	ifstream in;
	in.open(path);
	if (in.is_open()) {
		cout << "Содержимое файла:\n";
		while (getline(in, str))
			fStr += str + "\n";
		cout << fStr;
	}
	else
		cout << "Ошибка открытия файла.\n";
	in.close();
	cout << "\n";
	system("pause");
	remove("word.txt");
	cout << "Файл удалён.\n\n";*/
	
	// Задача 2.
	cout << "\tЗадача 2.\nВведите строку: ";
	getline(cin, str);
	if (overwrite(path, str) == false)
		cout << "Файла не существует!\n\n";
	else
		cout << "Файл успешно обнавлён.\n\n";

	return 0;
}