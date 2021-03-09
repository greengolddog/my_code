#include <bits/stdc++.h>
using namespace std;

void outv(vector<long long> arr, long long n) {
    for (long long i = 0; i < n; i++) {
	cout << arr[i] << ' ';
    }
    cout << "\n";
}

void f(vector<long long> arr, long long n, long long x, long long r) {
    if (x <= n) {
	for (auto i : arr) {
	    cout << i << ' ';
	}
	cout << n << endl;
    }
    arr.push_back(0);
    for (arr[r] = n - 1; arr[r] >= x; arr[r]--) {
	f(arr, n - arr[r], arr[r], r + 1);
    }
    arr.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    vector<long long> arr;
    f(arr, n, 1, 0);
}
