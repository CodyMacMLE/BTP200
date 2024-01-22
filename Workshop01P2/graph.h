#ifndef NAMESPACE_GRAPH_H // replace with relevant names, each header should have its own header guard, unique in the ENTIRE project
#define NAMESPACE_GRAPH_H

// Cody MacDonald
// 159702232
// cmacdonald33@myseneca.ca
// January 19th, 2024

namespace seneca
{
	/// <summary>
		/// Fills the samples array with the values read from keyboard.
		/// </summary>
		/// <param name="samples">the array to be filled with data</param>
		/// <param name="noOfSamples">the maximum number of values to read from keyboard</param>
	void getSamples(int samples[], int noOfSamples);

	/// <summary>
		/// Search in a collection of numbers, the biggest value.
		/// </summary>
		/// <param name="arr">an array representing the collection of integers</param>
		/// <param name="arrSize">the number of integers in the collection</param>
		/// <returns>the largest value from the array</returns>
	int findMax(int arr[], int arrSize);

	/// <summary>
		/// Prints a scaled bar relevant to the maximum value in the samples array.
		/// </summary>
		/// <param name="val">the of the sample to print</param>
		/// <param name="max">the biggest sample in the collection</param>
	void printSampleBar(int val, int max);

	/// <summary>
		/// Draw a graph, allowing the user to visually compare the samples.
		/// </summary>
		/// <param name="samples">the collection of samples to be drawn</param>
		/// <param name="noOfSamples">the number of samples in the collection</param>
		/// <param name="label">the name of the graph</param>
	void printGraph(int samples[], int noOfSamples, const char* label);
}
#endif