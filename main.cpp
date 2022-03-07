#include <iostream>
#include <fstream>
#include <string>
#include <limits>

int64_t add(int64_t a, int64_t b) {
    // Overflow and Underflow detection.
    if ((b > 0) && (a > std::numeric_limits<int64_t>::max() - b))
        throw std::invalid_argument("Overflow detected.");
    if ((b < 0) && (a < std::numeric_limits<int64_t>::min() - b))
        throw std::invalid_argument("Underflow detected.");
    // Addition operation.
    int64_t rest = 0;
    while (b) {
        rest = a & b;
        a = a ^ b;
        b = rest << 1;
    }
    return a;
}

int main() {
    std::string s_op1;
    std::string s_op2;
    std::string s_result;
    // Expected file format:
    // operand1 operand2 result
    // Each line is a test.
    std::ifstream infile("../test.txt");
    while (infile >> s_op1 >> s_op2 >> s_result) {
        int64_t op1, op2, result;
        if (s_op1 == "Max")
            op1 = std::numeric_limits<int64_t>::max();
        else if ((s_op1 == "Min"))
            op1 = std::numeric_limits<int64_t>::min();
        else
            op1 = strtoll(s_op1.c_str(), nullptr, 10);
        if (s_op2 == "Max")
            op2 = std::numeric_limits<int64_t>::max();
        else if ((s_op2 == "Min"))
            op2 = std::numeric_limits<int64_t>::min();
        else
            op2 = strtoll(s_op2.c_str(), nullptr, 10);
        try {
            std::cout << add(op1, op2) << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
    }
    return 0;
}
