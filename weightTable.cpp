//
// Created by Glenn on 3/18/2016.
//

#include "weightTable.h"

WeightTable::WeightTable() {
    // set the indeces of suited hands
    for (int i = 13; i<25; i++) {
        suited.insert(i);
    }
    for (int i = 37; i<48; i++) {
        suited.insert(i);
    }
    for (int i = 59; i<69; i++) {
        suited.insert(i);
    }
    for (int i = 79; i<88; i++) {
        suited.insert(i);
    }
    for (int i = 97; i<105; i++) {
        suited.insert(i);
    }
    for (int i = 113; i<120; i++) {
        suited.insert(i);
    }
    for (int i = 127; i<133; i++) {
        suited.insert(i);
    }
    for (int i = 139; i<144; i++) {
        suited.insert(i);
    }
    for (int i = 149; i<153; i++) {
        suited.insert(i);
    }
    for (int i = 157; i<160; i++) {
        suited.insert(i);
    }
    suited.insert(163);
    suited.insert(164);
    suited.insert(167);
    // generate pair set
    int pairIndex = 0;
    int increment = 25;
    for (int i=0; i<12; i++){
        pair.insert(pairIndex);
        pairIndex += increment;
        increment -= 2;
    }

    // create the weight table and set all weights to 1 initially
    for (int i=0; i<169; i++){
        vector<double> row;
        if (suited.count(i) > 0){
            for (int j=0; j<4; j++){
                row.push_back(1.0);
            }
        }else if (pair.count(i) > 0){
            for (int j=0; j<6; j++){
                row.push_back(1.0);
            }
        }else{
            for (int j=0; j<16; j++){
                row.push_back(1.0);
            }
        }
        this->table.push_back(row);
    }
    // assign group values based off modified table off wikipedia
    //0-12 AA-A2u, 13-24AK-A2s
    group1.insert(0); //AA
    group2.insert(1); //AK
    group3.insert(2); //AQ
    group4.insert(3); //AJ
    group5.insert(4); //AT
    group6.insert(5); //A9
    group7.insert(6); //A8
    group7.insert(7); //A7
    group8.insert(8); //A6
    group8.insert(9);
    group8.insert(10);
    group8.insert(11);
    group8.insert(12); //A2u
    group1.insert(13); //AKs
    group2.insert(14);
    group2.insert(15);
    group3.insert(16);
    group4.insert(17);
    group4.insert(18);
    group4.insert(19);
    group5.insert(20);
    group5.insert(21);
    group5.insert(22);
    group5.insert(23);
    group5.insert(24); //A2s
    group1.insert(25); //KKu
    group4.insert(26);
    group5.insert(27);
    group6.insert(28);
    group7.insert(29);
    group8.insert(30);
    group9.insert(31);
    group9.insert(32);
    group9.insert(33);
    group9.insert(34);
    group9.insert(35);
    group9.insert(36); //K2u
    group2.insert(37); //KQs
    group3.insert(38);
    group4.insert(39);
    group6.insert(40);
    group7.insert(41);
    group7.insert(42);
    group7.insert(43);
    group7.insert(44);
    group7.insert(45);
    group7.insert(46);
    group7.insert(47); //K2s
    group1.insert(48); //QQu
    group5.insert(49); //QJu
    group6.insert(50);
    group8.insert(51);
    group9.insert(52);
    group9.insert(53);
    group9.insert(54);
    group9.insert(55);
    group9.insert(56);
    group9.insert(57);
    group9.insert(58); //Q2u
    group3.insert(59); //QJs
    group4.insert(60);
    group5.insert(61);
    group7.insert(62);
    group9.insert(63);
    group9.insert(64);
    group9.insert(65);
    group9.insert(66);
    group9.insert(67);
    group9.insert(68); //Q2s
    group1.insert(69); //JJu
    group5.insert(70); //JTu
    group7.insert(71);
    group8.insert(72);
    group9.insert(73);
    group9.insert(74);
    group9.insert(75);
    group9.insert(76);
    group9.insert(77);
    group9.insert(78); //J2u
    group3.insert(79); //JTs
    group4.insert(80);
    group6.insert(81);
    group8.insert(82);
    group9.insert(83);
    group9.insert(84);
    group9.insert(85);
    group9.insert(86);
    group9.insert(87); //J2s
    group2.insert(88); //TTu
    group7.insert(89);
    group8.insert(90);
    group9.insert(91);
    group9.insert(92);
    group9.insert(93);
    group9.insert(94);
    group9.insert(95);
    group9.insert(96); //T2u
    group4.insert(97); //T9s
    group5.insert(98);
    group7.insert(99);
    group9.insert(100);
    group9.insert(101);
    group9.insert(102);
    group9.insert(103);
    group9.insert(104); //T2s
    group3.insert(105); //99u
    group7.insert(106);
    group9.insert(107);
    group9.insert(108);
    group9.insert(109);
    group9.insert(110);
    group9.insert(111);
    group9.insert(112); //92u
    group4.insert(113); //98s
    group5.insert(114);
    group8.insert(115);
    group9.insert(116);
    group9.insert(117);
    group9.insert(118);
    group9.insert(119); //92s
    group4.insert(120); //88u
    group8.insert(121);
    group9.insert(122);
    group9.insert(123);
    group9.insert(124);
    group9.insert(125);
    group9.insert(126); //82u
    group5.insert(127); //87s
    group6.insert(128);
    group8.insert(129);
    group9.insert(130);
    group9.insert(131);
    group9.insert(132); //82s
    group5.insert(133); //77u
    group8.insert(134);
    group9.insert(135);
    group9.insert(136);
    group9.insert(137);
    group9.insert(138); //72u
    group5.insert(139); //76s
    group6.insert(140);
    group8.insert(141);
    group9.insert(142);
    group9.insert(143); //72s
    group6.insert(144); //66u
    group8.insert(145);
    group9.insert(146);
    group9.insert(147);
    group9.insert(148); //62u
    group7.insert(149); //65s
    group7.insert(150);
    group9.insert(151);
    group9.insert(152); //62s
    group6.insert(153); //55u
    group8.insert(154);
    group9.insert(155);
    group9.insert(156); //52u
    group6.insert(157); //54s
    group7.insert(158);
    group9.insert(159); //52s
    group7.insert(160); //44u
    group9.insert(161);
    group9.insert(162); //42u
    group7.insert(163); //43s
    group8.insert(164); //42s
    group7.insert(165); //33u
    group9.insert(166); //32u
    group8.insert(167); //32s
    group7.insert(168); //22u
}

