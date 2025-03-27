#ifndef VALIDPARENTHESES_HPP
#define VALIDPARENTHESES_HPP

#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s)
    {
        // 由于栈结构的对称性，非常适合对称匹配类的问题
        std::stack<int> st;
        for(int i = 0; i < s.size(); ++i)
        {
            // 这里有一个重要的技巧，当匹配左括号的时候，让对应的右括号入栈，这样当匹配右括号的时候
            // 只需要判断栈顶字符是否与当前字符相等即可，可以简化代码
            if(s[i] == '(') st.push(')');
            else if(s[i] == '[') st.push(']');
            else if(s[i] == '{') st.push('}');
            // 对于字符是右括号的所有情况，第一种不匹配是有多余的右括号，此时栈为空
            // 第二种不匹配的情况是右括号字符与栈顶字符不相等，意味着不匹配
            else if(st.empty() || st.top() != s[i]) return false;
            // 说明当前字符与栈顶字符相等，匹配
            else st.pop();
        }

        // 最后一种不匹配情况是，此时栈中还剩余左括号对应的右括号字符，说明字符串中有多余的左括号，不匹配
        return st.empty();
    }
};


#endif  