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

        vec4 dot(const vec4 &dot) const;
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
        return vec4(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
    }

    vec4 vec4::operator*(const float factor) const
    {
        return vec4(x * factor, y * factor, z * factor, w * factor);
    }

    vec4 vec4::operator/(const float factor) const
    {
        return vec4(x / factor, y / factor, z / factor, w / factor);
    }

    vec4 vec4::operator-(const vec4 &vec) const
    {
        return vec4(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
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
        return (vec.x == x && vec.y == y && vec.z == z && vec.w == w);
    }

    vec4 vec4::dot(const vec4 &vec) const
    {
        return vec4(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
    }
}