// 백준 1517 버블소트
#include <iostream>

using namespace  std;

int n;
long long int arr[500000]; // -> n^2 불가
long long int sorted[500000];
long long int cnt;

// i: 정렬된 왼쪽 리스트에 대한 인덱스
// j: 정렬된 오른쪽 리스트에 대한 인덱스
// k: 정렬될 리스트에 대한 인덱스
/* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */
/* (실제로 숫자들이 정렬되는 과정) */
void merge(long long int list[], int left, int mid, int right){
    int i, j, k, l;
    i = left;
    j = mid+1;
    k = left;

    /* 분할 정렬된 list의 합병 */
    while(i <= mid && j <= right){
        if(list[i] <= list[j]){
            if(k > mid) cnt++;
            sorted[k++] = list[i++];
        }
        else{ // list[i] > list[j];
            if(mid > k) cnt++;
            sorted[k++] = list[j++];
        }
        // cnt++;
    }

    // 남아 있는 값들을 일괄 복사
    if(i > mid){
        for(l = j ; l <= right ; l++)
        sorted[k++] = list[l];
        cnt++;
    }
    // 남아 있는 값들을 일괄 복사
    else{
        for(l = i ; l <= mid ; l++)
        sorted[k++] = list[l];
        cnt++;
    }

    // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
    for(l = left ; l <= right ; l++){
        list[l] = sorted[l];
    }
}

 // 합병 정렬
void merge_sort(long long int list[], int left, int right){
    int mid;

    if(left < right){
        mid = (left + right) / 2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
        merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
        merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
        merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cnt = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    merge_sort(arr, 0, n-1);

    cout << cnt << endl;
    return 0;
}