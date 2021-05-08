//
// Created by helianhaodong on 2021/4/25.
//

/*
 *  fucntion 作参数类型实现回调
 */

#include "../all.h"

void selectSort(int* p, int n, std::function<bool(int, int)> cmp)
{
    for (int i = 0; i < n - 1; i ++ )
        for (int j = i + 1; j < n; j ++ )
            if (cmp(p[i], p[j]))
            {
                p[i] ^= p[j];
                p[j] ^= p[i];
                p[i] ^= p[j];
            }
}

int mainsele()
{
    int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    selectSort(arr, sizeof(arr) / sizeof(arr[0]), [](int x, int y) {
        return x > y;
    });

    std::for_each(arr, arr + 10, [](int& i){
        std::cout << i << std::endl;
    });

    return 0;
}
