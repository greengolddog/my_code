#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, b, k, s;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = n - 1; i >= n - k; i--) {
	arr[i] = 1;
    }
    while (1 == 1) {
	for (auto i : arr) {
	    cout << i;
	}
	cout << "\n";
	b = 0;
	for (int i = n - 2; i >= 0; i--) {
	    if (arr[i] == 0) {
		if (arr[i + 1] != 0) {
		    b = 1;
		    arr[i] = 1;
		    arr[i + 1] = 0;
		    s = 0;
		    for (int j = i + 2; j <= n - 1; j++) {
			if (arr[j] == 1) {
			    s++;
			    arr[j] = 0;
			}
		    }
		    for (int j = n - 1; j >= n - s; j--) {
			arr[j] = 1;
		    }
		    break;
		}
	    }
	}
	if (b == 0) {
	    break;
	}
    }
}