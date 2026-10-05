void problema_3(int n) {
    volatile int dummy = 0;
    for (int i = 1; i <= n / 3; i++) {
        for (int j = 1; j <= n; j += 4) {
            dummy++;
        }
    }
}