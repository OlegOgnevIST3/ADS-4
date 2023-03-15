// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int x = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                x++;
        }
    }
    return x;
}
int countPairs2(int* arr, int len, int value) {
    int x = 0;
    int a = len - 1;
    while (arr[a] > value) {
        a--;
    }
    for (int i = 0; i < a; i++) {
        for (int j = a; j > i; j--) {
            if (arr[i] + arr[j] == value)
                x++;
            if (arr[i] + arr[j] < value)
                continue;
        }
    }
    return x;
}
int countPairs3(int* arr, int len, int value) {
    int x = 0;
    for (int i = 0; i < len - 1 && arr[i] <= value; i++) {
        x += fun(arr + i + 1, len - i - 1, value - arr[i]);
    }
    return x;
}
int fun(int* arr, int size, int value) {
    int b = 0, a = size, c;
    int x = 0;
    while (b <= a) {
        c = (b + a) / 2;
        if (arr[c] < value) {
            b = c + 1;
        }
        else if (arr[c] > value) {
            a = c - 1;
        }
        else {
            x++;
            int i = c - 1;
            while (i >= b && arr[i] == value) {
                x++;
                i--;
            }
            i = c + 1;
            while (i <= a && arr[i] == value) {
                x++;
                i++;
            }
            return x;
        }
    }
    return x;
}
