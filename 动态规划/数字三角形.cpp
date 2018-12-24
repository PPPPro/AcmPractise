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



int main(int argc, char * argv[]) 
{
	int a[110][110];
	int res[110][110];
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= i; j++){
			cin >> a[i][j];
		}
	}
	res[0][0] = a[0][0];
	for(int i = 1; i < n; i++)
		for(int j = 0; j <= i; j++){
			if(j == 0)
				res[i][j] = a[i][j] + res[i-1][j];
			else if(j == i)
				res[i][j] = a[i][j] + res[i-1][j-1];
			else
				res[i][j] = max(res[i-1][j-1]+a[i][j],res[i-1][j]+a[i][j]);
		}

	
	int tx = 0;
	for(int i = 0; i < n; i++){
		if(tx < res[n-1][i])
			tx = res[n-1][i];
	}
	cout << tx;
    return 0;
}