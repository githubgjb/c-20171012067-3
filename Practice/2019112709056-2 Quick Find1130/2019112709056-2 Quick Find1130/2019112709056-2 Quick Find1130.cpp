// 2019112709056-2 Quick Find1130.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include "UnionFindTestHelper.h"
//#include "Graph1.h"
#include "GraphTestHelper.h"
using namespace std;





int _tmain(int argc, _TCHAR* argv[])
{
	int n = 1000000;
	//UnionFindTestHelper::testUF1(n);
	//UnionFindTestHelper::testUF2(n);
	//UnionFindTestHelper::testUF3(n);
	//UnionFindTestHelper::testUF4(n);
	//UnionFindTestHelper::testUF5(n);

	//GraphTestHelper::testGraph1();
	//GraphTestHelper::testReadGraph01();

	GraphTestHelper::testPath01();

	//------------------------------------------------
	cout << "�س�����" << endl;
	getchar();
	return 0;
}

