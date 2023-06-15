#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//opening files and setting var values
	ifstream itemFile;
	itemFile.open("Program2Input.txt", ios::in);
	int numItems = 0;
	float idealUtility = 1000.0;
	float utilityCheck = 0;
	float itemWeight = 0;
	float totalWeight = 0;
	float maxWeight = 500;
	float itemUtility = 0;
	float totalUtility = 0.00;
	bool selectedItems;
	tuple<float, float, bool> item; 
	vector<tuple<float, float, bool>> allItems;

	// adding items to all items list
	while (itemFile >> itemUtility >> itemWeight)
	{
		item = make_tuple(itemUtility, itemWeight, 0);
		allItems.push_back(item);
	}

	//sort them by having the most utility
	sort(allItems.begin(), allItems.end(), greater<>());

	//picking items based on utility and weight while the file is open and the total wight is less than max weight
	for (auto& p : allItems)
	{
		//add selected item to list
		itemWeight = get<1>(p);
		itemUtility = get<0>(p);
		if (totalWeight + itemWeight <= maxWeight)
		{
			get<2>(p) = 1;
			totalWeight += itemWeight;
			totalUtility +=  itemUtility;
			numItems++;
		}
	}

	//all of my outputs
	cout << "Total Weight: " << totalWeight << endl;
	cout << "Total Utility: " << totalUtility << endl;
	cout << "Total Number of Items: " << numItems << endl;
	cout << "Selected Items (Utility, Weight): " << endl;
	//out put the select items somehow
	for (auto& p : allItems)
	{
		itemUtility = get<0>(p);
		itemWeight = get<1>(p);
		selectedItems = get<2>(p);
		if (selectedItems)
		{
			cout << itemUtility << ", " << itemWeight << "\n";

		}
	}
	itemFile.close();
	return 0;
}