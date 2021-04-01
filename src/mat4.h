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
        mat4 operator*(const float &factor) const; // float 类型是否需要加引用， 直接传值是否可以
        mat4 operator/(const float &factor) const;

        mat4 operator+=(const mat4 &mat);
        mat4 operator-=(const mat4 &mat);
        mat4 operator==(const mat4 &mat);
        float *operator[](int row);

        mat4 product(const mat4 &mat) const; // 目前打算规定向量全为列向量,product 右乘 mat4 或者 vec4
        mat4 dot(const mat4 &mat) const;
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

    mat4 mat4::operator*(const float &factor) const
    {
        mat4 tmp;
        for (int i = 0; i < 16; i++)
            tmp.elems[i] = factor * this->elems[i];
        return tmp;
    }

    mat4 mat4::operator/(const float &factor) const
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

    mat4 mat4::dot(const mat4 &mat) const
    {
        mat4 tmp;
        for (int i = 0; i < 16; i++)
        {
            tmp.elems[i] = this->elems[i] * tmp.elems[i];
        }
        return tmp;
    }
} // namespace cx
