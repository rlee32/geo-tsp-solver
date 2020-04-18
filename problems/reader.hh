#pragma once

#include "geo.hh"

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

namespace problems {

using point_id_t = int;

std::vector<Geo> read_problem(const std::string &file_path);

} // namespace problems
