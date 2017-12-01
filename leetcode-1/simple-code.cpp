#include <vector>
#include <iostream>
#include <set>
using namespace std;

set<int> value_set;

int ite(int n) {
	int mod = 0;
	int addition = 0;
	while (n) {
		mod = n % 10;
		n = n / 10;
		addition += mod*mod;
	}
	return addition;
}
bool isHappy(int n) {
	int re = ite(n);
	while (re != 1) {
		if (value_set.count(re) == 0)
			value_set.insert(re);
		else
			return false;
		re = ite(re);
	}
	return  true;

}

void main() {
	bool a = isHappy(7);
	int b = 0;
}