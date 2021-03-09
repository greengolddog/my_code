#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    vector<long long> arr(n+1);
    vector<long long> arr2(n+1);
    arr[0] = 1;
    arr[1] = 2;
    arr2[0] = 1;
    arr2[1] = 1;
    for (long long i = 2; i <= n; i++) {
	arr[i] = 0;
	arr2[i] = 0;
	for (long long j = 0; j < i; j++) {
	    arr2[i] += arr2[j] * arr2[i-1-j];
	    arr2[i] = (arr2[i] % 1000000007);
	}
	arr2[i] = (arr2[i] % 1000000007);
	for (long long j = 0; j < i; j++) {
	    arr[i] += arr[j] * arr[i-1-j];
	    arr[i] += arr[j] * arr2[i-1-j];
	    arr[i] = (arr[i] % 1000000007);
	}
	arr[i] = (arr[i] % 1000000007);
    }
    cout << arr[n];
}