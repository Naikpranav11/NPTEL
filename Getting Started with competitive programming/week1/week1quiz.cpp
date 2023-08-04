#include<iostream>
using namespace std;

// int fun(int n){
//     int count = 0;
//     int i,j;
//     for (int i = 0; i < n; i++)
//     {
//         j = 1;
//         while (j<n)
//         {
//             count += 1;
//             j = j + 2;
//         }
        
//     }
//     return count;
// }
int main(){

    int count = 0;
    int n = 48;
    while(n > 1){
        if (n % 2 == 0)
        {
            n /= 2;
        }

        else{
            n = 3 * n + 1;
        }
        count++;
    }
    cout<<count<<endl;

    return 0;
}

//48 24 12 6 3 10 5 16 8 4 2 1