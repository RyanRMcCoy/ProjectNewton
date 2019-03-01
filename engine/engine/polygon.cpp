#include "pch.h"
#include "polygon.h"
#include "vector2.h"
#include "vertex.h"

polygon::polygon(int s) : sides(s) {}
polygon::polygon(int s, vertex r) : sides(s), root(r) {}

