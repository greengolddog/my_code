#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, z, p, m;
    vector<long long> arr(21);
    cin >> n;
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 8;
    for (long long i = 3; i <= n; i++) {
	arr[i] = (arr[i-1] * 3) - (arr[i - 3] * 2);
    }
    cout << arr[n];
}