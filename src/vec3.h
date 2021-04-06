/*
 * @Description: 
 * @Version: 2.0
 * @Autor: cc
 * @Date: 2021-03-31 18:55:43
 * @LastEditors: cc
 * @LastEditTime: 2021-04-05 03:00:11
 */
namespace cx
{
    class vec3
    {
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

        vec3 dot(const vec3 &vec) const;
        vec3 cross(const vec3 &vec) const;
    };

    vec3::vec3(float value)
    {
        vec3(value, value, 0.0);
    }

    vec3::vec3(float x, float y, float w) : x(x), y(y), w(w)
    {
    }

    vec3::~vec3()
    {
    }

    vec3 vec3::operator+(const vec3 &vec) const
    {
        return vec3(x + vec.x, y + vec.y, w + vec.w);
    }

    vec3 vec3::operator*(const float factor) const
    {
        return vec3(x * factor, y * factor, w * factor);
    }

    vec3 vec3::operator/(const float factor) const
    {
        return vec3(x / factor, y / factor, w / factor);
    }

    vec3 vec3::operator-(const vec3 &vec) const
    {
        return vec3(x - vec.x, y - vec.y, w - vec.w);
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
        return (vec.x == x && vec.y == y && vec.w == w);
    }

    vec3 vec3::dot(const vec3 &vec) const
    {
        return vec3(x * vec.x, y * vec.y, w * vec.w);
    }
}