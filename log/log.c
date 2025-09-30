#include "log.h"
#include <stdlib.h>
#include "daemon.h"

log_t* log_create() {
	log_t* self = calloc(1, sizeof(log_t));
	pthread_mutex_init(&self->mutex, NULL);
	self->level = g_daemon.cnf->log.level;
	self->type = g_daemon.cnf->log.type;

	switch(self->type) {
		case LT_STD:
			self->out = stdout;
			break;
		default:
			self->out = stdout;
			break;
	}

	return self;
}

void log_free(log_t* self) {
	pthread_mutex_destroy(&self->mutex);
	free(self);
}

void logging(LOG_LEVEL level, const char* module, const char* fmt, ...) {
	log_t* self = g_daemon.log;
	if(level < self->level)
		return;

	va_list args;
	va_start(args, fmt);

	pthread_mutex_lock(&self->mutex);
	fprintf(self->out, "[%s] ", module);
	vfprintf(self->out, fmt, args);
	fprintf(self->out, "\n");
	pthread_mutex_unlock(&self->mutex);

	va_end(args);
}
