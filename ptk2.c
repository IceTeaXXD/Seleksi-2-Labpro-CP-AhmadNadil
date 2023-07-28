#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int k;
    int v;
} Pair ;

typedef struct {
    Pair* arr[10000];
} HashMap;

typedef struct {
    int a;
    int b;
} Result;

HashMap* createHashMap() {
    HashMap* hm = (HashMap*) malloc(sizeof(HashMap));
    memset(hm->arr, 0, sizeof(hm->arr));
    return hm;
}

void append(HashMap* hm, int k, int v) {
    int idx = k % 10000;
    if (hm->arr[idx] == NULL) {
        Pair* p = (Pair*) malloc(sizeof(Pair));
        p->k = k;
        p->v = v;
        hm->arr[idx] = p;
    } else {
        int newIdx = idx+1;
        while (hm->arr[newIdx] != NULL) {
            newIdx++;
        }
        Pair* p = (Pair*) malloc(sizeof(Pair));
        p->k = k;
        p->v = v;
        hm->arr[newIdx] = p;
    }
}

Result findres(int arr[], int size, int target){
    Result res;
    HashMap* hm = createHashMap();
    for (int i = 0; i < size; i++) {
        append(hm, arr[i], i);
    }
    for (int i = 0; i < size; i++) {
        int temp = target - arr[i];
        int idx = temp % 10000;
        if (hm->arr[idx] != NULL) {
            if (i != hm->arr[idx]->v) {
                if (i>hm->arr[idx]->v) {
                    res.a = hm->arr[idx]->v;
                    res.b = i;
                    return res;
                } else {
                    res.a = i;
                    res.b = hm->arr[idx]->v;
                    return res;
                }
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    int target;
    scanf("%d", &target);
    Result res = findres(arr, n, target);
    printf("%d %d\n", res.a, res.b);
    return 0;
}