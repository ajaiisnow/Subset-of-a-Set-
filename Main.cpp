#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Display(vector<int> num)
{
	for (auto a : num)
	{
		cout << a << "  ";
	}
	cout << endl;
}
void generate_subsets(int idx, vector<int>& nums, vector<int>& current_set, vector<vector<int>>& sub_set)
{
	sub_set.push_back(current_set);
	for (int i = idx; i < nums.size(); i++)
	{
		current_set.push_back(nums[i]);
		Display(current_set);
		generate_subsets(i + 1, nums, current_set, sub_set);
		current_set.pop_back();
	}
}

vector<vector<int>>subsets_of_set( vector<int>& nums)
{
	vector<vector<int>> sub_set;
	vector<int>current_set;
	generate_subsets(0, nums, current_set, sub_set);
	return sub_set;
}

int main(int argc, char** argv)
{
	vector<int> numbers{ 1,2,2 };
	//sort(numbers.begin(), numbers.end(), [](int a, int b)->bool {return a < b; });
	vector<vector<int>>subset = subsets_of_set(numbers);
	cout << "Output of sets has: "<< subset.size() << " elments and elements are: "<< endl;

	cout << "[" << endl;
	for (auto set : subset)
	{
		cout << "[ ";
		for (auto num : set)
		{
			cout << num << " ";
		}
		cout << " ]" << endl;
	}

	cout << endl << "]" << endl;
	return 0;
}
