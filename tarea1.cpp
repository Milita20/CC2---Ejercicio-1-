#include<iostream>
using namespace std;
class DynamicIntegerArray{
private:
    int *data;
    int _size;
public:
    DynamicIntegerArray(){
        this->_size=0;
        this->data=new int[0];
    }
    DynamicIntegerArray(int arr[],int _size){
        this->_size=_size;
        this->data=new int[_size];
        for(int i=0;i<_size;i++)
            data[i]=arr[i];
    }
    DynamicIntegerArray(const DynamicIntegerArray &o){
        this->_size=o._size;
        this->data=new int[o._size];
        for(int i=0;i<_size;i++)
            data[i]=o.data[i];
    }
    int getSize()const{
        return _size;
    }
    void insertar(int value,int pos){
        int *b;
        b=new int[_size+1];
        for(int i=0;i<_size+1;i++)
        {
            if(i<pos){
                b[i]=data[i];
            }
            else if(i==pos){
                b[i]=value;
            }
            else if(i>pos){
                b[i]=data[i-1];
            }
        }
        delete [] data;
        for(int i=0;i<_size+1;i++)
            cout<<b[i]<<endl;
        cout<<value<<" "<<pos<<endl;
        delete [] b;
    }
    void remover(int pos){
        int *b,aux;
        b=new int[_size -1];
        int j=0;
        for(int i=0;i<_size;i++){
            if(i!=pos-1){
                b[j]=data[i];
                j++;
            }
            //cout<<b[i]<<endl;
            //cout<<pos<<" "<<endl;
        }
        delete [] data;
        for(int i=0;i<_size-1;i++)
            cout<<b[i]<<endl;
        delete[] b;
    }
    void push_backs(int value){
        int *b;
        b=new int[_size+1];
        for(int i=0;i<_size;i++)
            b[i]=data[i];
        b[_size]=value;
        delete [] data;
        for(int i=0;i<_size+1;i++)
            cout<<b[i]<<endl;
        delete [] b;
    }
    ~DynamicIntegerArray(){
        delete[] data;
    }
};

int main(){
    DynamicIntegerArray pa;
    //cout<<pa.getSize()<<endl;
    int arr[]={1,2,3,4,5};
    DynamicIntegerArray pa2(arr,5);
    DynamicIntegerArray pa3=pa2;
    //cout<<pa3.getSize()<<endl;
    DynamicIntegerArray *ptr=&pa3;
    //cout<<ptr->getSize()<<endl;
    pa2.insertar(3,3);
    //pa2.push_backs(4);
    //pa2.remover(3);
    return 0;
}
