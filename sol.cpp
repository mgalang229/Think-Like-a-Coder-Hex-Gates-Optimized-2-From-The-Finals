#include <bits/stdc++.h>

using namespace std;

string s, ns;

void HexToBinary() {
	map<char, string> mp;
	mp['0'] = "0000", mp['1'] = "0001";
	mp['2'] = "0010", mp['3'] = "0011";
	mp['4'] = "0100", mp['5'] = "0101";
	mp['6'] = "0110", mp['7'] = "0111";
	mp['8'] = "1000", mp['9'] = "1001";
	mp['A'] = "1010", mp['a'] = "1010";
	mp['B'] = "1011", mp['b'] = "1011";
	mp['C'] = "1100", mp['c'] = "1100";
	mp['D'] = "1101", mp['d'] = "1101";
	mp['E'] = "1110", mp['e'] = "1110";
	mp['F'] = "1111", mp['f'] = "1111";
	for (int i = 0; i < (int) ns.size(); i++) {
		s += mp[ns[i]];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, l;
	cin >> h >> l;
	string unlock[h], lock[l];
	for (int i = 0; i < h; i++) {
		cin >> unlock[i];
	}
	for (int i = 0; i < l; i++) {
		cin >> lock[i];
	}
	bool p[17];
	memset(p, false, sizeof(p));
	for (int i = 0; i < h; i++) {
		ns += unlock[i];
		HexToBinary();
		int b[1000], id = 0;
		memset(b, 0, sizeof(b));
		reverse(s.begin(), s.end());
		for (int j = 0; j < (int) s.size(); j++) {
			if (s[j] == '1') {
				b[id + 1]++;
			}
			id++;
		}
		int cnt2 = 0;
		for (int j = 0; j <= id; j++) {
			if (b[j] == 1) {
				p[cnt2] = true;
			}
			cnt2++;
		}
		ns = s = "";
	}
	cout << "BULBS: ";
	for (int i = 0; i < 17; i++) {
		if (p[i]) {
			cout << "BULB" << i << " ";
		}
	}
	cout << '\n';
	for (int i = 0; i < l; i++) {
		ns += lock[i];
		HexToBinary();
		int b[1000], id = 0;
		memset(b, 0, sizeof(b));
		reverse(s.begin(), s.end());
		for (int j = 0; j < (int) s.size(); j++) {
			if (s[j] == '1') {
				b[id + 1]++;
			}
			id++;
		}
		int cnt2 = 0;
		for (int j = 0; j <= id; j++) {
			if (b[j] == 1) {
				p[cnt2] = false;
			}
			cnt2++;
		}
		ns = s = "";
	}
	for (int i = 1; i < 17; i++) {
		if (i < 10) {
			if (p[i]) {
				cout << "DOOR 0" << i << ": true";
			} else {
				cout << "DOOR 0" << i << ": false";
			}
		} else {
			if (p[i]) {
				cout << "DOOR " << i << ": true";
			} else {
				cout << "DOOR " << i << ": false";
			}
		}
		cout << '\n';
	}
	return 0;
}
