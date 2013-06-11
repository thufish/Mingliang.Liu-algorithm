#include <algorithm>

using namespace std;

/** The straight forward solution is a two-pass algorithm using counting sort.
 *
 * First, iterate the array counting number of 0's, 1's, and 2's,
 * then overwrite array with total number of 0's, then 1's and followed by 2's.
 */
class Solution1 {
public:
    void sortColors(int A[], int n) {
        int red, white, blue;
        red = white = blue = 0;
        
        for (int i = 0; i < n; ++i)
        switch(A[i]) {
            case 0: ++red; break;
            case 1: ++white; break;
            case 2: ++blue; break;
            default: break;
        }
        
        fill(A, A + red, 0);
        fill(A + red, A + red + white, 1);
        fill(A + red + white, A + n, 2);
    }
};

/** Could you come up with an one-pass algorithm using only constant space?
 */
class Solution2 {
public:
    void sortColors(int A[], int n) {
        int red, white; // head index
        red = white = 0;
        
        for (int i = 0; i < n; ++i)
            switch(A[i]) {
                case 0:
                    A[red] = 0;
                    ++red;
                    if (red <= white)
                        A[white] = 1;
                    ++white;
                    if (white <= i)
                        A[i] = 2;                    
                    break;
                case 1:
                    A[white] = 1;
                    ++white;
                    if (white <= i)
                        A[i] = 2;
                    break;
            }
    }
};
