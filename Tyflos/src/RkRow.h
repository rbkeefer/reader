/*
 * RkRow.h
 *
 */

#ifndef RKROW_H_
#define RKROW_H_

class RkRow {
public:
	RkRow();
	RkRow(int inRow, int inLeft, int inRight);
	virtual ~RkRow();

	int left, right, row;

	CvPoint leftPoint();
	CvPoint rightPoint();

	bool pointIn(int inColumn, int inRow, int inTolerance=0);
	bool equals(RkRow* inLine);

	int width();

	void toString();
};

#endif /* RKROW_H_ */
