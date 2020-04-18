#include "problems/reader.hh"

int main(int, char**) {
    constexpr char PROBLEM_FILE[] = "problems/world.tsp"; // set fixed for now.
    const auto &coords = problems::read_problem(PROBLEM_FILE);
    std::cout << "Got " << coords.size() << " points from " << PROBLEM_FILE << std::endl;
    return 0;
}
