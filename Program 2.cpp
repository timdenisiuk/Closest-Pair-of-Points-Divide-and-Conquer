#include <iostream>
#include <fstream>
#include "ClosestPair.h"
using namespace std;

int main()
{
    ifstream infile("program2data.txt");
    ClosestPair CP;
    CP.setPoints(infile);
    CP.performAlgorithm();
}