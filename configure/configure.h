#ifndef __CONFIGURE_H__
#define __CONFIGURE_H__

typedef struct {
	int port;
	struct {
		int level;
		int type;
	}log;
}configure_t;

configure_t*	cnf_create(const char* filename);
void					cnf_free(configure_t* self);

#endif //__CONFIGURE_H__
