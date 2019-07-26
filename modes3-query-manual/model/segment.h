#ifndef SEGMENT_H_
#define SEGMENT_H_

#include <stddef.h>
#include <stdint.h>

#include "train.h"

typedef struct _Train Train;
typedef struct _Segment Segment;

typedef struct _Segment {
	int32_t segment_id;
	Train* train;
	Segment* connectedTo[2];
} Segment;

Segment** get_connectedTo(Segment*);
int get_connectedTo_count(Segment*);
Train* get_train(Segment*);

#endif /* SEGMENT_H_ */