int WeightTable::cardsToHandKey(int card1, int card2) {
    int val1 = 14 - card1/4;
    int val2 = 14 - card2/4;
    int suit1 = card1 % 4;
    int suit2 = card2 % 4;
    int key;
    int maxVal = max(val1, val2);
    int minVal = min(val1, val2);
    if (suit1 == suit2) {
        switch (maxVal) {
            case 3:
                key = 167;
                break;
            case 4:
                switch (minVal) {
                    case 3:
                        key = 163;
                        break;
                    case 2:
                        key = 164;
                        break;
                }
                break;
            case 5:
                switch (minVal) {
                    case 4:
                        key = 157;
                        break;
                    case 3:
                        key = 158;
                        break;
                    case 2:
                        key = 159;
                        break;
                }
                break;
            case 6:
                switch (minVal) {
                    case 5:
                        key = 149;
                        break;
                    case 4:
                        key = 150;
                        break;
                    case 3:
                        key = 151;
                        break;
                    case 2:
                        key = 152;
                        break;
                }
                break;
            case 7:
                switch (minVal) {
                    case 6:
                        key = 139;
                        break;
                    case 5:
                        key = 140;
                        break;
                    case 4:
                        key = 141;
                        break;
                    case 3:
                        key = 142;
                        break;
                    case 2:
                        key = 143;
                        break;
                }
                break;
            case 8:
                switch (minVal) {
                    case 7:
                        key = 127;
                        break;
                    case 6:
                        key = 128;
                        break;
                    case 5:
                        key = 129;
                        break;
                    case 4:
                        key = 130;
                        break;
                    case 3:
                        key = 131;
                        break;
                    case 2:
                        key = 132;
                        break;
                }
                break;
            case 9:
                switch (minVal) {
                    case 8:
                        key = 113;
                        break;
                    case 7:
                        key = 114;
                        break;
                    case 6:
                        key = 115;
                        break;
                    case 5:
                        key = 116;
                        break;
                    case 4:
                        key = 117;
                        break;
                    case 3:
                        key = 118;
                        break;
                    case 2:
                        key = 119;
                        break;
                }
                break;
            case 10:
                switch (minVal) {
                    case 9:
                        key = 97;
                        break;
                    case 8:
                        key = 98;
                        break;
                    case 7:
                        key = 99;
                        break;
                    case 6:
                        key = 100;
                        break;
                    case 5:
                        key = 101;
                        break;
                    case 4:
                        key = 101;
                        break;
                    case 3:
                        key = 103;
                        break;
                    case 2:
                        key = 104;
                        break;
                }
                break;
            case 11:
                switch (minVal) {
                    case 10:
                        key = 79;
                        break;
                    case 9:
                        key = 80;
                        break;
                    case 8:
                        key = 81;
                        break;
                    case 7:
                        key = 82;
                        break;
                    case 6:
                        key = 83;
                        break;
                    case 5:
                        key = 84;
                        break;
                    case 4:
                        key = 85;
                        break;
                    case 3:
                        key = 86;
                        break;
                    case 2:
                        key = 87;
                        break;
                }
                break;
            case 12:
                switch (minVal) {
                    case 11:
                        key = 59;
                        break;
                    case 10:
                        key = 60;
                        break;
                    case 9:
                        key = 61;
                        break;
                    case 8:
                        key = 62;
                        break;
                    case 7:
                        key = 63;
                        break;
                    case 6:
                        key = 64;
                        break;
                    case 5:
                        key = 65;
                        break;
                    case 4:
                        key = 66;
                        break;
                    case 3:
                        key = 67;
                        break;
                    case 2:
                        key = 68;
                        break;
                }
                break;
            case 13:
                switch (minVal) {
                    case 12:
                        key = 37;
                        break;
                    case 11:
                        key = 38;
                        break;
                    case 10:
                        key = 39;
                        break;
                    case 9:
                        key = 40;
                        break;
                    case 8:
                        key = 41;
                        break;
                    case 7:
                        key = 42;
                        break;
                    case 6:
                        key = 43;
                        break;
                    case 5:
                        key = 44;
                        break;
                    case 4:
                        key = 45;
                        break;
                    case 3:
                        key = 46;
                        break;
                    case 2:
                        key = 47;
                        break;
                }
                break;
            case 14:
                switch (minVal) {
                    case 13:
                        key = 13;
                    case 12:
                        key = 14;
                        break;
                    case 11:
                        key = 15;
                        break;
                    case 10:
                        key = 16;
                        break;
                    case 9:
                        key = 17;
                        break;
                    case 8:
                        key = 18;
                        break;
                    case 7:
                        key = 19;
                        break;
                    case 6:
                        key = 20;
                        break;
                    case 5:
                        key = 21;
                        break;
                    case 4:
                        key = 22;
                        break;
                    case 3:
                        key = 23;
                        break;
                    case 2:
                        key = 24;
                        break;
                }
                break;
        }
    }else{
        switch (maxVal) {
            case 2:
                key = 168;
                break;
            case 3:
                switch(minVal){
                    case 3:
                        key = 165;
                        break;
                    case 2:
                        key = 166;
                        break;
                }
                break;
            case 4:
                switch (minVal) {
                    case 4:
                        key = 160;
                        break;
                    case 3:
                        key = 161;
                        break;
                    case 2:
                        key = 162;
                        break;
                }
                break;
            case 5:
                switch (minVal) {
                    case 5:
                        key = 153;
                        break;
                    case 4:
                        key = 154;
                        break;
                    case 3:
                        key = 155;
                        break;
                    case 2:
                        key = 156;
                        break;
                }
                break;
            case 6:
                switch (minVal) {
                    case 6:
                        key = 144;
                        break;
                    case 5:
                        key = 145;
                        break;
                    case 4:
                        key = 146;
                        break;
                    case 3:
                        key = 147;
                        break;
                    case 2:
                        key = 148;
                        break;
                }
                break;
            case 7:
                switch (minVal) {
                    case 7:
                        key = 133;
                        break;
                    case 6:
                        key = 134;
                        break;
                    case 5:
                        key = 135;
                        break;
                    case 4:
                        key = 136;
                        break;
                    case 3:
                        key = 137;
                        break;
                    case 2:
                        key = 138;
                        break;
                }
                break;
            case 8:
                switch (minVal) {
                    case 8:
                        key = 120;
                        break;
                    case 7:
                        key = 121;
                        break;
                    case 6:
                        key = 122;
                        break;
                    case 5:
                        key = 123;
                        break;
                    case 4:
                        key = 124;
                        break;
                    case 3:
                        key = 125;
                        break;
                    case 2:
                        key = 126;
                        break;
                }
                break;
            case 9:
                switch (minVal) {
                    case 9:
                        key = 105;
                        break;
                    case 8:
                        key = 106;
                        break;
                    case 7:
                        key = 107;
                        break;
                    case 6:
                        key = 108;
                        break;
                    case 5:
                        key = 109;
                        break;
                    case 4:
                        key = 110;
                        break;
                    case 3:
                        key = 111;
                        break;
                    case 2:
                        key = 112;
                        break;
                }
                break;
            case 10:
                switch (minVal) {
                    case 10:
                        key = 88;
                        break;
                    case 9:
                        key = 89;
                        break;
                    case 8:
                        key = 90;
                        break;
                    case 7:
                        key = 91;
                        break;
                    case 6:
                        key = 92;
                        break;
                    case 5:
                        key = 93;
                        break;
                    case 4:
                        key = 94;
                        break;
                    case 3:
                        key = 95;
                        break;
                    case 2:
                        key = 96;
                        break;
                }
                break;
            case 11:
                switch (minVal) {
                    case 11:
                        key = 69;
                        break;
                    case 10:
                        key = 70;
                        break;
                    case 9:
                        key = 71;
                        break;
                    case 8:
                        key = 72;
                        break;
                    case 7:
                        key = 73;
                        break;
                    case 6:
                        key = 74;
                        break;
                    case 5:
                        key = 75;
                        break;
                    case 4:
                        key = 76;
                        break;
                    case 3:
                        key = 77;
                        break;
                    case 2:
                        key = 78;
                        break;
                }
                break;
            case 12:
                switch (minVal) {
                    case 12:
                        key = 48;
                        break;
                    case 11:
                        key = 49;
                        break;
                    case 10:
                        key = 50;
                        break;
                    case 9:
                        key = 51;
                        break;
                    case 8:
                        key = 52;
                        break;
                    case 7:
                        key = 53;
                        break;
                    case 6:
                        key = 54;
                        break;
                    case 5:
                        key = 55;
                        break;
                    case 4:
                        key = 56;
                        break;
                    case 3:
                        key = 57;
                        break;
                    case 2:
                        key = 58;
                        break;
                }
                break;
            case 13:
                switch (minVal) {
                    case 13:
                        key = 25;
                        break;
                    case 12:
                        key = 26;
                        break;
                    case 11:
                        key = 27;
                        break;
                    case 10:
                        key = 28;
                        break;
                    case 9:
                        key = 29;
                        break;
                    case 8:
                        key = 30;
                        break;
                    case 7:
                        key = 31;
                        break;
                    case 6:
                        key = 32;
                        break;
                    case 5:
                        key = 33;
                        break;
                    case 4:
                        key = 34;
                        break;
                    case 3:
                        key = 35;
                        break;
                    case 2:
                        key = 36;
                        break;
                }
                break;
            case 14:
                switch (minVal) {
                    case 14:
                        key = 0;
                        break;
                    case 13:
                        key = 1;
                        break;
                    case 12:
                        key = 2;
                        break;
                    case 11:
                        key = 3;
                        break;
                    case 10:
                        key = 4;
                        break;
                    case 9:
                        key = 5;
                        break;
                    case 8:
                        key = 6;
                        break;
                    case 7:
                        key = 7;
                        break;
                    case 6:
                        key = 8;
                        break;
                    case 5:
                        key = 9;
                        break;
                    case 4:
                        key = 10;
                        break;
                    case 3:
                        key = 11;
                        break;
                    case 2:
                        key = 12;
                        break;
                }
                break;
        }
    }
    return key;
}

