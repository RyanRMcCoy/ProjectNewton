///-------------------------------------------------/
///	Class: vector2
///
///	Purpose: This class provides 2 dimensional vector
///		functionality
///-------------------------------------------------/

#ifndef VECTOR2_H
#define VECTOR2_H

#include <string>

using namespace std;

class vector2
{
private:
	/// Variables: x, y
	/// Purpose: x and y component of vector respectively
	float x, y;
public:
	vector2();
	vector2(float, float);

	float getX();
	float getY();

	/// Function: magnitude
	/// Purpose: Returns magnitude or length of the vector
	float magnitude();

	/// Function: dot
	/// Purpose: Returns the dot product with v; [this • v]
	float dot(vector2 v);

	/// Function: unit
	/// Purpose: Returns a unit vector in the same direction
	vector2 unit();

	/// Function: perpendicular
	/// Purpose: Returns a vector perpendicular to this one
	vector2 perpendicular();

	/// Function: project
	/// Purpose: Projects this vector onto vector v
	vector2 project(vector2 v);

	/// Function: toString
	/// Purpose: Returns a string represenation of the vector
	string toString();

	/// Functions: operator(+, -, *, /)
	/// Purpose: Override basic mathematical operators to allow 
	///		vector math
	vector2 operator + (vector2 v);
	vector2 operator - (vector2 v);
	vector2 operator * (vector2 v);
	vector2 operator * (float f);
	vector2 operator / (vector2 v);
	vector2 operator / (float f);

	/// Functions: operator(...)
	/// Purpose: Override relational operators to allow comparisons
	///		between vectors. == and != compare based on whether the
	///		x and y values match. The others compare based on magnitude
	bool operator < (vector2 v);
	bool operator <= (vector2 v);
	bool operator == (vector2 v);
	bool operator != (vector2 v);
	bool operator >= (vector2 v);
	bool operator > (vector2 v);
};

#endif