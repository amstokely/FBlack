#ifndef FBLACK_FLACK_LINE_TEST_FIXTURE_H
#define FBLACK_FLACK_LINE_TEST_FIXTURE_H

#include <gtest/gtest.h>

class FBlackLineTestFixture : public ::testing::Test {
protected:
    void
    SetUp() override;

    void
    TearDown() override;

public:
    FBlackLineTestFixture();
    const std::string subroutineDeclaration;
    std::stringstream subroutineDeclarationStream;
    const std::string functionDeclaration;
    const std::string variableDeclaration;
    const std::string indentedVariableDeclaration;
    const std::string multiLineFunctionDeclaration;
    const std::string multiLineVariableDeclaration;
};


#endif //FBLACK_FLACK_LINE_TEST_FIXTURE_H