int WeightTable::cardsToSuitKey(int card1, int card2) {
    int val1 = 14 - card1/4;
    int val2 = 14 - card2/4;
    int suit1 = card1 % 4;
    int suit2 = card2 % 4;
    int key;
    int maxVal = max(val1, val2);
    int minVal = min(val1, val2);
    int maxSuit = max(suit1, suit2);
    int minSuit = min(suit1, suit2);
    // see if we are suited
    if (suit1==suit2){
        return suit1;
    }
    if (val1==val2){
        switch(minSuit){
            case 0:
                switch(maxSuit){
                    case 1:
                        return 0;
                    case 2:
                        return 1;
                    case 3:
                        return 2;
                }
            case 1:
                switch(maxSuit){
                    case 2:
                        return 3;
                    case 3:
                        return 4;
                }
            case 2:
                return 5;
        }
    }
    // we are in an unsuited non-pair situation
    int maxValSuit;
    int minValSuit;
    if (val1==maxVal){
        maxValSuit = suit1;
        minValSuit = suit2;
    }
    else{
        maxValSuit = suit2;
        minValSuit = suit1;
    }
    switch(maxValSuit){
        case 0:
            switch(minValSuit){
                case 1:
                    return 0;
                case 2:
                    return 1;
                case 3:
                    return 2;
            }
        case 1:
            switch(minValSuit){
                case 0:
                    return 3;
                case 2:
                    return 4;
                case 3:
                    return 5;
            }
        case 2:
            switch(minValSuit){
                case 0:
                    return 6;
                case 1:
                    return 7;
                case 3:
                    return 8;
            }
        case 3:
            switch(minValSuit){
                case 0:
                    return 9;
                case 1:
                    return 10;
                case 2:
                    return 11;
            }
    }
    return -1;
}

