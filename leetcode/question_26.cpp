#include <algorithm>

using namespace std;

/** This solution employs the STL algorithm library.
 *
 * Kind of cheating.
 */
class Solution1 {
public:
    int removeDuplicates(int A[], int n) {
        sort(A, A + n);
        return unique(A, A + n) - A;
    }
};

/** The hand written unique()
 *
 * If the sort can be used either, can you write the quick sort in 5 min?
 */
class Solution2 {
public:
    int removeDuplicates(int A[], int n) {
        if (A == NULL || n < 1)
            return 0;

        /** sort first **/
        sort(A, A + n);

        int nn = 1;
        for (int i = 1; i < n; ++i) {
           if (A[i] != A[i - 1])
               A[nn++] = A[i];
        }

        return nn;
    }
};
