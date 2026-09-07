class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(vector<int>& candidates, int start, int target) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target)
                break;

            path.push_back(candidates[i]);

            // i, not i + 1, because the same number can be reused
            backtrack(candidates, i, target - candidates[i]);

            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, 0, target);

        return ans;
    }
};