#ifndef INCLUDED_COLUMNLINES_H
#define INCLUDED_COLUMNLINES_H

class ColumnLine {

public:
    ColumnLine();
    ColumnLine(int inColumn, int inTop, int inBottom);

    int top, bottom, column;

    CvPoint topPoint();
    CvPoint bottomPoint();

    bool pointIn(int inColumn, int inRow, int inTolerance=0);
    bool equals(ColumnLine* inLine);

    int height();

    void toString();
};

#endif
