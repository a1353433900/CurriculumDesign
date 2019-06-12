#include "RootSystem.h"

//����: ��ӽ�ʦ��Ϣ
void AddTeacherInfo(int num)
{

	if (num <= 0)
	{
		ROOT();
	}
	system("cls");
	draw();
	for (int i = TeacherNumber; i < TeacherNumber + num; i++)
	{
		int t_classid;
		string t_name;
		long t_id;
		int x = 26, y = 8;
		system("cls");
		draw();
		gotoxy(x, y+4);
		cout << "�������ʦִ�̰༶:";
		cin >> t_classid;
		gotoxy(x, y+10);
		cout << "�������ʦ����:";
		cin >> t_id;
		gotoxy(x, y + 16);
		cout << "�������ʦ����:";
		cin >> t_name;
		T[i].SetInfo(t_id,t_name,t_classid);
	}
	gotoxy(26, 25);
	TeacherNumber += num;
	WirteTeacherInfo();
	WriteImport();
	cout << "¼��ɹ�!";
	system("pause");
	ROOT();
}

//����: ��ѯ��ʦ��Ϣ
void QueryTeacherInfo()
{
	system("cls");
	draw();
	int x = 26, y = 8;
	int i;
	gotoxy(x +4, y);
	cout << "����";
	gotoxy(x + 16, y);
	cout << "����";
	gotoxy(x + 28, y);
	cout << "ִ�̰༶";
	for (i = 0; i < TeacherNumber; i++)
	{
		gotoxy(x + 4, y+i+1);
		cout << T[i].id;
		gotoxy(x + 16, y+i+1);
		cout << T[i].name;
		gotoxy(x + 28, y+i+1);
		cout << T[i].classid;
	}
	gotoxy(x + 30, y + 2 + i);
	system("pause");
	system("cls");
	ROOT();
}

//����: ɾ����ʦ��Ϣ
void DeleteTeacherInfo()
{
	long tid;
	int find = 0;
	int i = 0;
	int x = 45, y = 6;
	gotoxy(x - 15, y + 26);
	cout << "������Ҫɾ���Ľ�ʦ����:";
	cin >> tid;
	for (i = 0; i < TeacherNumber; i++)
	{
		if (tid == T[i].id)
		{
			for (int deleteid = i; deleteid < TeacherNumber - 1; deleteid++)
			{
				swap(T[deleteid + 1], T[deleteid]);
			}
			gotoxy(x - 15, y + 28);
			TeacherNumber--;
			cout << "ɾ���ɹ�!";
			find = 1;
			break;
		}
	}
	if (find == 0)
	{
		gotoxy(x - 15, y + 28);
		cout << "û�в�ѯ���ù���,��˶Ժ�,�ٽ��в�����";
	}
	gotoxy(x - 10, y + 30);
	system("pause");
	WirteTeacherInfo();
	WriteImport();
	ROOT();
}

void ModifyTeacherInfo()
{
	int choice;
	long t_id;
	int t_classid;
	int i;
	int x = 45, y = 6;
	gotoxy(x - 15, y + 26);
	cout << "������Ҫ�޸Ľ�ʦѧ��:";
	cin >> t_id;
	for (i = 0; i < TeacherNumber; i++)
	{
		if (t_id == T[i].id)
		{
			system("cls");
			draw();
			int x = 26, y = 8;
			gotoxy(x, y);
			cout << "1.�޸Ľ�ʦ����";
			gotoxy(x, y+3);
			cout << "2.�޸Ľ�ʦִ�̰༶";
			gotoxy(x, y+6);
			cout << "3.���������ѡ��:";
			cin >> choice;
			switch (choice)
			{
			case 1:
				gotoxy(x, y + 22);
				cout << "�������޸ĵĹ���:";
				cin >> t_id;
				T[i].set_id(t_id);
				break;
			case 2:
				gotoxy(x, y + 22);
				cout << "������ִ�̰༶:";
				cin >> t_classid;
				T[i].set_classid(t_classid);
				break;
			default:
				cin.clear();
				cin.ignore(1024, '\n');
				break;
			}
		}
	}
}
