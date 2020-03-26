#include <cstdio>
#include <cstdlib>
#include <cstring>
namespace matrix
{
class matrix
{
public:
    typedef size_t size_matrix;

private:
    int inner_row, inner_column;
    double **p;

private:
    void allocmem(size_matrix _row, size_matrix _column)
    {
        p = new double *[_row];
        for (int i = 0; i < _row; i++)
        {
            p[i] = new double[_column];
        }
    }
    void freemem()
    {
        for (int i = 0; i < inner_row; i++)
        {
            delete[] p[i];
        }
        delete[] p;
    }

public:
    matrix(const size_matrix row, const size_matrix column)
    {
        inner_row = row;
        inner_column = column;
        allocmem(row, column);
    }
    matrix(const size_matrix row, const size_matrix column, double value)
    {
        inner_row = row;
        inner_column = column;
        allocmem(row, column);
        for (int k = 0; k < row; k++)
            for (int l = 0; l < column; l++)
                p[k][l] = value;
    }
    matrix(const size_matrix row, const size_matrix column, double **matarr)
    {
        inner_row = row;
        inner_column = column;
        allocmem(row, column);
        for (int k = 0; k < row; k++)
            for (int l = 0; l < column; l++)
                p[k][l] = matarr[k][l];
    }
    matrix(matrix &mat)
    {
    }
    ~matrix()
    {
        freemem();
    }

public:
    size_matrix row() const
    {
        return inner_row;
    }
    size_matrix column() const
    {
        return inner_column;
    }
    void resize(size_matrix row, size_matrix column)
    {
        freemem();
        inner_row = row;
        inner_column = column;
        allocmem(row, column);
    }

public:
    double *operator[](size_matrix row) { return p[row]; };
    const double *operator[](size_matrix row) const { return p[row]; };
    matrix &operator=(const matrix &rhs)
    {
        this->resize(rhs.row, rhs.column);
        for (int i = 0; i < inner_row; i++)
        {
            memcpy(p[i], rhs[i], inner_column * sizeof(double));
        }
        return *this;
    }
    bool operator==(const matrix &rhs) //还需改动 ， 大小不一致情况
    {
        for (int i = 0; i < inner_row; i++)
        {
            if (!memcmp(p[i], rhs[i], inner_column * sizeof(rhs[0][0])))
                return false;
        }
        return true;
    }
    matrix operator+(const matrix &rhs) const
    {
        try
        {
            if (this->row() != rhs.row() || (this->column() != rhs.column()))
            {
                throw - 1;
            }
            matrix res(this->row(), this->column());
            for (size_matrix i = 0; i < this->row(); ++i)
                for (size_matrix j = 0; j < this->column(); ++j)
                    res[i][j] = (*this)[i][j] + rhs[i][j];
            return res;
        }
        catch (int)
        {
            printf("inconsistent matrix size\n");
            exit(-1);
        }
    }
    matrix operator*(const matrix &rhs) const
    {
        try
        {
            if (this->column() != rhs.column() || this->row() != rhs.column())
                throw - 1;
            matrix res(this->row(), this->column());
            for (size_matrix i = 0; i < res.row(); ++i)
                for (size_matrix j = 0; j < res.column(); ++j)
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
            if (this->row() != rhs.row() || (this->column() != rhs.column()))
            {
                throw - 1;
            }
            matrix res(this->row(), this->column());
            for (size_matrix i = 0; i < this->row(); ++i)
                for (size_matrix j = 0; j < this->column(); ++j)
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
            if (this->column != rhs.row())
                throw - 1;
            for (size_matrix row = 0; row < this->row(); ++row)
                for (size_matrix column = 0; column < rhs.column(); ++column)
                    for (size_matrix k = 0; k < this->column(); ++k)
                        *this[row][column] += (*this)[row][k] * rhs[k][column];
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
                if (this->inner_row != rhs.inner_row)
                    throw - 1;
                else
                {
                    inner_row = this->inner_row + rhs.inner_row;
                    inner_column = this->inner_column + rhs.inner_column;
                    //double
                }
            }
        }
        catch (int)
        {
            exit(-1);
        }
    }
};
} // namespace matrix