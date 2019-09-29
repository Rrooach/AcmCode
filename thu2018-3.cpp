
#define _CRT_SECURE_NO_WARNINGS

//输入两个长度不超过200的正整数A,B，求A和B的乘积。保证输入的正整数不会以0开头，要求输出的正整数也不能以0开头

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

class BigInteger
{
public:
    static const int maxn = 1010;
    static int BASE;

    BigInteger(void)
    {
        n = 1;
        memset(digit, 0, sizeof(digit));
    }

    BigInteger(int one_digit)
    {
        n = 1;
        memset(digit, 0, sizeof(digit));
        digit[0] = one_digit;
    }

    BigInteger &operator=(const BigInteger &rhs)
    {
        n = rhs.n;
        for (int i = 0; i < n; i++)
        {
            digit[i] = rhs.digit[i];
        }
        return *this;
    }

    int digit[maxn], n;

    void readInput()
    {
        static char buffer[maxn];
        scanf("%s", buffer);
        int len = strlen(buffer);
        n = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            digit[n++] = buffer[i] - '0';
        }
    }

    void normalize(int i)
    {
        n = i;
        while (n > 1 && digit[n - 1] == 0)
        {
            n--;
        }
    }

    void clear0()
    {
        n = 1;
        memset(digit, 0, sizeof(digit));
    }

    void add(const BigInteger &rhs, BigInteger &result) const
    {
        int i, si = 0;
        result.clear0();
        for (i = 0; i < n + rhs.n; i++)
        {
            result.digit[i] = si + digit[i] + rhs.digit[i];
            result.digit[i + 1] = result.digit[i] / BASE;
            result.digit[i] = result.digit[i] % BASE;
        }
        result.normalize(n + rhs.n);
    }

    void sub(const BigInteger &rhs, BigInteger &result) const
    { //ensure *this >= rhs
        int i, x = 0;
        for (i = 0; i < n; i++)
        {
            x += digit[i];
            if (i < rhs.n)
            {
                x -= rhs.digit[i];
            }
            bool borrow = false;
            if (x < 0)
            {
                x += BASE;
                borrow = true;
            }
            result.digit[i] = x;
            if (borrow)
            {
                x = -1;
            }
            else
            {
                x = 0;
            }
        }
        result.normalize(i);
    }

    void mul(const BigInteger &rhs, BigInteger &result) const
    {
        for (int i = 0; i < n + rhs.n; i++)
        {
            result.digit[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < rhs.n; j++)
            {
                result.digit[i + j] += digit[i] * rhs.digit[j];
                if (result.digit[i + j] >= BASE)
                {
                    result.digit[i + j + 1] += result.digit[i + j] / BASE;
                    result.digit[i + j] %= BASE;
                }
            }
        }
        result.normalize(n + rhs.n);
    }

    void left_shift(int L)
    {
        int i;
        for (i = n - 1; i >= 0; i--)
        {
            digit[i + L] = digit[i];
        }
        for (i = L - 1; i >= 0; i--)
        {
            digit[i] = 0;
        }
        n += L;
    }

    bool tail(const BigInteger &rhs) const
    { // ensure rhs >= *this
        for (int i = 0; i < n; i++)
        {
            if (digit[i] != rhs.digit[i])
            {
                return false;
            }
        }
        return true;
    }

    int compare(const BigInteger &rhs) const
    {
        if (n != rhs.n)
        {
            return n - rhs.n;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (digit[i] != rhs.digit[i])
            {
                return digit[i] - rhs.digit[i];
            }
        }
        return 0;
    }

    void output() const
    {
        bool started = false;
        for (int i = n - 1; i >= 0; i--)
        {
            putchar('0' + digit[i]);
        }
        putchar('\n');
    }

    int toBASE10() // switch to integer of BASE 10
    {
        int ret = 0, i, multiplier = 1;
        for (i = 0; i < n; i++)
        {
            ret += digit[i] * multiplier;
            multiplier *= 10;
        }
        return ret;
    }
};

int BigInteger::BASE;

int main()
{
    int m = 10, k = 4, cnt = 0, i = 0, j = 1;
    scanf("%d%d", &m, &k);
    BigInteger::BASE = m;
    BigInteger A, B, C;
    vector<BigInteger> v;
    do
    {
        if (i == 0)
        {
            for (j = 1; j < m; j++)
            {
                A = BigInteger(j);
                A.mul(A, C);
                if (A.tail(C))
                {
                    cnt++;
                    v.push_back(A);
                }
                if (cnt == k)
                {
                    goto mark;
                }
            }
            i++;
        }
        else
        {
            vector<BigInteger> pre(v);
            for (j = 1; j < m; j++)
            {
                B = BigInteger(j);
                B.left_shift(i);
                for (vector<BigInteger>::iterator it = pre.begin(); it != pre.end(); it++)
                {
                    B.add(*it, A);
                    A.mul(A, C);
                    if (A.tail(C))
                    {
                        cnt++;
                        v.push_back(A);
                    }
                    if (cnt == k)
                    {
                        goto mark;
                    }
                }
            }
            i++;
        }
    } while (cnt < k);
mark:
    printf("%d", A.toBASE10());

    return 0;
}