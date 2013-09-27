#include <algorithm>
#include <string>
#include <stack>

using namespace std;

/** The naive solution.
 * We store every max so far len in a vector
 */
class Solution1 {
public:
    int longestValidParentheses(string s) {
        stack<int> p;               // The stack. No better data structure.
        vector<int> v(s.size(), 0); // vector for all max_so_far

        int max = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                p.push(i);
            else if (!p.empty()) {
                int left = p.top();
                p.pop();
                
                int max_curr = i - left + 1;
                if (left)
                    max_curr += v[left - 1]; // join succussive pairs
                if (max_curr > max)
                    max = max_curr;
                v[i] = max_curr;
            }
        }
        
        return max;
    }
};

/** Improved solution to save space.
 * Mark the string and find the longest 'L' string offline
 */
class Solution2 {
public:
    int longestValidParentheses(string s) {
        stack<int> p;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                p.push(i);
            else if (!p.empty()) {
                s[p.top()] = 'L';
                s[i] = 'L';
                p.pop();
            }
        }
        
        int max = 0;
        int curr = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'L')
                ++curr;
            else {
                if (curr > max)
                    max = curr;
                curr = 0;
            }
        }
        if (curr > max)
            max = curr;
            
        return max;
    }
};

/** The space saving algorithm. Get the max length online
 *
 * Use a stack to keep track of the positions of non-matching '('s.
 * Also need to keep track of the position of the last ')'.
 */
class Solution3 {
public:
    int longestValidParentheses(string s) {
        stack<int> p;
        int last = -1; // NOTE: the initial value of last is -1.
        int len = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                p.push(i);
            else if (p.empty())
                last = i;
            else {
                p.pop();
                if (p.empty())
                    len = max(len, i - last);
                else
                    len = max(len, i - p.top());
            }
        }
            
        return len;
    }
};

/** The O(1) space without any extra data structure!
 *
 * We count the matching ')' from left for every '(' and count the matching
 * '(' from right for every ')'
 */
class Solution4 {
public:
    int longestValidParentheses(string s) {
        return max(longestValidParentheses(s.begin(), s.end(), '('),
                   longestValidParentheses(s.rbegin(), s.rend(), ')'));
    }

    template <typename ForwardIterator>
    int longestValidParentheses(ForwardIterator b, ForwardIterator e, char c) {
        int left = 0, right = 0, len = 0;
        for (ForwardIterator i = b; i < e; i++) {
            if (*i == c)
                left++;
            else if (left > right) {
                right++;
                if (left == right)
                    len = max(len, left << 1);
            } else {
                left = right = 0;
            }
        }
        return len;
    }
};
