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
constexpr auto TABLE_SIZE = 97;
constexpr auto PRIME = 93;

int x_ma = 3, y_ma = 41;


// Class Hashtable
class HashTable {
private:
	//static const int hashGroups = 47;
	list<pair<int, string>> table[TABLE_SIZE];
public:
	bool isEmpty() const;
	//int hashFunction(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	void Connect(int key);
	void printTable(int x, int y);
};

class DoubleHash {
	int* hashTable;
	int curr_size;
public:
	bool isFull() {
		return (curr_size == TABLE_SIZE);
	}
	int hash1(int key) {
		return (key % TABLE_SIZE);
	}
	int hash2(int key) {
		return (PRIME - (key % PRIME));
	}

	DoubleHash()
	{
		hashTable = new int[TABLE_SIZE];
		curr_size = 0;
		for (int i = 0; i < TABLE_SIZE; i++)
			hashTable[i] = -1;
	}
	int insertHash(int key)
	{
		if (isFull())
			return 0;
		int index = hash1(key);
		if (hashTable[index] != -1) {
			int index2 = hash2(key);
			int i = 1;
			while (1) {
				int newIndex = (index + i * index2) % TABLE_SIZE;
				if (hashTable[newIndex] == -1) {
					hashTable[newIndex] = key;
					return newIndex;
				}
				i++;
			}
		}
		else
			hashTable[index] = key;
		return index;
		curr_size++;
	}
};

// return true if this HashTable is Empty
bool HashTable::isEmpty() const {
	int sum{};
	for (int i{}; i < TABLE_SIZE; i++) {
		sum += table[i].size();
	}
	if (!sum) {
		return true;
	}
	return false;
}

/*int HashTable::hashFunction(int key) {
	return key % hashGroups;
}*/

// Add key - value to Hashtable
void HashTable::insertItem(int key, string value) {
	DoubleHash h;
	int hashValue = h.insertHash(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr->second = value;
			break;
		}
	}
	if (!keyExists) {
		cell.emplace_back(key, value);
	}
	return;
}

// Remove element from Hashtable
void HashTable::removeItem(int key) {
	DoubleHash h;
	int hashValue = h.insertHash(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			// xoa phan tu trong list
			bItr = cell.erase(bItr);
			break;
		}
	}
	if (!keyExists) {
		gotoxy(x_ma, y_ma);
		cout << "[WARNING] KHONG TIM THAY KEY.";
	}
	return;
}

// Show display hashtable
void HashTable::printTable(int x, int y) {
	int iy = y;
	for (int i{}; i < TABLE_SIZE; i++) {
		if (table[i].size() == 0) continue;

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			iy++;
			gotoxy(x, iy);
			cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second;
		}

	}
	return;
}

// access the URL to the internet
void HashTable::Connect(int key) {
	DoubleHash h;
	int hashValue = h.insertHash(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			string connect_url = "start " + bItr->second;
			keyExists = true;
			// truy cap duong linh
			system(connect_url.c_str());
			break;
		}
	}
	if (!keyExists) {
		gotoxy(x_ma, y_ma);
		cout << "[WARNING] KHONG TIM THAY KEY" << endl;
	}
	return;
}
HashTable hash_url;
HashTable depth_1;
HashTable depth_2;
HashTable depth_3;
HashTable depth_4;
void printItinerary(map<string, string> dataSet)
{
	map<string, string> reversemap;
	map<string, string>::iterator it;

	for (it = dataSet.begin(); it != dataSet.end(); it++)
		reversemap[it->second] = it->first;
	string start;
	for (it = dataSet.begin(); it != dataSet.end(); it++)
	{
		if (reversemap.find(it->first) == reversemap.end())
		{
			start = it->first;
			break;
		}
	}
	if (start.empty())
	{
		cout << "Dau vao khong hop le" << endl;
		return;
	}
	it = dataSet.find(start);
	string content;
	int cou, i = 0;
	while (it != dataSet.end())
	{
		ifstream loadfile(it->first);
		cou = 1;
		while (!loadfile.eof()) {
			loadfile >> content;
			if (i == 0)
				hash_url.insertItem(cou, content);
			else if (i == 1)
				depth_1.insertItem(cou, content);
			else if (i == 2)
				depth_2.insertItem(cou, content);
			else if (i == 3)
				depth_3.insertItem(cou, content);
			else
				depth_4.insertItem(cou, content);
			cou++;
		}
		i++;
		it = dataSet.find(it->second);
	}
}
