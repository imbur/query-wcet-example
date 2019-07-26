#include <stddef.h>

#include "model/model_root.h"
#include "model/segment.h"
#include "model/train.h"

#ifdef DISPLAY
#include <stdio.h>
#endif

ModelRoot model;

typedef struct _CloseTrainsFrame {
	Segment* start;
	Segment* middle;
	Segment* end;
	Train* t1;
	Train* t2;
} CloseTrainsFrame;

typedef struct _CloseTrainsMatch {
	Segment* start;
	Segment* end;
} CloseTrainsMatch;

typedef struct _CloseTrainsMatchSet {
	CloseTrainsMatch matches[100];
} CloseTrainsMatchSet;

//////////////////////

void close_trains_matcher(CloseTrainsFrame *frame, int startOpIndex,
		CloseTrainsMatchSet *results) {
	int match_cntr = 0;
	int i0, i1, i2;

	for (i0 = 0; i0 < model.segment_count; i0++) {
		frame->start = model.segments[i0];
		for (i1 = 0; i1 < get_connectedTo_count(frame->start); i1++) {
			frame->middle = get_connectedTo(frame->start)[i1];
			for (i2 = 0; i2 < get_connectedTo_count(frame->middle); i2++) {
				frame->end = get_connectedTo(frame->middle)[i2];
				if (frame->start != frame->end) {
					frame->t2 = get_train(frame->end);
					if (frame->t2 != 0) {
						frame->t1 = get_train(frame->start);
						if (frame->t1 != 0) {
							if (frame->t1 != frame->t2) {
								results->matches[match_cntr].start =
										frame->start;
								results->matches[match_cntr++].end = frame->end;
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	// TODO model initialization
	// generateModel()

	// TODO initialize matcher structures
	CloseTrainsMatchSet *matches = NULL;
	CloseTrainsFrame *frame = NULL;

#ifdef DISPLAY
	printf("Hello, world!\n");
#endif

	int i = 0;
	close_trains_matcher(frame, i, matches);

	return 0;
}
