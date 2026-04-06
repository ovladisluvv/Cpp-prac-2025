#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <optional>

enum class Intersection_type {
    NOT_INTER = 0,
    INTER = 1,
    MATCH = 2
};

class Point
{
  public:
    double x, y;

    Point(double x_ = 0, double y_ = 0)
    {
        x = x_;
        y = y_;
    }
};

class Line
{
  public:
    Point p1, p2;

    Line(Point a, Point b)
    {
        p1 = a;
        p2 = b;
    }
};

std::optional<Point>
get_inter(const Line &l1, const Line &l2, Intersection_type &ans)
{
    constexpr double EPSILON = 1e-9;
    Point inter;
    double x1 = l1.p1.x, y1 = l1.p1.y;
    double x2 = l1.p2.x, y2 = l1.p2.y;
    double x3 = l2.p1.x, y3 = l2.p1.y;
    double x4 = l2.p2.x, y4 = l2.p2.y;
    double det = (x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1);

    if (std::abs(det) < EPSILON) {
        if (std::abs((y2 - y1) * (x3 - x1) - (x2 - x1) * (y3 - y1)) < EPSILON) {
            ans = Intersection_type::MATCH;
            return inter;
        }
        ans = Intersection_type::NOT_INTER;
        return std::nullopt;
    }

    inter.x = -((x1 * y2 - x2 * y1) * (x4 - x3) - (x3 * y4 - x4 * y3) * (x2 - x1)) / det;
    inter.y = ((x3 * y4 - x4 * y3) * (y2 - y1) - (x1 * y2 - x2 * y1) * (y4 - y3)) / det;
    return inter;
}

int
main()
{
    Point A, B, C, D;
    std::cin >> A.x >> A.y >> B.x >> B.y;
    std::cin >> C.x >> C.y >> D.x >> D.y;

    Line l1(A, B), l2(C, D);
    Intersection_type ans = Intersection_type::INTER;
    std::optional<Point> inter = get_inter(l1, l2, ans);

    std::cout << static_cast<int>(ans);
    if (ans == Intersection_type::INTER) {
        std::cout << ' ' << std::fixed << std::setprecision(5) << inter.value().x << ' ' << inter.value().y;
    }
    std::cout << std::endl;
}
