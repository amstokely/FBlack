include_directories(${GTEST_INCLUDE_DIRS})
set(FBLACK_LINE_TEST_SOURCES
    fblack_line_test.cc
    fblack_line_fixture.cc
)
list(TRANSFORM FBLACK_LINE_TEST_SOURCES PREPEND "${CMAKE_CURRENT_SOURCE_DIR}/")

add_executable(
        FblackLineTest
        ${FBLACK_LINE_TEST_SOURCES}
)
target_link_libraries(
        FblackLineTest PUBLIC gtest_main
)

add_test(
        NAME FblackLine_test
        COMMAND FblackLineTest --gtest_filter=*
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/cxx)

