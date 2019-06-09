#pragma once
#include "function.h"

extern Teacher T[100];
extern Student S[100];
extern int TeacherNumber, StudentNumber;
//����: ��ʾ�˵�ѡ��
void Menu()
{
	ifstream in("StudentInfo.txt");
	for (int i = 0; i < StudentNumber; i++)
	{
		in >> S[i];
	}
	system("cls");
	cout << TeacherNumber << ends << StudentNumber << endl;
	int choice;
	char x = 35, y = 10;
	gotoxy(x, y);
	cout << "**********************************" << endl;
	gotoxy(x, y + 1);
	cout << "*                                *" << endl;
	gotoxy(x, y + 2);
	cout << "*  ��ӭʹ��ѧ���ɼ�����ϵͳV0.1  *" << endl;
	gotoxy(x, y + 3);
	cout << "*                                *" << endl;
	gotoxy(x, y + 4);
	cout << "*  1.��ʦ��¼        2.ѧ����¼  *" << endl;
	gotoxy(x, y + 5);
	cout << "*                                *" << endl;
	gotoxy(x, y + 6);
	cout << "**********************************" << endl;
	gotoxy(x, y + 7);
	cout << "���������ѡ��:";
	cin >> choice;
	Checkpwd(choice);
}

//����: ��ȡ��ʦ��Ϣ
void ReadTeacherFile()
{
	const char * filename = "TeacherInfo.txt";
	ifstream in(filename, ios::in);
	if (!in.is_open())
		cout << "�ļ�������!" << endl;
	else
	{
		int find = 0;
		long t_id;
		string t_password;
		
		for (int i = 0; i < TeacherNumber; i++)
		{
			in >> T[i].id >> T[i].password >> T[i].name >> T[i].classid;
			T[i].Show();
		}
		cout << "�������ʦ����:";
		cin >> t_id;
		cout << "�������¼����:";
		cin >> t_password;
		for (int i = 0; i < 50; i++)
		{
			if (t_id == T[i].id)
			{
				if (t_password == T[i].password)
				{
					cout << "��¼�ɹ�!" << endl;
					CheckPermission(i);
				}
				else
					break;
			}
		}
		//cout << "���Ż��������!" << endl;
		//system("pause");
		Menu();
	}
}

//����: �����û�ѡ�񡣽��������֤����ȷ�������Ӧ��ϵͳ�������޷����롣
void Checkpwd(int choice)
{
	if (choice == 1)
	{
		ReadTeacherFile();
	}
}