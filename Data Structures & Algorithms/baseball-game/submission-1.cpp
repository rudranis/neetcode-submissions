class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        int res=0;
        for(const string&  c: operations){
            if(c=="+"){
            int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
                res += (a + b);
            }
            else if(c=="D"){
                st.push(2*st.top());
                res+=st.top();
            }
            else if(c=="C"){
                res-=st.top();
                st.pop();
            }
            else{
                st.push(stoi(c));
                res+=st.top();
            }
        }
        return res;
    }
};