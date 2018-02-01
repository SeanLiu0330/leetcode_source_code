#pragma once
#include "leetcode.h"
#include <vector>
#include <iostream>
#include <set>
#include <queue>


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
// ̨ʽ���ύ�汾1


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
 vector<int> findAnagrams(string s, string p) {
	 vector<int> res;
	 vector<string::size_type> sta;
	 int len_s = s.length(), len_p = p.length();
	 for (int i = 0; i<len_s; i++) {
		 if (i<len_p) {
			 string::size_type index = p.find_first_of(s[i]);
			 sta.push_back(index);
			 if (index != string::npos) {
				 p.erase(p.begin() + index);
			 }
			 if (i == len_p - 1) {
				 if (p.empty())
					 res.push_back(i + 1 - len_p);
				 continue;
			 }
		 }
		 else {
			 if (s[i] == s[i - len_p] && false) {
				 if (p.empty())
					 res.push_back(i + 1 - len_p);
				 if (sta[i - len_p] != string::npos)
					 p.insert(p.end(), 1, s[i - len_p]);
				 continue;
			 }
			 else {
				 if (sta[i - len_p] != string::npos)
					 p.insert(p.end(), 1, s[i - len_p]);
				 string::size_type index = p.find_first_of(s[i]);
				 sta.push_back(index);
				 if (index != string::npos) {
					 p.erase(p.begin() + index);
				 }
				 if (p.empty())
					 res.push_back(i + 1 - len_p);
			 }
		 }
	 }
	 return res;
 }
 

void main() {
	vector<int> res = findAnagrams(sss, ppp);
	root->left = new TreeNode(4);
	root->right = new TreeNode(5);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(2);
	root2->left = new TreeNode(1);
	root2->right = new TreeNode(2);
	bool f = isSubtree(root, root2);
	bool d = 0;
}