#include <stdio.h>

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    
    long long int energy[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &energy[i]);
    }
    
    // Find the minimum and maximum energy levels
    long long int minEnergy = energy[0];
    long long int maxEnergy = energy[0];
    for (int i = 1; i < N; i++) {
        if (energy[i] < minEnergy) {
            minEnergy = energy[i];
        }
        if (energy[i] > maxEnergy) {
            maxEnergy = energy[i];
        }
    }
    
    // Binary search to find the minimum energy level P
    long long int result = -1;
    while (minEnergy <= maxEnergy) {
        long long int midEnergy = (minEnergy + maxEnergy) / 2;
        
        // Count the number of animals with energy levels >= midEnergy
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (energy[i] >= midEnergy) {
                count++;
            }
        }
        
        if (count == X) {
            result = midEnergy;
            break;
        } else if (count < X) {
            maxEnergy = midEnergy - 1;
        } else {
            minEnergy = midEnergy + 1;
        }
    }
    
    printf("%lld\n", result);
    
    return 0;
}
