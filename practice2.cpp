#include <iostream>
using namespace std;
class number
{
public:
    int n;
    int sum = 0;

public:
    void in()
    {
        cin >> n;
    }
    virtual void calculate() {}
};
class series : public number
{
public:
    void calculate()
    {
        for (int i = 1; i <= n; i++)
        {
            int y = i * i;
            sum += y;
        }
        cout << sum << endl;
    }
};
int main()
{
    // number *n;
    // series s;
    // n=&s;
    // n->in();
    // n->calculate();
    // return 0;
    series obj;
    number *n = &obj;
    n->in();
    n->calculate();
}