//http://bailian.openjudge.cn/practice/2456
//百练2456
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
const int maxn = 1000000;

int N,C;
int a[100000];

bool judge(int s){
	int sum = 0;
	int cnt = 1;
	for(int i = 1; i < N; i++){
		if(sum + a[i] - a[i-1] < s){
			sum += (a[i] - a[i-1]);
		}else{
			sum = 0;
			cnt++;
		}
	}
	if(cnt >= C)return true;
	return false;
}

int bin_scarch(){
	int L;
	int R;
	int mid;
	R = L = a[N-1] - a[0];
	for(int i = 1; i < N; i++){
		if(a[i]-a[i-1] < L){
			L = a[i]-a[i-1];
		}
	}
	while(L <= R){
		mid = (R+L)/2;
		if(judge(mid)){
			L = mid + 1;
		}else{
			R = mid - 1;
		}
	}
	return R;
}


int main(int argc, char * argv[]) 
{
    cin >> N >> C;
    for(int i = 0; i < N; i++){
    	cin >> a[i];
    }

    sort(a,a+N);
    
    cout <<bin_scarch();

    return 0;
}