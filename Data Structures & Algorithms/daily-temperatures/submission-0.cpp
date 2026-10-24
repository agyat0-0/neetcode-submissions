class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days = temperatures.size();
        stack<int> st; 
        vector<int> answer(days, 0);
        for(int day = 0; day < days; day++)
        {
            while(!st.empty() && temperatures[day] > temperatures[st.top()])
            {
                int prev_day = st.top();
                st.pop();
                answer[prev_day] = day - prev_day;
            }
            st.push(day);
        }
        return answer;
    }
};
