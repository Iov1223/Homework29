#include <iostream>
#include <string>
#include <fstream>
using namespace std;


// ������ 2. �������� �� ������������� �����, ���� �� �� ����������.
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
	

	// ������ 1.
	cout << "\t������ 1.\n";
	fstream fs;
	fs.open(path, ios::in | ios::app);
	if (fs.is_open()) {
		cout << "���� ������.\n������� ����� (��� ���������� ������� \"end\"):\n";
		do {
			getline(cin, str);
			fs << str + "\n";
		} while (str != "end");
		cout << "\n������ ��������� � ����.\n\n";
		fs.seekg(0, ios::beg);
		char sym;
		cout << "������������ �����:\n";
		while (fs.get(sym))
			cout << sym;
		fs.close();
	}
	else
		cout << "������ �������� �����!\n";
	fs.close();
	cout << "\n";
	system("pause");
	remove("word.txt");
	cout << "���� �����.\n\n";

	// ������ 1.1
	/*cout << "\t������ 1.1\n";
	ofstream out;
	out.open(path);
	if (out.is_open()) {
		cout << "���� ������.\n������� ����� (��� ���������� ������� \"end\"):\n";
		do {
			getline(cin, str);
			out << str + "\n";
		} while (str != "end");
		cout << "\n������ ��������� � ����.\n\n";
	}
	else
		cout << "������ �������� �����.\n";
	out.close();

	ifstream in;
	in.open(path);
	if (in.is_open()) {
		cout << "���������� �����:\n";
		while (getline(in, str))
			fStr += str + "\n";
		cout << fStr;
	}
	else
		cout << "������ �������� �����.\n";
	in.close();
	cout << "\n";
	system("pause");
	remove("word.txt");
	cout << "���� �����.\n\n";*/
	
	// ������ 2.
	cout << "\t������ 2.\n������� ������: ";
	getline(cin, str);
	if (overwrite(path, str) == false)
		cout << "����� �� ����������!\n\n";
	else
		cout << "���� ������� �������.\n\n";

	return 0;
}