#include<iostream>
#include<cstring>
using namespace std;
string s;
int main(){
    int i,j,n,ten;
    getline(cin,s);
    for(i = 0; i < s.size(); i++){



        if(s[i] == '('){//�������������
            string tmp;
            i++;
            for(;i<s.size();i++){//�����������ĸ����һ���µģ�����Ҳ�У���ס���ſ�ʼ�ͽ�β��λ��
                if(s[i] == ')')break;
                else tmp.push_back(s[i]);
           }
           cout<<tmp;//��Ϊ�����ŵĻ�����Ҫ���һ�Σ������ȸ�������ˣ�
           i++;
            if(s[i] >= '0' && s[i] <= '9' && i < s.size()){//������ź��������ֵĻ�������
                int beishu[10];
                int k = 0;
                while(1){
                    if(s[i] >= '0' && s[i] <= '9' && i < s.size()){//��Ϊѭ����0��ʼ�����Ե�ѭ�����е�����ʱ����֪���Ǽ�λ���֣������ȴ�������
                        beishu[k] = int(s[i] - '0');
                        k++;
                    }
                    else break;
                    i++;
                }
                n=0;
                ten = 1;
                for(k = k-1;k>=0;k--){//�Ѵ�����������ƴ��һ������
                    n += beishu[k]*ten;
                    ten *= 10;
                }
                i--;
            for(n--;n>0;n--){
                    cout<<tmp;
            }
            }
        }




        else if(s[i] >='0' && s[i]<='9'){//������������֡�����
            n = 0;
            ten = 1;
            char c = s[i-1];
            n += int(s[i]-'0')*ten;
            ten*= 10;

            while((n--)-1)cout<<c;
        }




//���ɶ��û�С�����
        else
            cout<<s[i];
    }
    return 0;
}
