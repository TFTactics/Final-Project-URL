#include <chrono> // for std::chrono functions
#include <iostream>
#include <list>
#include <fstream>

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
    void printTable();
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

void HashTable::printTable() {
    for (int i{}; i < TABLE_SIZE; i++) {
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int key = 1000000;
    HashTable hash_url;
    for(int i = 0; i < key; i++)
        hash_url.insertItem(key,"Comeon");

    Timer t;
    hash_url.printTable();

    std::cout << fixed << "Time elapsed: " << t.elapsed() << " seconds\n";
    return 0;
}
