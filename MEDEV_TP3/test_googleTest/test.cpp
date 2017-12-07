#include "gtest/gtest.h"
#include "fonction.h"

class SommeTest : public ::testing::Test {
	protected:
	virtual void SetUp() {
	}

	virtual void TearDown() {
	// Code here will be called immediately after each test
	// (right before the destructor).
	}
};

TEST_F(SommeTest,test_bidon){
	const int x = 4;
	const int y = 5;
	EXPECT_EQ(9,somme(x,y));
}