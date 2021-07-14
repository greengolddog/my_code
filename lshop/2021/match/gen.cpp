#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll inp, inp2;
	cin >> inp;
	cout << inp << ' ';
	cin >> inp;
	cout << inp << ' ';
	cin >> inp >> inp2;
	if (inp2*2-2 < inp) {
		inp++;
		inp2 = 1001;
	}
	cout << inp << ' ' << inp2-1 << '\n';
	cout << "...\n...\n...";
}
