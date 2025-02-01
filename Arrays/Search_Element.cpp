// #include<iostream>
// using namespace std;
// int search(int arr[],int x){
//     for(int i=0;i<=10;i++){
//         if(arr[i]==x){
//             return i+1;
//         }
//     }
//             return -1;
// }
// int main(){
//     int array[10];
//     cout<<"Give the array elements"<<endl;
//     for(int i=0;i<10;i++){
//         cin>>array[i];
//     }
//     int answer;
//     int search_element;
//     cout<<"Enter Search element";
//     cin>>search_element;
//     answer=search(array,search_element);
//     cout<<"Element is present at"<<answer;
// }
#include <iostream>
using namespace std;

int search(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) { 
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int array[10];
    cout << "Give the array elements:" << endl;
    for (int i = 0; i < 10; i++) {
        cin >> array[i];
    }

    int search_element;
    cout << "Enter search element: ";
    cin >> search_element;

    int answer = search(array, 10, search_element);

    if (answer != -1)
        cout << "Element is present at position " << (answer + 1) << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
