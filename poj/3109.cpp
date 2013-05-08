#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "algorithm"

using namespace std;

// 题目给的点数上限 （为啥+10？裕度？）。
const int maxN = 100010;
// 根据 maxN 算出的完全二叉树的结点数 （又一个+10？）：因为 131072 = 2^17 (>
// 100000) 个叶子的完全二叉树需要 262143 = 2^18 - 1 个结点。这里没有考虑最底层
// 可以不满，为了方便 segment tree 的构造，因此有将近一半的空间被浪费。
const int maxSIZE = 262144 + 10;
// segment tree (for vertical segment)，其中每个结点 s[u] 对应一个垂直区间 [l,
// r] 以及一个分割点 mid，其中 l <= mid <= r 为离散后的 y 值。

// 如果一个垂直线段 Vi 包含 [l, r]，则在 s[u] 记录 Vi(本题只需记录线段数，因此
// 对应的操作为线段数+1)；否则，如果 Vi 与 [l, mid] 有交集就沿左子树(s[u*2])进
// 行递归，如果 Vi 与 [mid + 1, r] 有交集就沿右子树(s[u*2+1])进行递归。

// 线段树的效果可以归结为：用最少数量的尽可能大的区间将线段“分尸”
int s[maxSIZE];
// 离散化后的最大 y 值
int yrank_max;

struct NODE
{
        int x, y;
        // 离散化后的 y 值
        int yrank;
};

NODE node[maxN];
// 记录当前 yrank 在前面有否出现过，有的话才能与当前点形成水平线段
char check[maxN];
int n;
long long result;

void
insert(int u, int l, int r, int b, int e)
{
    int mid = (l + r) / 2;
    if (b > e)
    {
        return;
    }
    // 线段包含当前区间
    if (b <= l && e >= r)
    {
        ++s[u];
        return;
    }
    // 线段与左子区间有交集
    if (b <= mid)
    {
        insert((u << 1), l, mid, b, e);
    }
    // 线段与右子区间有交集
    if (e > mid)
    {
        insert((u << 1) + 1, mid + 1, r, b, e);
    }
}

int
find(int y)
{
    int u, l, r, mid;
    int sum = 0;
    u = 1;
    l = 1;
    r = yrank_max;
    while (l <= r)
    {
        mid = (l + r) / 2;
        // 当前区间包含 y，所以覆盖当前区间的所有*有效*垂直线段都与高度为 y 的
        // 当前水平线段相交
        sum += s[u];
        if (l == r)
        {
            break;
        }
        // y 位于左子区间，对左子区间进行递归查找
        if (y <= mid)
        {
            u = (u << 1);
            r = mid;
        }
        // y 位于右子区间，对右子区间进行递归查找
        else
        {
            u = (u << 1) + 1;
            l = mid + 1;
        }
    }
    return sum;
}

void
setzero(int u, int l, int r, int y)
{
    int mid = (l + r) / 2;
    // 剔除交点
    if (l == r)
    {
        s[u] = 0;
        return;
    }
    if (s[u] > 0)
    {
        // 线段被切割后，不能完全覆盖原有区间，向子区间退化
        s[(u << 1)] += s[u];
        s[(u << 1) + 1] += s[u];
        s[u] = 0;
    }
    // 交点处于左子区间，左子区间需要递归退化
    if (y <= mid)
    {
        setzero((u << 1), l, mid, y);
    }
    // 交点处于右子区间，右子区间需要递归退化
    else
    {
        setzero((u << 1) + 1, mid + 1, r, y);
    }
}

int
cmp_y(NODE a, NODE b)
{
    return a.y < b.y;
}

int
cmp(NODE a, NODE b)
{
    if (a.x != b.x)
    {
        return a.x < b.x;
    }
    return a.yrank < b.yrank;
}

int main()
{
    int i;
    char buf[20];
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
    {
        scanf("%s", buf);
        node[i].x = atoi(buf);
        scanf("%s", buf);
        node[i].y = atoi(buf);
    }
    // 将所有点按 y 坐标升序排序，以便下面离散化
    sort(node, node + n, cmp_y);
    // 将 y 离散化（不是必须的，但是会使程序其他部分更简明）
    node[0].yrank = 1;
    for (i = 1; i < n; ++i)
    {
        node[i].yrank = node[i - 1].yrank;
        if (node[i].y > node[i - 1].y)
        {
            ++node[i].yrank;
        }
    }
    yrank_max = node[n - 1].yrank;
    // 将所有点按 x 主序，y 辅序排序
    sort(node, node + n, cmp);
    result = n;
    for (i = 0; i < n; ++i)
    {
        // 前面出现过与当前点处于同样高度的点，即可以形成水平线段
        if (check[node[i].yrank])
        {
            // 在线段树中查找交点
            result += find(node[i].yrank);
        }
        check[node[i].yrank] = 1;
        // 当前水平线段与线段树中当前垂直线段的交点已经记录，如果不清除的话会被
        // 后续形成的同一高度的水平线段重复记录，所以要将这些交点剔除。其效果相
        // 当于用当前水平线段去切割线段树中的垂直线段，并且切割点废除，不能被子
        // 线段复用。
        setzero(1, 1, yrank_max, node[i].yrank);
        if (i > 0 && node[i].x == node[i - 1].x)
        {
            // 往线段树中插入垂直线段
            insert(1, 1, yrank_max, node[i - 1].yrank + 1, node[i].yrank - 1);
        }
    }
    printf("%I64d\n", result);
    return 0;
}
