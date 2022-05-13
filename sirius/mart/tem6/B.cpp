#include <bits/stdc++.h>
typedef long long ll;
#define double long long

const ll INF = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

double PI = acos(-1), eps = 1e-6;

struct point {
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}
	point operator- (point p) {
		return point(x - p.x, y - p.y);
	}
	bool operator< (point p) {
		return (p.x == x ? y < p.y : x < p.x);
	}
	bool operator!= (point p) {
		return p.x != x || p.y != y;
	}
	bool operator== (point p) {
		return p.x == x && p.y == y;
	}
};

istream& operator>> (istream& in, point& p) {
	in >> p.x >> p.y;
	return in;
}

ostream& operator<< (ostream& out, point& p) {
	out << p.x << ' ' << p.y;
	return out;
}

struct vct {
	point p;
	vct(point a = point(), point b = point()) {
		p = a - b;
	}
	double operator* (vct v) {
		return p.x * v.p.x + p.y * v.p.y;
	}
	double operator% (vct v) {
		return p.x * v.p.y - p.y * v.p.x;
	}
	double operator~ () {
		return p.x * p.x + p.y * p.y;
	}
	bool operator< (vct v) {
		return (*this % v == 0 ? ~*this < ~v : *this % v < 0);
	}
	bool operator<= (vct v) {
		return *this % v <= 0;
	}
	point operator+ (point pp) {
		return point(pp.x + p.x, pp.y + p.y);
	}
};

struct polygon {
	vector<point> arr;
	polygon(vector<point> arr = vector<point>(0)): arr(arr) {}
	ll area() {
		ll j = arr.size() - 1;
		ll ans = 0;
		for (ll i = 0; i < arr.size(); i++) {
			ans += vct(arr[j]) % vct(arr[i]);
			j = i;
		}
		return ans;
	}
};

istream& operator>> (istream& in, polygon& p) {
	ll n;
	in >> n;
	p.arr.resize(n);
	for (auto& i : p.arr) {
		in >> i;
	}
	sort(p.arr.begin(), p.arr.end());
	p.arr.resize(unique(p.arr.begin(), p.arr.end()) - p.arr.begin());
	return in;
}

ostream& operator<< (ostream& out, polygon& p) {
	out << p.arr.size() << '\n';
	for (auto& i : p.arr) {
		out << i << '\n';
	}
	ll x =  abs(p.area());
	if (x % 2 == 0) {
		cout << x / 2;
	} else {
		cout << x / 2 << '.' << 5;
	}
	return out;
}

struct convex_polygon {
	polygon cp;
	convex_polygon(polygon p = polygon()) {
		vector<vct> arr;
		point mp(1e10, 1e10);
		for (auto& i : p.arr) {
			assign_min(mp, i);
		}
		for (auto& i : p.arr) {
			if (i != mp) {
				arr.push_back(vct(i, mp));
			}
		}
		sort(arr.begin(), arr.end());
		vector<point> ans(1, mp);
		for (auto& i : arr) {
			point pp = i + mp;
			while (ans.size() > 1 && (vct(pp, ans[ans.size() - 2]) <= vct(ans.back(), ans[ans.size() - 2]))) {
				ans.pop_back();
			}
			ans.push_back(pp);
		}
		cp = polygon(ans);
	}
	double area() {
		return cp.area();
	}
};

int main() {
	freopen("hull.in", "r", stdin);
	freopen("hull.out", "w", stdout);
	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	polygon p;
	cin >> p;
	convex_polygon cp(p);
	cout << cp.cp;
}
/*
⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣵⣿⣿⣿⠿⡟⣛⣧⣿⣯⣿⣝⡻⢿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⠋⠁⣴⣶⣿⣿⣿⣿⣿⣿⣿⣦⣍⢿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⢷⠄⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢼⣿⣿⣿⣿
⢹⣿⣿⢻⠎⠔⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⣿⣿⣿⣿
⢸⣿⣿⠇⡶⠄⣿⣿⠿⠟⡛⠛⠻⣿⡿⠿⠿⣿⣗⢣⣿⣿⣿⣿
⠐⣿⣿⡿⣷⣾⣿⣿⣿⣾⣶⣶⣶⣿⣁⣔⣤⣀⣼⢲⣿⣿⣿⣿
⠄⣿⣿⣿⣿⣾⣟⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⢟⣾⣿⣿⣿⣿
⠄⣟⣿⣿⣿⡷⣿⣿⣿⣿⣿⣮⣽⠛⢻⣽⣿⡇⣾⣿⣿⣿⣿⣿
⠄⢻⣿⣿⣿⡷⠻⢻⡻⣯⣝⢿⣟⣛⣛⣛⠝⢻⣿⣿⣿⣿⣿⣿
⠄⠸⣿⣿⡟⣹⣦⠄⠋⠻⢿⣶⣶⣶⡾⠃⡂⢾⣿⣿⣿⣿⣿⣿
⠄⠄⠟⠋⠄⢻⣿⣧⣲⡀⡀⠄⠉⠱⣠⣾⡇⠄⠉⠛⢿⣿⣿⣿
⠄⠄⠄⠄⠄⠈⣿⣿⣿⣷⣿⣿⢾⣾⣿⣿⣇⠄⠄⠄⠄⠄⠉⠉
⠄⠄⠄⠄⠄⠄⠸⣿⣿⠟⠃⠄⠄⢈⣻⣿⣿⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⢿⣿⣾⣷⡄⠄⢾⣿⣿⣿⡄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠸⣿⣿⣿⠃⠄⠈⢿⣿⣿⠄⠄⠄⠄⠄⠄⠄
*/
