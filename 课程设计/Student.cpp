#include "Student.h"
#include "others.h"
/*void Student::Show()
{
}*/

extern Student S[100];
void Student::add(Teacher t)
{
	int x = 26, y = 8;
	system("cls");
	draw();
	gotoxy(x, y);
	cout << "������ѧ��ѧ��:";
	cin >> this->id;
	for (int i = 0; i < StudentNumber; i++)
	{
		if (id == S[i].id)
		{
			gotoxy(x, y+2);
			cout << "ѧ�Ŵ����ظ�,����������! ";
			system("pause");
			gotoxy(x, y + 2);
			cout << "                                            ";
			gotoxy(x, y);
			cout << "                                  ";
			gotoxy(x, y);
			cout << "������ѧ��ѧ��:";
			cin >> this->id;
		}
	}
	gotoxy(x, y+3);
	cout << "������ѧ������:";
	cin >> this->name;
	this->classid = t.get_classid();
	gotoxy(x, y + 6); 
	cout << "���������ĳɼ�:";
	cin >> this->chinese;
	gotoxy(x, y + 9); 
	cout << "��������ѧ�ɼ�:";
	cin >> this->math;
	gotoxy(x, y + 12); 
	cout << "������Ӣ��ɼ�:";
	cin >> this->english;
	this->sum = this->chinese + this->math + this->english;
	this->aver = this->sum / 3;
	gotoxy(x, y + 15);
}
