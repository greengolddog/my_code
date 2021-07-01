#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	srand(time(0));
	ll n = rand();
	ll now = 0;
	vector<string> arr;
	arr.push_back("size");
	arr.push_back("pop_back");
	arr.push_back("front");
	arr.push_back("pop_front");
	arr.push_back("back");
	arr.push_back("clear");
	arr.push_back("push_back");
	arr.push_back("push_front");
	for (ll i = 0; i < n; i++) {
		if (now < 10000) {
			ll r = rand()%8;
			cout << arr[r];
			if ((r == 6) || (r == 7)) {
				cout << ' ' << rand();
				now++;
			}
			if ((r == 1) || (r == 3)) {
				now--;
			}
			if (r == 5) {
				now = 0;
			}
		} else {
			ll r = rand()%6;
			cout << arr[r];
			if ((r == 1) || (r == 3)) {
				now--;
			}
			if (r == 5) {
				now = 0;
			}
		}
		cout << '\n';
	}
	cout << "exit" << endl;
}
