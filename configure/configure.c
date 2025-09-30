#include "configure.h"
#include <stdlib.h>
#include "log.h"

configure_t* cnf_create() {
	configure_t* self = calloc(1, sizeof(configure_t));

	// Default values
	self->port = 500;
	self->log.type = LT_STD;
	self->log.level = LL_ALL;

	return self;
}

void cnf_free(configure_t* self) {
	free(self);
}
