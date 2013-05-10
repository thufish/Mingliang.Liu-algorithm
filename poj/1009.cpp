#include <algorithm>
#include <iostream>
#include <cstdlib>

#define MAX_SIZE 1000
#define DUMP cout << out_value << " " << out_length << endl

using namespace std;

unsigned short values[MAX_SIZE];
int length[MAX_SIZE];
int total[MAX_SIZE];

int cols, pair_num;
unsigned short out_value;
unsigned out_length;

unsigned short cal_value(int i, unsigned j, int k)
{
    if (k == 0)
        return 0;
    else if (k > 0) {
        if (k + j < length[i])
            return 0;
        k -= length[i] -1 - j;
        int ii = i;
        while (k > 0 && ii < pair_num)
           k -= length[++ii]; 
        return abs(values[ii] - values[i]);
    } else if(k < 0) {
        k = 0 - k;
        if (k - 1 < j)
            return 0;
        int ii = i;
        k -= j;
        while (k > 0 && ii > 0)
            k -= length[--ii];
        return abs(values[ii] - values[i]);
    }
}


void edge(int i, unsigned j)
{
        
    int i1, i2, i3, i4, i5, i6, i7, i8;
    i1 = i2 = i3 = i4 = i5 = i6 = i7 = i8 = -1;

    unsigned index = j;
    if (i > 0)
        index += total[i - 1];

    if (index < cols)
        i1 = i2 = i3 = 0;
    if (index % cols == 0)
        i1 = i4 = i6 = 0;
    if ((index % cols) == (cols - 1))
        i3 = i5 = i8 = 0;
    if (index > total[pair_num - 1] - cols - 1)
        i6 = i7 = i8 = 0;

    if (i1 == -1) i1 = cal_value(i, j, 0 - cols - 1);
    if (i2 == -1) i2 = cal_value(i, j, 0 - cols);
    if (i3 == -1) i3 = cal_value(i, j, 0 - cols + 1);
    if (i4 == -1) i4 = cal_value(i, j, 0 - 1);
    if (i5 == -1) i5 = cal_value(i, j, 1);
    if (i6 == -1) i6 = cal_value(i, j, cols - 1);
    if (i7 == -1) i7 = cal_value(i, j, cols);
    if (i8 == -1) i8 = cal_value(i, j, cols + 1);

    i1 = max(i1, i2);
    i3 = max(i3, i4);
    i5 = max(i5, i6);
    i7 = max(i7, i8);

    i1 = max(i1, i3);
    i5 = max(i5, i7);

    unsigned short new_out_value = max(i1, i5);

    if (i == 0 && j == 0) {
        out_value = new_out_value;
        out_length = 1;
    } else if (new_out_value == out_value)
        out_length++; 
    else {
        // dump
        DUMP;
        // update
        out_value = new_out_value;
        out_length = 1;
    }
}

int main()
{
    // read the input
    while (true) {
        cin >> cols;
        if (cols == 0)
        {
            cout << "0" << endl;
            return 0;
        }

        pair_num = 0;
        // get the input image
        while (true) {
            cin >> values[pair_num] >> length[pair_num];
            if (values[pair_num] == 0 && length[pair_num] == 0)
                break;
            if (pair_num == 0)
                total[0] = length[0];
            else
                total[pair_num] = total[pair_num - 1] + length[pair_num];
            pair_num++;
        }

        cout << cols << endl;
        for (int i = 0; i < pair_num; ++i) {
            /////// short pairs
            if (length[i] < cols + 1) {
                for (unsigned j = 0; j < length[i]; ++j)
                    edge(i, j);
                continue;
            }

            /////// long pairs
            // pre
            unsigned j;
            for (j = 0; j < cols + 1; ++j)
                edge(i, j);

            if (j < length[i] - cols - 1) {
                if (out_value == 0)
                    out_length += length[i] - 2 * cols - 2; 
                else {
                    out_value = 0;
                    out_length = length[i] - 2 * cols - 2; 
                    DUMP;
                }
            }

            // post
            for (j = max(length[i] - cols - 1, cols + 1); j < length[i]; ++j)
                edge(i, j);
        }
        DUMP;
        cout << "0 0" << endl;
    }
 
    return 0;
}
