#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum ukaz {
	PUSH,
	PRINT,
	PLUS,
	MINUS,
	MUL,
	DIV,
	POW,
	LOG,
	LOG10,
	XCHG,
	INV,
	MOD,
	DUP,
	DROP,
	SIN,
	COS,
	TAN,
	SQRT,
	E,
	PI,
};
struct {
	char* ime_ukaza;
	enum ukaz ukaz;
} ukazi[] = {
	{ "print", PRINT },
	{ "+", PLUS },
	{ "-", MINUS },
	{ "*", MUL },
	{ "/", DIV },
	{ "^", POW },
	{ "log", LOG10 },
	{ "ln", LOG },
	{ "xchg", XCHG },
	{ "inv", INV },
	{ "mod", MOD },
	{ "dup", DUP },
	{ "drop", DROP },
	{ "sin", SIN },
	{ "cos", COS },
	{ "tan", TAN },
	{ "sqrt", SQRT },
	{ "e", E },
	{ "pi", PI },
};
static char input[2000];
enum ukaz preberi_ukaz() {
	if ( scanf("%s", input) == EOF )
		exit(0);
	for ( int i = 0; i < sizeof(ukazi)/sizeof(*ukazi); i++ )
		if ( !strcmp(ukazi[i].ime_ukaza, input ) )
			return ukazi[i].ukaz;
	return PUSH;
}

void error() {
	printf("ERR\n");
}

static inline void funkcija(double stevilo, double* prejsnje_stevilo) {
	for (;;)
		switch ( preberi_ukaz() ) {
			case PLUS:
				if ( prejsnje_stevilo ) {
					*prejsnje_stevilo += stevilo;
					return;
				}
				else
					error();
				break;
			case MINUS:
				if ( prejsnje_stevilo ) {
					*prejsnje_stevilo -= stevilo;
					return;
				}
				else
					error();
				break;
			case MUL:
				if ( prejsnje_stevilo ) {
					*prejsnje_stevilo *= stevilo;
					return;
				}
				else
					error();
				break;
			case DIV:
				if ( prejsnje_stevilo ) {
					*prejsnje_stevilo /= stevilo;
					return;
				}
				else
					error();
				break;
			case PUSH:
				funkcija ( atof(input), &stevilo );
				break;
			case PRINT:
				printf("%lf\n", stevilo);
				break;
			case POW:
				if ( prejsnje_stevilo ) {
					*prejsnje_stevilo = pow ( *prejsnje_stevilo, stevilo );
					return;
				}
				else
					error();
				break;
			case XCHG:
				if ( prejsnje_stevilo ) {
					double t = stevilo;
					stevilo = *prejsnje_stevilo;
					*prejsnje_stevilo = t;
				}
				else
					error();
				break;
			case MOD:
				if ( prejsnje_stevilo ) {
					*prejsnje_stevilo = fmod ( *prejsnje_stevilo, stevilo );
					return;
				}
				else
					error();
				break;
			case DUP:
				funkcija(stevilo, &stevilo);
				break;
			case DROP:
				return;
			case INV:
				stevilo = 1.0 / stevilo;
				break;
			case SQRT:
				stevilo = sqrt ( stevilo );
				break;
			case SIN:
				stevilo = sin ( stevilo );
				break;
			case COS:
				stevilo = cos ( stevilo );
				break;
			case TAN:
				stevilo = tan ( stevilo );
				break;
			case LOG:
				stevilo = log ( stevilo );
				break;
			case LOG10:
				stevilo = log10 ( stevilo );
				break;
			case E:
				funkcija ( M_E, &stevilo );
				break;
			case PI:
				funkcija ( M_PI, &stevilo );
				break;
		}
}

int main() {
	for (;;)
		switch ( preberi_ukaz() ) {
			case PRINT:
				printf ( "ERR\n" ); // FIXME
				break;
			case PUSH:
				funkcija ( atof(input), NULL );
				break;
			case E:
				funkcija ( E, NULL );
				break;
			case PI:
				funkcija ( M_PI, NULL );
				break;
			default:
				error();
		}
}
