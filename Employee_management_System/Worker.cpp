#include "Worker.h"

ostream& operator<<(ostream& out, const Worker& worker)
{
	cout << boolalpha;
	cout << "  " << worker.id << "\t" << worker.name;
	cout << "\t" << worker.postNum << "\t" << worker.isDepart << endl;
	return out;
}
