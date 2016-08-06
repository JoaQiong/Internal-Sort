//文件名:quickSort2.cpp
// 快速排序算法实现:读一串整型数据　进行排序　　最后输出
//快速排序思想：在待排序列中找到一个标准元素，将所有元素分为两组，使得第一组数据小于或等于标准元素，第二组数据大于标准元素
//第一组数据放在数组前面，第二组数据放在数组后面，标准元素放中间．然后对分成的两组数据重复上述过程．
#include <iostream>
using namespace std;
#define MAX 10
int ReadIntegerArray(int array[],int max,int flag);
void quickSort(int array[],int size);
void quickSort(int array[],int low,int high);
int Position(int array[],int low,int high);
void PrintIntegerArray(int array[],int size);
int main(){
    int IntegerArray[MAX],flag,CurrentSize;

    cout<<"请输入结束标记：";
    cin>>flag;

    CurrentSize=ReadIntegerArray(IntegerArray,MAX,flag);
    quickSort(IntegerArray,CurrentSize);
    PrintIntegerArray(IntegerArray,CurrentSize);

    return 0;
}

//函数：ReadIntegerArray
//作用：接收用户的输入，存入数组array，max是array的大小，flag是输入结束标记
//当输入数据个数达到最大长度或输入了flag时结束
int ReadIntegerArray(int array[],int max,int flag){
    int size=0;

    cout<<"请输入数组元素，以"<<flag<<"结束:  :";
    while(size<max){
    cin>>array[size];
        if(array[size]==flag) break;
        else ++size;
    }

    return size;
}

//快排包裹函数，为了与之前的排序算法一致
void quickSort(int array[],int size){
    quickSort(array,0,size-1);
}


//重载quickSort函数，实现递归过程
void quickSort(int array[],int low,int high){
    int flag;
    if(low>=high) return;
       flag=Position(array,low,high);
       quickSort(array,low,flag-1);
       quickSort(array,flag+1,high);
}

//函数：Position
//作用：将array里的数据在low--high数据段通过快排找到low的最终位置
//让array[low]的位置空出来
//从右往左找，保证右边大，当前high位置正确，再往左看
//找到不比temp大的值进行交换，让array[high]的位置空出来    ++low，继续下面的while，从左往右找，保证左边小
 //从左往右找，保证左边小，当前low位置正确，再往右看
 //找到比temp大的值进行交换，让array[low]的位置空出来
int Position(int array[],int low,int high){
    int temp;
    temp=array[low];
    while(low<high){
       while(low<high&&temp<=array[high]){
           --high;
       }
       if(low<high){
           array[low]=array[high];
           ++low;
       }
       while(low<high&&temp>array[low]){
           ++low;
       }
       if(low<high){
           array[high]=array[low];
           --high;
       }
    }
    array[low]=temp;
    return low;
}

//函数：PrintIntegerArray
//作用：打印输出array
void PrintIntegerArray(int array[],int size){
    if(size==0)  return;
    cout<<"快速排序后是："<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<'\t';
    }
}
