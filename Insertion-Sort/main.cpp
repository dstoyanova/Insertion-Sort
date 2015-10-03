//
//  main.cpp
//  Insertion-Sort
//
//  Created by Desislava Stoyanova on 10/2/15.
//  Copyright © 2015 Desislava Stoyanova. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void InsertionSort(vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j+1] = vec[j];
            j = j - 1;
        }
        vec[j+1] = key;
    }
}

int main(int argc, const char * argv[]) {
    vector<int> vec;
    int number;
    // Open the file to read numbers
    ifstream file_read;
    file_read.open("nums.txt");
    while (file_read >> number) {
        vec.push_back(number);
    }
    file_read.close();
    // Insertion Sort
    InsertionSort(vec);
    // Open file to write numbers in sorted order
    ofstream file_write;
    file_write.open("nums_sorted.txt");
    for (int i = 0; i < vec.size(); i++) {
        file_write << vec[i];
        file_write << "\n";
    }
    file_write.close();
    
    return 0;
}
