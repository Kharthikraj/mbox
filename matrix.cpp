#include "matrix.hpp"
#include "vec.hpp"

namespace mbox{
    template class mat<float, 4, 4>;
    template class mat<float, 3, 3>;
    template class mat<float, 2, 2>;
    template class mat<float, 1, 2>;
    template class mat<float, 1, 3>;
    template class mat<float, 1, 4>;
    template class mat<float, 2, 1>;
    template class mat<float, 2, 3>;
    template class mat<float, 2, 4>;
    template class mat<float, 3, 1>;
    template class mat<float, 3, 2>;
    template class mat<float, 3, 4>;
    template class mat<float, 4, 1>;
    template class mat<float, 4, 2>;
    template class mat<float, 4, 3>;

    // to vec
    template vec<float, 4> mat<float, 1, 4>::tovec();
    template vec<float, 4> mat<float, 4, 1>::tovec();
    template vec<float, 3> mat<float, 3, 1>::tovec();
    template vec<float, 3> mat<float, 1, 3>::tovec();

    // // determinant
    // template float mbox::mat<float, 1, 1>::determinant()const;
    // template float mbox::mat<float, 2, 2>::determinant()const;
    // template float mbox::mat<float, 3, 3>::determinant()const;
    // template float mbox::mat<float, 4, 4>::determinant()const;
}