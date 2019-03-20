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

TEST(physicalObjectTest, constructorFull) {
	physicalObject obj(vector2(5, 5), vector2(3, 2), vector2(1, 3), 6);
	EXPECT_TRUE(obj.getPosition() == vector2(5, 5));
	EXPECT_EQ(obj.getXpos(), 5);
	EXPECT_EQ(obj.getYpos(), 5);
	EXPECT_TRUE(obj.getVelocity() == vector2(3, 2));
	EXPECT_EQ(obj.getXvel(), 3);
	EXPECT_EQ(obj.getYvel(), 2);
	EXPECT_TRUE(obj.getAcceleration() == vector2(1, 3));
	EXPECT_EQ(obj.getXacc(), 1);
	EXPECT_EQ(obj.getYacc(), 3);
	EXPECT_EQ(obj.getMass(), 6);
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

TEST(physicalObjectTest, setPosVectorTest) {
	physicalObject obj;
	obj.setPosition(vector2(5, 5));
	EXPECT_TRUE(obj.getPosition() == vector2(5, 5));
	EXPECT_EQ(obj.getXpos(), 5);
	EXPECT_EQ(obj.getYpos(), 5);
}

TEST(physicalObjectTest, setVelVectorTest) {
	physicalObject obj;
	obj.setVelocity(vector2(5, 5));
	EXPECT_TRUE(obj.getVelocity() == vector2(5, 5));
	EXPECT_EQ(obj.getXvel(), 5);
	EXPECT_EQ(obj.getYvel(), 5);
}

TEST(physicalObjectTest, setAccVectorTest) {
	physicalObject obj;
	obj.setAcceleration(vector2(5, 5));
	EXPECT_TRUE(obj.getAcceleration() == vector2(5, 5));
	EXPECT_EQ(obj.getXacc(), 5);
	EXPECT_EQ(obj.getYacc(), 5);
}

TEST(physicalObjectTest, massTest) {
	physicalObject obj;
	obj.setMass(5);
	EXPECT_EQ(obj.getMass(), 5);
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

//Start of Vector2 Tests
TEST(vector2Test, defaultConstructor) {
	vector2 obj;
	EXPECT_EQ(obj.getX(), 0);
	EXPECT_EQ(obj.getY(), 0);
}

TEST(vector2Test, coordConstructor) {
	vector2 obj(5, 5);
	EXPECT_EQ(obj.getX(), 5);
	EXPECT_EQ(obj.getY(), 5);
}

TEST(vector2Test, magnitude) {
	vector2 obj(3, 4);
	EXPECT_EQ(obj.magnitude(), 5);
}

TEST(vector2Test, operatorPlus) {
	vector2 obj1(1, 0);
	vector2 obj2(0, 1);
	vector2 target(1, 1);

	vector2 obj3 = obj1 + obj2;

	EXPECT_TRUE(obj3 == target);
}

TEST(vector2Test, operatorMinus) {
	vector2 obj1(1, 0);
	vector2 obj2(0, 1);
	vector2 target(1, -1);

	vector2 obj3 = obj1 - obj2;

	EXPECT_TRUE(obj3 == target);
}

TEST(vector2Test, operatorMultVector) {
	vector2 obj1(1, 0);
	vector2 obj2(0, 1);
	vector2 target(0, 0);

	vector2 obj3 = obj1 * obj2;

	EXPECT_TRUE(obj3 == target);
}

TEST(vector2Test, operatorMultFloat) {
	vector2 obj1(1, 0);
	float obj2 = 2;
	vector2 target(2, 0);

	vector2 obj3 = obj1 * obj2;

	EXPECT_TRUE(obj3 == target);
}

TEST(vector2Test, operatorDivVector) {
	vector2 obj1(2, 2);
	vector2 obj2(2, 2);
	vector2 target(1, 1);

	vector2 obj3 = obj1 / obj2;

	EXPECT_TRUE(obj3 == target);
}

TEST(vector2Test, operatorDivFloat) {
	vector2 obj1(2, 2);
	float obj2 = 2;
	vector2 target(1, 1);

	vector2 obj3 = obj1 / obj2;

	EXPECT_TRUE(obj3 == target);
}

TEST(vector2Test, operatorLesser) {
	vector2 obj1(0, 0);
	vector2 target(1, 1);
	
	EXPECT_TRUE(obj1 < target);
}

TEST(vector2Test, operatorGreater) {
	vector2 obj1(2, 2);
	vector2 target(1, 1);

	EXPECT_TRUE(obj1 > target);
}

TEST(vector2Test, operatorLesserEqual) {
	vector2 obj1(0, 0);
	vector2 obj2(1, 1);
	vector2 target(1, 1);

	EXPECT_TRUE(obj1 <= target);
	EXPECT_TRUE(obj2 <= target);
}

TEST(vector2Test, operatorGreaterEqual) {
	vector2 obj1(2, 2);
	vector2 obj2(1, 1);
	vector2 target(1, 1);

	EXPECT_TRUE(obj1 >= target);
	EXPECT_TRUE(obj2 >= target);
}

TEST(vector2Test, operatorDot) {
	vector2 obj1(1, 1);
	vector2 obj2(1, 1);
	float target = 2;

	float obj3 = obj1.dot(obj2);
	EXPECT_EQ(obj3, target);
}

TEST(vector2Test, operatorProject) {
	vector2 obj1(0, 5);
	vector2 obj2(1, 1);
	vector2 target(0, 1);

	vector2 obj3 = obj2.project(obj1);

	EXPECT_TRUE(obj3 == target);
}
//Start of Force Tests
TEST(forceTest, defaultConstructor) {
	force obj;
	EXPECT_TRUE(obj.getObj() == physicalObject());
	EXPECT_TRUE(obj.getVector() == obj.getObj().getAcceleration());
	EXPECT_EQ(obj.getMagnitude(), 0);
}

TEST(forceTest, objConstructor) {
	force obj(physicalObject(vector2(5, 5)));
	EXPECT_TRUE(obj.getObj() == physicalObject(vector2(5, 5)));
	EXPECT_TRUE(obj.getVector() == obj.getObj().getAcceleration());
	EXPECT_EQ(obj.getMagnitude(), 0);
}

TEST(forceTest, vectorConstructor) {
	force obj(vector2(3, 4));
	EXPECT_TRUE(obj.getObj() == 
		physicalObject(vector2(), vector2(), vector2(3, 4) / obj.getObj().getMass()));
	EXPECT_TRUE(obj.getVector() == obj.getObj().getAcceleration());
	EXPECT_EQ(obj.getMagnitude(), 5);
}

TEST(forceTest, fullConstructor) {
	force obj(physicalObject(vector2(5, 5)), vector2(3, 4));
	EXPECT_TRUE(obj.getObj() == 
		physicalObject(vector2(5, 5), vector2(), vector2(3, 4) / obj.getObj().getMass()));
	EXPECT_TRUE(obj.getVector() == obj.getObj().getAcceleration());
	EXPECT_EQ(obj.getMagnitude(), 5);
}

TEST(forceTest, setObj) {
	force obj;
	obj.setObj(physicalObject(vector2(5, 5)));
	EXPECT_TRUE(obj.getObj() == physicalObject(vector2(5, 5)));
	EXPECT_TRUE(obj.getVector() == obj.getObj().getAcceleration());
	EXPECT_EQ(obj.getMagnitude(), 0);
}

TEST(forceTest, setVector) {
	force obj;
	obj.setVector(vector2(3, 4));
	EXPECT_TRUE(obj.getObj() ==
		physicalObject(vector2(), vector2(), vector2(3, 4) / obj.getObj().getMass()));
	EXPECT_TRUE(obj.getVector() == obj.getObj().getAcceleration());
	EXPECT_EQ(obj.getMagnitude(), 5);
}

TEST(forceTest, setMag) {
	force obj(vector2(1, 1));	
	obj.setMagnitude(5);
	EXPECT_TRUE(obj.getVector() == obj.getObj().getAcceleration());
	EXPECT_EQ(obj.getMagnitude(), 5);
}