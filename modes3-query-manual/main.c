#include <stddef.h>

#include "model/model_root.h"
#include "model/segment.h"
#include "model/train.h"

#include "model_generator.h"

#include "queries/close_trains.h"

#ifdef DISPLAY
#include <stdio.h>
#endif

ModelRoot model;

int main(void) {
	*((uint32_t*)0x41004408UL) = 0x00020000;
	*((uint8_t*)0x41004440UL) = 0x0002;

	*((uint32_t*)0x41004418UL) = 0x00020000;


	// TODO model initialization
	generate_model(&model);

	// TODO initialize matcher structures
	CloseTrainsMatchSet matches;
	CloseTrainsFrame frame;

	int i = 0;
	close_trains_matcher(&model,
			&frame /*TODO the content of this param is ignored for now*/,
			i /*TODO this param is ignored for now*/, &matches);

#ifdef DISPLAY
	for (int j = 0; j < matches.size; ++j) {
		printf("Match %d> start=%d ; end=%d\n", j+1,matches.matches[j].start->segment_id,matches.matches[j].end->segment_id);
	}
#endif

	return 0;
}
