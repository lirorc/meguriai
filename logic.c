#include "logic.h"

static bool
isobstacled(Vector2 vec)
{
	// use collision bitmap for faster check
	// when too many entities ?
	return false;
}

bool
iscollide(Planet* p)
{
	// check 8 balanced points from circle
	// NB: there is built-in collision check
	for(int i=0; i<8; i++) {
		if(isobstacled((Vector2){
					p->x + p->size*cos(i*PI/4),
					p->y + p->size*sin(i*PI/4)}))
			return true;
	} return false;
}

void
updatechild(Planet* p)
{
	p->rot+=p->rotd*PI/40;
	p->x = p->parent->x + p->dist*cos(p->rot);
	p->y = p->parent->y + p->dist*sin(p->rot);
}
