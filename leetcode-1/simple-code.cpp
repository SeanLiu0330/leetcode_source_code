#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		long left_sum = 0, sum_1 = 0;
		for (vector<int>::iterator i = nums.begin(); i<nums.end(); i++) {
			sum_1 += *i;
		}
		for (vector<int>::iterator j = nums.begin(); j<nums.end(); j++) {
			if ((sum_1 - left_sum - *j) == left_sum) {
				return j - nums.begin();
			}
			else {
				left_sum += *j;
			}
		}
		return -1;
	}
};