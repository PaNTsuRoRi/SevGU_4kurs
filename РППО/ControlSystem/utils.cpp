#include "utils.h"
#include <stdexcept>
#include <limits>

using namespace std;

bool isValidValueEntered() {
	if (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;
	}
	return true;
}