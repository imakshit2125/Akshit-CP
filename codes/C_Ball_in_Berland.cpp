#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map> // for less time complexity since unordered map takes o(1) time for inserting
#include <string>
#include <array>
#include <iomanip>
#include <set> // to store same countries only once
using namespace std;

void evalExpr(string expr, int n, double arr1[1000000], double arr2[1000000], double arr3[1000000], double arr4[1000000])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < expr.size(); j++)
        {
            if (expr[j] == '/')
            {
                if (j == 2)
                {
                    arr1[i] = arr1[i] / arr2[i];
                    arr2[i] = arr1[i];
                }
                else if (j == 5)
                {
                    arr2[i] = arr2[i] / arr3[i];
                    arr3[i] = arr2[i];
                    if (expr[2] == '/')
                    {
                        arr1[i] = arr2[i];
                    }
                }
                else if (j == 8)
                {
                    arr3[i] = arr3[i] / arr4[i];
                    arr4[i] = arr3[i];
                    if (expr[5] == '/')
                    {
                        arr2[i] = arr3[i];
                    }
                    if (expr[2] == '/')
                    {
                        arr1[i] = arr2[i];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < expr.size(); j++)
        {
            if (expr[j] == '*')
            {
                if (j == 2)
                {
                    arr1[i] = arr1[i] * arr2[i];
                    arr2[i] = arr1[i];
                    if (expr[5] == '/')
                    {
                        arr3[i] = arr2[i];
                    }
                    if (expr[8] == '/')
                    {
                        arr4[i] = arr3[i];
                    }
                }
                else if (j == 5)
                {
                    arr2[i] = arr2[i] * arr3[i];
                    arr3[i] = arr2[i];
                    if (expr[2] == '/' || expr[2] == '*')
                    {
                        arr1[i] = arr2[i];
                    }
                    if (expr[8] == '/')
                    {
                        arr4[i] = arr3[i];
                    }
                }
                else if (j == 8)
                {
                    arr3[i] = arr3[i] * arr4[i];
                    arr4[i] = arr3[i];
                    if (expr[5] == '/' || expr[5] == '*')
                    {
                        arr2[i] = arr3[i];
                    }
                    if (expr[2] == '/' || expr[2] == '*')
                    {
                        arr1[i] = arr2[i];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < expr.size(); j++)
        {
            if (expr[j] == '+')
            {
                if (j == 2)
                {
                    arr1[i] = arr1[i] + arr2[i];
                    arr2[i] = arr1[i];
                    if (expr[5] == '/' || expr[5] == '*')
                    {
                        arr3[i] = arr2[i];
                    }
                    if (expr[8] == '/' || expr[8] == '*')
                    {
                        arr4[i] = arr3[i];
                    }
                }
                else if (j == 5)
                {
                    arr2[i] = arr2[i] + arr3[i];
                    arr3[i] = arr2[i];
                    if (expr[2] == '/' || expr[2] == '*' || expr[2] == '+')
                    {
                        arr1[i] = arr2[i];
                    }
                    if (expr[8] == '/' || expr[8] == '*')
                    {
                        arr4[i] = arr3[i];
                    }
                }
                else if (j == 8)
                {
                    arr3[i] = arr3[i] + arr4[i];
                    arr4[i] = arr3[i];
                    if (expr[5] == '/' || expr[5] == '*' || expr[5] == '+')
                    {
                        arr2[i] = arr3[i];
                    }
                    if (expr[2] == '/' || expr[2] == '*' || expr[2] == '+')
                    {
                        arr1[i] = arr2[i];
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < expr.size(); j++)
        {
            if (expr[j] == '-')
            {
                if (j == 2)
                {
                    arr1[i] = arr1[i] - arr2[i];
                    arr2[i] = arr1[i];
                    if (expr[5] == '/' || expr[5] == '*' || expr[5] == '+')
                    {
                        arr3[i] = arr2[i];
                    }
                    if (expr[8] == '/' || expr[8] == '*' || expr[8] == '+')
                    {
                        arr4[i] = arr3[i];
                    }
                }
                else if (j == 5)
                {
                    arr2[i] = arr2[i] - arr3[i];
                    arr3[i] = arr2[i];
                    if (expr[2] == '/' || expr[2] == '*' || expr[2] == '+' || expr[2] == '-')
                    {
                        arr1[i] = arr2[i];
                    }
                    if (expr[8] == '/' || expr[8] == '*' || expr[8] == '+')
                    {
                        arr4[i] = arr3[i];
                    }
                }
                else if (j == 8)
                {
                    arr3[i] = arr3[i] - arr4[i];
                    arr4[i] = arr3[i];
                    if (expr[5] == '/' || expr[5] == '*' || expr[5] == '+' || expr[5] == '-')
                    {
                        arr2[i] = arr3[i];
                    }
                    if (expr[2] == '/' || expr[2] == '*' || expr[2] == '+' || expr[2] == '-')
                    {
                        arr1[i] = arr2[i];
                    }
                }
            }
        }
    }
}

int main()
{
    long long n;
    cin >> n;

    double arr1[n], arr2[n], arr3[n], arr4[n];

    string expr, region[n], country[n];

    cin >> expr;

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i] >> arr2[i] >> arr3[i] >> arr4[i] >> region[i] >> country[i];
    }

    set<pair<string, string>> myset;

    for (int i = 0; i < n; i++)
    {
        myset.insert(make_pair(region[i], country[i]));
    }

    unordered_map<string, double> a;

    evalExpr(expr, n, arr1, arr2, arr3, arr4); // caling function to evaluate expression

    for (int i = 0; i < n; i++)
    {
        a[country[i]] += arr1[i]; // storing same countries only once
    }
    for (auto i : myset)
    {
        cout << i.first << " " << i.second << " ";
        std::cout << std::fixed << std::showpoint;
        std::cout << std::setprecision(1);
        std::cout << a[i.second] << std::endl;
    }
    return 0;
}