void WeightTable::setAllWeights(vector< vector<double> > weights){
    int numWeightRows = weights.size();
    for (int i=0; i<numWeightRows; i++){
        this->table[i] = weights[i];
    }
}

int WeightTable::getHandGroup(int card1, int card2) {
    int hand = cardsToHandKey(card1, card2);
    if (this->group1.count(hand) > 0) return 1;
    if (this->group2.count(hand) > 0) return 2;
    if (this->group3.count(hand) > 0) return 3;
    if (this->group4.count(hand) > 0) return 4;
    if (this->group5.count(hand) > 0) return 5;
    if (this->group6.count(hand) > 0) return 6;
    if (this->group7.count(hand) > 0) return 7;
    if (this->group8.count(hand) > 0) return 8;
    return 9;
}

//void WeightTable::setGroupWeights(int groupNum, float weight) {
//    std::set<int>:: iterator it;
//    if (groupNum == 1) {
//        for (it = this->group1.begin(); it != this->group1.end(); ++it) {
//            int hand = *it;
//            this->table[hand] = weight;
//        }
//    }else if (groupNum == 2) {
//        for (it = this->group2.begin(); it != this->group2.end(); ++it) {
//            int hand = *it;
//            this->table[hand] = weight;
//        }
//    }else if (groupNum == 3) {
//        for (it = this->group3.begin(); it != this->group3.end(); ++it) {
//            int hand = *it;
//            this->table[hand] = weight;
//        }
//    } else if (groupNum == 4) {
//        for (it = this->group4.begin(); it != this->group4.end(); ++it) {
//            int hand = *it;
//            this->table[hand] = weight;
//        }
//    } else if (groupNum == 5) {
//        for (it = this->group5.begin(); it != this->group5.end(); ++it) {
//            int hand = *it;
//            this->table[hand] = weight;
//        }
//    } else if (groupNum == 6) {
//        for (it = this->group6.begin(); it != this->group6.end(); ++it) {
//            int hand = *it;
//            this->table[hand] = weight;
//        }
//    } else if (groupNum == 7) {
//        for (it = this->group7.begin(); it != this->group7.end(); ++it) {
//            int hand = *it;
//            this->table[hand] = weight;
//        }
//    } else if (groupNum == 8) {
//        for (it = this->group8.begin(); it != this->group8.end(); ++it) {
//            int hand = *it;
//            this->table[hand] = weight;
//        }
//    } else if (groupNum == 9) {
//        for (it = this->group9.begin(); it != this->group9.end(); ++it) {
//            int hand = *it;
//            this->table[hand] = weight;
//        }
//    }
//    return;
//}

