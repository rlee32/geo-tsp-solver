#include "problems/reader.hh"

namespace problems {

std::vector<Geo> read_problem(const std::string &file_path) {
    std::cout << "Reading problem file: " << file_path << std::endl;
    std::ifstream file_stream(file_path);
    if (not file_stream.is_open()) {
        throw std::runtime_error("Could not open file: " + file_path);
    }
    // header.
    size_t point_count{0};
    bool verified_geo{false};
    std::string line;
    while (not file_stream.eof()) {
        std::getline(file_stream, line);
        if (line.find("NODE_COORD_SECTION") != std::string::npos) {
            break; // header end.
        } else if (line.find("DIMENSION") != std::string::npos) {
            // point count.
            std::string point_count_string = line.substr(line.find(':') + 1);
            point_count = std::stoi(point_count_string);
            std::cout << "Number of points according to header: " << point_count << std::endl;
        } else if (line.find("EDGE_WEIGHT_TYPE") != std::string::npos) {
            constexpr char REQUIRED_EDGE_WEIGHT_TYPE[] = "GEOM";
            if (line.find(REQUIRED_EDGE_WEIGHT_TYPE) == std::string::npos) {
                throw std::runtime_error("Edge weight type is not " + std::string(REQUIRED_EDGE_WEIGHT_TYPE)
                    + ": " + line);
            } else {
                verified_geo = true;
            }
        }
    }
    if (point_count == 0) {
        throw std::runtime_error("Could not read any coordinates.");
    }
    if (!verified_geo) {
        throw std::runtime_error("Could not confirm edge weight type.");
    }

    // read coordinates.
    std::vector<Geo> geos;
    while (not file_stream.eof()) {
        if (geos.size() >= point_count) {
            break;
        }
        std::getline(file_stream, line);
        std::stringstream line_stream(line);
        point_id_t point_id{0};
        line_stream >> point_id;
        Geo::coord_t lat{0};
        line_stream >> lat;
        Geo::coord_t lon{0};
        line_stream >> lon;
        geos.push_back({lat, lon});
    }
    if (geos.size() != point_count) {
        throw std::runtime_error("Expected " + std::to_string(point_count) + " points, but got "
            + std::to_string(geos.size()) + ".");
    }
    return geos;
}

} // namespace problems
