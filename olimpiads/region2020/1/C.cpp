#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;
map<int,vector<pair<int,string>>> m;

vector<int> rec(vector<int>& arr, int nm, string str) {
	if (str.size() > 0 and str.size() % 2 == 0) {
		int c = 0;
		for (int i = 0; i < str.size()/2; i++) {
			if (str[i] != str[i+str.size()/2]) {
				c = 1;
				break;
			}
		}
		if (c == 0) {
			return arr;
		}
	}
	vector<int> arr2, arr3;
	for (auto i : m[nm]) {
		int c = 0;
		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] == i.first) {
				c = 1;
				break;
			}
		}
		if (c == 0) {
			arr.push_back(i.first);
			arr3 = rec(arr, i.first, str + i.second);
			if (arr3.size() > 0) {
				return arr3;
			}
			arr.pop_back();
		}
	}
	return arr2;
}

int main() {
	ll a,b,i1,i2,c;
	string i3;
	cin >> a >> b;
	for (int i = 0; i < b; i++) {
		cin >> i1 >> i2 >> i3;
		if (m.find(i1) == m.end()) {
			m[i1] = vector<pair<int,string>>(0,{0,""});
		}
		m[i1].push_back({i2,i3});
		if (m.find(i2) == m.end()) {
			m[i2] = vector<pair<int,string>>(0,{0,""});
		}
		m[i2].push_back({i1,i3});
	}
	vector<int> arr, arr2;
	c = 0;
	for (int i = 1; i <= a; i++) {
		arr.push_back(i);
		arr2 = rec(arr,i,"");
		arr.pop_back();
		if (arr2.size() > 0) {
			c = 1;
			cout << arr2.size() << endl;
			for (auto j : arr2) {
				cout << j << ' ';
			}
			break;
		}
	}
	if (c == 0) {
		cout << -1;
	}
}