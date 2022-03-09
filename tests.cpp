#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE exercises
#include <boost/test/unit_test.hpp>
#include "exercise1/exercise1.hpp"
#include "exercise2/exercise2.hpp"

bool is_number(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

BOOST_AUTO_TEST_SUITE(Exercises)

BOOST_AUTO_TEST_CASE(e1) {
    std::string s_op1;
    std::string s_op2;
    std::string s_result;
    // Expected file format:
    // operand1 operand2 result
    // Each line is a test.
    std::ifstream infile("../exercise1/test.txt");
    while (infile >> s_op1 >> s_op2 >> s_result) {
        int64_t op1, op2, result = -1;
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
        if (is_number(s_result))
            result = std::stoull(s_result);
        try {
            BOOST_CHECK(add(op1, op2) == result);
        } catch (const std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
}

BOOST_AUTO_TEST_CASE(e2) {
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
        // Verifies solution.
        uint64_t accum = 0;
        for (const auto& e : M)  {
            accum += e;
        }
        BOOST_CHECK(accum == S);
    }
}

BOOST_AUTO_TEST_SUITE_END()
