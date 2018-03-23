#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

/*
In principle, you are not allowed to
use other functions in <algorithm> or
include other header files. So before
using any other function in <algorithm>,
or including any other header file,
you may need to confirm with TA.
*/

/*
Add more functions as you need,
but DO NOT change the main function
or any given code.
*/
int** array;
vector<int> copyVector(vector<int>nums,int begin, int end){
	vector<int> a;
	for (int i = begin; i < end && i < nums.size(); i++){
		a.push_back(nums[i]);
	}
	return a;
}
//i,j is the initial index in B
int getMaxCoins(vector<int>B , int i, int j){
	int maxCoins = 0;
	if (array[i][j] == 0){
		if (i < j - 1){
			for (int k = i + 1; k < j; k++){
				maxCoins = max(B[i] * B[k] * B[j] + getMaxCoins(B, i, k) + getMaxCoins(B, k, j), maxCoins);
//				cout <<"index"<<" "<< i<<" "<<j<<" "<<k<<" "<<B[i] * B[k] * B[j]<<endl;
			}
		}
	array[i][j] = maxCoins;
	}
	
//	cout << array[i][j] << " " << i << " " << j<<endl;
//	cout << array[i][j];
	return array[i][j];
}
//int getMaxCoins(vector<int>nums){
//	if (nums.size()<=2)
//		return 0;	
//	int maxCoins = 0;
//	int begin = nums[0];
//	int end = nums[nums.size() - 1];
//	for (int i = 1; i < nums.size() - 1; i++){
//		vector<int> a = copyVector(nums,0, i + 1); 
//		vector<int> b = copyVector(nums, i, nums.size()); 
//		maxCoins = max(begin *nums[i]*end+getMaxCoins(a)+getMaxCoins(b),maxCoins);
//	}
//	return maxCoins;
//}
int maxCoins(vector<int>& nums) {
	// Create two virtual targets
	vector<int> B(1, 1);
	for (int i = 0; i < nums.size(); i++)
		B.push_back(nums[i]);
	B.push_back(1);
	/*
	Implement your algorithm here
	and return the maximum number
	of coins you can collect.
	*/
	int maxCoins = 0;
	if (nums.size() == 1)
		return nums[0];	
	for (int i = 1; i < B.size() - 1; i++){
		maxCoins = max(B[i] + getMaxCoins(B,0,i)
			+ getMaxCoins(B,i,B.size() - 1), maxCoins);
	}
	return maxCoins;
}

int main() {
	int N;
	vector<int> nums;

	cin >> N;
	for (int tmp, i = 0; i < N; i++) {
		cin >> tmp;
		nums.push_back(tmp);
	}
	array = new int*[N+2];
	for (int i = 0; i<N+2; i++)
		array[i] = new int[N+2];
	for (int i = 0; i < N + 2; i++)
	for (int j = 0; j < N + 2; j++)
		array[i][j] = 0;
	cout << maxCoins(nums) << endl;

	return 0;
}


