#include <iostream>
using namespace std;

int ans(string x, string y){
	int n = x.size() +1;
    int m = y.size() +1;
    int dp[n][m];

    for (int j=0; j < m; ++j) dp[0][j] = j*3;
    for (int i=0; i < n; ++i) dp[i][0] = i*3; 
        
    for (int i=1; i < n; ++i) {
        for (int j=1; j < m; ++j) {
            if (x[i-1] == y[j-1]) 
            	dp[i][j] = min(dp[i-1][j-1], min ((dp[i][j-1] +2),(dp[i-1][j] +2)));
            else dp[i][j] = min(dp[i][j-1] +3,dp[i-1][j] +3);  
        }
   	}
    return dp[n-1][m-1];
}

int main () {
    string x,y;
    while (cin >> x >> y) cout << ans(x,y) << endl;
}
 