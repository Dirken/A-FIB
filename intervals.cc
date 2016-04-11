#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main () {
	int n;
	double m;
	while (cin >> n) {
		if (n == 0) cout << 0 << endl;
		else {
			vector<double> v(n);
			for (int i = 0; i < n; ++i) { cin >> m; v[i] = m;}
			random_shuffle (v.begin(), v.end());
			sort(v.begin(), v.end());
			int pos = 0; int i = 0; int intervals = 1;
			while (i < n) {
				if (v[pos]+1 < v[i]) {
					pos = i;
					++intervals;
				}
				++i;
			}
			cout << intervals << endl;
		}
	}
}

/*
4  1.4 1.9 2.3 2.7
6  1.75 3.5 0.5 3 1.5 0.2
2  -2.5 -3.5

*/
