#include "pch.h"
#include "aabbHandler.h"
#include "vector2.h"

aabbHandler::aabbHandler()
{

}

vector2 aabbHandler::overlapping(circle o1, circle o2)
{
	return vector2();
}

vector2 aabbHandler::overlapping(circle o1, polygon o2)
{
	return vector2();
}

vector2 aabbHandler::overlapping(polygon o1, circle o2)
{
	return vector2();
}

vector2 aabbHandler::overlapping(polygon o1, polygon o2)
{
	return vector2(); 
}