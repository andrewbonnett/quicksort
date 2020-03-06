#include <iostream>
#include <string>
#include "QS.h"

using namespace std;

QS::QS() {
}

QS::~QS() {
    clear();
}

void QS::sortAll() {
    int left = 0;
    int right = numItems - 1;
    quicksort(left, right);
}
/*
Returns -1 if the array is empty, if either of the given integers
	* is out of bounds, or if the left index is not less than the right
	* index.
*/	
int QS::medianOfThree(int left, int right) {
    int middle = (left + right)/2;
    int temp = 0;
    //return -1 for the following:
    //if array is empty
    //if given integers are out of bounds
    //if left index is not less than right
    if (numItems == 0 || left < 0 || right < 0 || right <= left || right > numItems-1) {
        return -1;
    }
    if (array[left] > array[middle]) {
        temp = array[left];
        array[left] = array[middle];
        array[middle] = temp;
    }
    if (array[right] < array[middle]) {
        temp = array[right];
        array[right] = array[middle];
        array[middle] = temp;
    }
    
    if (array[middle] < array[left]) {
        temp = array[left];
        array[left] = array[middle];
        array[middle] = temp;
    }
    return middle;
}
	
int QS::partition(int left, int right, int pivotIndex) {
    int temp = 0;
    if (array == NULL || numItems == 0 || left < 0 || right < 0 || right <= left
        || right > numItems-1 || pivotIndex < left || pivotIndex > right) {
        return -1;
    }
    temp = array[pivotIndex];
    array[pivotIndex] = array[left];
    array[left] = temp;
    
    int up = left + 1;
    int down = right;
    
    do {
        while ((array[up] <= array[left]) && (up < right)) {
            up++;
        }
        while ((array[down] > array[left]) && (down > left)) {
            down--;
        }
    
        if (up < down) {
            temp = array[up];
            array[up] = array[down];
            array[down] = temp;
        }
    } while (up < down);
    
    temp = array[left];
    array[left] = array[down];
    array[down] = temp;
    
    return down;
}
	
string QS::getArray() const {
    string str = "";
    for (int i = 0; i < numItems; i++) {
        str.append(to_string(array[i]));
        if (i != numItems-1) {
            str.append(",");
        }
        
    }
    return str;
}

int QS::getSize() const {
    return numItems;
}

bool QS::addToArray(int value) {
    if (numItems == arrayCapacity) {
        return false;
    }
    else {
        array[numItems] = value;
        numItems++;//IS THIS RIGHT THO?
        return true;
    }
}

bool QS::createArray(int capacity) {
    clear();
    if (capacity < 0) { //if capacity is a negative number, return false
        return false;
    }
    arrayCapacity = capacity;
    array = new int[capacity];
    return true;
}

void QS::clear() {
        if (array != NULL) {
            delete [] array;
        }
        array = NULL;
        arrayCapacity = 0;
        numItems = 0;
}

void QS::quicksort(int left, int right) {
    if ((right - left) < 1) {
        return;
    }
    int pivot = medianOfThree(left, right);
    pivot = partition(left, right, pivot);
    quicksort(left, pivot - 1);
    quicksort(pivot + 1, right);
}