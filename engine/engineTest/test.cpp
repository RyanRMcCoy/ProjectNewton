#include "pch.h"
#include <cmath>

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

TEST(physicalObjectTest, constructorFull) {
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

TEST(physicalObjectTest, massGetterTest) {
	physicalObject obj;
	EXPECT_EQ(obj.getMass(), 0);
}

TEST(physicalObjectTest, densityGetterTest) {
	physicalObject obj;
	EXPECT_EQ(obj.getDensity(), 0);
}

TEST(physicalObjectTest, frictionGetterTest) {
	physicalObject obj;
	EXPECT_EQ(obj.getFriction(), 0);
}

//Start of material properties tests 
TEST(materialTest, circleDensityConstruct) {
	circle obj(4, vector2(0, 0), 2);
	EXPECT_EQ(round(obj.getMass()), 100);
}

TEST(materialTest, circleSetDensity) {
	circle obj(4, vector2(0, 0));
	EXPECT_EQ(round(obj.getMass()), 50);
	obj.setDensity(2);
	EXPECT_EQ(round(obj.getMass()), 100);
}

TEST(materialTest, circleSetMass) {
	circle obj(4, vector2(0, 0));
	EXPECT_EQ(round(obj.getMass()), 50);
	obj.setMass(100.48);
	EXPECT_EQ(obj.getDensity(), 2);
}

TEST(materialTest, polySetDensity) {
	vector2 vert[3] = {vector2(0, 0), vector2(3, 0), vector2(0, 4) };
	polygon obj(3, vert);
	EXPECT_EQ(round(obj.getMass()), 6);
	obj.setDensity(2);
	EXPECT_EQ(round(obj.getMass()), 12);
}

TEST(materialTest, polyArea) {
	vector2 vert[3] = { vector2(0, 0), vector2(3, 0), vector2(0, 4) };
	polygon obj(3, vert);
	EXPECT_EQ(obj.getArea(), 6);
}

TEST(materialTest, polySetMass) {
	circle obj(4, vector2(0, 0));
	EXPECT_EQ(round(obj.getMass()), 50);
	obj.setMass(100.48);
	EXPECT_EQ(obj.getDensity(), 2);
}

TEST(materialTest, RectDensityConstruct) {
	rectangle obj(2, 2, vector2(4, 3), 2);
	EXPECT_EQ(obj.getMass(), 8);
}

TEST(materialTest, RectSetDensity) {
	rectangle obj(2, 2, vector2(4, 3));
	EXPECT_EQ(obj.getMass(), 4);
	obj.setDensity(2);
	EXPECT_EQ(obj.getMass(), 8);
}

TEST(materialTest, RectSetMass) {
	rectangle obj(2, 2, vector2(4, 3));
	EXPECT_EQ(obj.getMass(), 4);
	obj.setMass(8);
	EXPECT_EQ(obj.getDensity(), 2);
}

TEST(materialTest, circleFriction) {
	circle obj(2);
	EXPECT_EQ(obj.getFriction(), 0);
	obj.setFriction(1);
	EXPECT_EQ(obj.getFriction(), 1);
}

TEST(materialTest, rectFriction) {
	rectangle obj(2, 2);
	EXPECT_EQ(obj.getFriction(), 0);
	obj.setFriction(1);
	EXPECT_EQ(obj.getFriction(), 1);
}
//Friction for both

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

TEST(circleTest, getArea) {
	circle obj(5, vector2());
	EXPECT_EQ(obj.getArea(), 3.14 * pow(5, 2));
}

//Start of Rectangle Tests
TEST(rectangleTest, defaultConstructor) {
	rectangle obj;
	EXPECT_TRUE(obj.getPosition() == vector2());
	EXPECT_EQ(obj.getSideX(), 0);
	EXPECT_EQ(obj.getSideY(), 0);
}

TEST(rectangleTest, constructorLens) {
	rectangle obj(6, 6);
	EXPECT_TRUE(obj.getPosition() == vector2(0, 0));
	EXPECT_EQ(obj.getSideX(), 6);
	EXPECT_EQ(obj.getSideY(), 6);
}

TEST(rectangleTest, constructorLensPos) {
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

TEST(rectangleTest, getArea) {
	rectangle obj(5, 5, vector2());

	EXPECT_EQ(obj.getArea(), 25);
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
	int i = 0;
	circle circ;
	EXPECT_TRUE(*obj.getObj() == (physicalObject) circ);
	EXPECT_EQ(obj.getMagnitude(), 0);
}

TEST(forceTest, objConstructor) {
	force obj(&circle(2, vector2(5, 5)));
	EXPECT_TRUE(*obj.getObj() == circle(2, vector2(5, 5)));
	EXPECT_EQ(obj.getMagnitude(), 0);
}

TEST(forceTest, vectorConstructor) {
	force obj(vector2(3, 4));
	circle target(1);
	target.setAcceleration(vector2(3, 4));
	EXPECT_TRUE(*obj.getObj() == target);
	EXPECT_EQ(obj.getMagnitude(), 5);
}

TEST(forceTest, fullConstructor) {
	force  obj(&circle(2, vector2(5, 5)), vector2(3, 4));
	circle target = circle(2, vector2(5, 5));
	target.setAcceleration(vector2(3, 4) / 12.56);
	EXPECT_TRUE(*obj.getObj() == target);
	EXPECT_EQ(obj.getMagnitude(), 5);
}

TEST(forceTest, setObj) {
	force obj;
	obj.setObj(&circle(2, vector2(5, 5)));
	EXPECT_TRUE(*obj.getObj() == circle(2, vector2(5, 5)));
	EXPECT_EQ(obj.getMagnitude(), 0);
}

TEST(forceTest, setVector) {
	force obj;
	obj.setVector(vector2(3, 4));
	circle target = circle();
	target.setAcceleration(vector2(3, 4));
	EXPECT_TRUE(*obj.getObj() == target);
	float mag_targ = obj.getMagnitude();
	EXPECT_EQ(mag_targ, 5);
}

TEST(forceTest, setMag) {
	force obj(vector2(1, 1));	
	obj.setMagnitude(5);
	EXPECT_EQ(obj.getMagnitude(), 5);
}

/*TEST(forceTest, getVector) {
	force obj(&circle(2, vector2(5, 5)), vector2(3, 4));
	EXPECT_EQ(obj.getVector(), vector2(3, 4));
}*/
	
/*TEST(forceTest, remove) {
	force obj(&circle(2, vector2(5, 5)), vector2(3, 4));
	EXPECT_EQ(obj.getObj()->getAcceleration(), vector2(0, 0));
}*/

// Start of SatHandler circle tests
TEST(satHandlerTest, circle_circle_Overlap) {
	satHandler collisionHandler;
	circle c1(5, vector2());
	circle c2(5, vector2(9, 0));
	EXPECT_TRUE(collisionHandler.overlapping(c1, c2) == vector2(-1, 0));
}

TEST(satHandlerTest, circle_circle_Overlap2) {
	satHandler collisionHandler;
	circle c1(5, vector2());
	circle c2(5, vector2(-5, 0));
	EXPECT_TRUE(collisionHandler.overlapping(c1, c2) == vector2(5, 0));
}

TEST(satHandlerTest, circle_circle_Touch) {
	satHandler collisionHandler;
	circle c1(15, vector2());
	circle c2(15, vector2(0, 30));
	EXPECT_TRUE(collisionHandler.overlapping(c1, c2) == vector2(0, 0));
}

TEST(satHandlerTest, circle_circle_NoOverlap) {
	satHandler collisionHandler;
	circle c1(5, vector2());
	circle c2(5, vector2(0, 11));
	EXPECT_TRUE(collisionHandler.overlapping(c1, c2) == vector2(0, 0));
}

// Start of SatHandler circle-rectangle tests
TEST(satHandlerTest, rectangle_circle_Overlap) {
	satHandler collisionHandler;
	circle c(5, vector2());
	rectangle r(vector2(10, 10), vector2(5, 0));
	vector2 overlap = collisionHandler.overlapping(c, r);
	cout << overlap.toString() << endl;
	EXPECT_TRUE(collisionHandler.overlapping(c, r) == vector2(-5, 0));
}

TEST(satHandlerTest, rectangle_circle_Overlap2) {
	satHandler collisionHandler;
	circle c(1, vector2());
	rectangle r(vector2(2, 2), vector2());
	EXPECT_TRUE(collisionHandler.overlapping(c, r) == vector2(0, 2));
}

TEST(satHandlerTest, rectangle_circle_Touch) {
	satHandler collisionHandler;
	circle c(1, vector2(0, -6));
	rectangle r(vector2(10, 10), vector2(0, -12));
	EXPECT_TRUE(collisionHandler.overlapping(c, r) == vector2(0, 0));
}

TEST(satHandlerTest, rectangle_circle_NoOverlap) {
	satHandler collisionHandler;
	circle c(50, vector2(1000, 0));
	rectangle r(vector2(100, 100), vector2(0, -2500));
	EXPECT_TRUE(collisionHandler.overlapping(c, r) == vector2(0, 0));
}

// Start of SatHandler triangle-circle tests

TEST(satHandlerTest, triangle_circle_Overlap) {
	satHandler collisionHandler;
	circle c(50);
	vector2 points[3] = {vector2(0, 100), vector2(100, 0), vector2(0, 0)};
	polygon t(3, points, vector2(-50, -50));
	vector2 overlap = collisionHandler.overlapping(c, t);
	cout << overlap.toString() << endl;
	EXPECT_TRUE(collisionHandler.overlapping(c, t).unit() == vector2(sqrt(2) / 2, sqrt(2) / 2));
}

// Start of SatHandler rectangle-rectangle tests
TEST(satHandlerTest, rectangle_rectangle_Overlap) {
	satHandler collisionHandler;
	rectangle r1(vector2(10, 10), vector2(5, 0));
	rectangle r2(vector2(10, 10));
	EXPECT_TRUE(collisionHandler.overlapping(r1, r2) == vector2(5, 0));
}

TEST(satHandlerTest, rectangle_rectangle_Overlap2) {
	satHandler collisionHandler;
	rectangle r1(vector2(10, 10));
	rectangle r2(vector2(20, 10), vector2(5, 0));
	EXPECT_TRUE(collisionHandler.overlapping(r1, r2) == vector2(0, 10));
}

TEST(satHandlerTest, rectangle_rectangle_Touch) {
	satHandler collisionHandler;
	rectangle r1(vector2(10, 10));
	rectangle r2(vector2(20, 10), vector2(5, 10));
	EXPECT_TRUE(collisionHandler.overlapping(r1, r2) == vector2(0, 0));
}

TEST(satHandlerTest, rectangle_rectangle_NoOverlap) {
	satHandler collisionHandler;
	rectangle r1(vector2(10, 10), vector2(500, 0));
	rectangle r2(vector2(10, 10));
	EXPECT_TRUE(collisionHandler.overlapping(r1, r2) == vector2(0, 0));
}