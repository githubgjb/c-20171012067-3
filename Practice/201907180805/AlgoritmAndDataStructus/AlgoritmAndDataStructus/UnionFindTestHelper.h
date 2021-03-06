

#include <iostream>
#include <ctime>

#include "UnionFind.h"
#include "UnionFind02.h"
#include "UnionFind03.h"
#include "UnionFind04.h"
#include "UnionFind05.h"
using namespace std;
namespace UnionFindTestHelper{
	
	void testUF1(int n){
		srand(time(NULL));
		UF1::UnionFind uf = UF1::UnionFind(n);

		time_t startTime = clock();
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a,b);
		}
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();

		cout << "UF1, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	}

	void testUF2(int n){
		srand(time(NULL));
		UF2::UnionFind02 uf = UF2::UnionFind02(n);

		time_t startTime = clock();
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();

		cout << "UF2, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		
	}

	void testUF3(int n){
		srand(time(NULL));
		UF3::UnionFind03 uf = UF3::UnionFind03(n);

		time_t startTime = clock();
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();

		cout << "UF3, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

	}

	void testUF4(int n){
		srand(time(NULL));
		UF4::UnionFind04 uf = UF4::UnionFind04(n);

		time_t startTime = clock();
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();

		cout << "UF4, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

	}

	void testUF5(int n){
		srand(time(NULL));
		UF5::UnionFind05 uf = UF5::UnionFind05(n);

		time_t startTime = clock();
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		for (int i = 0; i < n; i++)
		{
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();

		cout << "UF4, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

	}
}

