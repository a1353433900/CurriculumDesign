#pragma once
#include "MenageSystem.h"
#include "function.h"
#include "RootSystem.h"
#include "others.h"

extern Teacher T[100];
extern Student S[100];
extern int StudentNumber;
extern int TeacherNumber;

//��ʦ����ϵͳ
void TeacherSystem(int id) {
	int num;
	int x = 45, y = 6;
	int choice;
	system("cls");
	draw();
	gotoxy(x, y);
	cout << "��̨����ϵͳ";
	gotoxy(x + 6, y + 1);
	cout << "��ӭ��," << T[id].name << "��ʦ!";
	gotoxy(x - 5, y + 5);
	cout << "1.��ӱ���ѧ���ɼ���Ϣ";
	gotoxy(x - 5, y + 8);
	cout << "2.��ѯ����ѧ���ɼ���Ϣ";
	gotoxy(x - 5, y + 11);
	cout << "3.�޸ı���ѧ��������Ϣ";
	gotoxy(x - 5, y + 14);
	cout << "4.ɾ������ѧ���ɼ���Ϣ";
	gotoxy(x - 5, y + 17);
	cout << "5.�޸�����";
	gotoxy(x - 5, y + 20);
	cout << "0.�˳�" << endl;
	gotoxy(x - 15, y + 24);
	cout << "���������ѡ��:";
	cin >> choice;

	switch (choice)
	{
	case 0:
		Menu();
	case 1:
		gotoxy(x - 15, y + 26);
		cout << "���������ѧ��������:";
		cin >> num;
		AddStudentInfo(id,num);
		system("cls");
		TeacherSystem(id);
	case 2:
		QueryStudentInfo(id);
	case 3:
		ModifyStudentInfo(id);
		break;
	case 4:
		DeleteStudentInfo(id);
		break;
	case 5:
		gotoxy(x - 15, y + 25);
		T[id].ModifyPwd();
		WirteTeacherInfo();
		TeacherSystem(id);
	default:
		gotoxy(x - 15, y + 26);
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "�޸�ѡ��,������ѡ��! ";
		system("pause");
		TeacherSystem(id);
	}
}
//����Աϵͳ
void ROOT()
{
	int x = 45, y = 6;
	int choice;
	system("cls");
	draw();
	gotoxy(x, y);
	cout << "��̨����ϵͳ";
	gotoxy(x + 6, y + 1);
	cout << "��ӭ��,����Ա";
	gotoxy(x - 5, y + 5);
	cout << "1.���ѧ���ɼ���Ϣ";
	gotoxy(x + 16, y + 5);
	cout << "5.��ӽ�ʦ��Ϣ";
	gotoxy(x - 5, y + 8);
	cout << "2.��ѯѧ���ɼ���Ϣ";
	gotoxy(x + 16, y + 8);
	cout << "6.��ѯ��ʦ��Ϣ";
	gotoxy(x - 5, y + 11);
	cout << "3.�޸�ѧ��������Ϣ";
	gotoxy(x + 16, y + 11);
	cout << "7.�޸Ľ�ʦ��Ϣ";
	gotoxy(x - 5, y + 14);
	cout << "4.ɾ��ѧ���ɼ���Ϣ";
	gotoxy(x + 16, y + 14);
	cout << "8.ɾ����ʦ��Ϣ";
	gotoxy(x - 5, y + 17);
	cout << "9.�޸�����";
	gotoxy(x + 16, y + 17);
	cout << "0.�˳�" << endl;
	gotoxy(x - 15, y + 24);
	cout << "���������ѡ��:";
	cin >> choice;
	switch (choice)
	{
	case 1:
		int num;
		gotoxy(x - 15, y + 26);
		cout << "���������ѧ��������:";
		cin >> num;
		AddStudentInfo(num);
	case 2:
		QueryStudentInfo();
	case 3:
		ModifyStudentInfo();
	case 4:
		//DeleteStudentInfo();
	case 5:
		gotoxy(x - 15, y + 26);
		cout << "��������ӽ�ʦ������:";
		cin >> num;
		AddTeacherInfo(num);
		system("cls");
		ROOT();
	case 6:
		QueryTeacherInfo();
	case 7:
		ModifyTeacherInfo();
	case 8:
		DeleteTeacherInfo();
	case 0:
		Menu();
	default:
		cin.clear();
		cin.ignore(1024, '\n');
		break;
	}
}
//����: ���ѧ����Ϣ(��ʦϵͳ)
void AddStudentInfo(int id, int num)
{
	if (num <= 0)
	{
		TeacherSystem(id);
	}
	system("cls");
	draw();
	for (int i = StudentNumber; i < StudentNumber+num; i++)
	{
		S[i].add(T[id]);
	}
	gotoxy(26, 25);
	StudentNumber+=num;
	SortRank();
	SortRank(id);
	WriteStudentInfo();
	WriteImport();
	cout << "¼��ɹ�!";
	system("pause");

}
//����: ���ѧ����Ϣ(����Աϵͳ)
void AddStudentInfo(int num)
{

	if (num <= 0)
	{
		ROOT();
	}
	system("cls");
	draw();
	for (int i = StudentNumber; i < StudentNumber + num; i++)
	{
		S[i].add();
	}
	gotoxy(26, 25);
	StudentNumber += num;
	SortRank();
	WriteStudentInfo();
	WriteImport();
	cout << "¼��ɹ�!";
	system("pause");
	ROOT();
}
//����: ����ѧ���ɼ��Ƚ������
bool operator<(Student& l, Student& r)
{
	return l.sum > r.sum;
}
//����: ��ѯѧ���ɼ���Ϣ(��ʦϵͳ)
void QueryStudentInfo(int id)
{
	int choice;
	int i, find = 0;
	int n = 0;
	string tid;
	string tname;
	system("cls");
	draw();
	SortRank();
	SortRank(id);
	int x = 26, y = 8;
	gotoxy(x, y);
	cout << "1.����ѧ�Ų�ѯѧ���ɼ�";
	gotoxy(x, y+3);
	cout << "2.����������ѯѧ���ɼ�";
	gotoxy(x, y+6);
	cout << "3.��ѯ����ѧ���ɼ�";
	gotoxy(x, y+9);
	cout << "0.�˳�";
	gotoxy(x, y + 12);
	cout << "���������ѡ��:";
	cin >> choice;
	switch (choice)
	{
		case 0:
			TeacherSystem(id);
		case 1:
			gotoxy(x, y + 14);
			cout << "��������Ҫ��ѯ��ѧ��:";
			cin >> tid;
			for (i = 0; i < StudentNumber; i++)
			{
				if (T[id].get_classid() == S[i].classid)
				{
					if (tid == S[i].id)
					{
						system("cls");
						draw();
						gotoxy(x - 4, y);
						cout << "ѧ��";
						gotoxy(x + 10, y);
						cout << "����";
						gotoxy(x + 18, y);
						cout << "����";
						gotoxy(x + 24, y);
						cout << "��ѧ";
						gotoxy(x + 30, y);
						cout << "Ӣ��";
						gotoxy(x + 36, y);
						cout << "�ܷ�";
						gotoxy(x + 42, y);
						cout << "ƽ����";
						gotoxy(x + 50, y);
						cout << "����";
						gotoxy(x + 56, y);
						cout << "У��";
						gotoxy(x - 4, y + 1);
						cout << S[i].id;
						gotoxy(x + 10, y + 1);
						cout << S[i].name;
						gotoxy(x + 18, y + 1);
						cout << S[i].chinese;
						gotoxy(x + 24, y + 1);
						cout << S[i].math;
						gotoxy(x + 30, y + 1);
						cout << S[i].english;
						gotoxy(x + 36, y + 1);
						cout << S[i].sum;
						gotoxy(x + 42, y + 1);
						cout << S[i].aver;
						gotoxy(x + 50, y + 1);
						cout << S[i].get_classrank();
						gotoxy(x + 56, y + 1);
						cout << S[i].get_schoolrank();
						gotoxy(x, y + 2);
						system("pause");
						TeacherSystem(id);
					}
				}
			}
			if (i == StudentNumber)
			{
				system("cls");
				draw();
				gotoxy(x + 18, y);
				cout << "�޸�ѧ����Ϣ!";
				gotoxy(x + 28, y+1);
				system("pause");
				TeacherSystem(id);
			}
		case 2:
			gotoxy(x, y + 14);
			cout << "��������Ҫ��ѯ������:";
			cin >> tname;
			system("cls");
			draw();
			for (i = 0; i < StudentNumber; i++)
			{
				if (T[id].get_classid() == S[i].classid)
				{
					if (tname == S[i].name)
					{
						gotoxy(x - 4, y);
						cout << "ѧ��";
						gotoxy(x + 10, y);
						cout << "����";
						gotoxy(x + 18, y);
						cout << "����";
						gotoxy(x + 24, y);
						cout << "��ѧ";
						gotoxy(x + 30, y);
						cout << "Ӣ��";
						gotoxy(x + 36, y);
						cout << "�ܷ�";
						gotoxy(x + 42, y);
						cout << "ƽ����";
						gotoxy(x + 50, y);
						cout << "����";
						gotoxy(x + 56, y);
						cout << "У��";
						gotoxy(x - 4, y + 1 + n);
						cout << S[i].id;
						gotoxy(x + 10, y + 1 + n);
						cout << S[i].name;
						gotoxy(x + 18, y + 1 + n);
						cout << S[i].chinese;
						gotoxy(x + 24, y + 1 + n);
						cout << S[i].math;
						gotoxy(x + 30, y + 1 + n);
						cout << S[i].english;
						gotoxy(x + 36, y + 1 + n);
						cout << S[i].sum;
						gotoxy(x + 42, y + 1 + n);
						cout << S[i].aver;
						gotoxy(x + 50, y + 1 + n);
						cout << S[i].get_classrank();
						gotoxy(x + 56, y + 1 + n);
						cout << S[i].get_schoolrank();
						n++;
						find = 1;
					}
				}
				else
				{
					n--;
				}
			}
			if (find == 0)
			{
				system("cls");
				draw();
				gotoxy(x + 18, y);
				cout << "�޸�ѧ����Ϣ!";
				gotoxy(x + 28, y + 1);
				system("pause");
				TeacherSystem(id);
			}
			else
			{
				find = 0;
				gotoxy(x, y + 1 + i);
				system("pause");
				TeacherSystem(id);
			}
			break;
		case 3:
			system("cls");
			draw();
			gotoxy(x-4, y);
			cout << "ѧ��";
			gotoxy(x+10, y);
			cout << "����";
			gotoxy(x + 18, y);
			cout << "����";
			gotoxy(x + 24, y);
			cout << "��ѧ";
			gotoxy(x + 30, y);
			cout << "Ӣ��";
			gotoxy(x + 36, y);
			cout << "�ܷ�";
			gotoxy(x + 42, y);
			cout << "ƽ����";
			gotoxy(x + 50, y);
			cout << "����";
			gotoxy(x + 56, y);
			cout << "У��";
			for (i = 0; i < StudentNumber; i++)
			{
				if (T[id].get_classid() == S[i].classid)
				{
					gotoxy(x - 4, y + 1 + i);
					cout << S[i].id;
					gotoxy(x + 10, y + 1 + i);
					cout << S[i].name;
					gotoxy(x + 18, y + 1 + i);
					cout << S[i].chinese;
					gotoxy(x + 24, y + 1 + i);
					cout << S[i].math;
					gotoxy(x + 30, y + 1 + i);
					cout << S[i].english;
					gotoxy(x + 36, y + i + 1);
					cout << S[i].sum;
					gotoxy(x + 42, y + 1 + i);
					cout << S[i].aver;
					gotoxy(x + 50, y + 1 + i);
					cout << S[i].get_classrank();
					gotoxy(x + 56, y + 1 + i);
					cout << S[i].get_schoolrank();
				}
				else
				{
					y--;
				}
			}
			gotoxy(x + 30, y + 2 + i);
			system("pause");
			system("cls");
			TeacherSystem(id);
	default:
		gotoxy(x, y + 14);
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "�޸�ѡ��,������ѡ��! ";
		system("pause");
		QueryStudentInfo(id);
	}
}
//����: ��ѯѧ���ɼ���Ϣ(����Աϵͳ)
void QueryStudentInfo()
{
		int choice;
		int i, find = 0;
		int n = 0;
		string tid;
		string tname;
		SortRank();
		system("cls");
		draw();
		int x = 26, y = 8;
		gotoxy(x, y);
		cout << "1.����ѧ�Ų�ѯѧ���ɼ�";
		gotoxy(x, y + 3);
		cout << "2.����������ѯѧ���ɼ�";
		gotoxy(x, y + 6);
		cout << "3.��ѯ����ѧ���ɼ�";
		gotoxy(x, y + 9);
		cout << "0.�˳�";
		gotoxy(x, y + 12);
		cout << "���������ѡ��:";
		cin >> choice;
		switch (choice)
		{
		case 0:
			ROOT();
		case 1:
			gotoxy(x, y + 14);
			cout << "��������Ҫ��ѯ��ѧ��:";
			cin >> tid;
			for (i = 0; i < StudentNumber; i++)
			{
					system("cls");
					draw();
					gotoxy(x - 4, y);
					cout << "ѧ��";
					gotoxy(x + 10, y);
					cout << "����";
					gotoxy(x + 18, y);
					cout << "����";
					gotoxy(x + 24, y);
					cout << "��ѧ";
					gotoxy(x + 30, y);
					cout << "Ӣ��";
					gotoxy(x + 36, y);
					cout << "�ܷ�";
					gotoxy(x + 42, y);
					cout << "ƽ����";
					gotoxy(x + 50, y);
					cout << "У��"; 
					gotoxy(x + 55, y);
					cout << "�༶";
					gotoxy(x - 4, y + 1);
					cout << S[i].id;
					gotoxy(x + 10, y + 1);
					cout << S[i].name;
					gotoxy(x + 18, y + 1);
					cout << S[i].chinese;
					gotoxy(x + 24, y + 1);
					cout << S[i].math;
					gotoxy(x + 30, y + 1);
					cout << S[i].english;
					gotoxy(x + 36, y + 1);
					cout << S[i].sum;
					gotoxy(x + 42, y + 1);
					cout << S[i].aver;
					gotoxy(x + 50, y + 1);
					cout << S[i].get_schoolrank();
					gotoxy(x + 55, y + 1);
					cout << S[i].classid;
					gotoxy(x, y + 2);
					system("pause");
					ROOT();
			
			}
			if (i == StudentNumber)
			{
				system("cls");
				draw();
				gotoxy(x + 18, y);
				cout << "�޸�ѧ����Ϣ!";
				gotoxy(x + 28, y + 1);
				system("pause");
				ROOT();
			}
		case 2:
			gotoxy(x, y + 14);
			cout << "��������Ҫ��ѯ������:";
			cin >> tname;
			system("cls");
			draw();
			for (i = 0; i < StudentNumber; i++)
			{
				if (tname == S[i].name)
				{
					gotoxy(x - 4, y);
					cout << "ѧ��";
					gotoxy(x + 10, y);
					cout << "����";
					gotoxy(x + 18, y);
					cout << "����";
					gotoxy(x + 24, y);
					cout << "��ѧ";
					gotoxy(x + 30, y);
					cout << "Ӣ��";
					gotoxy(x + 36, y);
					cout << "�ܷ�";
					gotoxy(x + 42, y);
					cout << "ƽ����";
					gotoxy(x + 50, y);
					cout << "У��";
					gotoxy(x + 55, y);
					cout << "�༶";
					gotoxy(x - 4, y + 1 + n);
					cout << S[i].id;
					gotoxy(x + 10, y + 1 + n);
					cout << S[i].name;
					gotoxy(x + 18, y + 1 + n);
					cout << S[i].chinese;
					gotoxy(x + 24, y + 1 + n);
					cout << S[i].math;
					gotoxy(x + 30, y + 1 + n);
					cout << S[i].english;
					gotoxy(x + 36, y + 1 + n);
					cout << S[i].sum;
					gotoxy(x + 42, y + 1 + n);
					cout << S[i].aver;
					gotoxy(x + 50, y + 1 + n);
					cout << S[i].get_schoolrank();
					gotoxy(x + 55, y + 1 + n);
					cout << S[i].classid;
					n++;
					find = 1;
				}
			}
			if (find == 0)
			{
				system("cls");
				draw();
				gotoxy(x + 18, y);
				cout << "�޸�ѧ����Ϣ!";
				gotoxy(x + 28, y + 1);
				system("pause");
				ROOT();
			}
			else
			{
				find = 0;
				gotoxy(x, y + 1 + i);
				system("pause");
				ROOT();
			}
			break;
		case 3:
			system("cls");
			draw();
			gotoxy(x - 4, y);
			cout << "ѧ��";
			gotoxy(x + 10, y);
			cout << "����";
			gotoxy(x + 18, y);
			cout << "����";
			gotoxy(x + 24, y);
			cout << "��ѧ";
			gotoxy(x + 30, y);
			cout << "Ӣ��";
			gotoxy(x + 36, y);
			cout << "�ܷ�";
			gotoxy(x + 42, y);
			cout << "ƽ����";
			gotoxy(x + 50, y);
			cout << "У��";
			gotoxy(x + 55, y);
			cout << "�༶";
			for (i = 0; i < StudentNumber; i++)
			{
				gotoxy(x - 4, y + 1 + i);
				cout << S[i].id;
				gotoxy(x + 10, y + 1 + i);
				cout << S[i].name;
				gotoxy(x + 18, y + 1 + i);
				cout << S[i].chinese;
				gotoxy(x + 24, y + 1 + i);
				cout << S[i].math;
				gotoxy(x + 30, y + 1 + i);
				cout << S[i].english;
				gotoxy(x + 36, y + i + 1);
				cout << S[i].sum;
				gotoxy(x + 42, y + 1 + i);
				cout << S[i].aver;
				gotoxy(x + 50, y + 1 + i);
				cout << S[i].get_schoolrank();
				gotoxy(x + 55, y + 1 + i);
				cout << S[i].classid;
			}
			gotoxy(x + 30, y + 2 + i);
			system("pause");
			system("cls");
			ROOT();
		default:
			gotoxy(x, y + 14);
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�޸�ѡ��,������ѡ��! ";
			system("pause");
			QueryStudentInfo();
		}
}
//����: �޸�ѧ����Ϣ(��ʦϵͳ)
void ModifyStudentInfo(int id)
{
	string tid;
	int find = 0;
	int i = 0;
	int x = 45, y = 6;
	int choice;
	string t_name, t_id;
	double t_grade;
	gotoxy(x - 15, y + 26);
	cout << "������Ҫ�޸ĵ�ѧ��ѧ��:";
	cin >> tid;
	for (i = 0; i < StudentNumber; i++)
	{
		if (tid == S[i].id&&S[i].classid == T[id].get_classid())
		{
			system("cls");
			draw();
			int x = 26, y = 8;
			gotoxy(x, y);
			cout << "1.�޸�ѧ��";
			gotoxy(x, y + 3);
			cout << "2.�޸�����";
			gotoxy(x, y + 6);
			cout << "3.�޸����ĳɼ�";
			gotoxy(x, y + 9);
			cout << "4.�޸���ѧ�ɼ�";
			gotoxy(x, y + 12);
			cout << "5.�޸�Ӣ��ɼ�";
			gotoxy(x, y + 15);
			cout << "6.ȫ���޸�";
			gotoxy(x, y + 18);
			cout << "0.�������˵�";
			gotoxy(x, y + 21);
			cout << "��ѡ���޸ĵ���Ϣ:";
			cin >> choice;
			switch (choice)
			{
			case 1:
				gotoxy(x, y+22);
				cout << "������ѧ��:";
				cin >> t_id;
				S[i].set_id(t_id);
				break;
			case 2:
				gotoxy(x, y + 22);
				cout << "����������:";
				cin >> t_name;
				S[i].set_name(t_name);
				break;
			case 3:
				gotoxy(x, y + 22);
				cout << "���������ĳɼ�:";
				cin >> t_grade;
				S[i].set_chinese(t_grade);
				break;
			case 4:
				gotoxy(x, y + 22);
				cout << "��������ѧ�ɼ�:";
				cin >> t_grade;
				S[i].set_math(t_grade);
				break;
			case 5:
				gotoxy(x, y + 22);
				cout << "������Ӣ��ɼ�:";
				cin >> t_grade;
				S[i].set_english(t_grade);
				break;
			case 6:
				S[i].add(T[id]);
			case 0:
				ROOT();
			default:
				cin.clear();
				cin.ignore(1024, '\n');
				break;
			}
			gotoxy(x, y + 25);
			cout << "�޸ĳɹ�!";
			WriteStudentInfo();
			find = 1;
			break;
		}
	}
	if (find == 0)
	{
		gotoxy(x - 15, y + 28);
		cout << "û�в�ѯ����ѧ��,��˶Ժ�,�ٽ��в�����";
	}
	gotoxy(x - 10, y + 30);
	system("pause");
	SortRank();
	SortRank(id);
	WriteStudentInfo();
	WriteImport();
	TeacherSystem(id);
}
//����: �޸�ѧ����Ϣ(����Աϵͳ)
void ModifyStudentInfo()
{
	string tid;
	int find = 0;
	int i = 0;
	int x = 45, y = 6;
	int choice;
	string t_name, t_id;
	double t_grade;
	gotoxy(x - 15, y + 26);
	cout << "������Ҫ�޸ĵ�ѧ��ѧ��:";
	cin >> tid;
	for (i = 0; i < StudentNumber; i++)
	{
		if (tid == S[i].id)
		{
			system("cls");
			draw();
			int x = 26, y = 8;
			gotoxy(x, y);
			cout << "1.�޸�ѧ��";
			gotoxy(x, y + 3);
			cout << "2.�޸�����";
			gotoxy(x, y + 6);
			cout << "3.�޸����ĳɼ�";
			gotoxy(x, y + 9);
			cout << "4.�޸���ѧ�ɼ�";
			gotoxy(x, y + 12);
			cout << "5.�޸�Ӣ��ɼ�";
			gotoxy(x, y + 15);
			cout << "6.ȫ���޸�";
			gotoxy(x, y + 18);
			cout << "0.�������˵�";
			gotoxy(x, y + 21);
			cout << "��ѡ���޸ĵ���Ϣ:";
			cin >> choice;
			switch (choice)
			{
			case 1:
				gotoxy(x, y + 22);
				cout << "������ѧ��:";
				cin >> t_id;
				S[i].set_id(t_id);
				break;
			case 2:
				gotoxy(x, y + 22);
				cout << "����������:";
				cin >> t_name;
				S[i].set_name(t_name);
				break;
			case 3:
				gotoxy(x, y + 22);
				cout << "���������ĳɼ�:";
				cin >> t_grade;
				S[i].set_chinese(t_grade);
				break;
			case 4:
				gotoxy(x, y + 22);
				cout << "��������ѧ�ɼ�:";
				cin >> t_grade;
				S[i].set_math(t_grade);
				break;
			case 5:
				gotoxy(x, y + 22);
				cout << "������Ӣ��ɼ�:";
				cin >> t_grade;
				S[i].set_english(t_grade);
				break;
			case 6:
				S[i].add();
			case 0:
				ROOT();
			default:
				cin.clear();
				cin.ignore(1024, '\n');
				break;
			}
			gotoxy(x, y + 25);
			cout << "�޸ĳɹ�!";
			WriteStudentInfo();
			find = 1;
			break;
		}
	}
	if (find == 0)
	{
		gotoxy(x - 15, y + 28);
		cout << "û�в�ѯ����ѧ��,��˶Ժ�,�ٽ��в�����";
	}
	gotoxy(x - 10, y + 30);
	system("pause");
	SortRank();
	WriteStudentInfo();
	WriteImport();
	ROOT();
}
//����: ɾ��ѧ����Ϣ(��ʦϵͳ)
void DeleteStudentInfo(int id)
{
	string tid;
	int find = 0;
	int i = 0;
	int x = 45, y = 6;
	gotoxy(x - 15, y + 26);
	cout << "������Ҫɾ����ѧ��ѧ��:";
	cin >> tid;
	for (i = 0; i < StudentNumber; i++)
	{
		if (tid == S[i].id&&S[i].classid==T[id].get_classid())
		{
			for (int deleteid = i;  deleteid < StudentNumber-1; deleteid++)
			{
				swap(S[deleteid + 1], S[deleteid]);
			}
			gotoxy(x - 15, y + 28);
			StudentNumber--;
			cout << "ɾ���ɹ�!";
			find = 1;
			break;
		}
	}
	if (find == 0)
	{
		gotoxy(x - 15, y + 28);
		cout << "û�в�ѯ����ѧ��,��˶Ժ�,�ٽ��в�����";
	}
	gotoxy(x - 10, y + 30);
	system("pause");
	SortRank();
	SortRank(id);
	WriteStudentInfo();
	WriteImport();
	TeacherSystem(id);
	
}
//����: ����¼��Ȩ��,ѡ�������Ӧ��ϵͳ
void CheckPermission(int id) {
	
	if (id == -1)
	{
		ROOT(); //�����ܹ���Աϵͳ
	}
	else
	{
		TeacherSystem(id); //�����ʦϵͳ
		system("pause");
	}
	
		
}

//����: ����ʦ��Ϣд���ļ�(TeacherInfo.txt)
void WirteTeacherInfo()
{
	ofstream out("TeacherInfo.txt");
	for (int i = 0; i < TeacherNumber; i++)
	{
		out << T[i].id << " " << T[i].password << " " << T[i].name << " " << T[i].classid << "\n";
	}
}