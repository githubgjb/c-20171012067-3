//��������
//������JSON���������Ժ�����Ӧ�ó����������

//Edge��װ���������¶

#include <iomanip>
#include "Line.h"
using namespace std;

namespace Index{

	void selectionSort(){
		int a[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		//���ַ�ʽ

		/*
		Line *line = new Line(a, 10);
		line->selectionSort();
		for (int i = 0; i < 10; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		delete line;
		*/


		Line line2(a,10);
		line2.selectionSort();
		for (int i = 0; i < 10; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;

		cout << "�س�����" << endl;
		getchar();

	}
}

