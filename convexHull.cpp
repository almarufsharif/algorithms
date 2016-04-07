/*
 Program for convex hull calculation
 Sample input:
	10
	1 3
	5 4
	11 1
	8 2
	14 4
	11 5
	12 8
	8 12
	7 7
	2 8
*/

#include <iostream>
#include <algorithm>
#include <vector>

struct Point{
	int x;
	int y;
	Point(int xx, int yy) : x(xx), y(yy) { }
	Point() : x(0), y(0) { }
	int operator <(const Point& P) const {
		return (x < P.x || (x == P.x && y < P.y));
	}

	void Display() {
		std::cout << "(" << x << ", " << y << ")" << std::endl;
	}
};

Point points[100];
int nSize;

int turn(const Point& A, const Point& B, const Point&C)
{
	return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}
int main()
{
	int x, y;
	Point tmp;
	std::cout << "Enter number of points: ";
	std::cin >> nSize;

	for(int i = 0; i < nSize; i++) {
		std::cin >> x >> y;
		tmp.x = x;
		tmp.y = y;
		points[i] = tmp;
	}

	std::cout << "Before sorting..." << std::endl;
	char ch = 'A';
	for(int i = 0; i < nSize; i++) {
		std::cout << ch++;
		points[i].Display();
	}

	std::cout << "After sorted..." << std::endl;
	std::sort(points, points + nSize);
	ch = 'A';
	for(int i = 0; i < nSize; i++) {
		std::cout << ch++;
		points[i].Display();
	}

	int k = 0;
	std::vector<Point> V(2 * nSize);
	for(int i = 0; i < nSize; i++) {
		while(k >= 2 && turn(V[k-2], V[k-1], points[i]) <= 0)
			k--;
		V[k++] = points[i];
	}

	//V.resize(k-1);

	std::cout << "Lower Half part of convex hull..." << std::endl;
	for(std::vector<Point>::iterator it = V.begin(); it != V.end(); it++)
		std::cout << "X = " << it->x << " Y = " << it->y << std::endl;

	// Upper half part
	for(int i = nSize - 2, t = k + 1; i >= 0; i--) {
		while( k >= t && turn (V[k-2], V[k-1], points[i]) <= 0)
			k--;
		V[k++] = points[i];
	}

	V.resize(k-1);

	std::cout << "Upper Half part of convex hull..." << std::endl;
	for(std::vector<Point>::iterator it = V.begin(); it != V.end(); it++)
		std::cout << "X = " << it->x << " Y = " << it->y << std::endl;


	return 0;
}


