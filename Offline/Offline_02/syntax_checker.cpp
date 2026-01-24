#include <stack>
#include <string>
using namespace std;

/**
 * Helper function to check if an opening bracket matches a closing bracket
 * @param opening: The opening bracket character
 * @param closing: The closing bracket character
 * @return true if they form a matching pair, false otherwise
 */
bool isMatchingPair(char opening, char closing)
{
    if (opening == '(' && closing == ')' || opening == '{' && closing == '}' || opening == '[' && closing == ']')
        return true;

    return false;
}

/**
 * Checks if brackets in an arithmetic expression are properly matched
 * @param expression: A string containing an arithmetic expression
 * @return true if all brackets are properly matched and balanced, false otherwise
 */
bool isValidExpression(const string &expression)
{
    stack<char> st;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.empty() || !isMatchingPair(st.top(), ch))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

/* 
Compiling Commands: g++ -std=c++11 syntax_checker_tester.cpp syntax_checker.cpp -o main
11 ./main
*/
