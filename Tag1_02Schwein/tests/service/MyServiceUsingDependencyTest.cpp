//
// Created by JoachimWagner on 24.02.2025.
//

#include "MyServiceUsingDependencyTest.h"


TEST_F(MyServiceUsingDependencyTest, MockdemoFooFunc) {



    // Recorddmode
    EXPECT_CALL(dependencyMock, foo("HALLO"));

    // Replay

    objectUnderTest.f("hello");
}

TEST_F(MyServiceUsingDependencyTest, MockdemoFooBarFunc) {
/*
 *  size_t g(std::string value) {
        value += " Welt";
        return dependency.foobar(value) + 5;;
    }
 *
 */
    // Arrange
    // Recorddmode
    EXPECT_CALL(dependencyMock, foobar(_))
            .Times(1)
            .WillOnce(Return(2));

    EXPECT_CALL(dependencyMock, foobar("Hallo Welt"))
            .Times(1)
            .WillOnce(Return(3));


    // Replay

    // Action


    // Assertion
    EXPECT_THAT( objectUnderTest.g("Hello"), Eq(7));
    EXPECT_THAT( objectUnderTest.g("Hallo"), Eq(8));

}

TEST_F(MyServiceUsingDependencyTest, MockdemoBarFunc) {
    /*
     * long h() {
        return dependency.bar() * dependency.bar();

    }
     *
     */

    // Arrange
    // Recordmode
    EXPECT_CALL(dependencyMock, bar()).Times(1).WillOnce(Return(2));

    // Action
    const auto result = objectUnderTest.h();

    // Assertion
    EXPECT_THAT(result, Eq(4));
}
