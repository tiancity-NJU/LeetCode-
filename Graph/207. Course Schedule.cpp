/*
author: ypz
从indegree中找所有点中入度数为0的点，构成初始队列；
通过队首出列，调整与队首元素出度相连的所有点的入度数，并检查这些点的入度数是否为0，若是则入队列；
重复步骤直至队列为空，此时若从队列中出列的所有点的数目为原来有向图中所有点的数目，则图中不存在闭合的环，且出列的顺序是一种可行的遍历方法。
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        if(ans.size() == numCourses) return true;
        else return false;
    }
    
    /*
    // dfs, 该解法超时
    bool dfs(vector<vector<int>> matrix, int i, vector<int>& flag) {
        if(flag[i] == 1) return true; // 表示有环
        if(flag[i] == 2) return false; // 该点已经访问过
        flag[i] = 1;
        for(auto m: matrix[i]) {
            if(dfs(matrix, m, flag)) return true;
        }
        flag[i] = 2;
        return false;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> matrix(numCourses, vector<int>{});
        for(int i = 0; i < prerequisites.size(); i++) 
            matrix[prerequisites[i].second].push_back(prerequisites[i].first);
        vector<int> flag(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(dfs(matrix, i, flag) == true) return false; 
        }
        return true;
    }
    */
};
