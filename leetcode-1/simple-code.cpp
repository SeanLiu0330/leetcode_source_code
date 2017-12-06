#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <map>
using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


// ���ڸ�����ԭ�롢���롢�������ȡ��
// ������ڵ��������� ���ڽ����� �üӷ��ķ�ʽʵ�֣�
// �������ʱ�� ����λ���ֲ��䣻
// �����󷴱�Ϊԭ���ʱ�� ����λͬ�����䣻


 
struct matrix {
	int m[2][2];
	matrix() {
		m[0][0] = 1;
		m[1][1] = 1;
		m[0][1] = 0;
		m[1][0] = 0;
	}
};
matrix matrixmul(matrix a, matrix b) {
	matrix temp = matrix();
	for (int i = 0; i<2; i++) {
		for (int j = 0; j<2; j++) {
			temp.m[i][j] = a.m[i][0] * b.m[0][j] + a.m[i][1] * b.m[1][j];
		}
	}
	return temp;
}
matrix Q(matrix base, int n) {
	matrix ans = matrix();
	while (n) {
		if (n & 1)
			ans = matrixmul(base, ans);
		base = matrixmul(base, base);
		n >>=1;
	}
	return ans;
}
int climbStairs(int n) {
	matrix base = matrix();
	matrix origin = matrix();
	base.m[0][1] = 1;
	base.m[1][0] = 1;
	base.m[1][1] = 0;
	origin.m[1][0] = 1;
	origin.m[1][1] = 0;
	matrix final_mat = Q(base, n);
	matrix re = matrixmul(final_mat, origin);
	return re.m[1][0];

}
void main() {
	int t = climbStairs(44);
	int c = 0;
}

