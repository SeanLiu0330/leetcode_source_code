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


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 TreeNode* root = new TreeNode(3);
 TreeNode* root2 = new TreeNode(4);

 bool equalornot(TreeNode* root1, TreeNode* root2, bool& flag) {
	 if (!flag)
		 return false;
	 if ((root1 == NULL && root2 == NULL)) {
		 return true;
	 }
	 else if (root1 == NULL || root2 == NULL) {
		 flag = false;
		 return false;
	 }
	 else if (root1->val != root2->val)
		 return flag = false;

	 equalornot(root1->left, root2->left, flag);
	 equalornot(root1->right, root2->right, flag);
	 return flag;


 }
 bool isSubtree(TreeNode* s, TreeNode* t) {
	 bool flag = false;
	 queue<TreeNode*> treeque;
	 treeque.push(s);
	 while (!treeque.empty()) {
		 bool flag1 = 1;
		 TreeNode* root1 = treeque.front();
		 treeque.pop();
		 if (flag = equalornot(root1, t, flag1)) {
			 break;
		 }
		 if (root1->left != NULL)
			 treeque.push(root1->left);
		 if (root1->right != NULL)
			 treeque.push(root1->right);
	 }
	 return flag;
 }

 

void main() {
	root->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(2);
	root2->left = new TreeNode(1);
	root2->right = new TreeNode(2);
	bool f = isSubtree(root, root2);
	bool d = 0;
}