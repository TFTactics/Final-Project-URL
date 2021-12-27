#include <chrono> // for std::chrono functions
#include <iostream>
#include <list>
#include <fstream>
#include <map>

using namespace std;

const int PRIME = 29;
const int TABLE_SIZE = 53;

class Timer
{
private:
    // Type aliases to make accessing nested type easier
    using clock_type = chrono::steady_clock;
    using second_type = chrono::duration<double, std::ratio<1> >;

    chrono::time_point<clock_type> m_beg { clock_type::now() };

public:
    void reset()
    {
        m_beg = clock_type::now();
    }

    double elapsed() const
    {
        return chrono::duration_cast<second_type>(clock_type::now() - m_beg).count();
    }
};

class HashTable {
private:
    //static const int hashGroups = 47;
    list<pair<int, string>> table[TABLE_SIZE];
public:
    //bool isEmpty() const;
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
					curr_size++;
					return newIndex;
				}
				i++;
			}
		}
		else
			hashTable[index] = key;
		curr_size++;
		return index;
    }
};

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

int main()
{
	int loop = 1000000;
    Timer t;
    map<string, string> dataSet1;
    for(int i = 0; i < loop; i++)
    	printItinerary(dataSet1);

    std::cout << fixed << "Time elapsed: " << t.elapsed() << " seconds\n";

    return 0;
}
