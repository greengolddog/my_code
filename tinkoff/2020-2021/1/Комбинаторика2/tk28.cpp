#include <bits/stdc++.h>
using namespace std;

int c;

void f(vector<long long> arr,vector<long long> cf,vector<long long> cfi, long long n, long long x, long long r, long long mcf) {
    arr.push_back(0);
    for (long long i = x; i <= n+5; i++) {
	if (mcf > cfi[i]) {
	    arr[r] = cf[i];
	    if ((n - arr[r]) >= 0) {
		cfi[i]++;
		f(arr, cf, cfi, n - arr[r], i, r + 1, mcf);
		cfi[i]--;
	    }
	}
    }
    arr.pop_back();
    if (n == 0) {
	long long c = 0;
	for (auto i : arr) {
	    if (c == 1) {
		cout << "+";
	    }
	    cout << i;
	    c = 1;
	}
	cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, m;
    cin >> n >> m;
    vector<long long> arr;
    vector<long long> cf(n+5,1);
    vector<long long> cfi(n+5,0);
    for (long long i = 2; i < n+5; i++) {
	cf[i] = cf[i-1]+cf[i-2];
    }
    f(arr, cf, cfi, n, 1, 0, m);
}
