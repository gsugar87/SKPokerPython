#include <Python.h>
#include <iostream>
#include <cstdio>
#include <ctime>
#include "SevenEval.h"
#include "SevenEval.cpp"
#include <vector>
#include "FiveEval.h"
#include "FiveEval.cpp"
#include "weightTable.cpp"
#include "weightTable.h"

using namespace std;

WeightTable weightTable = WeightTable();
SevenEval const eval7;
FiveEval const eval5;

int getInitialRank(vector<int> ourCards, vector<int> boardCards){
    int ourHandInitialRank = 0;
    int numBoardCards = boardCards.size();
    if (numBoardCards == 4){
        // do an iteration of all board possibilities to get best rank
        int handRank1 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[0], boardCards[1], boardCards[2]);
        int handRank2 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[0], boardCards[1], boardCards[3]);
        int handRank3 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[0], boardCards[2], boardCards[3]);
        int handRank4 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[1], boardCards[2], boardCards[3]);
        int handRank5 = eval5.GetRank(ourCards[0], boardCards[0], boardCards[1], boardCards[2], boardCards[3]);
        int handRank6 = eval5.GetRank(ourCards[1], boardCards[0], boardCards[1], boardCards[2], boardCards[3]);
        int handRanks[] = {handRank1, handRank2 , handRank3, handRank4, handRank5, handRank6};
        for (int i=0; i<6; i++){
            ourHandInitialRank = max(ourHandInitialRank, handRanks[i]);
        }
    } else if (numBoardCards == 5){
        int handRank1 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[0], boardCards[1], boardCards[2]);
        int handRank2 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[0], boardCards[1], boardCards[3]);
        int handRank3 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[0], boardCards[1], boardCards[4]);
        int handRank4 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[0], boardCards[2], boardCards[3]);
        int handRank5 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[0], boardCards[2], boardCards[4]);
        int handRank6 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[0], boardCards[3], boardCards[4]);
        int handRank7 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[1], boardCards[2], boardCards[3]);
        int handRank8 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[1], boardCards[2], boardCards[4]);
        int handRank9 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[1], boardCards[3], boardCards[4]);
        int handRank10 = eval5.GetRank(ourCards[0], boardCards[0], boardCards[1], boardCards[2], boardCards[3]);
        int handRank11 = eval5.GetRank(ourCards[0], boardCards[0], boardCards[1], boardCards[2], boardCards[4]);
        int handRank12 = eval5.GetRank(ourCards[0], boardCards[0], boardCards[1], boardCards[3], boardCards[4]);
        int handRank13 = eval5.GetRank(ourCards[0], boardCards[0], boardCards[2], boardCards[3], boardCards[4]);
        int handRank14 = eval5.GetRank(ourCards[0], boardCards[1], boardCards[2], boardCards[3], boardCards[4]);
        int handRank15 = eval5.GetRank(ourCards[1], boardCards[0], boardCards[1], boardCards[2], boardCards[3]);
        int handRank16 = eval5.GetRank(ourCards[1], boardCards[0], boardCards[1], boardCards[2], boardCards[4]);
        int handRank17 = eval5.GetRank(ourCards[1], boardCards[0], boardCards[1], boardCards[3], boardCards[4]);
        int handRank18 = eval5.GetRank(ourCards[1], boardCards[0], boardCards[2], boardCards[3], boardCards[4]);
        int handRank19 = eval5.GetRank(ourCards[1], boardCards[1], boardCards[2], boardCards[3], boardCards[4]);
        int handRank20 = eval5.GetRank(boardCards[0], boardCards[1], boardCards[2], boardCards[3], boardCards[4]);
        int handRank21 = eval5.GetRank(ourCards[0], ourCards[1], boardCards[2], boardCards[3], boardCards[4]);
        int handRanks[] = {handRank1, handRank2 , handRank3, handRank4, handRank5, handRank6,
                           handRank7, handRank8, handRank9, handRank10, handRank11, handRank12,
                           handRank13, handRank14, handRank15, handRank16, handRank17, handRank18,
                           handRank19, handRank20, handRank21};
        for (int i=0; i<21; i++){
            ourHandInitialRank = max(ourHandInitialRank, handRanks[i]);
        }
    } else {
        ourHandInitialRank = eval5.GetRank(ourCards[0], ourCards[1], boardCards[0], boardCards[1], boardCards[2]);
    }
    return ourHandInitialRank;
}

