#include "fblack_line_fixture.h"

FBlackLineTestFixture::FBlackLineTestFixture() :
        subroutineDeclaration("subroutine foo(bar)"),
        subroutineDeclarationStream(subroutineDeclaration),
        functionDeclaration("function foo(bar)"),
        variableDeclaration("integer :: foo"),
        indentedVariableDeclaration("    integer :: foo"),
        multiLineFunctionDeclaration("function foo(bar, &"),
        multiLineVariableDeclaration("integer :: foo, &")
{}

void FBlackLineTestFixture::SetUp() {
    // Setup
}

void FBlackLineTestFixture::TearDown() {
    // Cleanup
}
