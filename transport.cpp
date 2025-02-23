#include<iostream>
#include<fstream>
#include<string>
#include <thread>
using namespace std;
struct information {
	float matrix[10][10] = {
		{0,1.9,1.6,5.2,9.5,7.0,2.2,4.6,11.1,10.5},
		{1.9,0,1.4,1000,1000,5.9,3.8,4.6,1000,1000},
		{1.6,1.4,0,	4.4,8.2,5.4,1000,3.2,1000,1000},
		{5.2,1000,4.4,0,6,7.1,2.8,1.5,9.1,10.0},
		{9.5,1000,8.2,6,0,4.7,1000,5.0,13.2,3.7},
		{7.0,5.9,5.4,7.1,4.7,0,1000,5.3,1000,4.1},
		{7.0,3.8,1000,2.8,1000,1000,0,3.6,8.7,1000},
		{4.6,4.5,3.2,1.5,5.1,5.3,3.6,0,9.1,8.2},
		{11.1,1000,1000,9.1,13.2,1000,8.7,9.1,0,1000},
		{10.5,1000,1000,10.0,3.7,4.1,1000,8.2,1000,0}
	};
	string stations[10][10];
	float price[10][10];
	string place[10];
}site;
class welcoming {
	public:
		void store() {
			ofstream file;
			file.open("station.txt", ios::out);
			if (file.fail()) {
				cerr << "Error to create a file\n";
			}
			file << "Piazza\n" << "6-kilo\n" << "4-kilo\n" << "Mexico\n" << "Bole\n" << "Megenagna\n" << "Merkato\n" << "Legehar\n" << "Ayertena\n" << "Gerge\n";
			file.close();
		}
};
string transit(int);
float Bill(float);
void Introduction();
void display(int, int);
int main() {
	welcoming place;
	system("color 3E");
	place.store();

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++) {
				if (site.matrix[j][k] > site.matrix[j][i] + site.matrix[i][k]) {
					site.matrix[j][k] = site.matrix[j][i] + site.matrix[i][k];

					site.stations[j][k] = transit(i);
				}
			}
	}

	ifstream file2;
	file2.open("station.txt", ios::in);
	if (file2.fail()) {
		cerr << "Error to open the file\n";
	}
	int n = 0;
	while (n < 10) {
		getline(file2, site.place[n]);
		n++;
	}

	file2.close();
	Introduction();
	int j, k;
	cout << "Boarding :"; cin >> j;
	cout << "Alighting :"; cin >> k;

	float *p = &site.matrix[j][k];
	site.price[j][k] = Bill(*p);
	system("cls");
	display(j, k);
	return 0;
}



string transit(int n) {
	string store;
	ifstream file1;
	file1.open("station.txt", ios::in);
	if (file1.fail()) {
		cerr << "Error to open the file\n";
	}

	for (int i = 0; i <= n; i++) {
		getline(file1, store);
	}
	file1.close();
	return store;
}

void Introduction() {
	cout << "*****************************************************************************" << endl;
	cout << "*                                                                           *" << endl;
	cout << "*                              WELCOME                                     *" << endl;
	cout << "*              Transport Fare Calculator for Public Transit                *" << endl;
	cout << "*                                                                           *" << endl;
	cout << "*****************************************************************************" << endl;
	string message1 = "\nPlease Insert your Boarding and Alighting Site:\n";
	for (size_t i = 0; i < message1.size(); ++i) {
		char c = message1[i];
		cout << c << flush;
		this_thread::sleep_for(chrono::milliseconds(50));
	}

	for (int i = 0; i < 10; i++) {
		cout << "Insert " << i << " for " << site.place[i] << endl;
	}

}

float Bill(float p) {
	cout << "Which Transport Type do you prefer?" << endl;
	cout << "For Taxi service insert : T" << endl;
	cout << "For Bus service insert : B" << endl;
	char choice;
	cin >> choice;
	switch (choice) {
	case'T':
		return 5 * p;
	case'B':
		return 4.5 * p;
	default:
		cout << "You made a wrong choice" << endl;
		Bill(p);
		break;
	}
}

void display(int j, int k) {
	cout << "You journey will be From:   " << site.place[j] << endl;
	cout << "TO :                     " << site.place[k] << endl;
	cout << "The shortest path is " << site.matrix[j][k] << " Km " << endl;
	cout << "Through :            " << site.stations[j][k] << endl;
	cout << site.place[j] << "  ======>  " << site.stations[j][k] << "  ======>  " << site.place[k] << endl;
	cout << "The Total price is:  " << site.price[j][k] << " Birr" << endl;
	cout << "*****************************************************************************" << endl;
	string message4 = "*                              MELKAM GUZO!                                *\n";
	for (size_t i = 0; i < message4.size(); ++i) {
		char c = message4[i];
		cout << c << flush;
		this_thread::sleep_for(chrono::milliseconds(50));
	}
	cout << "*****************************************************************************" << endl;
}