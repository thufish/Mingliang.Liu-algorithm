#include <iostream>
#include <string>

using namespace std;

int main() {
    int round;
    while (cin >> round) {
        if (round == -1)
            break;
        cout << "Round " << round << endl;

        string solution;
        cin >> solution;
        bool flag_s[26] = {false};
        int count = 0;
        for (int i = 0; i < solution.length(); ++i)
            if (!flag_s[solution[i] - 'a']) {
                flag_s[solution[i] - 'a'] = true;
                count++;
            }
        
        string guess;
        cin >> guess;
        bool flag_g[26] = {false};
        int hang = 0;
        bool chickened = true;
        for (int i = 0; i < guess.length(); ++i)
            if (!flag_g[guess[i] - 'a']) {
                flag_g[guess[i] - 'a'] = true;
                if (flag_s[guess[i] - 'a']) {
                    count--;
                    if (count <= 0) {
                        cout << "You win." << endl;
                        chickened = false;
                        break;
                    }
                }
                else {
                    hang++;
                    if (hang == 7) {
                        cout << "You lose." << endl;
                        chickened = false;
                        break;
                    }
                }
            }

        if (chickened)
            cout << "You chickened out." << endl;
    }

    return 0;
}
