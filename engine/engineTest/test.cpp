#include "pch.h"

//Start of physical object tests
TEST(physicalObjectTest, defaultConstructor) {
	physicalObject obj;
	EXPECT_TRUE(obj.getPosition() == vector2());
	EXPECT_EQ(obj.getXpos(), 0);
	EXPECT_EQ(obj.getYpos(), 0);
	EXPECT_TRUE(obj.getVelocity() == vector2());
	EXPECT_EQ(obj.getXvel(), 0);
	EXPECT_EQ(obj.getYvel(), 0);
	EXPECT_TRUE(obj.getAcceleration() == vector2());
	EXPECT_EQ(obj.getXacc(), 0);
	EXPECT_EQ(obj.getYacc(), 0);
}

TEST(physicalObjectTest, constructorPos) {
	physicalObject obj(vector2(5, 5));
	EXPECT_TRUE(obj.getPosition() ==vector2(5, 5));
	EXPECT_EQ(obj.getXpos(), 5);
	EXPECT_EQ(obj.getYpos(), 5);
	EXPECT_TRUE(obj.getVelocity() == vector2());
	EXPECT_EQ(obj.getXvel(), 0);
	EXPECT_EQ(obj.getYvel(), 0);
	EXPECT_TRUE(obj.getAcceleration() == vector2());
	EXPECT_EQ(obj.getXacc(), 0);
	EXPECT_EQ(obj.getYacc(), 0);
}

TEST(physicalObjectTest, constructorPosVel) {
	physicalObject obj(vector2(5, 5), vector2(3, 2));
	EXPECT_TRUE(obj.getPosition() == vector2(5, 5));
	EXPECT_EQ(obj.getXpos(), 5);
	EXPECT_EQ(obj.getYpos(), 5);
	EXPECT_TRUE(obj.getVelocity() == vector2(3, 2));
	EXPECT_EQ(obj.getXvel(), 3);
	EXPECT_EQ(obj.getYvel(), 2);
	EXPECT_TRUE(obj.getAcceleration() == vector2());
	EXPECT_EQ(obj.getXacc(), 0);
	EXPECT_EQ(obj.getYacc(), 0);
}

TEST(physicalObjectTest, constructorPosVelAcc) {
	physicalObject obj(vector2(5, 5), vector2(3, 2), vector2(1, 3));
	EXPECT_TRUE(obj.getPosition() == vector2(5, 5));
	EXPECT_EQ(obj.getXpos(), 5);
	EXPECT_EQ(obj.getYpos(), 5);
	EXPECT_TRUE(obj.getVelocity() == vector2(3, 2));
	EXPECT_EQ(obj.getXvel(), 3);
	EXPECT_EQ(obj.getYvel(), 2);
	EXPECT_TRUE(obj.getAcceleration() == vector2(1, 3));
	EXPECT_EQ(obj.getXacc(), 1);
	EXPECT_EQ(obj.getYacc(), 3);
}

TEST(physicalObjectTest, setPosTest) {
	physicalObject obj;
	obj.setPosition(5, 5);
	EXPECT_TRUE(obj.getPosition() == vector2(5, 5));
	EXPECT_EQ(obj.getXpos(), 5);
	EXPECT_EQ(obj.getYpos(), 5);
}

TEST(physicalObjectTest, setVelTest) {
	physicalObject obj;
	obj.setVelocity(5, 5);
	EXPECT_TRUE(obj.getVelocity() == vector2(5, 5));
	EXPECT_EQ(obj.getXvel(), 5);
	EXPECT_EQ(obj.getYvel(), 5);
}

TEST(physicalObjectTest, setAccTest) {
	physicalObject obj;
	obj.setAcceleration(5, 5);
	EXPECT_TRUE(obj.getAcceleration() == vector2(5, 5));
	EXPECT_EQ(obj.getXacc(), 5);
	EXPECT_EQ(obj.getYacc(), 5);
}

//Start of circle tests
TEST(circleTest, defaultConstructor) {
	circle obj;
	EXPECT_TRUE(obj.getPosition() == vector2());
	EXPECT_EQ(obj.getRadius(), 0);
}

TEST(circleTest, constructorRad) {
	circle obj(5);
	EXPECT_TRUE(obj.getPosition() == vector2());
	EXPECT_EQ(obj.getRadius(), 5);
}

TEST(circleTest, constructorRadPos) {
	circle obj(5, vector2(4, 3));
	EXPECT_TRUE(obj.getPosition() == vector2(4, 3));
	EXPECT_EQ(obj.getRadius(), 5);
}

TEST(circleTest, setRadius) {
	circle obj;
	obj.setRadius(5);
	EXPECT_EQ(obj.getRadius(), 5);
}

//Start of Rectangle Tests
TEST(rectangleTest, defaultConstructor) {
	rectangle obj;
	EXPECT_TRUE(obj.getPosition() == vector2());
	EXPECT_EQ(obj.getSideX(), 0);
	EXPECT_EQ(obj.getSideY(), 0);
}

TEST(rectangleTest, constructorRad) {
	rectangle obj(6, 6);
	EXPECT_TRUE(obj.getPosition() == vector2(3, 3));
	EXPECT_EQ(obj.getSideX(), 6);
	EXPECT_EQ(obj.getSideY(), 6);
}

TEST(rectangleTest, constructorRadPos) {
	rectangle obj(6, 6, vector2(4, 3));
	EXPECT_TRUE(obj.getPosition() == vector2(4, 3));
	EXPECT_EQ(obj.getSideX(), 6);
	EXPECT_EQ(obj.getSideY(), 6);
}

TEST(rectangleTest, setSideX) {
	rectangle obj;
	obj.setSideX(6);
	EXPECT_TRUE(obj.getPosition() == vector2(3, 0));
	EXPECT_EQ(obj.getSideX(), 6);
	EXPECT_EQ(obj.getSideY(), 0);
}

TEST(rectangleTest, setSideY) {
	rectangle obj;
	obj.setSideY(6);
	EXPECT_TRUE(obj.getPosition() == vector2(0, 3));
	EXPECT_EQ(obj.getSideX(), 0);
	EXPECT_EQ(obj.getSideY(), 6);
}