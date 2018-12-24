#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
const int maxn = 3410;


int n,m;
int v[maxn],w[maxn];
int dp[12885];
int main(int argc, char * argv[]) 
{
	ms(dp);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		 cin >> w[i] >> v[i];

	for(int i = 1; i <= n; i++){
		for(int j = m; j >= w[i]; j--){
			dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout << dp[m];
    return 0;
}