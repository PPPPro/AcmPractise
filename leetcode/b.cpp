#include<iostream>
#include<cstring>
#include<map>
#include<set>
#include<vector>
using namespace std;

int numSubarraysWithSum(vector<int>& A, int S) {
    int cnt = 0;
    for(int i= 0; i < A.size(); i++){
        int sum = 0;
        for(int j = i; j < A.size(); j++){
            sum += A[j];
            if(sum == S)cnt++;
            else if(sum > S)break;
        }
    }
    return cnt;
}
int main(){
    vector<int> A;
    int size;
    cin >> size;
    int S;
    cin >> S;
    for(int i = 0; i < size; i++){
        int t;
        cin >> t;
        A.push_back(t);
    }
    cout << numSubarraysWithSum(A,S);
}
