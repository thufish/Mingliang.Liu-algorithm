#include <algorithm>
#include <vector>

using namespace std;

/** The naive solution for all pairs of lines. O(N^2)
 *
 * This can not pass the large dataset
 */
class Solution1 {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        for (int i = 0; i < height.size(); ++i)
            for (int j = i + 1; j < height.size(); ++j)
                if ((j - i) * min(height[i], height[j]) > max_area)
                    max_area = (j - i) * min(height[i], height[j]);
                    
        return max_area;
    }
};

/** The O(NlgN) solution by sorting and visiting the height in asscending order
 * 
 * This can pass the large dataset
 */
struct Container {
    int i;
    int h;
    
    Container(int i, int h): i(i), h(h) {}
};

bool operator < (const Container &left, const Container &right) {
    return left.h < right.h;
}

class Solution2 {
public:
    int maxArea(vector<int> &height) {
        vector<Container> C;
        for (int i = 0; i < height.size(); ++i)
            C.push_back(Container(i, height[i]));
        
        sort(C.begin(), C.end());
        
        vector<bool> taken(C.size(), false);
        int max_area = 0;
        int left, right;
        left = 0;
        right = C.size() - 1;
        for (int k = 0; k < C.size() - 1; ++k) {
            taken[C[k].i] = true;
            for (; taken[right]; --right);
            for (; taken[left]; ++left);
            int max_from_me = max(abs((left - C[k].i) * C[k].h),
                                  abs((right - C[k].i) * C[k].h));
            if (max_from_me > max_area)
                max_area = max_from_me;
        }

        return max_area;
    }
};

/** The O(N) solution using greedy algorithm
 * 
 * 类似于2Sum的思想，两边设一个指针，然后计算area，如果height[i] <=
 * height[j]，那么i++，因为在这里height[i]是瓶颈，j往里移只会减少面积，不会再增加area。
 *
 * 这是一个贪心的策略，每次取两边围栏最矮的一个推进，希望获取更多的水。 
 * 一个不严格的证明：
 *
 * 当height[i] <= height[j]时，为什么是i++，而不是j++来获取可能更多的水？
 *
 * 假设j' > j，之所以j'往左移，是因为存在height[i'] > height[j'] (i’ <= i),
 * 而那时area' = (j' - i') * min(height[i'], height[j'])，
 *
 * 因为height[j'] == min(height[i'], height[j'])，所以area' = (j' - i') *
 * height[j']。
 *
 * 而i 和 j'构成的面积area = (j' - i) * min(height[i], height[j'])。
 *
 * area' >= area，所以j不需要往右移。
 *
 */
class Solution3 {
public:
    int maxArea(vector<int> &height) {
        int most_water = 0;
        
        int i = 0; 
        int j = height.size() - 1;
        while (i < j) {
            int most_ij = (j - i) * min(height[i], height[j]);
            if (most_ij > most_water)
                most_water = most_ij;
            if (height[i] < height[j])
                ++i;
            else
                --j;
        }
        
        return most_water;
    }
};
