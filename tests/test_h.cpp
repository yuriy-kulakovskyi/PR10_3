#include "gtest/gtest.h"
#include "../include/functions.h"
#include "../include/structures.h"

TEST(SortByStoreTest, SortsCorrectly) {
  Product products[3] = {
    {"Product1", "StoreB", 10.0, 5, "pcs"},
    {"Product2", "StoreA", 20.0, 3, "pcs"},
    {"Product3", "StoreC", 15.0, 7, "pcs"}
  };

  SortByStore(products, 3);

  EXPECT_EQ(products[0].store, "StoreA");
  EXPECT_EQ(products[1].store, "StoreB");
  EXPECT_EQ(products[2].store, "StoreC");
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}