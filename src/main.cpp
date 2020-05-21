#include "Run.h"

int main()
{
	Run* run = new Run();
	run->start();
	delete run;

	return 0;
}