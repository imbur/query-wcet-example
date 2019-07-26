#ifndef QUERIES_CLOSE_TRAINS_H_
#define QUERIES_CLOSE_TRAINS_H_

#include "../model/segment.h"
#include "../model/train.h"
#include "../model/model_root.h"

typedef struct _CloseTrainsFrame {
	Segment *start;
	Segment *middle;
	Segment *end;
	Train *t1;
	Train *t2;
} CloseTrainsFrame;

typedef struct _CloseTrainsMatch {
	Segment *start;
	Segment *end;
} CloseTrainsMatch;

typedef struct _CloseTrainsMatchSet {
	int size;
	CloseTrainsMatch matches[10];
} CloseTrainsMatchSet;

void close_trains_matcher(ModelRoot *model, CloseTrainsFrame *frame, int startOpIndex,
		CloseTrainsMatchSet *results);

#endif /* QUERIES_CLOSE_TRAINS_H_ */
