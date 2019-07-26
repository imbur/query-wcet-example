#ifndef TRAIN_H_
#define TRAIN_H_

#include "segment.h"

typedef struct _Segment Segment;

typedef struct _Train {
	double speed;
	Segment* on;
} Train;

#endif /* TRAIN_H_ */
