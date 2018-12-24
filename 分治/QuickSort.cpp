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

////////////////////// begin    end
void QuickSort(int a[],int s,int e){
	if( s >= e )
		return;
	int k = a[s];
	int i = s,j = e;
	while( i != j){
		while(i < j && a[j] >= k)
			j--;
		swap(a[i],a[j]);
		while(i < j && a[i] <= k)
			i++;
		swap(a[i],a[j]);
		// cout << " ///////////////";
		// for(int i = 0; i <= e; i++){
		// 	cout << a[i] << " ";
		// }cout << endl;
	}
	QuickSort(a,s,i-1);
	QuickSort(a,i+1,e);

}

int a[10000];

int main(int argc, char * argv[]) 
{
	//int size = sizeof(a)/sizeof(int);
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++)
		cin >> a[i];
	QuickSort(a,0,n-1);
	
	for(int i = 0; i < n; i++)
		cout << a[i] << ",";
	cout << endl;

    return 0;
}