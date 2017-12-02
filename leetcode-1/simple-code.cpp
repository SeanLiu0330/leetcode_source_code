#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <string>
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
string toHex(int num) {
	string re;
	char c_a[16] = { '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f' };
	int count = 8;
	int flag = 15;
	int index = 0;
	while (count--) {
		index = num&flag;
		num >>= 4;
		re += c_a[index];
	}
	reverse(re.begin(), re.end());
	while (re.find_first_of('0') == 0) {
		re.erase(re.begin());
	}
	return re;
}
void main() {
	string a = toHex(26);
}