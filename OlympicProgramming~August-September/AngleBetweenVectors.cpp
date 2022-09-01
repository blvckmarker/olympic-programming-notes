#include "GeometricBase.h"

using namespace std;

inline double const scalar_product(vector<double> a, vector<double> b)
{
    double sp = 0;
    for (int i = 0; i < a.size(); ++i) {
        sp += a[i] * b[i];
    }

    return sp;
}

inline double const length(vector<double> a) {
    return sqrt(scalar_product(a, a));
}

inline double const get_angle(vector<double> a, vector<double> b) {
    return acos(scalar_product(a, b) / (length(a) * length(b)));
}


int main() {

    int n;
    cin >> n;

    vector<double> v1(n), v2(n);

    for (auto& x : v1) 
        cin >> x;
    for (auto& x : v2) 
        cin >> x;

    cout << get_angle(v1, v2) << "\n";

    return 0;
}