#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, b;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = n - 1; i >= 0; i--) {
	arr[i] = i + 1;
    }
    while (1 == 1) {
	for (int i = 0; i < n; i++) {
	    cout << arr[i];
	}
	cout << "\n";
	b = 0;
	for (int i = n - 2; i >= 0; i--) {
	    if (arr[i + 1] > arr[i]) {
		b = 1;
		int it = 0;
		for (int j = i + 1; j < n; j++) {
		    if (arr[j] >= arr[i]) {
			it = j;
		    } else {
			break;
		    }
		}
		swap(arr[it], arr[i]);
		reverse(arr.begin() + i + 1, arr.end());
		break;
	    }
	}
	if (b == 0) {
	    break;
	}
    }
}