#include "main.h"

//calcula o coeficiente angular da reta
//tga = yb - ya / xb - xa
double findSlope (int xA, int yA, int xB, int yB) {
    double tg;
    if (xA == xB) {
        tg = 0;
        return tg;
    }
    tg = (double) (yB - yA) / (xB - xA);
    return tg;
}

int isInside (int xA, int xB, int xptC, int yptC, int xptD, int yptD) {
    if ((xptC >= xA) && (xptD < xA)) {
        //D nao esta contido em C
        return -1;
    }

    if ((xptC <= xB) && (xptD > xB)) {
        //D nao esta contido em C
        return -1;
    }

    if ((xptC <= xA) && (xptD > xA)) {
        
    } else {
        if (findSlope(xA, 0, xptC, yptC) < findSlope(xA, 0, xptD, yptD)) {
            //D nao esta contido em C
            return -1;
        }
    }

    if ((xptC >= xB) && (xptD < xB)) {

    } else {
        if (findSlope(xB, 0, xptC, yptC) > findSlope(xB, 0, xptD, yptD)) {
            //D nao esta contido em C
            return -1;
        }
    }
    
    //D esta contido em C
    return 1;
}