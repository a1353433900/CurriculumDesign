#include "Student.h"
#include "others.h"
/*void Student::Show()
{
}*/

void Student::add(Teacher t)
{
	int x = 26, y = 8;
	system("cls");
	draw();
	gotoxy(x, y);
	cout << "������ѧ��ѧ��:";
	cin >> this->id;
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
