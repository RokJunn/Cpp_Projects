#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

enum Color { RED, BLUE, YELLOW };

class Point {
	int x, y;
public:
	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}
	int xGetter() {
		return x;
	}
	int yGetter() {
		return y;
	}
};

class Shape {
	Color lineColor;
public:
	Color getLineColor() const { return lineColor; }
	virtual Shape* clone() const = 0;
	virtual void print() const = 0;
	virtual float getLength() const = 0;
};

class ClosedShape : public Shape {
};

class Polygon : public ClosedShape {
};

class Triangle : public Polygon {
	float area;
	float distance1, distance2, distance3;
	int x1, y1, x2, y2, x3, y3;
public:
	Triangle(Point p1, Point p2, Point p3) {
		x1 = p1.xGetter(); x2 = p2.xGetter(); x3 = p3.xGetter();
		y1 = p1.yGetter(); y2 = p2.yGetter(); y3 = p3.yGetter();
		distance1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		distance2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
		distance3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
		area = (distance1 + distance2 + distance3) / 2;
	}
	Shape* clone() const {
		return new Triangle(Point(x1, y1), Point(x2, y2), Point(x3, y3));
	}
	virtual float getLength() const {
		return area;
	}
	virtual void print() const {
		cout << "Triangle :" << " (" << x1 << "," << y1 << ")" << " (" << x2 << "," << y2 << ")" << " (" << x3 << "," << y3 << ")" << endl;
	}
};

class Rectangle : public Polygon {
	float area;
	int x1, y1, x2, y2, x3, y3, x4, y4;
public:
	Rectangle(Point p1, Point p2, Point p3, Point p4) {
		x1 = p1.xGetter(); x2 = p2.xGetter(); x3 = p3.xGetter(); x4 = p4.xGetter();
		y1 = p1.yGetter(); y2 = p2.yGetter(); y3 = p3.yGetter(); y4 = p4.yGetter();
		float distance1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		float distance2 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
		area = distance1 * distance2;
	}
	Shape* clone() const {
		return new Rectangle(Point(x1, y1), Point(x2, y2), Point(x3, y3), Point(x4, y4));
	}
	virtual float getLength() const {
		return area;
	}
	virtual void print() const {
		cout << "Rectangle :" << " (" << x1 << "," << y1 << ")" << " (" << x2 << "," << y2 << ")" << " (" << x3 << "," << y3 << ")" << " (" << x4 << "," << y4 << ")" << endl;
	}
};

class ShapeList {
	vector<Shape*> list;
public:
	void addShape(Shape* const shape) {
		list.push_back(shape->clone());
	}
	void print() const {
		for (const auto shape : list) {
			shape->print();
		}
	}
	double getTotalArea() {
		double TotalArea = 0;
		for (int i = 0; i < list.size(); i++) {
			TotalArea +=  list[i]->getLength();
		}
		return TotalArea;
	}
};

int main() {
	Point p1(0, 0), p2(0, 10), p3(20, 20), p4(20, 30);

	Shape* const r = new Rectangle(p1, p2, p3, p4);
	Shape* const t = new Triangle(p1, p2, p3);

	ShapeList list{};
	list.addShape(r);
	list.addShape(t);
	delete r;
	delete t;

	list.print();
	cout << list.getTotalArea() << endl;
}
