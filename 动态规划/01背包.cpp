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
#define LOCAL

struct Bag{
	int w;
	int d;
}bag[3510];

int dp[3510][13000];
int main(int argc, char * argv[]) 
{
    
	int N,M;
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		cin >> bag[i].w >> bag[i].d;

	for(int i = 0; i <= M; i++)
		dp[0][i] = 0;
	for(int i = 0; i < N; i++)
		dp[i][0] = 0;

	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= M; j++){
			if(j-bag[i].w >= 0) 
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-bag[i].w]+bag[i].d);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	cout << dp[N][M];
    return 0;
}

