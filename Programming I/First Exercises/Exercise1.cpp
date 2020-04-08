#include <iostream>

struct Coord {
	float pX;
	float pY;
};

struct Triangle {
	Coord vert1;
	Coord vert2;
	Coord vert3;
};

struct Circle {
	float radius;
	Coord center;
};

struct Square{
	Coord vert1;
	Coord vert2;
};

struct Scene {
	float width;
	float height;

	Triangle triangle1;
	Circle circle1;
	Square square1;
};

int main() {	
	return 0;
}