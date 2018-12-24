#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str = "abddghj";
	string::iterator it;              //指向string类的迭代器。你可以理解为指针
	for (it = str.begin(); it != str.end(); it++)
	{
		if (*it == 'd')
			str.erase(it);          //删除it处的一个字符
	}
	cout << str << endl;
}
