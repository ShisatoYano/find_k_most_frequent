#include <bits/stdc++.h>
using namespace std;

// print the k numbers with most occurrences
void print_k_most_frequent_num(int array[], int n, int k) {
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i) {
        map[array[i]]++;
    }

    // use frequencies as indexes and
    // put elements with given frequency
    vector<int> freq[n + 1];
    for (int i = 0; i < n; ++i) {
        int f = map[array[i]];
        if (f != -1) {
            freq[f].push_back(array[i]);
            map[array[i]] = -1;
        }
    }

    int count = 0;

    // traverse the frequency array from
    // right side
    for (int i = n; i >= 0; --i) {
        for (int x : freq[i]) {
            cout << x << " ";
            count++;
            if (count == k) {
                return;
            }
        }
    }
}

int main() {
    int array[] = {3, 1, 4, 4, 5, 2, 6, 1};
    int n = sizeof(array) / sizeof(array[0]);

    int k = 3;

    print_k_most_frequent_num(array, n, k);

    return 0;
}
