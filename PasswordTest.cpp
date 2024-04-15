/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password){
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, same_letter_start){
	Password my_password;
	int actual = my_password.count_leading_characters("AAH");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, both_cases){
	Password my_password;
	int actual = my_password.count_leading_characters("AaA");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, separation_password){
	Password my_password;
	int actual = my_password.count_leading_characters("zzzgarazzz");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, space_password){
	Password my_password;
	int actual = my_password.count_leading_characters("   ");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, endline_password){
	Password my_password;
	int actual = my_password.count_leading_characters("\ntest");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_password){
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(CaseTest, both_cases){
	Password my_password;
	bool actual = my_password.has_mixed_case("AaA");
	ASSERT_EQ(true, actual);
}

TEST(CaseTest, lower_only){
	Password my_password;
	bool actual = my_password.has_mixed_case("abc");
	ASSERT_EQ(false, actual);
}

TEST(CaseTest, upper_only){
	Password my_password;
	bool actual = my_password.has_mixed_case("ABC");
	ASSERT_EQ(false, actual);
}

TEST(CaseTest, symbols){
	Password my_password;
	bool actual = my_password.has_mixed_case("&%$(@%&*)");
	ASSERT_EQ(false, actual);
}