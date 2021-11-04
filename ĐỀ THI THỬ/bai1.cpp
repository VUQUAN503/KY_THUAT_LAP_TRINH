
#include <iostream>
#include <cmath>

void input(int &n)
{
    std::cout << "Nhap so nguyen : ";
    std::cin >> n;
}

float tinhP(int n, int m)
{
    if(n + m <= 0)
        return 0;
    return sqrt((pow(n, 2) + 1)/(n + m));
}

float tinhQ(int x, int n)
{
    float sum = 10*exp(x - 1);
    for(int i = 1; i <= n; ++i)
    {
        sum += pow(x, 2 * i)/(pow(5, i));
    }
    return sum;
}


int main()
{
    int n, m;
    float x;
    input(n);
    input(m);
    std::cout << "Nhap x: ";
    std::cin >> x;
    std::cout << "P(n, m) = " << tinhP(m, n) << std::endl;
    std::cout << "Q(x, n + m) = " << tinhQ(x, n + m) << std::endl;
    return 0;
}