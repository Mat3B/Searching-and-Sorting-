/*
 * Name: Mathew Breland
 * Date Submitted: 2/15/2023
 * Lab Section: 001
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once

#include <vector>

template <class T>
std::vector<T> mergeSort(std::vector<T> lst) {

    if (lst.size() <= 1) {  // if statement that returns if the size is invalid

        return lst;

    }

    // dividing the list into two halves (first part of merge sort)
    // all of this is done using vectors because that is what is in the given function 
    std::vector<T> leftValues(lst.begin(), lst.begin() + lst.size() / 2);
    std::vector<T> rightValues(lst.begin() + lst.size() / 2, lst.end());

    // sorting the left and right halves using recursion 
    std::vector<T> sortedLeft = mergeSort(leftValues);
    std::vector<T> sortedRight = mergeSort(rightValues);

    // doing the merge part of the merge sort 
    std::vector<T> result;
    result.reserve(sortedLeft.size() + sortedRight.size());

    // creation of two variables i and j for the while statement 
    size_t i = 0;
    size_t j = 0;

    while (i < sortedLeft.size() && j < sortedRight.size()) { // while loops that run until the size is invalid

        if (sortedLeft[i] < sortedRight[j]) { 

            result.push_back(sortedLeft[i]);   // pushing back value to result
            i++;
        }

        else {

            result.push_back(sortedRight[j]);  // pushing back value to result
            j++;
        }
    }

    while (i < sortedLeft.size()) {        // while loop that runs if the above while loop is not valid

        result.push_back(sortedLeft[i]);   // pushing back value to result
        i++;
    }

    while (j < sortedRight.size()) {       // while loop that runs if the above while loop is not valid

        result.push_back(sortedRight[j]);  // pushing back value to result
        j++;
    }

    return result;  // returning the result 
}


template <class T>
std::vector<T> quickSort(std::vector<T> lst) {

    if (lst.size() <= 1) {              // if statement that runs if the size is invalid

        return lst;                     // returning 1st if size is invalid 

    }

    // creation of a pivot using class T (it would be somewhat helpful if they would show us how to do this in lecture)
    T pivot = lst[lst.size() / 2];

    std::vector<T> leftValues, rightValues, equalValues;  // creations of vectors left right and equal
    for (const T& iter : lst) {         // pivot is essential when using a quicksort

        if (iter < pivot) {             // if the elem (vector iterator) less than pivot

            leftValues.push_back(iter);
        }

        else if (iter > pivot) {        // if the elem (vector iterator) greater than pivot

            rightValues.push_back(iter);
        }

        else {                          // else that could only run if < is false and > is false

            equalValues.push_back(iter);
        }

    }

    // sorting and combining results 
    std::vector<T> sortedLeft = quickSort(leftValues);
    std::vector<T> sortedRight = quickSort(rightValues);

    // creation of a vector called result that will store the result value 
    std::vector<T> result;

    // reserving the size of the result vector using the sorted left, equal and sorted right sizes
    result.reserve(sortedLeft.size() + equalValues.size() + sortedRight.size());

    // inserting the sorted left begin and end
    result.insert(result.end(), sortedLeft.begin(), sortedLeft.end());

    // inserting the equal begin and equal end
    result.insert(result.end(), equalValues.begin(), equalValues.end());

    // inserting the sorted right begin and end 
    result.insert(result.end(), sortedRight.begin(), sortedRight.end());

    return result;  // returning the result of the sort
}
