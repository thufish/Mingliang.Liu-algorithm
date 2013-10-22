class Solution {
public:
    int romanToInt(string s) {
        typedef std::pair<int, std::string> valueMapping;
        static std::vector<valueMapping> importantNumbers = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100,  "C"}, { 90, "XC"}, { 50, "L"}, { 40, "XL"},
            {10,   "X"}, {  9, "IX"}, {  5, "V"}, {  4, "IV"},
            {1,    "I"},
        };
        
        int number = 0;
        int index = 0;
        for (int i = 0; i < importantNumbers.size(); i++) {
            while (index < s.length() && starts_with(s, index, importantNumbers[i].second)) {
                number += importantNumbers[i].first;
                index += importantNumbers[i].second.length();
            }
        }
        
        return number;
    }
    
    static bool starts_with(const string &str, int start_index, const string &prefix) {
        return str.compare(start_index, prefix.length(), prefix) == 0;
    }
};

int romanToInt(string s) {
    if (s.length()==0) return 0;

    map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;

    int n = s.length();
    int sum = m[s[n-1]];
    for (int i=n-2; i>=0; i--) {
        if (m[s[i+1]] <= m[s[i]])
            sum += m[s[i]];
        else
            sum -= m[s[i]];
    }
    return sum;
}
