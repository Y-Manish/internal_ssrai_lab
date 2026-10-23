#include <iostream>
#include <cmath>
#include <utility>
#include <cassert>

// Forward declarations of functions implemented in the static library
double deg2rad(double deg);
double distance(double x1, double y1, double x2, double y2);
std::pair<double, double> rotate(double x, double y, double angle_deg);

// Helper function for testing floating-point precision
bool is_close(double a, double b, double epsilon = 1e-6) {
    return std::abs(a - b) < epsilon;
}

int main() {
    // 1. Test deg2rad(double)
    assert(is_close(deg2rad(0.0), 0.0));
    assert(is_close(deg2rad(180.0), 3.141592653589793));
    assert(is_close(deg2rad(90.0), 1.5707963267948966));
    assert(is_close(deg2rad(-90.0), -1.5707963267948966));

    // 2. Test distance(x1, y1, x2, y2)
    assert(is_close(distance(0.0, 0.0, 0.0, 0.0), 0.0));
    assert(is_close(distance(0.0, 0.0, 3.0, 4.0), 5.0)); 
    assert(is_close(distance(-1.0, -1.0, 2.0, 3.0), 5.0));

    // 3. Test rotate(x, y, angle_deg)
    auto p1 = rotate(1.0, 0.0, 90.0);
    assert(is_close(p1.first, 0.0));
    assert(is_close(p1.second, 1.0));

    auto p2 = rotate(1.0, 0.0, 180.0);
    assert(is_close(p2.first, -1.0));
    assert(is_close(p2.second, 0.0));

    auto p3 = rotate(0.0, 0.0, 45.0);
    assert(is_close(p3.first, 0.0));
    assert(is_close(p3.second, 0.0));

    std::cout << "All tests passed!" << std::endl;
    return 0;
}

