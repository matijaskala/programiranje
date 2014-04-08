#include <stdio.h>
#include <stdlib.h>

typedef struct _double_stack double_stack;
struct _double_stack {
	double st;
	double_stack* n;
	double_stack* p;
};

static void stack_push ( double_stack** s, double st ) {
	double_stack* n = malloc ( sizeof(double_stack) );
	n->n = NULL;
	n->st = st;
	n->p = *s;
	if ( *s )
		(*s)->n = n;
	else
		*s = n;
	*s = n;
}

static inline double stack_empty ( double_stack** s ) {
	return !*s;
}

static double stack_get ( double_stack** s ) {
	if ( stack_empty ( s ) ) {
		fprintf ( stderr, "empty_list_exception\n" );
		exit ( 1 );
	}
	return (*s)->st;
}

static double stack_pop ( double_stack** s ) {
	double st = stack_get ( s );
	double_stack* n = *s;
	*s = (*s)->p;
	free ( n );
	return st;
}

int main() {
	double_stack* s = NULL; // mora biti NULL
	stack_push ( &s, 2 );
	stack_push ( &s, 4 );
	printf ( "%f\n", stack_get ( &s ) );
	stack_pop ( &s );
	printf ( "%f\n", stack_get ( &s ) );
	return 0;
}
