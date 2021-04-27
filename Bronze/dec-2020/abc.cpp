#include <bits/stdc++.h>
using namespace std;

int main() {
    int nums[7];
    for (int i = 0; i < 7; i++)
        cin >> nums[i];
    sort(nums, nums + 7);
    cout << nums[0] << " " << nums[1] << " " << nums[6] - nums[0] - nums[1] << endl;
}
