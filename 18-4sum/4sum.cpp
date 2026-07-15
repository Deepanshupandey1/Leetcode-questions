class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int i = 0;

        while(i < n - 3)
        {
            int j = i + 1;

            while(j < n - 2)
            {
                int left = j + 1;
                int right = n - 1;

                while(left < right)
                {
                    long long sum = (long long)nums[i] +
                                    nums[j] +
                                    nums[left] +
                                    nums[right];

                    if(sum == target)
                    {
                        ans.push_back(
                        {
                            nums[i],
                            nums[j],
                            nums[left],
                            nums[right]
                        });

                        left++;
                        right--;

                        while(left < right && nums[left] == nums[left - 1])
                        {
                            left++;
                        }

                        while(left < right && nums[right] == nums[right + 1])
                        {
                            right--;
                        }
                    }
                    else if(sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }

                j++;

                while(j < n - 2 && nums[j] == nums[j - 1])
                {
                    j++;
                }
            }

            i++;

            while(i < n - 3 && nums[i] == nums[i - 1])
            {
                i++;
            }
        }
        return ans;
    }
};