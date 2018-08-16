#ifndef INCLUDED_BOUNDINGRECTANGLE_H
#define INCLUDED_BOUNDINGRECTANGLE_H

class BoundingRectangle {

public:
    BoundingRectangle();
    BoundingRectangle(int inTop, int inBottom, int inLeft, int inRight);
    BoundingRectangle(BoundingRectangle* inRectangle);

    int top, bottom, left, right;

    CvPoint topLeft();
    CvPoint bottomLeft();
    CvPoint topRight();
    CvPoint bottomRight();

    bool pointIn(int inColumn, int inRow, int inTolerance=0);
    bool equals(BoundingRectangle* inRect);
    bool isColumnShape();
    bool isRowShape();

    int area();
    int width();
    int height();

    void toString();
    void toCode(int num);
};

#endif
