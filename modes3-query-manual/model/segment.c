#include "segment.h"

Segment** get_connectedTo(Segment* segment){
	return segment->connectedTo;
}

int get_connectedTo_count(Segment* segment){
	int size = 2;
	for(int i = 0; i < 2; i++){
		size -= (segment->connectedTo[i] == NULL);
	}
	return size;
}

Train* get_train(Segment* segment){
	return segment->train;
}
