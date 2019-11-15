#include<bits/stdc++.h>

using namespace std;

bool bloomFilter[100] = {0};

int calculate_h1(char arr[],int n)
{
    int sum=0;
    for( unsigned int i = 0; arr[i]!='\0' && i<20 ; i++)
    {
        //cout << "ascii value: " << (int)arr[i] << '\n';
        sum+=(int)arr[i];
    }
    //cout << "sum: " << sum << '\n';
    return sum % n;
}

int calculate_h2(char arr[], int n)
{
    int sum_h2=0;
    for( unsigned int i = 0; arr[i]!='\0' && i<20 ; i++)
    {
        int temp = (int)arr[i] % 13;
        //cout << "temp values: " << temp << '\n';
        sum_h2+=temp;
    }
    //cout << "sum2: " << sum_h2 << '\n';
    return sum_h2 % n;
}

bool check(string s, int n)
{
    char temp_arr[20];
    strcpy(temp_arr, s.c_str());
    temp_arr[20]='\0';

    int index1 = calculate_h1(temp_arr, n);
    int index2 = calculate_h2(temp_arr, n);

    if(bloomFilter[index1] && bloomFilter[index2])
        return true;

    return false;
}

void set_bloom(char arr[], int n)
{
    //h1 calculate
    int index = calculate_h1(arr, n);
    bloomFilter[index] = true;
    //cout << "index1: " << index << '\n';

    //h2 calculate
    int index_h2 = calculate_h2(arr, n);
    bloomFilter[index_h2] = true;
    //cout << "index2: " << index_h2 << '\n';
}

int main()
{
    int n;
    cin >> n;

    //w websites
    int w;
    cin >> w;
    while(w--)
    {
        string temp;
        cin >> temp;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        char arr[20];
        strcpy(arr, temp.c_str());
        arr[20]='\0';
        set_bloom(arr, n);
    }

    //t test case
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if(check(s, n))
            cout << "May be" << '\n';
        else
            cout << "Definitely not" << '\n';
    }

    return 0;
}