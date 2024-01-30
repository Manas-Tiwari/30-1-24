/*
 *
 * Program to sort array.
 *
 * */


#include<bits/stdc++.h>

using namespace std;


void sort(int n, vector<int> &nums) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        swap(nums[i], nums[minIndex]);
    }
}

int main() {
	int n;
	cout << "Total numbers to sort: ";
	cin >> n;
	vector<int> nums(n);
	cout << "Enter number to sort, seperated by space character : ";
	for (int i = 0; i < n; i++){
		cin >> nums[i];
	}
	sort(n, nums);
	for (int i; i < n; i++){
		cout << nums[i] << " ";
	}
	cout << '\n';
	return 0;
}
