#include <gtest/gtest.h>
#include "fblack_line_fixture.h"
#include <string>
#include <utility>

class Line {
private:
    std::string line_;
    bool isSubroutineDeclaration_ = false;
    bool isFunctionDeclaration_ = false;
    bool isVariableDeclaration_ = false;
    bool hasAmpersand_ = false;
    bool hasComma_ = false;
    bool hasLeftParenthesis_ = false;
    bool hasRightParenthesis_ = false;
    void init(std::string line) {
        this->line_ = std::move(line);

        auto checkAndSetFlag = [&](const std::string &delimiter, bool &flag) {
            flag = (this->line_.find(delimiter) != std::string::npos);
        };

        checkAndSetFlag("subroutine", this->isSubroutineDeclaration_);
        checkAndSetFlag("function", this->isFunctionDeclaration_);
        checkAndSetFlag("::", this->isVariableDeclaration_);
        checkAndSetFlag("&", this->hasAmpersand_);
        checkAndSetFlag(",", this->hasComma_);
        checkAndSetFlag("(", this->hasLeftParenthesis_);
        checkAndSetFlag(")", this->hasRightParenthesis_);
    }
public:
    explicit Line(std::string line) {
        this->init(std::move(line));
    }

    explicit Line(std::stringstream &line) {
        this->init(line.str());
    }

    std::string getLine() {
        return this->line_;
    }

    bool isSubroutineDeclaration() const {
        return this->isSubroutineDeclaration_;
    }

    bool isFunctionDeclaration() const {
        return this->isFunctionDeclaration_;
    }

    bool isVariableDeclaration() const {
        return this->isVariableDeclaration_;
    }

    bool hasAmpersand() const {
        return this->hasAmpersand_;
    }

    bool hasComma() const {
        return this->hasComma_;
    }

    bool hasLeftParenthesis() const {
        return this->hasLeftParenthesis_;
    }

    bool hasRightParenthesis() const {
        return this->hasRightParenthesis_;
    }

    void removeLeadingWhitespace() {
        this->line_ = this->line_.substr(this->line_.find_first_not_of(' '));
    }

   };

TEST_F(FBlackLineTestFixture, Line_getLine) {
    Line line(this->subroutineDeclaration);
    EXPECT_EQ(line.getLine(), this->subroutineDeclaration);
}

TEST_F(FBlackLineTestFixture, Line_streamConstructor) {
    Line line(this->subroutineDeclarationStream);
    EXPECT_EQ(line.getLine(), this->subroutineDeclaration);
}

TEST_F(FBlackLineTestFixture, Line_isSubroutine) {
    Line line(this->subroutineDeclaration);
    EXPECT_TRUE(line.isSubroutineDeclaration());
}

TEST_F(FBlackLineTestFixture, Line_isFunction) {
    Line line(this->functionDeclaration);
    EXPECT_TRUE(line.isFunctionDeclaration());
}

TEST_F(FBlackLineTestFixture, Line_isVariable) {
    Line line(this->variableDeclaration);
    EXPECT_TRUE(line.isVariableDeclaration());
}

TEST_F(FBlackLineTestFixture, Line_hasAmpersand) {
    Line line(this->multiLineFunctionDeclaration);
    EXPECT_TRUE(line.hasAmpersand());
}

TEST_F(FBlackLineTestFixture, Line_hasComma) {
    Line line(this->multiLineVariableDeclaration);
    EXPECT_TRUE(line.hasComma());
}

TEST_F(FBlackLineTestFixture, Line_hasLeftParenthesis) {
    Line line(this->multiLineFunctionDeclaration);
    EXPECT_TRUE(line.hasLeftParenthesis());
}

TEST_F(FBlackLineTestFixture, Line_hasRightParenthesis) {
    Line line(this->functionDeclaration);
    EXPECT_TRUE(line.hasRightParenthesis());
}

TEST_F(FBlackLineTestFixture, Line_removeLeadingWhitespace) {
    Line line(this->indentedVariableDeclaration);
    line.removeLeadingWhitespace();
    EXPECT_EQ(line.getLine(), this->variableDeclaration);
}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}