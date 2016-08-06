//文件名:BubbleSort.cpp
// 冒泡排序算法实现:读一串整型数据　进行排序　　最后输出
//冒泡排序思想：从头到尾比较相邻的两个元素，小的放前面，大的放后面，这样一次冒泡后最大的就是最后一个
//再从头开始到size-1比较相邻的元素，这样比较的冒泡次数为size-１，比较次数为size-(本次冒泡第i次)
#include <iostream>
using namespace std;
#define MAX 10
int ReadIntegerArray(int array[],int max,int flag);
void BubbleSort(int array[],int size);
void PrintIntegerArray(int array[],int size);
int main(){
    int IntegerArray[MAX],flag,CurrentSize;

    cout<<"请输入结束标记：";
    cin>>flag;

    CurrentSize=ReadIntegerArray(IntegerArray,MAX,flag);
    BubbleSort(IntegerArray,CurrentSize);
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

//函数：BubbleSort
//作用：将array里的数据进行冒泡排序，size为数组长度
//i表示冒泡次数，j表示比较次数
void BubbleSort(int array[],int size){
    int temp;
    bool flag;  //记录一趟冒泡中有没有发生过交换
    int i,j;
    for(i=1;i<size;i++){
       flag=false;
       for(j=0;j<size-i;j++){
           if(array[j]>array[j+1]){
               temp=array[j];
               array[j]=array[j+1];
               array[j+1]=temp;
               flag=true;
           }
       }
       if(flag!=true)  break;  //没有交换，已经有序，无需再冒泡
    }
}

//函数：PrintIntegerArray
//作用：打印输出array
void PrintIntegerArray(int array[],int size){
    if(size==0)  return;
    cout<<"冒泡排序后是："<<endl;
    for(int i=0;i<size;i++){
        cout<<array[i]<<'\t';
    }
}
