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

