//程序的入口
//再引用JSON解析，可以和其它应用程序可以用了

//Edge封装到类里，不暴露

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
		//两种方式

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

