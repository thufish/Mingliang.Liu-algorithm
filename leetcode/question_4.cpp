#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m == 0 && n == 0)
            return 0;
        else if (m == 0 && n == 1)
            return B[0];
        else if (m == 1 && n == 0)
            return A[0];
        else if (m == 1 && n == 1)
            return (A[0] + B[0]) / 2.0;
        else {
            int i, j;
            i = j = 0;
        
            int p, q;
            p = q = 0;
            
            for(int count = 0; count <= (m + n) / 2; count++) {
                if (i == m) {
                    p = q;
                    q = B[j++];
                } else if (j == n) {
                    p = q;
                    q = A[i++];
                } else {
                    if (A[i] <= B[j]) {
                        p = q;
                        q = A[i++];
                    } else {
                        p = q;
                        q = B[j++];
                    }
                }
            }

            if ((m + n) % 2 == 1)
                return q;
            else
                return (p + q) / 2.0;
        }
    }
};

int main() {
    int a[] = {};
    int b[] = {2, 3};

    Solution S;
    cout << S.findMedianSortedArrays(a, 0, b, 2) << endl;

    return 0;
}
