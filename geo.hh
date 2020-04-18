#pragma once

// Geographic coordinates.
struct Geo {
    double lat, lon; // rad
    using cost_t = int;
    // Returns the cost / distance to 'other', in meters.
    int cost(const Geo& geo);
};

