#include "model_generator.h"

Segment segments[SEGMENTS_MAX];

void generate_model(ModelRoot *model) {
	// Static allocation of structures in the memory
	// TODO figure out how to dynamically allocate them if there is no memory management support
	static Segment s1;
	static Segment s2;
	static Segment s3;
	static Segment s4;
	static Segment s5;
	static Segment s6;
	static Segment s7;

	static Train t1;
	static Train t2;

	int i;

	model->segments[0] = &s1;
	model->segments[1] = &s2;
	model->segments[2] = &s3;
	model->segments[3] = &s4;
	model->segments[4] = &s5;
	model->segments[5] = &s6;
	model->segments[6] = &s7;

	model->trains[0] = &t1;
	model->trains[1] = &t2;

	// Connecting segments - creating a circle
	s1.segment_id = 1;
	s1.connectedTo[0] = &s7;
	s1.connectedTo[1] = &s2;
	s1.train = 0;

	s2.segment_id = 2;
	s2.connectedTo[0] = &s1;
	s2.connectedTo[1] = &s3;
	s2.train = 0;

	s3.segment_id = 3;
	s3.connectedTo[0] = &s2;
	s3.connectedTo[1] = &s4;
	s3.train = 0;

	s4.segment_id = 4;
	s4.connectedTo[0] = &s3;
	s4.connectedTo[1] = &s5;
	s4.train = 0;

	s5.segment_id = 5;
	s5.connectedTo[0] = &s4;
	s5.connectedTo[1] = &s6;
	s5.train = 0;

	s6.segment_id = 6;
	s6.connectedTo[0] = &s5;
	s6.connectedTo[1] = &s7;
	s6.train = 0;

	s7.segment_id = 7;
	s7.connectedTo[0] = &s6;
	s7.connectedTo[1] = &s1;
	s7.train = 0;

	// Placing trains on s3 and s5 so that they are considered "close"

	s3.train = &t1;
	t1.on = &s3;
	t1.speed = 11.1;

	s5.train = &t2;
	t2.on = &s5;
	t2.speed = -3.1;

	// Set model object counts in model root

	model->segment_count = 7;
	model->train_count = 2;

	// Dummy segments
	for (i = model->segment_count; i < SEGMENTS_MAX; ++i) {
		// Pointers are set here
		model->segments[i] = segments + i;
		model->segments[i]->segment_id=i;
	}

	for (i = model->segment_count; i < SEGMENTS_MAX - 1; ++i) {
		model->segments[i]->connectedTo[0] = model->segments[i - 1];
		model->segments[i]->connectedTo[1] = model->segments[i + 1];
	}

	static Train t3;
	t3.on = model->segments[100];
	model->segments[100]->train = &t3;
	static Train t4;
	t4.on = model->segments[150];
	model->segments[150]->train = &t4;
	static Train t5;
	t5.on = model->segments[200];
	model->segments[200]->train = &t5;
	static Train t6;
	t6.on = model->segments[250];
	model->segments[250]->train = &t6;
	static Train t7;
	t7.on = model->segments[300];
	model->segments[300]->train = &t7;
	static Train t8;
	t8.on = model->segments[350];
	model->segments[350]->train = &t8;
	static Train t9;
	t9.on = model->segments[400];
	model->segments[400]->train = &t9;
	static Train t10;
	t10.on = model->segments[450];
	model->segments[450]->train = &t10;

	model->segment_count=SEGMENTS_MAX;
	model->train_count=10;
}
