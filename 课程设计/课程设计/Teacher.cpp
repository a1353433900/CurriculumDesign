#include "Teacher.h"
#include "others.h"

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
