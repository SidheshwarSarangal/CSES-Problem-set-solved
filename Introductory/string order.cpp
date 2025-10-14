#include <bits/stdc++.h>
using namespace std;

// Function to find the k-th digit in the infinite sequence
char findKthDigit(long long k) {
    long long len = 1;      // length of current group numbers (1, 2, 3, ...)
    long long count = 9;    // number of integers in this group
    long long start = 1;    // first number of this group

    // Step 1: find which group contains the k-th digit
    while (k > len * count) {
        k -= len * count;
        len++;
        count *= 10;
        start *= 10;
    }

    // Step 2: find the exact number that contains the k-th digit
    start += (k - 1) / len;
    string s = to_string(start);

    // Step 3: find the specific digit in that number
    return s[(k - 1) % len];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        cout << findKthDigit(k) << "\n";
    }

    return 0;
}
