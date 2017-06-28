#include "Utils.h"
#include "Cell.h"
#include <algorithm>
#include <cstdlib>

using namespace std;

namespace Utils {
	int distance(const Cell &a, const Cell &b) {
		return max(abs(a.column - b.column), abs(a.row - b.row));
	}

}