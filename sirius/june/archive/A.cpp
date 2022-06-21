/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>
#include "optimization.h" // http://acm.math.spbu.ru/~sk1/algo/lib

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define err(...) fprintf(stderr, "%.2f : ", 1. * clock() / CLOCKS_PER_SEC), fprintf(stderr, __VA_ARGS__), fflush(stderr)

namespace Coder {
	char digit16(int x) {
		return x < 10 ? '0' + x : 'A' + x - 10;
	}

	uint32_t an = 0;
	vector<uint8_t> a;
	void addBit(int x) {
		if (an % 8 == 0)
			a.push_back(0);
		a.back() |= x << (an++ % 8);
	}
	void addBits(int x, int k) {
		assert(x < (1 << k));
		forn(i, k)
			addBit((x >> i) & 1);
	}
	void flush() {
		for (auto x : a) {
			writeChar(digit16(x % 16));
			writeChar(digit16(x >> 4));
		}
	}

	void code(vector<uint8_t> &text) {
		err("encode len=%ld\n", a.size());
		/** THE ALGORITHM **/
		addBits(text.size(), 24);
		for (auto c : text)
			addBits(c, 7);
		/** END OF THE ALGORITHM **/
		flush();
	}
};

namespace Decoder {
	int digit16(uint8_t x) {
		return isdigit(x) ? x - '0' : x - 'A' + 10;
	}
	void prepare(vector<uint8_t> &text) {
		for (auto &c : text)
			c = digit16(c);
	}

	void decode(vector<uint8_t> &a) {
		err("decode len=%ld\n", a.size());
		auto readBits = [&](int bn = 1) {
			static size_t k = 0;
			int32_t c = 0;
			forn(j, bn) {
				assert(k / 4 < a.size());
				c |= ((a[k / 4] >> (k % 4)) & 1) << j, k++;
			}
			return c;
		};
		prepare(a);

		/** THE ALGORITHM **/
		int n = readBits(24);
		forn(i, n)
			writeChar(readBits(7));
		/** END OF THE ALGORITHM **/
	}
};

int main() {
	vector<uint8_t> text;
	while (!isEof())
		text.push_back(getChar());

	auto isEncoded = [&]() {
		for (auto c : text)
			if (!('0' <= c && c <= '9') && !('A' <= c && c <= 'F'))
				return 0;
		return 1;
	};

	(!isEncoded() ? Coder::code : Decoder::decode)(text);
}
