#include <string>
#include <vector>
#include <iostream>

using namespace std;

/** The naive sort and compare one. O(NlgN) */
bool is_permutation1(string &str1, string &str2) {
    /** trivial cases first */
    if (str1.length() != str2.length())
        return false;
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

/** Count the number of every char and compare the counts */
bool is_permutation2(const string &str1, const string &str2) {
    if (str1.length() != str2.length())
        return false;

    vector<size_t> count1(128, 0);
    for (char c : str1)
        count1[c]++;
    vector<size_t> count2(128, 0);
    for (char c : str2)
        count2[c]++;

    return count1 == count2;
}

/** A smarter one which saves one counter vector and returns in time */
bool is_permutation3(const string &str1, const string &str2) {
    /** this line is important in this solution */
    if (str1.length() != str2.length())
        return false;

    vector<size_t> count(128, 0);
    for (char c : str1)
        ++count[c];
    for (char c : str2)
        if (count[c]-- == 0)
            return false;

    return true;
}

int main() {
    string s1 = "abcdefghijklmn";
    string s2 = "def";
    string s3 = "nmlkjihgfedcba";
    string s4 = "abcdefghijkmln";
    string s5 = "abcdefghijklmn";

    cout << is_permutation1(s2, s1) << is_permutation1(s3, s1) << is_permutation1(s4, s1) << is_permutation1(s5, s1) << endl;
    cout << is_permutation2(s2, s1) << is_permutation2(s3, s1) << is_permutation2(s4, s1) << is_permutation2(s5, s1) << endl;
    cout << is_permutation3(s2, s1) << is_permutation3(s3, s1) << is_permutation3(s4, s1) << is_permutation3(s5, s1) << endl;
    return 0;
}
