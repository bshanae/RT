#ifndef CL_FLOAT_H
# define CL_FLOAT_H

# define RT_FLOAT

# ifdef RT_FLOAT
#  define FLOAT				float
#  define FLOAT4			float4
#  define API_FLOAT4		cl_float4
#  define SQRT				sqrtf
#  define SIN				sinf
#  define COS				cosf
#  define MIN				fminf
#  define MAX				fmaxf
# endif

# ifdef RT_DOUBLE
#  define FLOAT				double
#  define FLOAT4			double4
#  define API_FLOAT4		cl_double4
#  define FSQRT				sqrt
#  define FSIN				sin
#  define FCOS				cos
#  define FMIN				fmin
#  define FMAX				fmax
# endif

#endif
