/*
 * Name: Mathew Breland
 * Date Submitted: 2/15/2023
 * Lab Section: 001
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once

#include <vector>
#include <iostream>

using namespace std;

template <class T>
int linearSearch(std::vector<T> data, T target) {

	for (int i = 0; i < data.size(); i++) {     // for loop that runs until reaches data.size

		// cout << data[i] << endl;

		if (data[i] == target) return i;        // looking for target, if i is equal to target it returns i (end of linear search)
	}

	return -1;                                  // if you get to this point, it is invalid
}


template <class T>
int binarySearch(std::vector<T> data, T target) {

    int leftValue = 0;                      // creation of the left point value
    int rightValue = data.size() - 1;       // creation of the right point value 

    while (leftValue <= rightValue) {       // while loop that runs until left is greater than the right 

        int midValue = leftValue + (rightValue - leftValue) / 2;    // algorithm used to set the mid point value

        if (data[midValue] == target) {     // first if statement if the data value using midpint is equal to the target

            return midValue;

        }

        else if (data[midValue] < target) { // second if statement if the data value using midpoint is less than the target

            leftValue = midValue + 1;

        }

        // does not work without this else
        else {

            rightValue = midValue - 1;      // else setting right value to midvalue - 1

        }

    }

    return -1; // if you get to this point, it is invalid

}
