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
//http://poj.org/problem?id=1458
char s1[1000];
char s2[1000];
int dp[1000][1000];

int main(int argc, char * argv[]) 
{
    while(cin >> s1 >> s2){
    	int len1 = strlen(s1);
    	int len2 = strlen(s2);

    	for(int i = 0; i <= len1; i++)
    		dp[i][0] = 0;
    	for(int i = 0; i <= len2; i++)
    		dp[0][i] = 0;

    	for(int i = 1; i <= len1; i++){
    		for(int j = 1; j <= len2; j++){
    			if(s1[i-1] == s2[j-1])dp[i][j] = dp[i-1][j-1] + 1;
    			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    		}
    	}

    	cout << dp[len1][len2] << endl;
    }

    return 0;
}