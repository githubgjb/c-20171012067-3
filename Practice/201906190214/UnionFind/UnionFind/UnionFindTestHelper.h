

#include <iostream>
#include <ctime>

#include "UnionFind01.h"
#include "UnionFind02.h"
using namespace std;

// ���Բ��鼯�ĸ�������
namespace UnionFindTestHelper{
	// ���Ե�һ�汾�Ĳ��鼯, ����Ԫ�ظ���Ϊn
	void testUF1(int n){

		srand(time(NULL));
		UF1::UnionFind01 uf = UF1::UnionFind01(n);

		time_t startTime = clock();

		// ����n�β���, ÿ�����ѡ������Ԫ�ؽ��кϲ�����
		for (int i = 0; i < n; i++){
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		// �ٽ���n�β���, ÿ�����ѡ������Ԫ��, ��ѯ�����Ƿ�ͬ��һ������
		for (int i = 0; i < n; i++){
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();

		// ��ӡ�������2n�������ĺ�ʱ
		cout << "UF1, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	}

	void testUF2(int n){

		srand(time(NULL));
		UF2::UnionFind02 uf = UF2::UnionFind02(n);

		time_t startTime = clock();

		// ����n�β���, ÿ�����ѡ������Ԫ�ؽ��кϲ�����
		for (int i = 0; i < n; i++){
			int a = rand() % n;
			int b = rand() % n;
			uf.unionElements(a, b);
		}
		// �ٽ���n�β���, ÿ�����ѡ������Ԫ��, ��ѯ�����Ƿ�ͬ��һ������
		for (int i = 0; i < n; i++){
			int a = rand() % n;
			int b = rand() % n;
			uf.isConnected(a, b);
		}
		time_t endTime = clock();

		// ��ӡ�������2n�������ĺ�ʱ
		cout << "UF2, " << 2 * n << " ops, " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	}

}