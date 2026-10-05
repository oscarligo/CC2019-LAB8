void problema_2(int n) {
    if (n <= 1) return;
    volatile int dummy = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dummy++;
            break;
        }
    }
}