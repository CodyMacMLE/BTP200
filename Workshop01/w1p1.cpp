#include "io.h"
#include "graph.h"
using namespace std;
using namespace seneca;

/// <summary>
/// The main function of the program.
/// </summary>
/// <returns>Always returns 0.</returns>
int main()
{
	int noOfSamples = 0;
	int samples[MAX_NO_OF_SAMPLES] = { 0 };
	bool done = false;

	drawLine(GRAPH_WIDTH);
	drawLineWithLabel(GRAPH_WIDTH, "Welcome to SeneGraph");
	drawLine(GRAPH_WIDTH);

	while (!done)
	{
		int userChoice = menu(noOfSamples);
		switch (userChoice)
		{
		case 1:
			printMsg("Enter number of available samples: ");
			noOfSamples = getInt(1, MAX_NO_OF_SAMPLES);
			break;
		case 2:
			if (noOfSamples == 0)
			{
				printErrorMsg("Number of samples must be set first!");
			}
			else
			{
				printMsg("Please enter the sample values:\n");
				getSamples(samples, noOfSamples);
			}
			break;
		case 3:
			if (noOfSamples == 0)
			{
				printErrorMsg("Number of samples must be set first!");
			}
			else if (samples[0] == 0)
			{
				printMsg("Samples missing. Please enter the sample values.\n");
			}
			else
			{
				printGraph(samples, noOfSamples, "SeneGraph");
			}
			break;
		case 0:
			printMsg("Thank you for using SeneGraph. Bye!\n");
			done = true;
		}
	}
}