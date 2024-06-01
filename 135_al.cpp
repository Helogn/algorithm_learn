class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if(size == 1) return 1;

        int amt = 0;
        vector<int> lVec(size, 1), rVec(size, 1);
        for(int i = 1; i<size; i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                lVec[i] = lVec[i-1] + 1;
            }
            else if (ratings[i] < ratings[i-1])
            {
                rVec[i-1] = rVec[i] + 1;
            }
            else
            {
                rVec[i] = rVec[i-1];
                lVec[i] = lVec[i-1];
            }
        }
        for (int i = 0; i<size; i++)
        {
            amt += max(rVec[i], lVec[i]);
        }

        return amt;

    }
};