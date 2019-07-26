#ifndef MODEL_ROOT_H_
#define MODEL_ROOT_H_

#include "train.h"
#include "segment.h"

#define TRAINS_MAX 10
#define SEGMENTS_MAX 10

typedef struct _ModelRoot {
	int train_count;
	int segment_count;
	Train *trains[TRAINS_MAX];
	Segment *segments[SEGMENTS_MAX];
} ModelRoot;

#endif /* MODEL_ROOT_H_ */
