#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;
typedef cc_hash_table<int, int, hash<int>> ht;
// typedef cc_hash_table<
//     int, int, hash<int>, equal_to<int>, direct_mask_range_hashing<int>,
//     hash_standard_resize_policy<hash_exponential_size_policy<>, hash_load_check_resize_trigger<true>, true>>
//     ht;

bool eraseVals = false;
void benchmarkPolicy(string msg, vector<pii> &vals, int NUM_ITERS) {
    clock_t begin = clock();
    ht test;
    for (int t = 0; t < NUM_ITERS; t++) {
        for (auto i : vals) {
            test[i.first] = test[i.first] + i.second * t;
        }
    }
    cout << msg << ": " << string(60 - msg.size(), ' ') << "\t" << (double)(clock() - begin) / CLOCKS_PER_SEC << endl;
}

void benchmarkStl(string msg, vector<pii> &vals, int NUM_ITERS) {
    clock_t begin = clock();
    unordered_map<int, int> test;
    for (int t = 0; t < NUM_ITERS; t++) {
        for (auto i : vals) {
            test[i.first] = test[i.first] + i.second * t;
        }
    }
    cout << msg << ": " << string(60 - msg.size(), ' ') << "\t" << (double)(clock() - begin) / CLOCKS_PER_SEC << endl;
}

void benchmark(string msg, vector<pii> vals, int NUM_ITERS) {
    benchmarkStl("unordered map " + msg, vals, NUM_ITERS);
    benchmarkPolicy("policy hash table " + msg, vals, NUM_ITERS);
    cout << endl;
}

vector<pii> generateVec(int max_val, bool shuffled) {
    vector<int> k(max_val), v(max_val);
    vector<pii> vals;
    iota(k.begin(), k.end(), 0);
    iota(v.begin(), v.end(), 0);
    if (shuffled) {
        random_shuffle(k.begin(), k.end());
        random_shuffle(v.begin(), v.end());
    }
    for (int i = 0; i < max_val; i++) {
        vals.push_back({k[i], v[i]});
    }
    return vals;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    benchmark("linear insertion", generateVec(1e7, false), 1);
    benchmark("linear read/write", generateVec(1e5, false), 1000);
    benchmark("random insertion", generateVec(1e7, true), 1);
    benchmark("random read/write", generateVec(1e5, true), 1000);
}