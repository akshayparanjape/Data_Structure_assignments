/* Complete program in  C++  to insert an element in sorted array */

#include <iostream>  // contains everything needed for input/output.

using namespace std;  // mainly for cout<< and cin>>

/*) function search for searching a position in an sorted array 'a'
where the value 'v' can be inserted using ternary search.*/

int search(int a[],int n,int v,int pos)
  //a[] array,n no of element in array
  //v value to be inserted
  // pos is the position where v is to be inserted
    {
        int new_l,new_r,left=0,right=n; //left, right are the extreme positions
        // new_l, new_r are the position at one third and two third in the array

        while(v<a[right])    // //while loop for the ternary search
        {
            new_l=(2*left+right)/3;  // one third
            new_r=(left+2*right)/3;  // two third
            if (v<a[new_l])
                right=new_l-1;
            else if (v>a[new_r])
                left=new_r+1;
            else
                {
                left=new_l+1;
                right=new_r-1;
                }
        }
        pos=right+1;   // getting the position for given value

        return pos;    //to be used in insert
    }

/* function insert to insert the value 'v' at the position returned by search function defined above. */

void insert(int a[],int m,int v,int pos)
// m size of array
// pos position returned from search
    {
        int j=m;
        while(j>=pos)
        {
            a[j+1]=a[j];
            j--;            // inserting the element v by shifting element to the right
        }
        a[j+1]=v;
    }


int main()   //main function calling above two function
{
    int n,v,i ;
    cout<< "Enter no of element in array :";
    cin>> n;
    cout<< "\nEnter the elements below :\n";
    int a[n];                 // array of size n+1
    for (i=0; i<n ; i++)      // increment of i by 1 upto n-1
    {
        cin>>a[i];            // building your array
    }
    int b[n],l,m,k;   //l,m,k for  loop
    for(m=0;m<n;m++)
    {
        b[m]=0;
    }
    b[0]=a[0];  //initial value
    for(l=1;l<n;l++)
    {
        v=a[l];
        insert(b,l-1,v,search(b,l-1,v,0));
        for (int i=0;i<n;i++)
        cout<<b[i]<<" ";
        cout<<endl;
    }
    cout<< " The sorted array is : ";
    for(k=0;k<n;k++)
    {

        cout << " " << b[k];
    }
}
