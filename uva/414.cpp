#include <string>
#include <iostream>

#define COLS 25

using namespace std;

int main() {
    int rows;

    while ((cin >> rows) && rows != 0) {
        int max = 0;
        int sum = 0;
        int counts[12] = {0};
        for (int i = 0; i < rows; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < str.size(); j++)
                if (str[j] == 'X')
                    counts[i]++;

            if (str.size() != COLS) {
                string str2;
                cin >> str2;
                for (int j = 0; j < str2.size(); j++)
                    if (str2[j] == 'X')
                        counts[i]++;
            }

            sum += counts[i];

            if (counts[i] > max)
                max = counts[i];
        }

        cout << (max * rows - sum) << endl;
    }

    return 0;
}
