//
// Created by Glenn on 3/18/2016.
//
#ifndef TEST_BUILD_WEIGHTTABLE_H
#define TEST_BUILD_WEIGHTTABLE_H

#include <iostream>
#include <set>
#include <vector>

using namespace std;
class WeightTable {
public:
    vector< vector<double> > table;
    set<int> group1;
    set<int> group2;
    set<int> group3;
    set<int> group4;
    set<int> group5;
    set<int> group6;
    set<int> group7;
    set<int> group8;
    set<int> group9;
    set<int> suited;
    set<int> pair;

    WeightTable();
    void setAllWeights(vector< vector<double> > weights);
    int cardsToHandKey(int card1, int card2);
    int cardsToSuitKey(int card1, int card2);
    // Extra functions we probably won't use since the weight table can be made in python
    int getHandGroup(int card1, int card2);
//    void setWeightsBasedOnBettingHistory(int bettingHistory);
//    void setGroupWeights(int groupNum, float weight);
};


#endif //TEST_BUILD_WEIGHTTABLE_H
