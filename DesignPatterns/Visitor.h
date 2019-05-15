#pragma once

#include<iostream>
#include<vector>
#include<cstdlib>


struct Point
{
    double x, y;
};
std::ostream& operator<<(std::ostream& os, Point p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

class Rectangle;
class Square;
class Circle;


class Visitor
{
public:
    virtual void Process(const Rectangle& rect) const = 0;
    virtual void Process(const Square& rect) const = 0;
    virtual void Process(const Circle& rect) const = 0;
};


class Shape
{
public:
    virtual void ProcessVisitor(std::shared_ptr<Visitor> v) const = 0;
    virtual double GetArea() const = 0;
};
class Rectangle : public Shape
{
    Point top_left;
    Point bottom_right;
public:
    Rectangle(Point top_left, Point bottom_right)
        : top_left(top_left)
        , bottom_right(bottom_right)
    {}
    Point GetTopLeft() const
    {
        return top_left;
    }
    Point GetBottomDown() const
    {
        return bottom_right;
    }
    virtual double GetArea() const
    {
        return (bottom_right.x - top_left.x) * (bottom_right.y - top_left.y);
    }
    virtual void ProcessVisitor(std::shared_ptr<Visitor> v) const
    {
        v->Process(*this);
    }
};
class Square : public Shape
{
    Point top_left;
    double width;
public:
    Square(Point top_left, double width)
        : top_left(top_left)
        , width(width)
    {}
    Point GetTopLeft() const
    {
        return top_left;
    }
    double GetWidth() const
    {
        return width;
    }
    virtual double GetArea() const
    {
        return width * width;
    }
    virtual void ProcessVisitor(std::shared_ptr<Visitor> v) const
    {
        v->Process(*this);
    }
};
class Circle : public Shape
{
    Point center;
    double r;
public:
    Circle(Point center, double r)
        : center(center)
        , r(r)
    {}
    Point GetCenter() const
    {
        return center;
    }
    double GetRadius() const
    {
        return r;
    }
    virtual double GetArea() const
    {
        return 3.14 * r * r;
    }
    virtual void ProcessVisitor(std::shared_ptr<Visitor> v) const
    {
        v->Process(*this);
    }
};


class NameVisitor : public Visitor
{
public:
    virtual void Process(const Rectangle& rect) const override
    {
        std::cout << "Rectangle" << std::endl;
    }
    virtual void Process(const Square& sq) const override
    {
        std::cout << "Square" << std::endl;
    }
    virtual void Process(const Circle& c) const override
    {
        std::cout << "Circle" << std::endl;
    }
};
class InfoVisitor : public Visitor
{
public:
    virtual void Process(const Rectangle& rect) const override
    {
        std::cout << rect.GetTopLeft() << " "
            << rect.GetBottomDown() << std::endl;
    }
    virtual void Process(const Square& sq) const override
    {
        std::cout << sq.GetTopLeft() << " " << sq.GetWidth() << std::endl;
    }
    virtual void Process(const Circle& c) const override
    {
        std::cout << c.GetCenter() << " " << c.GetRadius() << std::endl;
    }
};
class AreaVisitor : public Visitor
{
public:
    virtual void Process(const Rectangle& rect) const override
    {
        std::cout << rect.GetArea() << std::endl;
    }
    virtual void Process(const Square& sq) const override
    {
        std::cout << sq.GetArea() << std::endl;
    }
    virtual void Process(const Circle& c) const override
    {
        std::cout << c.GetArea() << std::endl;
    }
};


void Test()
{
    std::vector<std::shared_ptr<Shape>> shapes;
    for (int i = 0; i < 10; ++i)
    {
        int shape_number = rand() % 3;
        if (shape_number == 0)
        {
            Point f{ i, i };
            Point s{ i + 1, i + 1 };
            shapes.emplace_back(std::make_shared<Rectangle>(f, s));
            std::cout << "Added Rectangle" << std::endl;
        }
        else if (shape_number == 1)
        {
            Point f{ i, i };
            shapes.emplace_back(std::make_shared<Square>(f, 0.5f));
            std::cout << "Added Square" << std::endl;
        }
        else
        {
            Point f{ i, i };
            shapes.emplace_back(std::make_shared<Circle>(f, 0.5f));
            std::cout << "Added Circle" << std::endl;
        }
    }

    std::cout << "Processing NameVisitor" << std::endl;
    std::shared_ptr<Visitor> name_visitor(std::make_shared<NameVisitor>());
    for (int i = 0; i < shapes.size(); ++i)
    {
        shapes[i]->ProcessVisitor(name_visitor);
    }

    std::cout << "Processing InfoVisitor" << std::endl;
    std::shared_ptr<Visitor> info_visitor(std::make_shared<InfoVisitor>());
    for (int i = 0; i < shapes.size(); ++i)
    {
        shapes[i]->ProcessVisitor(info_visitor);
    }

    std::cout << "Processing AreaVisitor" << std::endl;
    std::shared_ptr<Visitor> area_visitor(std::make_shared<AreaVisitor>());
    for (int i = 0; i < shapes.size(); ++i)
    {
        shapes[i]->ProcessVisitor(area_visitor);
    }
}



