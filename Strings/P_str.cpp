#include <iostream>
#include <algorithm>
using namespace std;

void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}

void find(char charArr[], int index, int length){
    if(index == length){
        for(int i = 0; i < length; ++i){
            cout << charArr[i];
        }
        cout << endl; 
        return;
    }

    for(int i = index; i < length; ++i){
        swap(charArr[i], charArr[index]);
        find(charArr, index + 1, length);
        swap(charArr[i], charArr[index]); 
    }
}

int main(){
    string str;
    cin >> str;
    int length = str.length();
    char* charArr = &str[0];
    find(charArr, 0, length);
    return 0;
}
