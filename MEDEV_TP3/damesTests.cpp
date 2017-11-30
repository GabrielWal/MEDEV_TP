#include "gtest/gtest.h"
#include "dames.h"

class DamesTests : public ::testing::Test {
	protected:
		Dames jeu;
	virtual void SetUp() {
		jeu = Dames();
	}

	virtual void TearDown() {
	// Code here will be called immediately after each test
	// (right before the destructor).
	}
};

TEST_F(DamesTests,test_deplacements_possibles){
	const int x = 18;
	EXPECT_EQ(x,jeu.deplacements_possibles().size());
}