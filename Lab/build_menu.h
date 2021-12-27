#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <list>
#include <Windows.h>
#include <map>
#include "graphic.h"
#include <iomanip>
using namespace std;

void clear_userInput() {
	gotoxy(3, 41);
	for (int ix = 3; ix < 50; ix++) {
		gotoxy(ix, 41);
		cout << " ";
	}
}

void buidMenu() {
	// dựng khung
	resizeConsole(1550, 700);
	int h = 35, w = 202;
	int x = 2, y = 2;
	gotoxy(x, y);
	cout << char(218);
	gotoxy(x + w, y);
	cout << char(191);
	gotoxy(x, y + h);
	cout << char(192);
	gotoxy(x + w, y + h);
	cout << char(217);
	for (int ix = x + 1; ix < x + w; ix++) {
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y + h);
		cout << char(196);
	}
	for (int iy = y + 1; iy < y + h; iy++) {
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x + w, iy);
		cout << char(179);
	}

	// DỰNG KHUNG PHỤ
	gotoxy(40, y);
	cout << char(194);
	gotoxy(40, y + h);
	cout << char(193);
	for (int iy = y + 1; iy < y + h; iy++) {
		gotoxy(40, iy);
		cout << char(179);
	}

	gotoxy(x, 13);
	cout << char(195);
	for (int ix = x + 1; ix < 40; ix++) {
		gotoxy(ix, 13);
		cout << char(196);
	}
	gotoxy(40, 24);
	cout << char(180);

	gotoxy(x, 24);
	cout << char(195);
	for (int ix = x + 1; ix < 40; ix++) {
		gotoxy(ix, 24);
		cout << char(196);
	}
	gotoxy(40, 24);
	cout << char(180);


	// Chèn menu

	int x_link = 3, y_link = 3;
	gotoxy(x_link, y_link);
	SetColor(10);
	cout << "****************MENU****************";
	SetColor(15);
	gotoxy(x_link, y_link + 2);
	cout << "1. UTEX";
	gotoxy(x_link, y_link + 4);
	cout << "2. Facebook";
	gotoxy(x_link, y_link + 6);
	cout << "3. Youtube";
	gotoxy(x_link, y_link + 8);
	cout << "4. Github";

	// Chèn chức năng

	int x_func = 3, y_func = 14;
	gotoxy(x_func, y_func);
	SetColor(10);
	cout << "**************CHUC NANG**************";
	SetColor(15);
	gotoxy(x_func, y_func + 2);
	cout << "1. Xoa URL.";
	gotoxy(x_func, y_func + 4);
	cout << "2. Truy cap URL.";
	gotoxy(x_func, y_func + 6);
	cout << "3. Lam lai.";
	gotoxy(x_func, y_func + 8);
	cout << "4. Thoat.";

	// CHÈN URL DEPTH
	int x_depth = 3, y_depth = 25;
	gotoxy(x_depth, y_depth);
	SetColor(10);
	cout << "**************URL DEPTH**************";
	SetColor(15);
	gotoxy(x_depth, y_depth + 2);
	cout << "1. URL depth 1";
	gotoxy(x_depth, y_depth + 4);
	cout << "2. URL depth 2 for link 1";
	gotoxy(x_depth, y_depth + 6);
	cout << "3. URL depth 2 for link 2";
	gotoxy(x_depth, y_depth + 8);
	cout << "4. URL depth 2 for link 3";
	gotoxy(x_depth, y_depth + 10);
	cout << "5. URL depth 2 for link 4";

	// KHUNG CHO DEPTH

	gotoxy(115, 3);
	SetColor(10);
	cout << "DANH SACH URL";
	// KHUNG CHO USER
	int h_user = 2, w_user = 50;
	int x_user = 2, y_user = 40;
	gotoxy(x_user, y_user);
	cout << char(218);
	gotoxy(x_user + w_user, y_user);
	cout << char(191);
	gotoxy(x_user, y_user + h_user);
	cout << char(192);
	gotoxy(x_user + w_user, y_user + h_user);
	cout << char(217);
	for (int ix = x_user + 1; ix < x_user + w_user; ix++) {
		gotoxy(ix, y_user);
		cout << char(196);
		gotoxy(ix, y_user + h_user);
		cout << char(196);
	}
	for (int iy = y_user + 1; iy < y_user + h_user; iy++) {
		gotoxy(x_user, iy);
		cout << char(179);
		gotoxy(x_user + w_user, iy);
		cout << char(179);
	}

	SetColor(15);
}