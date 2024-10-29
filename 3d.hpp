#pragma once
#include "matrix.hpp"
#include "vec.hpp"
#include "cmath"

namespace mbox{

        class Quat: private vec<float, 4>{      
        private:
            float x, y, z, w;

        protected:
            void updatetovec();
            void updatevals();     

        public:
            using vec<float, 4>::vec;

            void printQuat(){this->printVec();}

            float X(){updatevals();return x;};
            float Y(){updatevals();return y;};
            float Z(){updatevals();return z;};
            float W(){updatevals();return w;};

            Quat operator*(Quat& other);
            Quat& operator=(const Quat& other);

            Quat normalize();
            Quat conjugate();
            Quat inverse(){
                Quat temp = this->normalize();
                return temp.conjugate();
            }
            static Quat createQuatFromAxisAngle(vec3&, float);
            static Quat createQuatFromEuler(float ax, float ay, float az, bool isDeg=true);

            float scalar(){return this->getElement(3);};
            float magnitude()override{return vec<float, 4>::magnitude();};
    };

    namespace transform{
        template <typename T, int row, int column>
        static mat<T, row, column> translate(const mat<T, row, column>& mat, const vec<T, row-1>& vect, bool direction = false);

        template <typename T, int row, int column>
        static mat<T, row, column> scale(const mat<T, row, column>& mat, const vec<T, row-1>& vect, bool direction = false);

        mbox::mat<float, 4, 4> createRotation(Quat& obj);
    }
}

#include "3d.tpp"