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

int main() {
	// TODO model initialization
//	generate_model(&model)

	// TODO initialize matcher structures
	CloseTrainsMatchSet *matches = NULL;
	CloseTrainsFrame *frame = NULL;

#ifdef DISPLAY
	printf("Hello, world!\n");
#endif

	int i = 0;
	close_trains_matcher(&model, frame, i, matches);

	return 0;
}
