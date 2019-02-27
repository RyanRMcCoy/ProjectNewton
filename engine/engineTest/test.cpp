#include "pch.h"

TEST(physicalObjectTest, deaultConstructor) {
	physicalObject obj;
	EXPECT_EQ(obj.getXpos(), 0);
	EXPECT_EQ(obj.getYpos(), 0);
	EXPECT_EQ(obj.getXvel(), 0);
	EXPECT_EQ(obj.getYvel(), 0);
	EXPECT_EQ(obj.getXacc(), 0);
	EXPECT_EQ(obj.getYacc(), 0);
}