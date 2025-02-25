//
// Created by JoachimWagner on 24.02.2025.
//

#include "MyServiceUsingDependencyTest.h"


TEST_F(MyServiceUsingDependencyTest, MockdemoFooFunc) {

/*
 *
 *  void f(std::string value) {
        transform(value.begin(), value.end(), value.begin(), ::toupper);
        dependency.foo(value);
    }
 *
 */

    // Recordmode
    EXPECT_CALL(dependencyMock, foo("HALLO"));
    //EXPECT_CALL(dependencyMock, foo(_)); Parameter laesst alle Werte zu

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


    EXPECT_CALL(dependencyMock, foobar(EndsWith("Welt")))
            .Times(2)
            .WillRepeatedly(Return(3));


    // Replay

    // Action


    // Assertion
    EXPECT_THAT( objectUnderTest.g("Hello"), Eq(8));
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
    EXPECT_CALL(dependencyMock, bar()).Times(AtLeast(1)).WillRepeatedly(Return(3));

    // Action
    const auto result = objectUnderTest.h();

    // Assertion
    EXPECT_THAT(result, Eq(9));
}
