//��������
//������JSON���������Ժ�����Ӧ�ó����������

//Edge��װ���������¶

#include "Line.h"
using namespace std;

namespace Index{

	void mergeSort(){
		int a[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		Line line(a, 10);
		line.mergeSort();
		for (int i = 0; i < 10; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}

	void insertionSort(){
		int a[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		Line line(a,10);
		//line.insertionSort01Swap();	
		//line.insertionSort02Swap();
		line.insertionSort03Assigment();
		for (int i = 0; i < 10; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
	}


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



	}
}

