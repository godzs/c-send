// ���Ͷ�.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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
	char total_temp[1500];   //�����ݰ����䵱���ݵ���ʱ��Ź��ܣ�
	char password[20];       //����
	char temp[50];        //�������ݰ������ڽ��ļ�����
	int x;
};
void send::inputpssword()
{
	cout << "���Ͷ�:" << endl;
	cout << "���������룺" << endl;      //��������
	cin >> password;
	while (strcmp(password, "hello") != 0)
	{
		cout << "��Ч����" << endl;
		cout << "�������������룺" << endl;;
		cin >> password;
	}
	cout << "OK!" << endl;
	getchar();
}

class out :public send
{
public:
	void output();     //����ͷ�����ݰ�����βд���ļ�
	void pack();  //�������ݣ����ܣ��ְ�
protected:
	char tail[30];      //��ͷ
	char head[30];     //��β
};
void out::pack()
{
	int x, num;
	int i, data_long;
	cout << "please enter the word:" << endl;    //��������
	gets_s(total_temp);
	data_long = strlen(total_temp);
	num = data_long / 50;
	if (data_long > 50)
	{
		cout << "���ݵĳ��ȴ���50�����ж������!" << endl << "���ݽ�����Ϊ" << num + 1 << "�����ݰ���" << endl;
	}
	for (i = 0; i <= num; i++)
	{
		memcpy(temp, total_temp + 50 * i, 50);
		x = 0;
		while (temp[x] != '\0')                    //�����ݼ���
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
	ofstream ocout("C:\\Users\\zhousheng\\Desktop\\text.txt");	   //�������text.txt
	if (ocout.is_open())            //�ж��ļ��Ƿ��
	{
		if (temp[0] != '\0')      //���ļ���д���ͷ����β�ͼ��ܵ�����
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

