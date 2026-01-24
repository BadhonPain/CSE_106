#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    stack<char> st;
    st.push(' ');
    for (int i = n - 1; i >= 0; i--)
    {
        char ch = s[i];
        if (st.top() == ch)
        {
            st.pop();
        }
        else
            st.push(ch);
    }
    string out_string = "";
    while (st.top() != ' ')
    {
        out_string += st.top();
        st.pop();
    }
    cout << out_string << endl;
}