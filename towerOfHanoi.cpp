#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n,char fromRod,char toRod,char auxRod)
{
    if(n==1)
    {
        cout<<"A move disk 1 from rod "<<fromRod<<" to "<<toRod<<endl;
        return;
    }
    towerOfHanoi(n-1,fromRod,auxRod, toRod);
    cout<<"B move disk "<<n<<"from "<< fromRod<<" to "<<toRod<<endl;
    towerOfHanoi(n-1,auxRod,toRod,fromRod);
}

int main()
{
    int n;
    cin>>n;

    towerOfHanoi(n,'A','C','B');
    return 0;

}
