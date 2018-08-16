#ifndef INCLUDED_ROWLINES_H
#define INCLUDED_ROWLINES_H

class RowLine {

public:
    RowLine();
    RowLine(int inRow, int inLeft, int inRight);

    int left, right, row;

    CvPoint leftPoint();
    CvPoint rightPoint();

    bool pointIn(int inColumn, int inRow, int inTolerance=0);
    bool equals(RowLine* inLine);

    int width();

    void toString();
};

#endif
