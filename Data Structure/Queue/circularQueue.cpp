#include<bits/stdc++.h>
using namespace std;

class Queue{
  int rear, front;
  int size;
  int *arr;

  public:
      Queue(int s){
          size = s;
          front = rear = -1;
          arr = new int[s];
      }

      void enQueue(int value);
      int deQueue();
      void displayQueue();
};

 void Queue::enQueue(int value){
     if((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))){
        cout << "Queue is full\n";
        return;
     }
     else if(front == -1){
        rear = front = 0;
        arr[front] = value;
     }

     else if(rear == size - 1 && front != 0){
        rear = 0;
        arr[rear] = value;
     }
     else{
        rear++;
        arr[rear] = value;
     }
}

int Queue::deQueue(){

   if(front = -1){
    cout << "Queue is Empty\n";
    return INT_MIN;
   }

   int data = arr[front];
   arr[front] = 1;

   if(front == rear){
    rear = -1;
    front = -1;
   }
   else if(front == size - 1){
    front = 0;
   }
   else{
    front++;
   }
   return data;
}

void Queue::displayQueue(){
  if(front == -1){
    cout << "Queue is Empty\n";
    return;
  }
   cout << "\nElements in Circular Queue are: ";

  if(rear >= front){
    for(int i = front; i <= rear; i++){
        cout << arr[i] << " ";
    }
  }

  else{
    for(int i = front; i < size; i++){
        cout << arr[i] << " ";
    }
    for(int i = 0; i < rear; i++){
        cout << arr[i] << " ";
    }
  }

}

int main(){

 Queue q(5);

 q.enQueue(10);
 q.enQueue(11);
 q.enQueue(12);
 q.enQueue(13);
 q.enQueue(14);

 q.displayQueue();

 cout << "\nDeleted value = %d\n", q.deQueue();
 cout << "\nDeleted value = %d\n", q.deQueue();

 q.displayQueue();

 q.enQueue(9);
 q.enQueue(20);
 q.enQueue(5);

 q.displayQueue();
 q.enQueue(20);

 return 0;
}


