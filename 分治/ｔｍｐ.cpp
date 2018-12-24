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
int tmp[100];
void Merge(int a[],int tmp[],int begin,int mid,int end){
	int p1 = begin;
	int p2 = end;

	while(i < l)
}
void MergeSort(int a[],int begin,int end){
	if(begin < end){
		int mid = l+(r-l)/2;
		MergeSort(a,begin,mid);
		MergeSort(a,mid+1,end);
		Merge(a,begin,mid,end);
	}
}

int main(int argc, char * argv[]) 
{
	int a[100];
    int n;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    	cin >> a[i];

    MergeSort(a,0,n-1);
    
    for(int i = 0; i < n; i++)
    	cout << a[i] << " ";
    
    return 0;
}