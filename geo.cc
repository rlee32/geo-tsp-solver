#include "geo.hh"

#include <cmath>

//constexpr double PI = 3.14159265358979323846264;
//constexpr double DEG_TO_RAD = PI / 180.0;

Geo::cost_t Geo::cost(const Geo &other) {
    // Implementation from http://www.math.uwaterloo.ca/tsp/world/geom.html
    const coord_t dlon = lon - other.lon;
    const coord_t q1 = std::cos(other.lat) * std::sin(dlon);
    const coord_t q3 = std::sin(0.5 * dlon);
    const coord_t q4 = std::cos(0.5 * dlon);
    const coord_t dlat = lat - other.lat;
    const coord_t lat_sum = lat + other.lat;
    const coord_t q2 = std::sin(lat_sum) * q3 * q3 - std::sin(dlat) * q4 * q4;
    const coord_t q5 = std::cos(dlat) * q4 * q4 - std::cos(lat_sum) * q3 * q3;
    return static_cast<cost_t>(6378388.0 * std::atan2(std::sqrt(q1 * q1 + q2 * q2), q5) + 1.0);
}
