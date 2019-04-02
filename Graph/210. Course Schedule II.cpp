/*
同207.
author: ypz
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> connection(numCourses, vector<int>{});
        for(int i = 0; i < prerequisites.size(); i++) {
            connection[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
        }
        queue<int> zero_indegree;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) zero_indegree.push(i);
        }
        while(zero_indegree.size() > 0) {
            int temp = zero_indegree.front();
            for(int i = 0; i < connection[temp].size(); i++) {
                indegree[connection[temp][i]]--;
                if(indegree[connection[temp][i]] == 0)
                    zero_indegree.push(connection[temp][i]);
            }
            ans.push_back(temp);
            zero_indegree.pop();
        }
        if(ans.size() == numCourses) return ans;
        else return {};
    }
};
