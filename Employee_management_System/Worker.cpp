#include "Worker.h"

ostream& operator<<(ostream& out, const Worker& worker)
{
	cout << "  " << worker.id;
	cout << "     " << worker.name;
	cout << "     " << worker.postNum << endl;
	return out;
}