//void WeightTable::setWeightsBasedOnBettingHistory(int bettingHistory) {
//    // Different weights for how much/often a player has bet preflop
//    if (bettingHistory == 0) {
//        this->setGroupWeights(1, 0.4);
//        this->setGroupWeights(2, 0.5);
//        this->setGroupWeights(3, 0.7);
//        this->setGroupWeights(4, 0.9);
//        this->setGroupWeights(5, 1.0);
//        this->setGroupWeights(6, 1.0);
//        this->setGroupWeights(7, 0.9);
//        this->setGroupWeights(8, 0.7);
//        this->setGroupWeights(9, 0.3);
//    }
//    else if (bettingHistory == 1) {
//        this->setGroupWeights(1, 0.9);
//        this->setGroupWeights(2, 1.0);
//        this->setGroupWeights(3, 0.9);
//        this->setGroupWeights(4, 0.6);
//        this->setGroupWeights(5, 0.5);
//        this->setGroupWeights(6, 0.3);
//        this->setGroupWeights(7, 0.1);
//        this->setGroupWeights(8, 0.05);
//        this->setGroupWeights(9, 0.01);
//    }
//    else if (bettingHistory == 2) {
//        this->setGroupWeights(1, 1.0);
//        this->setGroupWeights(2, 1.0);
//        this->setGroupWeights(3, 0.8);
//        this->setGroupWeights(4, 0.6);
//        this->setGroupWeights(5, 0.3);
//        this->setGroupWeights(6, 0.1);
//        this->setGroupWeights(7, 0.05);
//        this->setGroupWeights(8, 0.01);
//        this->setGroupWeights(9, 0.005);
//    }
//    return;
//}

