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


 
int findShortestSubArray(vector<int>& nums) {
	map<int, vector<vector<int>::iterator>> re;
	int long_num = nums[0] , num_times = 1;
	for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++) {
		re[*i].push_back(i);
		if (re[*i].size() == 1) {
			//long_num = *i;
			continue;
		}
		if (re[*i].size()>num_times ) {
			num_times = re[*i].size();
			long_num = *i;
		}
		if (re[*i].size() == num_times ) {
			if ((i - re[*i][0]) < (*(re[long_num].end() - 1)) - *(re[long_num].begin())) {
				num_times = re[*i].size();
				long_num = *i;
			}			
		}
	}
	return *(re[long_num].end()-1) - *(re[long_num].begin());
}
void main() {
	vector<int> nums = {1,2,2,3,1};
	int t = findShortestSubArray(nums);
	int c = 0;
}

