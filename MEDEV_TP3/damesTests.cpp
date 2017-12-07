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

TEST_F(DamesTests,test_deplacement_valide){
	const int x = 0;
	const int y = 3;
	const int u = 1;
	const int v = 4;
	EXPECT_EQ(true,jeu.deplacement(x,y,u,v)); 
}

TEST_F(DamesTests,test_deplacement_hors_plateau){
        const int x = 0;
        const int y = 3;
        const int u = -1;
        const int v = 4;
        EXPECT_EQ(false,jeu.deplacement(x,y,u,v));
}

TEST_F(DamesTests,test_deplacement_impossible){
        const int x = 0;
        const int y = 3;
        const int u = 1;
        const int v = 2;
        EXPECT_EQ(false,jeu.deplacement(x,y,u,v));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
