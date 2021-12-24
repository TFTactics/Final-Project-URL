#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <list>
#include <Windows.h>
#include <map>
#include "graphic.h"
#include <iomanip>
#include "hashtable.h"
#include "build_menu.h"
using namespace std;


// show display all of URL which you choose

int x_main = 3, y_main = 41;
int x_show = 41, y_show = 4;

void ShowDis() {
	int x = x_show, y = y_show;
	cout << "URL depth 1: ";
	hash_url.printTable(x, y);
	y += 6;
	gotoxy(x, y);
	cout << "URL depth 2 for link 1";
	depth_1.printTable(x, y);
	y += 6;
	gotoxy(x, y);
	cout << "URL depth 2 for link 2";
	depth_2.printTable(x, y);
	y += 6;
	gotoxy(x, y);
	cout << "URL depth 2 for link 3";
	depth_3.printTable(x, y);
	y += 6;
	gotoxy(x, y);
	cout << "URL depth 2 for link 4";
	depth_4.printTable(x, y);
}

int main(int argc, char const* argv[])
{
	map<string, string> dataSet1;
	map<string, string> dataSet2;
	map<string, string> dataSet3;
	map<string, string> dataSet4;
	int choose;
	int choose_2;
	int choose_3;
	int key;

	while (1) {
		bool reset = false;
		while (1) {
			buidMenu();
			gotoxy(x_main, y_main);
			cout << "CHON WEBSITE: ";
			cin >> choose;
			if (choose == 1) {
				dataSet1["test//utex//depth1.txt"] = "test//utex//depth2(1).txt";
				dataSet1["test//utex//depth2(1).txt"] = "test//utex//depth2(2).txt";
				dataSet1["test//utex//depth2(2).txt"] = "test//utex//depth2(3).txt";
				dataSet1["test//utex//depth2(3).txt"] = "test//utex//depth2(4).txt";
				dataSet1["test//utex//depth2(4).txt"] = "end";
				printItinerary(dataSet1);
				break;
			}
			else if (choose == 2) {
				dataSet2["test//fb//depth1.txt"] = "test//fb//depth2(1).txt";
				dataSet2["test//fb//depth2(1).txt"] = "test//fb//depth2(2).txt";
				dataSet2["test//fb//depth2(2).txt"] = "test//fb//depth2(3).txt";
				dataSet2["test//fb//depth2(3).txt"] = "test//fb//depth2(4).txt";
				dataSet2["test//fb//depth2(4).txt"] = "end";
				printItinerary(dataSet2);
				break;
			}
			else if (choose == 3) {
				dataSet3["test//youtube//depth1.txt"] = "test//youtube//depth2(1).txt";
				dataSet3["test//youtube//depth2(1).txt"] = "test//youtube//depth2(2).txt";
				dataSet3["test//youtube//depth2(2).txt"] = "test//youtube//depth2(3).txt";
				dataSet3["test//youtube//depth2(3).txt"] = "test//youtube//depth2(4).txt";
				dataSet3["test//youtube//depth2(4).txt"] = "end";
				printItinerary(dataSet3);
				break;
			}
			else if (choose == 4) {
				dataSet4["test//github//depth1.txt"] = "test//github//depth2(1).txt";
				dataSet4["test//github//depth2(1).txt"] = "test//github//depth2(2).txt";
				dataSet4["test//github//depth2(2).txt"] = "test//github//depth2(3).txt";
				dataSet4["test//github//depth2(3).txt"] = "test//github//depth2(4).txt";
				dataSet4["test//github//depth2(4).txt"] = "end";
				printItinerary(dataSet4);
				break;
			}
			else {
				gotoxy(x_main, y_main);
				cout << "XIN MOI NHAP DUNG CU PHAP";
				Sleep(1000);
				clear_userInput();
			}
		}
		gotoxy(x_show, y_show);
		ShowDis();

		while (1) {
			gotoxy(x_main, y_main);
			cout << "CHON CHUC NANG: ";
			cin >> choose_2;
			switch (choose_2) {
			case 1:
				while (1) {
					gotoxy(x_main, y_main);
					cout << "LUA CHON CUA BAN: ";
					cin >> choose_3;
					gotoxy(x_main, y_main);
					clear_userInput();
					switch (choose_3) {
					case 1:
						gotoxy(x_main, y_main);
						cout << "CHON KEY: ";
						cin >> key;
						hash_url.removeItem(key);
						break;
					case 2:
						gotoxy(x_main, y_main);
						cout << "CHON KEY: ";
						cin >> key;
						depth_1.removeItem(key);
						break;
					case 3:
						gotoxy(x_main, y_main);
						cout << "CHON KEY: ";
						cin >> key;
						depth_2.removeItem(key);
						break;
					case 4:
						gotoxy(x_main, y_main);
						cout << "CHON KEY: ";
						cin >> key;
						depth_3.removeItem(key);
						break;
					case 5:
						gotoxy(x_main, y_main);
						cout << "CHON KEY: ";
						cin >> key;
						depth_4.removeItem(key);
						break;
					default:
						gotoxy(x_main, y_main);
						cout << "XIN MOI NHAP DUNG CU PHAP" << endl;
						Sleep(2000);
						system("cls");
						buidMenu();
						gotoxy(x_show, y_show);
						ShowDis();
					}
					if (choose_3 == 1 || choose_3 == 2 || choose_3 == 3 || choose_3 == 4 || choose_3 == 5) break;
				}
				Sleep(1000);
				system("cls");
				buidMenu();
				gotoxy(x_show, y_show);
				ShowDis();
				break;
			case 2: {
				gotoxy(x_main, y_main);
				cout << "CHON URL DEPTH TRUY CAP: ";
				cin >> choose_3;
				gotoxy(x_main, y_main);
				clear_userInput();
				switch (choose_3) {
				case 1:
					gotoxy(x_main, y_main);
					cout << "CHON KEY: ";
					cin >> key;
					hash_url.Connect(key);
					break;
				case 2:
					gotoxy(x_main, y_main);
					cout << "CHON KEY: ";
					cin >> key;
					depth_1.Connect(key);
					break;
				case 3:
					gotoxy(x_main, y_main);
					cout << "CHON KEY: ";
					cin >> key;
					depth_2.Connect(key);
					break;
				case 4:
					gotoxy(x_main, y_main);
					cout << "CHON KEY: ";
					cin >> key;
					depth_3.Connect(key);
					break;
				case 5:
					gotoxy(x_main, y_main);
					cout << "CHON KEY: ";
					cin >> key;
					depth_4.Connect(key);
					break;
				default:
					gotoxy(x_main, y_main);
					cout << "XIN MOI NHAP DUNG CU PHAP" << endl;
					Sleep(2000);
					system("cls");
					buidMenu();
					gotoxy(x_show, y_show);
					ShowDis();
					if (choose_3 == 1 || choose_3 == 2 || choose_3 == 3 || choose_3 == 4 || choose_3 == 5) break;
				}
				Sleep(1000);
				system("cls");
				buidMenu();
				gotoxy(x_show, y_show);
				ShowDis();
				break;
			}
			case 3:
				reset = true;
				break;
			case 4:
				exit(1);
			default:
				gotoxy(x_main, y_main);
				cout << "XIN MOI NHAP DUNG CU PHAP";
				Sleep(1000);
				clear_userInput();
				break;
			}
			if (reset == true) {
				system("cls");
				break;
			}
		}
	}
	return 0;
}