#include <iostream>
#include <vector>

using namespace std;

pair<int, int> binary_search(const vector<int>& arr, const int n, const int x) {
    int l = 0, r = n;

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] >= x) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    int first_a = l;

    if (first_a == n || arr[first_a] != x) {
        return make_pair(first_a, first_a);
    }

    l = first_a;
    r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] <= x) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    return make_pair(first_a, l);
}

int main () {
    int n = 0, k = 0;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;
    vector<int> in_data(k);
    for (int i = 0; i < k; i++) {
        cin >> in_data[i];
    }

    for (int i : in_data) {
        auto result = binary_search(arr, n, i);
        int susp_f = result.first;
        int susp_s = result.second;

        if (susp_f < n && arr[susp_f] == i) {
            cout << 1 << " " << susp_f << " " << susp_s << endl;
        }
        else {
            cout << 0 << " " << susp_f << " " << susp_s << endl;
        }
    }
}