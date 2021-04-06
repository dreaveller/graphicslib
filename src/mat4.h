#include <vec4.h>

namespace cx
{
    class mat4
    {
    private:
        float elems[16] = {float(0)};

    public:
        mat4();
        mat4(float elem);
        mat4(float elem, int flag);
        ~mat4();

        mat4 operator+(const mat4 &mat) const;
        mat4 operator-(const mat4 &mat) const;
        mat4 operator*(const float factor) const;
        mat4 operator/(const float factor) const;

        mat4 operator+=(const mat4 &mat);
        mat4 operator-=(const mat4 &mat);
        mat4 operator==(const mat4 &mat);
        float *operator[](int row);

        mat4 product(const mat4 &mat) const; // 目前打算规定向量全为列向量,product 右乘 mat4 或者 vec4
        vec4 product(const vec4& vec) const;
        mat4 dot(const mat4 &mat) const;
        void transpose();

    private:
        void swap(float &a, float &b);
    };

    mat4::mat4()
    {
        mat4(float(0));
    }

    mat4::mat4(float elem)
    {
        mat4(elem, 1);
    }

    mat4::mat4(float elem, int flag)
    {
        if (flag == 1)
            elems[0] = elems[5] = elems[10] = elems[15] = elem;
        else
            elems[3] = elems[6] = elems[9] = elems[12] = elem;
    }

    mat4::~mat4()
    {
    }

    mat4 mat4::operator+(const mat4 &mat) const
    {
        cx::mat4 tmp;
        for (int i = 0; i < 16; i++)
            tmp.elems[i] = mat.elems[i] + this->elems[i];
        return tmp;
    }

    mat4 mat4::operator-(const mat4 &mat) const
    {
        cx::mat4 tmp;
        for (int i = 0; i < 16; i++)
            tmp.elems[i] = this->elems[i] - mat.elems[i];
        return tmp;
    }

    mat4 mat4::operator*(const float factor) const
    {
        mat4 tmp;
        for (int i = 0; i < 16; i++)
            tmp.elems[i] = factor * this->elems[i];
        return tmp;
    }

    mat4 mat4::operator/(const float factor) const
    {
        mat4 tmp;
        for (int i = 0; i < 16; i++)
            tmp.elems[i] = this->elems[i] / factor;
        return tmp;
    }

    mat4 mat4::operator+=(const mat4 &mat){};
    mat4 mat4::operator-=(const mat4 &mat){};
    mat4 mat4::operator==(const mat4 &mat){};
    float *mat4::operator[](int row){};

    mat4 mat4::product(const mat4 &mat) const
    {
        mat4 tmp;
        for (int i = 0; i < 16; i++)
        {
            int row = i / 4;
            int col = i % 4;
            tmp.elems[i] = this->elems[row * 4] * mat.elems[col] +
                           this->elems[row * 4 + 1] * mat.elems[col + 4] +
                           this->elems[row * 4 + 2] * mat.elems[col + 8] +
                           this->elems[row * 4 + 3] * mat.elems[col + 12];
        }
        return tmp;
    }

    vec4 mat4::product(const vec4& vec) const
    {
        float _x = vec.x * elems[0] + vec.y * elems[1] + vec.z * elems[2] + vec.w * elems[3];
        float _y = vec.x * elems[4] + vec.y * elems[5] + vec.z * elems[6] + vec.w * elems[7];
        float _z = vec.x * elems[8] + vec.y * elems[9] + vec.z * elems[10] + vec.w * elems[11];
        float _w = vec.x * elems[12] + vec.y * elems[13] + vec.z * elems[14] + vec.w * elems[15];
        return vec4(_x, _y, _z, _w);
        // mat4 和 vec4 大概需要放到同一个头文件里，关于工具类的设计范式，感觉还有很多东西要学
    }

    mat4 mat4::dot(const mat4 &mat) const
    {
        mat4 tmp;
        for (int i = 0; i < 16; i++)
        {
            tmp.elems[i] = this->elems[i] * tmp.elems[i];
        }
        return tmp;
    }

    void mat4::transpose()
    {
        swap(elems[1], elems[4]);
        swap(elems[2], elems[8]);
        swap(elems[3], elems[12]);
        swap(elems[6], elems[9]);
        swap(elems[7], elems[13]);
        swap(elems[11], elems[14]);
    }

    void mat4::swap(float &a, float &b)
    {
        float tmp = a;
        a = b;
        b = tmp;
    }
} // namespace cx
