#include "function.h"
#include "others.h"
#include <iostream>
#include <windows.h>
#pragma warning(disable:4996)

extern int TeacherNumber;
extern int StudentNumber;

int main(void)
{
	system("mode con cols=110 lines=40");
	//ϵͳ��ʼǰ,��ȡϵͳ��Ҫ����(��ʦ����,ѧ������)
	ReadImport();
	//��ӡ�˵�
	Menu();
	system("pause");
	return 0;
}