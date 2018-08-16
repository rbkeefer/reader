/*
 * RkColumn.h
 *
 *  Created on: Mar 29, 2010
 *      Author: rob
 */

#ifndef RKCOLUMN_H_
#define RKCOLUMN_H_

class RkColumn {
public:
	RkColumn();
    RkColumn(int inColumn, int inTop, int inBottom);

    virtual ~RkColumn();

    int top, bottom, column;

    CvPoint topPoint();
    CvPoint bottomPoint();

    bool pointIn(int inColumn, int inRow, int inTolerance=0);
    bool equals(RkColumn* inLine);

    int height();

    void toString();
};

#endif /* RKCOLUMN_H_ */
