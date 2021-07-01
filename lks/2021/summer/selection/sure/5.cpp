#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct block {
	vector<ll> arr;
	ll sum = 0, size;
	block(vector<ll> arr2 = vector<ll>(0, 0)) {
		arr = arr2;
		size = arr.size();
		for (ll i = 0; i < size; i++) {
			sum += arr[i];
		}
	}
	ll rast(ll x) {
		if (x <= arr[0]) {
			return abs(sum - x*size);
		}
		if (x >= arr[size - 1]) {
			return abs(x*size - sum);
		}
		ll ans = 0;
		for (auto i : arr) {
			ans += abs(x - i);
		}
		return ans;
	}
	bool insert(ll x, ll ps = 10000000000) {
		if ((size == 0) || (arr[0] > x) || (arr[size - 1] < x)) {
			if (ps > x) {
				size++;
				sum += x;
				if (size == 1) {
					arr.push_back(x);
					return true;
				}
				arr.insert(arr.end()-1, x);
				return true;
			}
			return false;
		}
		for (ll i = 1; i < size; i++) {
			if ((x >= arr[i]) && (x <= arr[i])) {
				arr.insert(arr.begin()+i-1, x);
				sum += x;
				size++;
				return true;
			}
		}
		return false;
	}
	void push_back(ll x) {
		arr.push_back(x);
		sum += x;
		size++;
	}
	ll operator[] (ll x) {
		return arr[x];
	}
};

struct sqrt_dec {
	vector<block> arr;
	ll size, k = 400, stc, sum = 0;
	sqrt_dec(vector<pair<ll, ll>> arr2 = vector<pair<ll, ll>>(0, {0, 0})) {
		size = arr2.size();
		stc = 0;
		arr = vector<block>((size+k-1)/k, block(vector<ll>(0, 0)));
		for (ll i = 0; i < size; i++) {
			sum += abs(arr2[i].second);
			arr[i/k].push_back(arr2[i].first);
		}
	}
	pair<ll, ll> dist() {
		ll now_size = size/2, x = 0;
		for (block& i : arr) {
			if (i.size > now_size) {
				x = i[now_size];
				break;
			}
			now_size -= i.size;
		}
		if (size % 2 == 0) {
			now_size = size/2-1;
			for (block& i : arr) {
				if (i.size > now_size) {
					x = min(i[now_size], x);
					break;
				}
				now_size -= i.size;
			}
		}
		ll ans = sum;
		for (block& i : arr) {
			ans += i.rast(x);
		}
		return {x, ans};
	}
	void insert(pair<ll, ll> ins) {
		if (size == 0) {
			arr.push_back(block(vector<ll>(0, 0)));
		}
		sum += abs(ins.second);
		ll x = ins.first;
		size++;
		stc++;
		ll b = 1;
		for (ll i = 0; i < (arr.size() - 1); i++) {
			if (arr[i].insert(x, arr[i+1][0])) {
				b = 0;
				break;
			}
		}
		if (b) {
			arr[arr.size()-1].insert(x);
		}
		if (stc == k) {
			per();
		}
	}
	void per() {
		stc = 0;
		vector<ll> arr2;
		for (block& i : arr) {
			for (ll j = 0; j < i.size; j++) {
				arr2.push_back(i[j]);
			}
		}
		arr = vector<block>((size+k-1)/k, block(vector<ll>(0, 0)));
		for (ll i = 0; i < size; i++) {
			arr[i/k].push_back(arr2[i]);
		}
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	sqrt_dec s;
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll com;
		cin >> com;
		if (com == 2) {
			pair<ll, ll> ans = s.dist();
			cout << ans.first << ' ' << ans.second << '\n';
		} else {
			ll x, y;
			cin >> x >> y;
			s.insert({x, y});
		}
	}
}
