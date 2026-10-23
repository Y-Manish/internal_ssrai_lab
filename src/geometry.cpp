#include <cmath>
#include <utility>

// 1. Converts degrees to radians
double deg2rad(double deg) {
    const double pi = 3.14159265358979323846;
    return deg * (pi / 180.0);
}

// 2. Calculates the Euclidean distance between two points (x1, y1) and (x2, y2)
double distance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

// 3. Rotates a point (x, y) counterclockwise around the origin (0, 0) by angle_deg degrees
std::pair<double, double> rotate(double x, double y, double angle_deg) {
    double rad = deg2rad(angle_deg);
    double cos_rad = std::cos(rad);
    double sin_rad = std::sin(rad);
    
    double rotated_x = x * cos_rad - y * sin_rad;
    double rotated_y = x * sin_rad + y * cos_rad;
    
    return std::make_pair(rotated_x, rotated_y);
}

