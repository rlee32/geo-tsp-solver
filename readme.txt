This is an implementation of k-opt, using S2 for to dramatically increase efficiency, something like O(n^k) for standard k-opt to O(n * log(n) ^ (k - 1)).

All coordinates are immediately converted to radians from input, to avoid recomputing from degrees during run time.

Style notes:
1. References and pointers are left-associated (int &i instead of int& i).
2. PascalCase for custom type names, snake_case for everything else.
3. Namespace follows directory structure. Namespaces will be made for a header name if contents of header are not named the same as header.
4. Headers have .hh extension and source files have .cc extension.
5. Compile-time constants are capitilized snake_case.
6. Braces start inline, and end on a separate line.
