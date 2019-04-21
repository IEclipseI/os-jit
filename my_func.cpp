//
// Created by roman on 20.04.19.
//

int count_1() {
    unsigned int x = 0xAFBFCFDF;
    int res = 0;
    while(x != 0) {
        if (x % 2 == 1)
            res++;
        x /= 2;
    }
    return res;
}


//55 48 89 e5 c7 45 f8 df cf bf af c7 45 fc 00 00
//00 00 83 7d f8 00 74 18 8b 45 f8 83 e0 01 85 c0
//74 04 83 45 fc 01 8b 45 f8 d1 e8 89 45 f8 eb e2
//8b 45 fc 5d c3
