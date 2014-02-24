#include <stdio.h>

#define CHOOSE_EXPR(q,x,y) __builtin_choose_expr(q,x,y)
#define TYPES_COMPATIBLE(x,y) __builtin_types_compatible_p(x,y)

#define istypeof(v,x) TYPES_COMPATIBLE( v, __typeof__(x) )

void izpisi_int(int x) {
	printf("%d\n", x);
}

void izpisi_float(float x) {
	printf("%f\n", x);
}

#define izpisi(x) CHOOSE_EXPR( istypeof(float,x)||istypeof(double,x), izpisi_float, izpisi_int ) (x)

int main() {
	int x = 65;
	float y = 43;
	double z = 57;
	short s = 84;
	izpisi(x);
	izpisi(y);
	izpisi(z);
	izpisi(s);
	return 0;
}
