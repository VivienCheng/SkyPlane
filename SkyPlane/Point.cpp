#include "Point.h"


Point::Point():x_(0),y_(0){}
Point::Point(double xx, double yy): x_(xx), y_(yy) {}
Point::Point(const Point &a):x_(a.x_), y_(a.y_) {}

Point::~Point() {}

//set
void Point::X(double xx ) {  x_ = xx; }
void Point::Y(double yy ) { y_ = yy; }
void Point::SetPoint(double xx, double yy) { x_ = xx, y_ = yy; }
void Point::SetPoint(Point &a) { x_ = a.x_, y_ = a.y_; }

void Point::MoveX(double a) { x_ += a; }
void Point::MoveY(double a) { y_ += a; }



//get
double Point::X() { return x_ ; }
double Point::Y() { return y_; }
Point& Point::GetPoint() { return *this; }