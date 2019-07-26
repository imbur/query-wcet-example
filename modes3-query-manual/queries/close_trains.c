#include "close_trains.h"

void close_trains_matcher(ModelRoot *model, CloseTrainsFrame *frame, int startOpIndex,
		CloseTrainsMatchSet *results) {
	int match_cntr = 0;
	int i0, i1, i2;

	for (i0 = 0; i0 < model->segment_count; i0++) {
		frame->start = model->segments[i0];
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
