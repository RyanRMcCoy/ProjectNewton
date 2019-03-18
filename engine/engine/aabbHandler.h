#pragma once
class aabbHandler
{
public:
	aabbHandler();

	bool overlapping(circle o1, circle o2);
	bool overlapping(circle o1, polygon o2);
	bool overlapping(polygon o1, circle o2);
	bool overlapping(polygon o1, polygon o2);
};

