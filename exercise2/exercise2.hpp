#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// Assumptions:
// Since the exercise is not clear about it but the examples sugest it, I will assume T as an ordered vector.
// T is always >= any M's element.
void find_largest_sum(uint64_t T, const std::vector<uint64_t> &I, std::vector<uint64_t>& M, uint64_t &S) {
    uint64_t accum = 0;
    uint64_t a = 0, b = 0;
    a = I.back();
    accum = a;
    for (int i = I.size() - 2; i > 0; --i) {
        b = I.at(i);
        if (accum + b <= S) {
            M.push_back(b);
            accum += b;
        }
        if (accum + b == S)
            break;
    }
    M.push_back(a);
}
