#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<long long, set<long long>> dict;
    set <long long> s;
    set <long long> se;
    set <long long> se2;
    long long n, m, k;
    cin >> n >> m >> k;
    map<long long, set<long long>> arr;
    string command;
    long long first, second;
    long long x;
    for (long long i = 0; i < k; i++) {
	cin >> command >> first;
	if ((command == "ADD") || (command == "DELETE")) {
	    cin >> second;
	    x = first;
	    first = second;
	    second = x;
	    if (command == "ADD") {
		if (se.find(second) == se.end()) {
		    se.insert(second);
		    dict[second] = s;
		}
		dict[second].insert(first);
		if (se2.find(first) == se2.end()) {
		    se2.insert(first);
		    arr[first] = s;
		}
		arr[first].insert(second);
	    } else {
		dict[second].erase(first);
		arr[first].erase(second);
	    }
	} else {
	    if (command == "CLEAR") {
		if (se2.find(first) != se2.end()) {
		    for (auto i : arr[first]) {
			dict[i].erase(first);
		    }
		    arr[first] = s;
		}
	    }
	    if (command == "LISTSET") {
		if (se2.find(first) != se2.end()) {
		    if (arr[first].size() > 0) {
			for (auto i : arr[first]) {
			    cout << i << ' ';
			}
			cout << endl;
		    } else {
			cout << -1 << endl;
		    }
		} else {
		    cout << -1 << endl;
		}
	    }
	    if (command == "LISTSETSOF") {
		if (se.find(first) != se.end()) {
		    if (dict[first].size() > 0) {
			for (auto i : dict[first]) {
			    cout << i << ' ';
			}
			cout << endl;
		    } else {
			cout << -1 << endl;
		    }
		} else {
		    cout << -1 << endl;
		}
	    }
	}
    }
}