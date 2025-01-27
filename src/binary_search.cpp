#include <iostream>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

/* Binary search:
 * Need Start point, End point, searching Item and array(vector)
 * Then you need to define area of searching in array
 * Complexity O(log n);
 */

int binary_search(vector<int>& vec, int start, int end, int item) {
	if (vec.size() == 0) return -1;

	while (end >= start) {
		double mid{ ceil((start + end) / 2) };

		if (item == vec[mid]) return mid;
		if (item < vec[mid]) {
			end = mid;
			mid = end / 2;
		}
		if (item > vec[mid]) {
			start = mid;
			mid = (end - start) / 2;
		}
	}

	return -1;
}


int main() {
	vector<int> vec(10);
	iota(vec.begin(), vec.end(), 0);
	cout << "Initial vector is ";
	for (int el : vec)
		cout << el << ' ';
	cout << endl;
	cout << "Result is " << binary_search(vec, 0, vec.size() - 1, 5) << endl;
	return 0;
}