#include "Teacher.h"
#include "others.h"

extern Teacher T[100];
extern int TeacherNumber;
void Teacher::SetInfo(long m_id, string m_name, int m_classid, string m_password)
{
	id = m_id;
	password = m_password;
	name = m_name;
	classid = m_classid;
}

void Teacher::Show() 
{ 
	cout << id << ends << password << ends << name << ends << classid << endl; 
}

void Teacher::set_id(long id)
{
	for (int i = 0; i < TeacherNumber; i++)
	{
		while (id == T[i].id && id != this->id)
		{
			gotoxy(26, 32);
			cout << "���Ŵ����ظ�,����������! ";
			system("pause");
			gotoxy(26, 32);
			cout << "                                            ";
			gotoxy(26, 30);
			cout << "                                  ";
			gotoxy(26, 30);
			cout << "�����빤��ѧ��:";
			cin >> id;
		}
	}
	this->id = id;
}

void Teacher::set_classid(int classid)
{
	this->classid = classid;
}

int Teacher::get_classid()
{
	return classid;
}

void Teacher::ModifyPwd()
{
	cout << "��������Ҫ�޸ĵ�����:";
	cin >> password;
	gotoxy(30, 32);
	cout << "�޸ĳɹ�! ";
	system("pause");
}
