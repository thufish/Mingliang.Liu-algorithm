#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    vector<string> counts = {"", "", "double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple"};
    string N, F;
    int c = 1;
    while (c <= T) {
        cin >> N >> F;
        cout << "Case #" << c << ":";

        int format_index = 0;
        int number_index = 0;
        while (format_index < F.size()) {
            int length = 0;
            while (format_index < F.size() && F[format_index] != '-') {
                length = length * 10 + F[format_index] - '0';
                format_index++;
            }

            while (length > 0) {
                int number = N[number_index] - '0';
                int count = 0;
                while (length > 0 && (N[number_index] - '0' == number)) {
                    number_index++;
                    count++;
                    length--;
                }
                if (count == 1)
                    cout << " " << numbers[number];
                else if (count <= 10)
                    cout << " " << counts[count] << " " << numbers[number]; 
                else for (int i = 0; i < count; i++)
                    cout << " " << numbers[number];
            }

            format_index++;
        }

        cout << endl;
        c++;
    }

    return 0;
}
