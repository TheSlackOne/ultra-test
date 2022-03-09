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
    for (int i = 0; i < I.size() && accum < S; ++i) {
        accum += I.at(i);
        M.push_back(I.at(i));
        for (int j = i + 1; j < I.size() && accum < S; ++j) {
            accum += I.at(j);
            // Saves to vector while accum < S.
            M.push_back(I.at(j));
            if (accum <= S) {
                if (accum == S)
                    return;
                continue;
            }
            // accum > S, tries to find an element to remove.
            uint64_t diff = accum - S;
            for (int k = 0; k < M.size(); ++k) {
                if (M.at(k) == diff) {
                    M.erase(M.begin() + k);
                    return;
                }
            }
            break;
        }
        accum = 0;
        M.clear();
    }
}
