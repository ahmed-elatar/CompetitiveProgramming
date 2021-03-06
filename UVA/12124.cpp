#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <hash_map>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
using namespace std;

#define PI 3.14159265359
#define all(v) v.begin(),v.end()
#define sortva(v) sort(all(v))
#define sortvd(v) sort(v.rbegin(),v.rend())
#define sortaa(a,n) sort(a,a+n)
#define sortad(a,n) sort(a,a+n),reverse(a,a+n)
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1,v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define sfstr(v) scanf("%s", v);
#define sz(v) v.size()
#define ndl puts("")
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main() {
	PLAY();

	int t;
	cin >> t;
	string type, name;
	int price, quality;
	while (t--) {
		int n, p;
		cin >> n >> p;
		map<string, map<int, int>> mp;
		for (int i = 0; i < n; i++) {
			cin >> type >> name >> price >> quality;
			if (mp[type].find(quality) == mp[type].end()) mp[type][quality] = price;
			else mp[type][quality] = min(mp[type][quality], price);
		}
		int lo = 0, hi = 1e9 + 100, res = 0;
		while (lo <= hi) {
			int mid = (lo + hi) / 2; // quality
			int cost = 0;
			for (auto e : mp) {
				map<int, int>::iterator it = e.second.lower_bound(mid);
				if (it == e.second.end()) {
					cost = INT_MAX;
					break;
				}
				int mn = INT_MAX;
				for (; it != e.second.end(); it++)
					mn = min(mn, it->second);
				cost += mn;
			}
			if (cost <= p) lo = mid + 1, res = mid;
			else hi = mid - 1;
		}
		cout << res << endl;
	}

	return 0;
}
