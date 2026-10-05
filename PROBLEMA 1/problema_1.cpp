void problema_1(int n) {
    volatile int counter = 0;
    for (int i = n / 2; i <= n; i++) {
        for (int j = 1; j + n / 2 <= n; j++) {
            for (int k = 1; k <= n; k = k * 2) {
                counter++;
            }
        }
    }
}