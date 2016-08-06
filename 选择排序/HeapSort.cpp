//文件名:HeapSort.cpp
//堆排序算法实现:读一串整型数据　进行排序　　最后输出
//堆排序是nlogn的不稳定的排序算法，首先对每个非叶子结点调用向下过滤函数将数组调整为一个堆
//然后执行n-1次deQueue，即将array[0]与堆的最后一个元素相交换，堆规模减１.再对堆的根调用向下过滤，使堆重新有序
#include <iostream>
using namespace std;
#define MAX 10
int ReadIntegerArray(int array[],int max,int flag);
void HeapSort(int array[],int size);
void percolateDown(int array[],int hole,int size);
void PrintIntegerArray(int array[],int size);
int main(){
    int IntegerArray[MAX],flag,CurrentSize;

    cout<<"请输入结束标记：";
    cin>>flag;

    CurrentSize=ReadIntegerArray(IntegerArray,MAX,flag);
    HeapSort(IntegerArray,CurrentSize);
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

//函数：HeapSort
//作用：将array里的数据进行直接插入排序，size为数组长度
void HeapSort(int array[],int size){
    int temp;
    int i;

    //创建初始的堆
    for(i=size/2-1;i>=0;i--){
        percolateDown(array,i,size);
    }

    //执行n-1次deQueue
    for(i=size-1;i>0;--i){
        temp=array[0];
        array[0]=array[i];
        array[i]=temp;
        percolateDown(array,0,i);
    }
}

//函数：percolateDown向下过滤函数
//作用：进行堆排，第一个参数是待排序的数组，第二个参数是向下过滤的起始位置，第三个是目前堆的大小
void percolateDown(int array[],int hole,int size){
    int child;
    int temp=array[hole];
    for(;hole*2+1<size;hole=child){
        child=hole*2+1;
        if(child!=size-1&&array[child+1]>array[child]){
            child++;
        }
        if(array[child]>temp){
            array[hole]=array[child];
        }
        else{
            break;
        }
    }
    array[hole]=temp;
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
