#include "gtest/gtest.h"
#include "Probability.h"
#include <stdexcept>

TEST(ProbabilityTests, TestConstructor) {
    EXPECT_NO_THROW(Probability(0.0));
    EXPECT_NO_THROW(Probability(1.0));
    EXPECT_THROW(Probability(-1), std::invalid_argument);
    EXPECT_THROW(Probability(2), std::invalid_argument);
}

TEST(ProbabilityTests, TestAssignmentOperatorDouble) {
    Probability p;
    EXPECT_NO_THROW(p = 0.0);
    EXPECT_NO_THROW(p = 1.0);
    EXPECT_THROW(p = 2, std::invalid_argument);
    EXPECT_THROW(p = -1, std::invalid_argument);
}

TEST(ProbabilityTests, TestCastToDouble) {
    double p = 0.5;
    EXPECT_DOUBLE_EQ((double)Probability(p), p);
    EXPECT_DOUBLE_EQ((double)Probability(p), p);
}

TEST(ProbabilityTests, TestOperatorNot) {
    double p1{0.2};
    double p2{0.7};
    EXPECT_DOUBLE_EQ((double)(~Probability(p1)), 1 - p1);
    EXPECT_DOUBLE_EQ((double)(~Probability(p2)), 1 - p2);
}

TEST(ProbabilityTests, TestOperatorAnd) {
    double p1{0.5};
    double p2{0.5};
    double p3{0.3};
    EXPECT_DOUBLE_EQ((double)(Probability(p1) & Probability(p2)), p1*p2);
    EXPECT_DOUBLE_EQ((double)(Probability(p1) & Probability(p3)), p1*p3);
    EXPECT_DOUBLE_EQ((double)(Probability(p2) & Probability(p3)), p2*p3);
}

TEST(ProbabilityTests, TestOperatorOr) {
    double p1{0.2};
    double p2{0.3};
    double p3{0.9};
    EXPECT_DOUBLE_EQ((double)(Probability(p1)|Probability(p2)), p1 + p2 - p1*p2);
    EXPECT_DOUBLE_EQ((double)(Probability(p1)|Probability(p3)), p1 + p3 - p1*p3);
    EXPECT_DOUBLE_EQ((double)(Probability(p2)|Probability(p3)), p2 + p3 - p2*p3);
}

TEST(ProbabilityTests, TestOperatorCaret) {
    double p1{0.3};
    double p2{0.9};
    double p3{0.4};
    EXPECT_DOUBLE_EQ((double)(Probability(p1)^Probability(p2)), p1 + p2 - 2*p1*p2);
    EXPECT_DOUBLE_EQ((double)(Probability(p1)^Probability(p3)), p1 + p3 - 2*p1*p3);
    EXPECT_DOUBLE_EQ((double)(Probability(p2)^Probability(p3)), p2 + p3 - 2*p2*p3);
}

TEST(ProbabilityTests, TestOperatorMinus) {
    double p1{0.2};
    double p2{0.7};
    double p3{0.5};
    EXPECT_DOUBLE_EQ((double)(Probability(p1)-Probability(p2)), p1 - p1*p2);
    EXPECT_DOUBLE_EQ((double)(Probability(p1)-Probability(p3)), p1 - p1*p3);
    EXPECT_DOUBLE_EQ((double)(Probability(p2)-Probability(p3)), p2 - p2*p3);
}

