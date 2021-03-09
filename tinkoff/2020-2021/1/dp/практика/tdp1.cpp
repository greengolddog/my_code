#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, sum;
    double no;
    cin >> n;
    vector<int> arr;
    no = 2;
    arr.push_back(1);
    arr.push_back(1);
    while (no <= n) {
	int ni = round(no);
	if (ni % 2 == 0) {
	    arr.push_back(arr[no-1]);
	} else {
	    arr.push_back(arr[no-1]+arr[ni/2]);
	}
	no++;
    }
    cout << arr[n];
}