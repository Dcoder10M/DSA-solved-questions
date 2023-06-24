class Solution {
public:
    bool OPERATOR(char ch){
        return (ch == '&' || ch == '|' || ch == '&' || ch == '!') ;
    }
    
    char find(int T , int F , char op){
        if(op == '!') return T ? 'f' : 't' ;
        else if(op == '|') return T ? 't' : 'f' ;
        else if(op == '&') return F ? 'f' : 't' ;
        return 'a' ;
    }
    bool parseBoolExpr(string exp) {
        stack<char> st ;
        for(int i = 0 ; i < exp.size() ; ++i ){
            if(exp[i] == ',') continue ;
            
            if(OPERATOR(exp[i]) || exp[i] == 't' || exp[i] == 'f' || exp[i] == '(') st.push(exp[i]) ;
            else if(exp[i] == ')'){
                //evaluate and push to top
                int T = 0 , F = 0 ;
                char op ;
                while(st.size() and st.top() != '('){
                    if(st.top() == 't') ++T ;
                    else if(st.top() == 'f') ++F ;
                    st.pop() ;
                }
                st.pop() ; //remove the opening bracket 
                op = st.top() ; st.pop() ; //just begin the bracket the operator will be there
                st.push(find(T,F,op)) ;
            }
        }   
        return st.top() == 't' ;
    }
};