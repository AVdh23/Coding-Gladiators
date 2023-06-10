#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int animals, cap;
    cin >> animals >> cap;

    vector<int> energy(animals);
    for (int i = 0; i < animals; i++) {
        cin >> energy[i];
    }

    sort(energy.begin(), energy.end());

    if (cap == animals) {
        cout << energy[0];
    } else if (energy[animals - cap] == energy[animals - cap - 1]) {
        cout << "-1";
    } else {
        cout << energy[animals - cap];
    }

    return 0;
}
