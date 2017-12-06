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