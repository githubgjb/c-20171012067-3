// 2019112709056-2 Quick Find1130.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include "UnionFindTestHelper.h"
using namespace std;





int _tmain(int argc, _TCHAR* argv[])
{
	int n = 10000;
	UnionFindTestHelper::testUF1(n);
	UnionFindTestHelper::testUF2(n);

	//------------------------------------------------
	cout << "�س�����" << endl;
	getchar();
	return 0;
}

