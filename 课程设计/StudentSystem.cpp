#include "StudentSystem.h"

extern Student S[100];
void StudentSystem()
{
	int x = 30;
	int y = 10;
	int i;
	string tid, tpwd;
	system("cls");
	gotoxy(x, y);
	cout << "***************************************";
	for (i = 1; i < 10; i++)
	{
		gotoxy(x, y+i);
		cout << "*                                     *";
	}
	gotoxy(x, y + i);
	cout << "***************************************";
	gotoxy(35, 12);
	cout << "ѧ��:";
	gotoxy(35, 16);
	cout << "����:";
	gotoxy(42, 12);
	cin >> tid;
	gotoxy(42, 16);
	cin >> tpwd;
	for (int i = 0; i < StudentNumber; i++)
	{
		if (S[i].id == tid)
		{
			if (S[i].pwd == tpwd)
			{
				QueryGrade(i);
			}
		}
	}
}

void QueryGrade(int id)
{
	int x = 26, y = 3;
	system("cls");
	draw();
	gotoxy(x, y + 3);
	cout << "����:" << S[id].name;
	gotoxy(x, y + 7);
	cout << "�༶:" << S[id].classid;
	gotoxy(x, y + 11);
	cout << "���ĳɼ�:"<<S[id].chinese;
	gotoxy(x, y + 15);
	cout << "��ѧ�ɼ�:"<<S[id].math;
	gotoxy(x, y + 19);
	cout << "Ӣ��ɼ�:"<<S[id].english;
	gotoxy(x, y + 23);
	cout << "�ܷ�:" << S[id].sum;
	gotoxy(x, y + 27);
	cout << "ƽ����:" << S[id].aver;
}
