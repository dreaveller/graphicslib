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

        vec3 operator+();
        vec3 operator*();
        vec3 operator/();
        vec3 operator-();

        vec3 operator+=();
        vec3 operator-=();
        vec3 operator==();
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

}