class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int cnt=0;
        int sum=0;
       sort(cost.begin(),cost.end());
       for(int i=cost.size()-1; i>=0; i--)
       {
        if(cnt==2)
        {
            cnt=0;
            continue;
        }
        sum+=cost[i];
        cnt++;



       }
       return sum;

    }
};