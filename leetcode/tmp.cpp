#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str = "abddghj";
	string::iterator it;              //ָ��string��ĵ���������������Ϊָ��
	for (it = str.begin(); it != str.end(); it++)
	{
		if (*it == 'd')
			str.erase(it);          //ɾ��it����һ���ַ�
	}
	cout << str << endl;
}
