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
    int n;
    int a[1010];
    int res[1010];

    cin >> n;
    for(int i = 1; i <= n; i++){
    	res[i] = 1;
    	cin >> a[i];
    }

    for(int i = 2; i <= n; i++){
    	for(int j = 1; j < i; j++){
    		if(a[i] > a[j] && res[i] <= res[j]){
    				res[i] = res[j]+1;
    		}
    	}
    }
    

    cout << * max_element(res+1,res+n);
    return 0;
}