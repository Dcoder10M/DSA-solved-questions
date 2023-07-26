class StockSpanner {
    stack<vector<int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int sec=1;
        while(!st.empty() && st.top()[0]<=price){
            sec+=st.top()[1];
            st.pop();
        }
        st.push({price,sec});
        return sec;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */