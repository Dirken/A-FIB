#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 
typedef vector< vector<int> > Graph;
 
bool dosColorable(Graph& G) {
    queue<int> Q;
    vector<int> colors(G.size(), -1);
    for (int i = 0; i < G.size(); ++i) {
        if (colors[i] < 0) {
            Q.push(i);
            colors[i] = 1;
            while (not Q.empty()) {
                int f = Q.front(); Q.pop();
                for (int j = 0; j < G[f].size(); ++j) {
                    if (colors[G[f][j]] < 0) {
                        Q.push(G[f][j]);
                        colors[G[f][j]] = 1 - colors[f];
                    }
                    else if (colors[G[f][j]] == colors[f]) return false;
                }
            }
        }
    }
    return true;
}
 
int main() {
    int n, m;
    while (cin >> n >> m) {
        Graph G(n);
        int n1, n2;
        for (int i = 0; i < m; ++i) {
            cin >> n1 >> n2;
            G[n1].push_back(n2);
            G[n2].push_back(n1);
        }
        if (!dosColorable(G))   cout << "no" << endl;
        else                    cout << "yes" << endl;             
    }
}