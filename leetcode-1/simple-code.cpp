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


 
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		/*
		auto v = std::remove(nums.begin(), nums.end(), val);
		int sz = distance(nums.begin(), v);
		//nums.resize(sz);
		return sz;
		*/


		int sz = nums.size();
		if (sz == 0) return 0;
		while (nums[sz - 1] == val && sz >0) sz--;
		for (int i = 0; i<sz; ++i) {
			if (nums[i] == val) {
				nums[i] = nums[sz - 1];
				sz--;
				while (nums[sz - 1] == val) sz--;
			}
		}
		nums.resize(sz);
		return sz;

	}
};


