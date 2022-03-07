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

int main() {
    // Expected file format:
    // T: The Max value (integer).
    // I: A set of values (array of integers).
    // S: A solution (integer).
    std::ifstream infile("../exercise2/test.txt");
    std::string line;
    while (std::getline(infile, line))
    {
        if (line.empty()) continue;
        // Reads T.
        uint64_t T = std::stoll(line);
        // Reads I.
        std::getline(infile, line);
        std::istringstream ss(line);
        std::vector<uint64_t> I;
        uint64_t value;
        while (ss >> value) I.push_back(value);
        // Reads S.
        std::getline(infile, line);
        uint64_t S = std::stoll(line);
        // Calculates M.
        std::vector<uint64_t> M;
        find_largest_sum(T, I, M, S);
        for (const auto& e : M)  {
            std::cout << e << " ";
        }
    }

    return 0;
}