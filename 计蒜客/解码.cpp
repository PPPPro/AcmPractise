#include<iostream>
#include<cstring>
using namespace std;
string s;
int main(){
    int i,j,n,ten;
    getline(cin,s);
    for(i = 0; i < s.size(); i++){



        if(s[i] == '('){//如果遇见了括号
            string tmp;
            i++;
            for(;i<s.size();i++){//将括号里的字母赋给一个新的，不用也行，记住括号开始和结尾的位置
                if(s[i] == ')')break;
                else tmp.push_back(s[i]);
           }
           cout<<tmp;//因为有括号的话至少要输出一次，所以先给他输出了；
           i++;
            if(s[i] >= '0' && s[i] <= '9' && i < s.size()){//如果括号后面有数字的话。。。
                int beishu[10];
                int k = 0;
                while(1){
                    if(s[i] >= '0' && s[i] <= '9' && i < s.size()){//因为循环是0开始，所以当循环进行到这里时，不知道是几位数字，所以先存下来。
                        beishu[k] = int(s[i] - '0');
                        k++;
                    }
                    else break;
                    i++;
                }
                n=0;
                ten = 1;
                for(k = k-1;k>=0;k--){//把存下来的数字拼成一个整数
                    n += beishu[k]*ten;
                    ten *= 10;
                }
                i--;
            for(n--;n>0;n--){
                    cout<<tmp;
            }
            }
        }




        else if(s[i] >='0' && s[i]<='9'){//如果遇见了数字。。。
            n = 0;
            ten = 1;
            char c = s[i-1];
            n += int(s[i]-'0')*ten;
            ten*= 10;

            while((n--)-1)cout<<c;
        }




//如果啥都没有。。。
        else
            cout<<s[i];
    }
    return 0;
}
