#include <iostream>
#include <vector>
#include<limits.h>
using namespace std;
 
long long soluciona(vector<long long>& v) {
    int n = v.size();
    //per simplicitat tenim una columna i una fila extra m[0][0] no l'usem
    long long minim[n][n];
    long long aux;
    int i, j, k, L;
    // cost is zero when multiplying one matrix.
    for (i = 1; i < n; i++) minim[i][i] = 0;
 
    for (int length = 2; length < n; ++length) {
        for (i = 1; i <= n-length +1; ++i){
            j = i+length -1;
            minim[i][j] = LLONG_MAX;
            for (k=i; k<=j-1; k++) {
                // aux = cost/scalar multiplications
                aux = minim[i][k] + minim[k+1][j] + v[i-1]*v[k]*v[j];
                if (aux < minim[i][j]) minim[i][j] = aux;
            }
        }
    }
    return minim[1][n-1];
}
 
int main(){
    int n;
    while (cin >> n) {
        vector<long long> v;
        for (int i = 0; i <= n; ++i) { int m; cin >> m; v.push_back(m);}
        cout << soluciona(v) << endl;
    }
}