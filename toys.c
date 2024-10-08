#include <stdio.h>

// Function to calculate gcd of two numbers
long long gcd(long long a, long long b) {
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to calculate lcm of two numbers
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

// Function to calculate the number of multiples
long long count_multiples(long long N, long long x) {
    return N / x;
}

int main() {
    int T;
    scanf("%d", &T);  // Read number of test cases

    for (int i = 0; i < T; i++) {
        long long N, A, B, C, D;
        scanf("%lld %lld %lld %lld %lld", &N, &A, &B, &C, &D);

        long long count = 0;

        // Inclusion-Exclusion principle
        count += count_multiples(N, A);
        count += count_multiples(N, B);
        count += count_multiples(N, C);
        count += count_multiples(N, D);

        count -= count_multiples(N, lcm(A, B));
        count -= count_multiples(N, lcm(A, C));
        count -= count_multiples(N, lcm(A, D));
        count -= count_multiples(N, lcm(B, C));
        count -= count_multiples(N, lcm(B, D));
        count -= count_multiples(N, lcm(C, D));

        count += count_multiples(N, lcm(lcm(A, B), C));
        count += count_multiples(N, lcm(lcm(A, B), D));
        count += count_multiples(N, lcm(lcm(A, C), D));
        count += count_multiples(N, lcm(lcm(B, C), D));

        count -= count_multiples(N, lcm(lcm(A, B), lcm(C, D)));

        printf("Case #%d: %lld\n", i+1, count);
    }

    return 0;
}
