// 发送端.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
using namespace std;
class send {
public:
	void inputpssword();
protected:
	char total_temp[1500];   //总数据包（充当数据的临时存放功能）
	char password[20];       //密码
	char temp[50];        //发送数据包，用于将文件发送
	int x;
};
void send::inputpssword()
{
	cout << "发送端:" << endl;
	cout << "请输入密码：" << endl;      //输入密码
	cin >> password;
	while (strcmp(password, "hello") != 0)
	{
		cout << "无效密码" << endl;
		cout << "请重新输入密码：" << endl;;
		cin >> password;
	}
	cout << "OK!" << endl;
	getchar();
}

class out :public send
{
public:
	void output();     //将包头，数据包，包尾写入文件
	void pack();  //输入数据，加密，分包
protected:
	char tail[30];      //包头
	char head[30];     //包尾
};
void out::pack()
{
	int x, num;
	int i, data_long;
	cout << "please enter the word:" << endl;    //输入数据
	gets_s(total_temp);
	data_long = strlen(total_temp);
	num = data_long / 50;
	if (data_long > 50)
	{
		cout << "数据的长度大于50，进行多包传输!" << endl << "数据将被分为" << num + 1 << "个数据包！" << endl;
	}
	for (i = 0; i <= num; i++)
	{
		memcpy(temp, total_temp + 50 * i, 50);
		x = 0;
		while (temp[x] != '\0')                    //对数据加密
		{
			if (x <= 3)
			{
				temp[x] = temp[x] + 10;
			}
			else if (x <= 7)
			{
				temp[x] = temp[x] - 10;
			}
			else
			{
				temp[x] = temp[x] - 2;
			}
			x++;
		}
		if (data_long > 50)
			cout << "data packeet" << i + 1 << endl;
		cout << " Complete encrypt!" << endl;
		output();
	}
}

void out::output()
{
	char tail[30] = "#C++ Mirosoft Visual Studio";
	char head[30] = "Data Encapsulation";
	ofstream ocout("C:\\Users\\zhousheng\\Desktop\\text.txt");	   //创建或打开text.txt
	if (ocout.is_open())            //判断文件是否打开
	{
		if (temp[0] != '\0')      //向文件中写入包头，包尾和加密的数据
		{
			ocout << head << " ";
			ocout << temp;
			ocout << " " << tail;
			cout << "Complete save!" << endl;    
		}
	}
	ocout.close();
	CopyFile("C:\\Users\\zhousheng\\Desktop\\text.txt", "C:\\Users\\zhousheng\\Desktop\\test.txt", false);
}
int main()
{
	out a;
	a.inputpssword();
	while (1)
	{

		a.pack();
	}
	return 0;
}

