#ifndef VECTOR2_H
#define VECTOR2_H

class vector2
{
protected:
	float x, y;
public:
	vector2();
	vector2(float xs, float ys);

	float getX();
	float getY();

	float magnitude();
	float dot(vector2 v);
	vector2 unit();
	vector2 project(vector2 v);

	vector2 operator + (vector2 v);
	vector2 operator - (vector2 v);
	vector2 operator * (vector2 v);
	vector2 operator * (float f);
	vector2 operator / (vector2 v);
	vector2 operator / (float f);

	bool operator < (vector2 v);
	bool operator <= (vector2 v);
	bool operator == (vector2 v);
	bool operator >= (vector2 v);
	bool operator > (vector2 v);
};

#endif