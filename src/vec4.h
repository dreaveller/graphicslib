namespace cx
{
    class vec4
    {
    private:
    public:
        float x, y, z, w;
        vec4(float value);
        vec4(float x, float y, float z, float w);
        ~vec4();

        vec4 operator+(const vec4 &vec) const;
        vec4 operator*(const float factor) const;
        vec4 operator/(const float factor) const;
        vec4 operator-(const vec4 &vec) const;

        vec4 operator+=(const vec4 &vec);
        vec4 operator-=(const vec4 &vec);
        bool operator==(const vec4 &vec) const;
    };

    vec4::vec4(float value)
    {
        vec4(value, value, value, 0.0);
    }

    vec4::vec4(float x, float y, float z, float w)
    {
        x = x;
        y = y;
        z = z;
        w = w;
    }

    vec4::~vec4()
    {
    }

    vec4 vec4::operator+(const vec4 &vec) const
    {
        float _x = x + vec.x;
        float _y = y + vec.y;
        float _z = z + vec.z;
        float _w = w + vec.w;
        return vec4(_x, _y, _z, _w);
    }

    vec4 vec4::operator*(const float factor) const
    {
        float _x = x * factor;
        float _y = y * factor;
        float _z = z * factor;
        float _w = w * factor;
        return vec4(_x, _y, _z, _w);
    }

    vec4 vec4::operator/(const float factor) const
    {
        float _x = x / factor;
        float _y = y / factor;
        float _z = z / factor;
        float _w = w / factor;
        return vec4(_x, _y, _z, _w);
    }

    vec4 vec4::operator-(const vec4 &vec) const
    {
        float _x = x - vec.x;
        float _y = y - vec.y;
        float _z = z - vec.z;
        float _w = w - vec.w;
        return vec4(_x, _y, _z, _w);
    }

    vec4 vec4::operator+=(const vec4 &vec)
    {
        x += vec.x;
        y += vec.y;
        z += vec.z;
        w += vec.w;
    }

    vec4 vec4::operator-=(const vec4 &vec)
    {
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;
        w -= vec.w;
    }

    bool vec4::operator==(const vec4 &vec) const
    {
        if (vec.x == x && vec.y == y && vec.z == z && vec.w == w)
            return true;
        else return false;
    }

}