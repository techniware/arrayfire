#include <af/dim4.hpp>
#include <af/defines.h>
#include <ArrayInfo.hpp>
#include <Array.hpp>
#include <bilateral.hpp>
#include <kernel/bilateral.hpp>

using af::dim4;

namespace opencl
{

template<typename T, bool isColor>
Array<T> * bilateral(const Array<T> &in, const float &s_sigma, const float &c_sigma)
{
    const dim4 dims     = in.dims();

    Array<T>* out       = createEmptyArray<T>(dims);

    kernel::bilateral<T, isColor>(*out, in, s_sigma, c_sigma);

    return out;
}

#define INSTANTIATE(T)\
template Array<T> * bilateral<T,true >(const Array<T> &in, const float &s_sigma, const float &c_sigma);\
template Array<T> * bilateral<T,false>(const Array<T> &in, const float &s_sigma, const float &c_sigma);

INSTANTIATE(float )
INSTANTIATE(double)
INSTANTIATE(char  )
INSTANTIATE(int   )
INSTANTIATE(uint  )
INSTANTIATE(uchar )

}