#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

double medianVec(const vector<int>& v) {
    int m = v.size();
    if (m % 2 == 0)
        return (v[m/2 - 1] + v[m/2]) / 2.0;
    else
        return (double)v[m/2];
}

int main() {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    vector<int> data(n);
    cout << "Masukkan data: ";
    for (int i = 0; i < n; i++) cin >> data[i];

    sort(data.begin(), data.end());

    double total = 0;
    for (int x : data) total += x;
    double mean = total / n;

    double median = medianVec(data);

    map<int,int> freq;
    for (int x : data) freq[x]++;
    int maxFreq = 0;
    for (auto &p : freq) maxFreq = max(maxFreq, p.second);

    vector<int> modus;
    for (auto &p : freq)
        if (p.second == maxFreq) modus.push_back(p.first);

    vector<int> lower, upper;
    if (n % 2 == 0) {
        lower.assign(data.begin(), data.begin() + n/2);
        upper.assign(data.begin() + n/2, data.end());
    } else {
        lower.assign(data.begin(), data.begin() + n/2);
        upper.assign(data.begin() + n/2 + 1, data.end());
    }

    double q1 = medianVec(lower);
    double q2 = median;
    double q3 = medianVec(upper);

    cout << "\nHasil Perhitungan\n";
    cout << "Mean    : " << mean << endl;
    cout << "Median  : " << median << endl;

    cout << "Modus   : ";
    for (int m : modus) cout << m << " ";
    cout << endl;

    cout << "Kuartil 1 (Q1): " << q1 << endl;
    cout << "Kuartil 2 (Q2): " << q2 << endl;
    cout << "Kuartil 3 (Q3): " << q3 << endl;

    return 0;
}
