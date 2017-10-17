//
// Created by liuyubobobo on 5/5/17.
//

#ifndef INC_06_PATH_COMPRESSION_UNIONFIND1_H
#define INC_06_PATH_COMPRESSION_UNIONFIND1_H

#include <iostream>
#include <cassert>

using namespace std;

// ���ǵĵ�һ��Union-Find
namespace UF1 {

	class UnionFind {

	private:
		int *id;    // ���ǵĵ�һ��Union-Find���ʾ���һ������
		int count;  // ���ݸ���

	public:
		// ���캯��
		UnionFind(int n) {
			count = n;
			id = new int[n];
			// ��ʼ��, ÿһ��id[i]ָ���Լ�, û�кϲ���Ԫ��
			for (int i = 0; i < n; i++)
				id[i] = i;
		}

		// ��������
		~UnionFind() {
			delete[] id;
		}

		// ���ҹ���, ����Ԫ��p����Ӧ�ļ��ϱ��
		int find(int p) {
			assert(p >= 0 && p < count);
			return id[p];
		}

		// �鿴Ԫ��p��Ԫ��q�Ƿ�����һ������
		// O(1)���Ӷ�
		bool isConnected(int p, int q) {
			return find(p) == find(q);
		}

		// �ϲ�Ԫ��p��Ԫ��q�����ļ���
		// O(n) ���Ӷ�
		void unionElements(int p, int q) {

			int pID = find(p);
			int qID = find(q);

			if (pID == qID)
				return;

			// �ϲ�������Ҫ����һ������Ԫ��, ������Ԫ�ص��������ϱ�źϲ�
			for (int i = 0; i < count; i++)
			if (id[i] == pID)
				id[i] = qID;
		}
	};
}

#endif //INC_06_PATH_COMPRESSION_UNIONFIND1_H