#include <cassert>
#include <stack>

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> S;
        
        for (string t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                assert(!S.empty());
                int num1 = S.top(); S.pop();
                int num2 = S.top(); S.pop();
                switch (t.front()) {
                    case '+':
                        S.push(num2 + num1);
                        break;
                    case '-':
                        S.push(num2 - num1);
                        break;
                    case '*':
                        S.push(num2 * num1);
                        break;
                    case '/':
                        S.push(num2 / num1);
                        break;
                } 
            } else
                S.push(stoi(t));
        }
        
        return S.top();
    }
};
