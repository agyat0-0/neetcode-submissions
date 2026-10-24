class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        vector<int> indegree (numCourses, 0);
        for(const auto& edge:prerequisites)
        {
            int precourse = edge[1];
            int inCourse = edge[0];
            indegree[inCourse]++;
            edges[precourse].push_back(inCourse);
        }

        queue<int> q;
        for (int course =0; course<numCourses; course++)
        {
            if (indegree[course]==0)
            {
                q.push(course);
            }
        }
        vector<int> order;
        order.reserve(numCourses);
        while(!q.empty())
        {
            int curCourse = q.front();
            q.pop();
            order.push_back(curCourse);

            for (int course:edges[curCourse])
            {
                indegree[course]--;
                if(indegree[course]==0)
                {
                    q.push(course);
                }
            }
        }
        return order.size()==numCourses ? order : vector<int>{};
    }
};
