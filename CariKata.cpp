#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int ROW = 25;
const int COL = 25;

bool searchWord(char grid[ROW][COL], string word) {
    int len = word.length();

