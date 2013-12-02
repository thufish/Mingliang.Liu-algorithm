#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

const int num = 90000;

void prime_sieve(int n, bool prime[]) {
    prime[0] = false;
    prime[1] = false;
    int i;
    for (i = 2; i <= n; i++)
        prime[i] = true;
 
    int limit = sqrt(n);
    for (i = 2; i <= limit; i++)
        if (prime[i])
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
}

void prime_sieve2(int n, bool prime[]) {
    prime[0] = prime[1] = false;
    prime[2] = true;
    for (int i = 3; i <= n; i++)
        prime[i] = (i % 2);
    
    int limit = sqrt(n);
    for (int i = 3; i <= limit; i += 2)
        if (prime[i])
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
}

int main() {
    bool prime[num + 1] = {false};
    prime_sieve(num, prime);

    bool prime2[num + 1] = {false};
    prime_sieve2(num, prime2);

    for (int i = 0; i <= num; i++)
        assert(prime[i] == prime2[i]);

    return 0;
}
