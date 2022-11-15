#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	int idx;
	for (idx = 0; idx < q->size; idx++) {
		if (proc->priority < q->proc[idx]->priority) break;
	}

	//move the back to make space for incoming proc
	for (int i = q->size; i > idx; i--) {
		q->proc[i] = q->proc[i - 1];
	}

	//put proc to idx in queue, increment size
	q->proc[idx] = proc;
	q->size++;
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (empty(q)) return NULL;

	//else get proc at last index (highest priority)
	q->size--;
	return q->proc[q->size];
}

