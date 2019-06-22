#ifndef FLOAT_MACRO_H
# define FLOAT_MACRO_H

# define FLOAT_MACRO	float

# if FLOAT_MACRO == float
#  define COS_MACRO		cosf
# elif 	FLOAT_MACRO == double
#  define COS_MACRO		cos
# endif

# if FLOAT_MACRO == float
#  define SIN_MACRO		sinf
# elif 	FLOAT_MACRO == double
#  define SIN_MACRO		sin
# endif

# if FLOAT_MACRO == float
#  define SQRT_MACRO	sqrtf
# elif 	FLOAT_MACRO == double
#  define SQRT_MACRO	sqrt
# endif

# define SQRT_MACRO_CL	sqrt

#endif
