#include <cstdio>
#include <cstdlib>
#include <cstring>
namespace cx
{
    class matrix
    {
    public:
        typedef size_t size_matrix;

    private:
        int _row, _col;
        float **p;

    private:
        void allocmem(size_matrix _row, size_matrix _col)
        {
            p = new float *[_row];
            for (int i = 0; i < _row; i++)
            {
                p[i] = new float[_col];
            }
        }
        void freemem()
        {
            for (int i = 0; i < _row; i++)
            {
                delete[] p[i];
            }
            delete[] p;
        }

    public:
        matrix(const size_matrix row, const size_matrix col);
        matrix(const size_matrix row, const size_matrix col, float value);
        matrix(const size_matrix row, const size_matrix col, float **matarr);
        matrix(matrix &mat);
        ~matrix();

    public:
        size_matrix row() const
        {
            return _row;
        }
        size_matrix col() const
        {
            return _col;
        }
        void resize(size_matrix row, size_matrix col)
        {
            freemem();
            _row = row;
            _col = col;
            allocmem(row, col);
        }

    public:
        float *operator[](size_matrix row) { return p[row]; };
        const float *operator[](size_matrix row) const { return p[row]; };
        matrix &operator=(const matrix &rhs)
        {
            this->resize(rhs.row(), rhs.col());
            for (int i = 0; i < _row; i++)
            {
                memcpy(p[i], rhs[i], _col * sizeof(float));
            }
            return *this;
        }
        bool operator==(const matrix &rhs) //还需改动 ， 大小不一致情况
        {
            for (int i = 0; i < _row; i++)
            {
                if (!memcmp(p[i], rhs[i], _col * sizeof(rhs[0][0])))
                    return false;
            }
            return true;
        }
        matrix operator+(const matrix &rhs) const
        {
            try
            {
                if (this->row() != rhs.row() || (this->col() != rhs.col()))
                {
                    throw -1;
                }
                matrix res(this->row(), this->col());
                for (size_matrix i = 0; i < this->row(); ++i)
                    for (size_matrix j = 0; j < this->col(); ++j)
                        res[i][j] = (*this)[i][j] + rhs[i][j];
                return res;
            }
            catch (int)
            {
                printf("inconsistent matrix size\n");
            }
        }
        matrix operator*(const matrix &rhs) const
        {
            try
            {
                if (this->col() != rhs.col() || this->row() != rhs.col())
                    throw -1;
                matrix res(this->row(), this->col());
                for (size_matrix i = 0; i < res.row(); ++i)
                    for (size_matrix j = 0; j < res.col(); ++j)
                        res[i][j] = (*this)[i][j] * rhs[i][j];
                return res;
            }
            catch (int)
            {
                printf("inconsistent matrix size\n");
                exit(-1);
            }
        }
        matrix operator-(const matrix &rhs) const
        {
            try
            {
                if (this->row() != rhs.row() || (this->col() != rhs.col()))
                {
                    throw -1;
                }
                matrix res(this->row(), this->col());
                for (size_matrix i = 0; i < this->row(); ++i)
                    for (size_matrix j = 0; j < this->col(); ++j)
                        res[i][j] = (*this)[i][j] - rhs[i][j];
                return res;
            }
            catch (int)
            {
                printf("inconsistent matrix size\n");
                exit(-1);
            }
        }
        matrix &operator+=(const matrix &rhs) const
        {
            return (*this) + rhs;
        }
        matrix &operator*=(const matrix &rhs) const
        {
            return (*this) * rhs;
        }
        matrix &operator-=(const matrix &rhs) const
        {
            return (*this) - rhs;
        }

    public:
        void dot(const matrix &rhs)
        {
            try
            {
                if (this->col() != rhs.row())
                    throw -1;
                for (size_matrix row = 0; row < this->row(); ++row)
                    for (size_matrix col = 0; col < rhs.col(); ++col)
                        for (size_matrix k = 0; k < this->col(); ++k)
                            *this[row][col] += (*this)[row][k] * rhs[k][col];
                return;
            }
            catch (int)
            {
                printf("a wrong size...\n");
                exit(-1);
            }
        }
        void cat(const matrix &rhs, int flag)
        {
            try
            {
                if (flag == 0)
                {
                    if (this->_row != rhs._row)
                        throw -1;
                    else
                    {
                        _row = this->_row + rhs._row;
                        _col = this->_col + rhs._col;
                        //float
                    }
                }
            }
            catch (int)
            {
                exit(-1);
            }
        }
    };

    matrix::matrix(const size_matrix row, const size_matrix col)
    {
        matrix(row, col, 0.0);
    }
    matrix::matrix(const size_matrix row, const size_matrix col, float value)
    {
        _row = row;
        _col = col;
        allocmem(row, col);
        for (int k = 0; k < row; k++)
            for (int l = 0; l < col; l++)
                p[k][l] = value;
    }
    matrix::matrix(const size_matrix row, const size_matrix col, float **matarr)
    {
        _row = row;
        _col = col;
        allocmem(row, col);
        for (int k = 0; k < row; k++)
            for (int l = 0; l < col; l++)
                p[k][l] = matarr[k][l];
    }
    matrix::matrix(matrix &mat)
    {
    }
    matrix::~matrix()
    {
        freemem();
    }
}