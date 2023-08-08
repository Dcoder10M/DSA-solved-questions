class Solution {
public:
    string smallestSubsequence(string str) {
        
        int n = str.size();
        
        // declare a stack, this will store the character in increasing order
        
        stack<char> st;
        
        vector<int> last_index(26, -1);
        
        // store the last index of every character
        
        for(int i = 0; i < n; i++)
        {
            last_index[str[i] - 'a'] = i;
        }
        
        // curr_set will keep track of included characters
        
        unordered_set<char> curr_set;
        
        for(int i = 0; i < n; i++)
        {
            // if the curr character is included then simply skip it
            
            if(curr_set.count(str[i]))
            {
                continue;
            }
            
            // pop the largest character from top, if the top element is present to the right of i
            
            while(!st.empty() && st.top() > str[i] && last_index[st.top() - 'a'] > i)
            {
                curr_set.erase(st.top());
                
                st.pop();
            }
            
            // add the curr character
            
            st.push(str[i]);
                
            curr_set.insert(str[i]);
        }
        
        // make the res array
        
        string res = "";
        
        while(st.empty() == false)
        {
            res += st.top();
            
            st.pop();
        }
        
        // reverse the res
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};