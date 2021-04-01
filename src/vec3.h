namespace cx
{
    class vec3
    {
    private:
    public:
        float x, y, w;
        vec3(float value);
        vec3(float x, float y, float w);
        ~vec3();

        vec3 operator+(const vec3 &vec) const;
        vec3 operator*(const float factor) const;
        vec3 operator/(const float factor) const;
        vec3 operator-(const vec3 &vec) const;

        vec3 operator+=(const vec3 &vec);
        vec3 operator-=(const vec3 &vec);
        bool operator==(const vec3 &vec) const;
    };

    vec3::vec3(float value)
    {
        vec3(value, value, 0.0);
    }

    vec3::vec3(float x, float y, float w)
    {
        x = x;
        y = y;
        w = w;
    }

    vec3::~vec3()
    {
    }

    vec3 vec3::operator+(const vec3 &vec) const
    {
        float _x = x + vec.x;
        float _y = y + vec.y;
        float _w = w + vec.w;
        return vec3(_x, _y, _w);
    }

    vec3 vec3::operator*(const float factor) const
    {
        float _x = x * factor;
        float _y = y * factor;
        float _w = w * factor;
        return vec3(_x, _y, _w);
    }

    vec3 vec3::operator/(const float factor) const
    {
        float _x = x / factor;
        float _y = y / factor;
        float _w = w / factor;
        return vec3(_x, _y, _w);
    }

    vec3 vec3::operator-(const vec3 &vec) const
    {
        float _x = x - vec.x;
        float _y = y - vec.y;
        float _w = w - vec.w;
        return vec3(_x, _y, _w);
    }

    vec3 vec3::operator+=(const vec3 &vec)
    {
        x += vec.x;
        y += vec.y;
        w += vec.w;
    }

    vec3 vec3::operator-=(const vec3 &vec)
    {
        x -= vec.x;
        y -= vec.y;
        w -= vec.w;
    }

    bool vec3::operator==(const vec3 &vec) const
    {
        if (vec.x == x && vec.y == y && vec.w == w)
            return true;
        else
            return false;
    }

}