// Note the inputs must be between 0-51 (0 is As, 3 is Ac)
static PyObject* evaluate(PyObject* self, PyObject *args){
    // This is for the flop (need to generate 2 board cards)
    int oppHand1, oppHand2, board1, board2, board3, board4, board5;

    int ourHandInitialRank;
    int oppHandInitialRank;

    float oppHandWeight;

    vector< vector<double> > hp(3, vector<double>(3,1));
    vector<double> hpTotal(3);
    vector<double> hpTotalPotential(3);
    int index;
    int aheadIndex = 0;
    int tiedIndex = 1;
    int behindIndex =2;

    int j = 0;
    for (int i=0;i<3;i++){
        for (j=0;j<3;j++){
            hp[i][j] = 0;
        }
        hpTotal[i] = 0;
    }

    short unsigned opp_ranking;
    short unsigned our_ranking;

    PyObject * handListObj;
    PyObject * boardListObj;
    PyObject * weightsListObj = NULL;
    PyObject * floatObj;
    PyObject * weightRowObj;
    if (!PyArg_ParseTuple(args, "OO|O", &handListObj, &boardListObj, &weightsListObj)) return NULL;

    int numLinesBoard = PyList_GET_SIZE(boardListObj);

    vector<int> ourCards;
    vector<int> oppCards;
    vector<int> boardCards;
    int dummyCard;
    vector< vector<double> > weights;
    for (int i=0; i<2; i++){
        floatObj = PyList_GetItem(handListObj, i);
        dummyCard = PyLong_AsLong(floatObj);
        if (dummyCard<0){
            dummyCard = 0;
        }
        ourCards.push_back(dummyCard);
        oppCards.push_back(dummyCard);
    }
    for (int i=0; i<numLinesBoard; i++){
        floatObj = PyList_GetItem(boardListObj, i);
        boardCards.push_back(PyLong_AsLong(floatObj));
    }
    // See if we should add the weights
    if (NULL != weightsListObj) {
        int numLinesWeights = PyList_GET_SIZE(weightsListObj);
        for (int i = 0; i < numLinesWeights; i++) {
            floatObj = PyList_GetItem(weightsListObj, i);
            int numLinesWeightRow = PyList_Size(floatObj);
            vector<double> weightRow;
            for (int j = 0; j < numLinesWeightRow; j++) {
                weightRowObj = PyList_GetItem(floatObj, j);
                weightRow.push_back(PyFloat_AsDouble(weightRowObj));
            }
            weights.push_back(weightRow);
        }
        // set the table weights
        weightTable.setAllWeights(weights);
    }
    else{
        // recall the weight table to reset the weights!
        weightTable = WeightTable();
    }
    // return Py_BuildValue("f", PyFloat_AsDouble(weightRowObj));

    board1 = boardCards[0];
    board2 = boardCards[1];
    board3 = boardCards[2];
    if (numLinesBoard >= 4){
        board4 = boardCards[3];
    }
    if (numLinesBoard == 5){
        board5 = boardCards[4];
    }
    ourHandInitialRank = getInitialRank(ourCards, boardCards);
    // make opponent's hand [0-51]
    for (oppHand1 = 0; oppHand1<52; oppHand1++){
        if (oppHand1 == ourCards[0] or oppHand1 == ourCards[1] or oppHand1 == board1 or oppHand1 == board2 or
            oppHand1 == board3) continue;
        // check if we have river and turn cards too...
        if (numLinesBoard == 4 and oppHand1 == board4) continue;
        if (numLinesBoard == 5 and oppHand1 == board5) continue;
        oppCards[0] = oppHand1;
        for (int oppHand2 = oppHand1+1; oppHand2<52; oppHand2++){
            if (oppHand2 == ourCards[0] or oppHand2 == ourCards[1] or oppHand2 == board1 or oppHand2 == board2 or
                oppHand2 == board3) continue;
            // check if we have river and turn cards too...
            if (numLinesBoard == 4 and oppHand2 == board4) continue;
            if (numLinesBoard == 5 and oppHand2 == board5) continue;
            oppCards[1] = oppHand2;
            // get the weight for the opponent's hand
            oppHandWeight = weightTable.table[weightTable.cardsToHandKey(oppHand1,oppHand2)][weightTable.cardsToSuitKey(oppHand1,oppHand2)];
            // get the opponent's 5 card possibility
            oppHandInitialRank = getInitialRank(oppCards, boardCards);
            if (oppHandInitialRank < ourHandInitialRank){
                index = aheadIndex;
            }else if (oppHandInitialRank == ourHandInitialRank){
                index = tiedIndex;
            }else{
                index = behindIndex;
            }
            hpTotal[index] += oppHandWeight;
            // go through every board possibility (see if it is the turn or not)
            if (numLinesBoard == 4){
                for (board5=0; board5<52; board5++){
                    if (board5 == ourCards[0] or board5 == ourCards[1] or board5 == oppHand1 or board5 == oppHand2 or
                        board5 == board1 or board5 == board2 or board5 == board3 or board5 == board4) continue;
                    // see what the rankings are!
                    our_ranking = eval7.GetRank(ourCards[0], ourCards[1], board1, board2, board3, board4, board5);
                    opp_ranking = eval7.GetRank(oppHand1, oppHand2, board1, board2, board3, board4, board5);
                    if (our_ranking>opp_ranking){
                        hp[index][aheadIndex] += oppHandWeight;
                        hpTotalPotential[aheadIndex] += oppHandWeight;
                    }else if (our_ranking==opp_ranking){
                        hp[index][tiedIndex] += oppHandWeight;
                        hpTotalPotential[tiedIndex] += oppHandWeight;
                    }else{
                        hp[index][behindIndex] += oppHandWeight;
                        hpTotalPotential[behindIndex] += oppHandWeight;
                    }
                }
            } else if (numLinesBoard == 3){
                for (board4 = 0; board4 < 52; board4++) {
                    if (board4 == ourCards[0] or board4 == ourCards[1] or board4 == oppHand1 or board4 == oppHand2 or
                        board4 == board1 or board4 == board2 or board4 == board3)
                        continue;
                    for (board5 = board4 + 1; board5 < 52; board5++) {
                        if (board5 == ourCards[0] or board5 == ourCards[1] or board5 == oppHand1 or board5 == oppHand2 or
                            board5 == board1 or board5 == board2 or board5 == board3)
                            continue;
                        // see what the rankings are!
                        our_ranking = eval7.GetRank(ourCards[0], ourCards[1], board1, board2, board3, board4, board5);
                        opp_ranking = eval7.GetRank(oppHand1, oppHand2, board1, board2, board3, board4, board5);
                        if (our_ranking>opp_ranking){
                            hp[index][aheadIndex] += oppHandWeight;
                            hpTotalPotential[aheadIndex] += oppHandWeight;
                        }else if (our_ranking==opp_ranking){
                            hp[index][tiedIndex] += oppHandWeight;
                            hpTotalPotential[tiedIndex] += oppHandWeight;
                        }else{
                            hp[index][behindIndex] += oppHandWeight;
                            hpTotalPotential[behindIndex] += oppHandWeight;
                        }
                    }
                }
            } else {
                // we are on the river! no need to simulate extra board cards!
                our_ranking = eval7.GetRank(ourCards[0], ourCards[1], board1, board2, board3, board4, board5);
                opp_ranking = eval7.GetRank(oppHand1, oppHand2, board1, board2, board3, board4, board5);
                if (our_ranking > opp_ranking) {
                    hp[index][aheadIndex] += oppHandWeight;
                    hpTotalPotential[aheadIndex] += oppHandWeight;
                } else if (our_ranking == opp_ranking) {
                    hp[index][tiedIndex] += oppHandWeight;
                    hpTotalPotential[tiedIndex] += oppHandWeight;
                } else {
                    hp[index][behindIndex] += oppHandWeight;
                    hpTotalPotential[behindIndex] += oppHandWeight;
                }
            }// Done going through all possible boards
        }
    }
    // Done going through all opponents possible hands
    // Make sure there are no zeros in the hands
    float ppot;
    float npot;
    if ((hpTotal[behindIndex]+hpTotal[tiedIndex]) == 0){
        ppot = 9999999.;
    }
    else{
        ppot = (hp[behindIndex][aheadIndex]+hp[behindIndex][tiedIndex]/2.0+hp[tiedIndex][aheadIndex]/2.)/
                 (hpTotal[behindIndex]+hpTotal[tiedIndex]/2.);
    }
    if ((hpTotal[aheadIndex]+hpTotal[tiedIndex]) == 0){
        npot = 9999999.;
    }
    else{
        npot = (hp[aheadIndex][behindIndex]+hp[tiedIndex][behindIndex]/2.0+hp[aheadIndex][tiedIndex]/2.)/
               (hpTotal[aheadIndex]+hpTotal[tiedIndex]/2.);
    }

    return Py_BuildValue("ffffffff", hpTotal[aheadIndex], hpTotal[tiedIndex], hpTotal[behindIndex],
                         hpTotalPotential[aheadIndex], hpTotalPotential[tiedIndex],
                         hpTotalPotential[behindIndex], ppot, npot);
}

static PyMethodDef HandEvaluatorCPPMethods[] = {
        {"evaluate", evaluate, METH_VARARGS, "Evaulate the strength of a texas hold'em hand."},
        {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC inithandEvaluatorCPP(void)
{
    (void) Py_InitModule("handEvaluatorCPP", HandEvaluatorCPPMethods);
}

