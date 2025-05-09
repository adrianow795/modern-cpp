#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include <map>
#include <functional>

using namespace std;

typedef vector<shared_ptr<Shape>> Collection;

void printCollectionElements(const Collection& collection)
{
    for(Collection::const_iterator it = collection.begin(); it != collection.end(); ++it)
        if(*it)
            (*it)->print();
}

void printAreas(const Collection& collection)
{
    for(vector<shared_ptr<Shape>>::const_iterator it = collection.begin(); it != collection.end(); ++it)
        if(*it)
            cout << (*it)->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info)
{
    Collection::const_iterator iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr int fibo(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    return fibo(n-2) + fibo(n-1);
}

int fiboLoop(int n)
{
    int a = 1, b = 1;
    int result = 0;
    if(n == 0)
    {
        return 0;
    }
    if(n < 3)
    {
        return 1;
    }
    for(int i = 2; i < n; i++)
    {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main()
{
    Collection shapes {
        make_shared<Circle>(2.0), 
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
        make_shared<Square>(Color::GREEN),
        make_shared<Circle>(4.0)};
    printCollectionElements(shapes);
    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), 
              shapes.end(), 
              [](shared_ptr<Shape> first, shared_ptr<Shape> second){
                    if(first == nullptr || second == nullptr)
                        return false;
                    return (first->getArea() < second->getArea());
              });

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);
    auto perimeterBiggerThan20 = [](shared_ptr<Shape> s)
    {
        if(s)
            return (s->getPerimeter() > 20);
        return false;
    };
    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");

    auto areaLessThanX = [x=10](shared_ptr<Shape> s)
    {
        if(s)
            return (s->getArea() < 10);
        return false;
    };


    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");
    // desired behavior could be observed for n = 45
    const auto n = 20;
    constexpr auto x = fibo(n);
    auto y = fiboLoop(n);
    std::cout << "fibo(" << n << "): " << x  << ":" << y << std::endl; 
    
    std::cout << "Alignof circle: " << alignof(Circle) << std::endl;
    std::cout << "**************************************"<< std::endl;
    map<shared_ptr<Shape>, double> mapOfPer;
    //mapOfPer.emplace(shapes[0], shapes[0]->getPerimeter());
    for(const auto &el: shapes)
    {
        if(el)
        {
            mapOfPer.emplace(el, el->getPerimeter());
        }
    }

    for(auto &&[key, value]: mapOfPer)
    {
        key->print();
        std::cout << "perimenter:" << value << "\n ************** \n";
    }


    return 0;
}

