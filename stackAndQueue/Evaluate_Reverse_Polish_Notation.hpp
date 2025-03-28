#ifndef EVALUATE_REVERSE_POLISH_NOTATION_HPP
#define EVALUATE_REVERSE_POLISH_NOTATION_HPP

#include <string>
using std::string; using std::stoi;

#include <vector>
using std::vector;

#include <stack>
using std::stack;

class Solution {
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> operators;
        for (auto &token : tokens)
        {
            if(token != "+" && token != "-" && token != "*" && token != "/")
            {
                operators.push(stoi(token));
            } else {
                int rhs = operators.top();
                operators.pop();
                int lhs = operators.top();
                operators.pop();
                token == "+" ? operators.push(lhs + rhs)
                             : token == "-" ? operators.push(lhs - rhs)
                                            : token == "*" ? operators.push(lhs * rhs)
                                                           : operators.push(lhs / rhs);
            }
        }
        return operators.top();
    }
};


#endif