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


// ���ڸ�����ԭ�롢���롢�������ȡ��
// ������ڵ��������� ���ڽ����� �üӷ��ķ�ʽʵ�֣�
// �������ʱ�� ����λ���ֲ��䣻
// �����󷴱�Ϊԭ���ʱ�� ����λͬ�����䣻
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