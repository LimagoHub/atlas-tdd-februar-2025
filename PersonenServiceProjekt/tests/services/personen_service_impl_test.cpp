//
// Created by JoachimWagner on 25.02.2025.
//

#include "personen_service_impl_test.h"

TEST_F(personen_service_impl_test, speichern__VornameZuKurz__throws_personen_service_exception){
    try {
        // Arrange
        person invalidPerson{"j", "Doe"};

        // Action
        objectUnderTest.speichern(invalidPerson);

        FAIL() << "personen_service_exception erwartet";
    } catch( const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrEq("Vorname zu kurz!"));
    }
}

TEST_F(personen_service_impl_test, speichern__NachnameZuKurz__throws_personen_service_exception){
    try {
        // Arrange
        person invalidPerson{"John", "D"};

        // Action
        objectUnderTest.speichern(invalidPerson);

        FAIL() << "personen_service_exception erwartet";
    } catch( const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrEq("Nachname zu kurz!"));
    }
}
TEST_F(personen_service_impl_test, speichern__BlacklistedPerson__throws_personen_service_exception){
    try {
        // Arrange
        person validPerson{"John", "Doe"};

        EXPECT_CALL(blackListServiceMock, isBlacklisted(_)).WillOnce(Return(true));

        // Action
        objectUnderTest.speichern(validPerson);

        FAIL() << "personen_service_exception erwartet";
    } catch( const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrEq("Person ist auf der Blacklist"));
    }
}

TEST_F(personen_service_impl_test, speichern__UnexpectedExceptionInUnderlyingService__throws_personen_service_exception){
    try {
        // Arrange
        person validPerson{"John", "Doe"};

        EXPECT_CALL(repositoryMock, save_or_update(_)).WillOnce(Throw(std::out_of_range("Upps")));

        // Action
        objectUnderTest.speichern(validPerson);

        FAIL() << "personen_service_exception erwartet";
    } catch( const personen_service_exception & ex) {
        EXPECT_THAT(ex.what(), StrEq("Datenbank nicht erreichbar"));
    }
}

TEST_F(personen_service_impl_test, speichern__HappyDay__personPassedToRepo){

        InSequence dummy;

        // Arrange
        person validPerson{"John", "Doe"};
        EXPECT_CALL(blackListServiceMock, isBlacklisted(_)).WillOnce(Return(false));
        EXPECT_CALL(repositoryMock, save_or_update(validPerson));



        // Action
        objectUnderTest.speichern(validPerson);

}

TEST_F(personen_service_impl_test, speichern__happy_day__person_passed_to_repo_overloaded) {

    InSequence dummy;
    person captured_person{};
    EXPECT_CALL(blackListServiceMock, isBlacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(repositoryMock, save_or_update(_)).WillOnce(DoAll(SaveArg<0>(&captured_person)));

    objectUnderTest.speichern("John","Mustermann");

    EXPECT_THAT( captured_person.getVorname(), AnyOf(StartsWith("J"), StartsWith("M")));
    EXPECT_THAT(captured_person.getNachname(), AnyOf(Eq("Doe"), Eq("Mustermann")));
    EXPECT_THAT(captured_person.getId(), Not(IsEmpty()));
}
