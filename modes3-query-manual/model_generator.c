#include "model_generator.h"

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
	s1.train = NULL;

	s2.segment_id = 2;
	s2.connectedTo[0] = &s1;
	s2.connectedTo[1] = &s3;
	s2.train = NULL;

	s3.segment_id = 3;
	s3.connectedTo[0] = &s2;
	s3.connectedTo[1] = &s4;
	s3.train = NULL;

	s4.segment_id = 4;
	s4.connectedTo[0] = &s3;
	s4.connectedTo[1] = &s5;
	s4.train = NULL;

	s5.segment_id = 5;
	s5.connectedTo[0] = &s4;
	s5.connectedTo[1] = &s6;
	s5.train = NULL;

	s6.segment_id = 6;
	s6.connectedTo[0] = &s5;
	s6.connectedTo[1] = &s7;
	s6.train = NULL;

	s7.segment_id = 7;
	s7.connectedTo[0] = &s6;
	s7.connectedTo[1] = &s1;
	s7.train = NULL;

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
}
