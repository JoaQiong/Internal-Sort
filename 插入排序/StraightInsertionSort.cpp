//文件名:StraightInsertionSort.cpp
//直接插入排序算法实现:读一串整型数据　进行排序　　最后输出
//整个排序过程为进行n-1趟插入，即：先将序列中的第一个记录看成是一个有序的子序列，然后从
//第二个记录起逐个进行插入，直至逐个序列有序．
#include <iostream>
using namespace std;
#define MAX 10
int ReadIntegerArray(int array[],int max,int flag);
void StraightInsertionSort(int array[],int size);
void StraightInsertionSort2(int array[],int size);
void PrintIntegerArray(int array[],int size);
int main(){
    int IntegerArray[MAX],flag,CurrentSize;

    cout<<"请输入结束标记：";
    cin>>flag;

    CurrentSize=ReadIntegerArray(IntegerArray,MAX,flag);
    StraightInsertionSort(IntegerArray,CurrentSize);
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

//函数：StraightInsertionSort
//作用：将array里的数据进行直接插入排序，size为数组长度
void StraightInsertionSort(int array[],int size){
    int temp;
    for(int i=1;i<size;i++){
        temp=array[i];
        if(array[i]<array[i-1]){
            int j;
            for(j=i-1;j>=0&&array[j]>temp;--j){
                array[j+1]=array[j];
            }
            array[j+1]=temp;
        }
    }
}

//函数：PrintIntegerArray
//作用：打印输出array
void PrintIntegerArray(int array[],int size){
    if(size==0)  return;
    cout<<"直接插入排序后是："<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<'\t';
    }
}
