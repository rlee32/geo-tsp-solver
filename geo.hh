#pragma once

// Geographic coordinates.
struct Geo {
    using coord_t = double;
    coord_t lat, lon; // rad
    using cost_t = int;
    // Returns the cost / distance to 'other', in meters.
    cost_t cost(const Geo& geo);
};

