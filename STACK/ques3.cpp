//infix to postfix conversion
#include <iostream>
#include <stack>
using namespace std;

int prec(char c)
{
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return -1;
}

int main()
{
    string s="A+B*C";
    stack<char> st;
    string ans="";

    for(char ch:s)
    {
        if(isalnum(ch))
            ans+=ch;

        else
        {
            while(!st.empty() && prec(st.top())>=prec(ch))
            {
                ans+=st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }

    cout<<ans;
}