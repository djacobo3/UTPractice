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
TEST(CountLeadingTest, single_letter_password){
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(CountLeadingTest, same_letter_start){
	Password my_password;
	int actual = my_password.count_leading_characters("AAH");
	ASSERT_EQ(2, actual);
}
TEST(CountLeadingTest, both_cases){
	Password my_password;
	int actual = my_password.count_leading_characters("AaA");
	ASSERT_EQ(1, actual);
}
TEST(CountLeadingTest, separation_password){
	Password my_password;
	int actual = my_password.count_leading_characters("zzzgarazzz");
	ASSERT_EQ(3, actual);
}
TEST(CountLeadingTest, space_password){
	Password my_password;
	int actual = my_password.count_leading_characters("   ");
	ASSERT_EQ(3, actual);
}
TEST(CountLeadingTest, endline_password){
	Password my_password;
	int actual = my_password.count_leading_characters("\ntest");
	ASSERT_EQ(1, actual);
}
TEST(CountLeadingTest, empty_password){
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(CaseTest, lower_then_upper){
	Password my_password;
	bool actual = my_password.has_mixed_case("AaA");
	ASSERT_EQ(true, actual);
}
TEST(CaseTest, upper_then_lower){
	Password my_password;
	bool actual = my_password.has_mixed_case("aA");
	ASSERT_EQ(true, actual);
}
TEST(CaseTest, lower_only){
	Password my_password;
	bool actual = my_password.has_mixed_case("abc");
	ASSERT_EQ(false, actual);
}
TEST(CaseTest, lower_and_symbols){
	Password my_password;
	bool actual = my_password.has_mixed_case("abbc^%&*");
	ASSERT_EQ(false, actual);
}
TEST(CaseTest, upper_only){
	Password my_password;
	bool actual = my_password.has_mixed_case("ABC");
	ASSERT_EQ(false, actual);
}
TEST(CaseTest, upper_and_symbols){
	Password my_password;
	bool actual = my_password.has_mixed_case("ABC%$^*");
	ASSERT_EQ(false, actual);
}
TEST(CaseTest, symbols_only){
	Password my_password;
	bool actual = my_password.has_mixed_case("&%$(@%&*)");
	ASSERT_EQ(false, actual);
}

TEST(AutoPassTest, construct){
	Password my_password;
	bool actual = my_password.authenticate("ChicoCA-95929");
	ASSERT_EQ(true, actual);
}

TEST(SetTest, seven_characters){
	Password my_password;
	my_password.set("Abcdefg");
	bool actual = my_password.authenticate("Abcdefg");
	ASSERT_EQ(false, actual);
}
TEST(SetTest, eight_characters){
	Password my_password;
	my_password.set("Abcdefgh");
	bool actual = my_password.authenticate("Abcdefgh");
	ASSERT_EQ(true, actual);
}
TEST(SetTest, twenty_characters){
	Password my_password;
	my_password.set("Abcdefghijklmnopqrst");
	bool actual = my_password.authenticate("Abcdefghijklmnopqrst");
	ASSERT_EQ(true, actual);
}
TEST(SetTest, twenty_one_characters){
	Password my_password;
	my_password.set("Abcdefghijklmnopqrstu");
	bool actual = my_password.authenticate("Abcdefghijklmnopqrstu");
	ASSERT_EQ(false, actual);
}
TEST(SetTest, lower_only){
	Password my_password;
	my_password.set("passwordtest");
	bool actual = my_password.authenticate("passwordtest");
	ASSERT_EQ(false, actual);
}
TEST(SetTest, upper_only){
	Password my_password;
	my_password.set("PASSWORDTEST");
	bool actual = my_password.authenticate("PASSWORDTEST");
	ASSERT_EQ(false, actual);
}
TEST(SetTest, lower_and_upper){
	Password my_password;
	my_password.set("PasswordTest");
	bool actual = my_password.authenticate("PasswordTest");
	ASSERT_EQ(true, actual);
}
/*
TEST(SetTest, four_leading_characters){
	Password my_password;
	my_password.set("PPPPasswordTest");
	bool actual = my_password.authenticate("PPPPasswordTest");
	ASSERT_EQ(false, actual);
}
*/
/*
TEST(SetTest, in_history_already){
	Password my_password;
	my_password.set("PasswordTest");
	my_password.set("PasswordTest2");
	my_password.set("PasswordTest");
	bool actual = my_password.authenticate("PasswordTest");
	ASSERT_EQ(false, actual);
}
*/
TEST(SetTest, not_in_history){
	Password my_password;
	my_password.set("PasswordTest");
	my_password.set("PasswordTest2");
	my_password.set("PasswordTest3");
	bool actual = my_password.authenticate("PasswordTest3");
	ASSERT_EQ(true, actual);
}