#include<iostream>
using namespace std;

constexpr auto TABLE_SIZE = 53;

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
    int hash2(int key, int PRIME) {
        return (PRIME - (key % PRIME));
    }
    DoubleHash()
    {
        hashTable = new int[TABLE_SIZE];
        curr_size = 0;
        for (int i = 0; i < TABLE_SIZE; i++)
            hashTable[i] = -1;
    }

    void removeHash() {
        curr_size = 0;
        for (int i = 0; i < TABLE_SIZE; i++)
            hashTable[i] = -1;
    }

    int insertHash(int key, int PRIME)
    {
        int i = 0;
        if (isFull())
            return 0;
        int index = hash1(key);
        if (hashTable[index] != -1) {
            int index2 = hash2(key, PRIME);
            i = 1;
            while (1) {
                int newIndex = (index + i * index2) % TABLE_SIZE;
                if (hashTable[newIndex] == -1) {
                    hashTable[newIndex] = key;
                    curr_size++;
                    break;
                }
                i++;
            }
        }
        else
            hashTable[index] = key;
        curr_size++;
        return i;
    }
    void displayHash()
    {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (hashTable[i] != -1)
                cout << i << " --> " << hashTable[i] << endl;
            else
                cout << i << endl;
        }
    }
};

bool isPrime(int a) {
    for (int i = 2; i < a; i++)
        if (a % i == 0)
            return false;
    return true;
}

int main()
{
    int a[30] = { 855, 855, 142, 462, 611, 877, 424, 678, 752, 443, 296, 673, 401, 313, 875, 721, 818, 610, 171, 932, 112, 695, 169, 831, 401, 488, 685, 901, 497, 589 };
    int loop1 = 1;
    while (loop1 <= 1) {
        DoubleHash h;
        int sum1, min1 = 9999999, min2 = 0;
        for (int i = 43; i > 1; i--) {
            if (isPrime(i))
            {
                int loop2 = 1;
                sum1 = 0;
                while (loop2 <= loop1) {
                    int count1 = 0;
                    for (int j = 0; j < 30; j++) {
                        count1 += h.insertHash(a[j], i);
                    }
                    sum1 += count1;
                    h.removeHash();
                    loop2++;
                }
                if (sum1 < min1) {
                    min1 = sum1;
                    min2 = i;
                }
                cout << i << "\t-->\t" << (float)sum1 / loop1 << endl;
            }
        }
        cout << "-------------" << endl;
        cout << min2 << "\t-->\t" << (float)min1 / loop1 << endl;
        cout << "-------------" << endl;
        loop1 += 10;
    }

    return 0;
}
