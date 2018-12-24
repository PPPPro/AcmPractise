// http://icpcsummer.openjudge.cn/2018hw1/08/
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
const int maxn =  1e5;
int s;
void QuickSort(int a[],int begin,int end){
	if(begin >= end) return;
	int i = begin;
	int j = end;
	int key = a[begin];

	while(i != j){
		while(i < j && a[j] >= key)
			j--;
		swap(a[i],a[j]);
		while(i < j && a[i] <= key)
			i++;
		swap(a[i],a[j]);
		// cout << " ///////////////";
		// for(int i = 0; i <= end; i++){
		// 	cout << a[i] << " ";
		// }cout << endl;
	}
	if(i < s) QuickSort(a,i+1,end);
	else{
		QuickSort(a,begin,i-1);
		QuickSort(a,i+1,end);
	}
}
int main(int argc, char * argv[]) 
{
	int n,m;
	int a[maxn];

	cin >> n;
	for(int i = 0 ; i < n; i++)
		cin >> a[i];
	cin >> m;
	s = n-m;
	QuickSort(a,0,n-1);

	for(int i = n-1; i >= s; i--)
		cout << a[i] <<endl;

    return 0;
}
