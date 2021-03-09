#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    multiset <int> s;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
	cin >> arr[i];
    }
    for (int i = 0; i < k; i++) {
	s.insert(arr[i]);
    }
    cout << *s.begin() << ' ';
    for (int i = k; i < n; i++) {
	s.insert(arr[i]);
	s.erase(s.find(arr[i-k]));
	cout << *s.begin() << ' ';
    }
}