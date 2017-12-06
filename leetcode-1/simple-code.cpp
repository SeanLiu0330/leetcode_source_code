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


// 关于负数的原码、反码、补码的求取：
// 补码存在的意义在于 便于将减法 用加法的方式实现；
// 在求反码的时候 符号位保持不变；
// 补码求反变为原码的时候 符号位同样不变；


 
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

