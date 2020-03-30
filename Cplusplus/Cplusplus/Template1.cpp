#include <memory> // brings in TEMPLATE macros.

#define _MAKE_UNIQUE(TEMPLATE_LIST, PADDING_LIST, LIST, COMMA, X1, X2, X3, X4)  \
\
template<class T COMMA LIST(_CLASS_TYPE)>    \
inline std::unique_ptr<T> make_unique(LIST(_TYPE_REFREF_ARG))    \
{    \
    return std::unique_ptr<T>(new T(LIST(_FORWARD_ARG)));    \
}

_VARIADIC_EXPAND_0X(_MAKE_UNIQUE, , , , )
#undef _MAKE_UNIQUE