#include <string>
#include <cstring>
#include <iostream>

#define COLS 25

using namespace std;

int main() {
    int rows;

    while ((cin >> rows) && rows != 0) {
        int max = 0;
        int sum = 0;
        int counts[12];
        memset(counts, 0, sizeof(counts));
        getchar();
        for (int i = 0; i < rows; i++) {
            string str;
            getline(cin, str); // not cin >> str !!!
            
            for (int j = 0; j < COLS; j++)
                if (str[j] == 'X')
                    counts[i]++;

            sum += counts[i];

            if (counts[i] > max)
                max = counts[i];
        }

        cout << (max * rows - sum) << endl;
    }

    return 0;
}
