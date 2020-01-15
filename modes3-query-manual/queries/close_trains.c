#include "close_trains.h"

void close_trains_matcher(ModelRoot *model,
		CloseTrainsFrame *frame /*TODO the content of this param is ignored for now*/,
		int startOpIndex /*TODO this param is ignored for now*/,
		CloseTrainsMatchSet *results) {
	int match_cntr = 0;
	int i0, i1, i2;

	for (i0 = 0; i0 < model->segment_count; i0++) {
		frame->start = model->segments[i0];
		frame->t1 = get_train(frame->start);
		if (frame->t1 != 0) {
			results->matches[match_cntr].start = frame->start;
		}
	}

	results->size = match_cntr;

	return;
}
