
#include <iostream>
#include<pthread.h>
#include <unistd.h>
#include <ctype.h>

#include <string.h>
using namespace std;

const int total_threads = 4;
string x;

void* input_string( void*arg)
{

   
    cout<<"Thread no -1 \nEnter String:";
    cin>>x;
  
          
      
        pthread_exit(NULL);
    return 0;
}


void* reverse(void * arg)
{
      sleep(2);
       cout<<"Thread no -2 \nReversing :\n";
   
    int n =x.length() , i;
    i=n;
  
    while(i>=0)
    {
        cout<<x[i];
        i--;
        
    }
        
    return 0;

        pthread_exit(NULL);
}
void* ttouper(void * arg)
{
     sleep(4);
      cout<<"\nThread no -3 \nCapitalizing:\n";
 
      int n =x.length() , i;
    i=0;

    while(i<n)
    {
           cout<<(char)toupper(x[i]);
        i++;
        
    }
      pthread_exit(NULL);
return 0;

}
void * shiftthread(void * args)
{
    
    sleep(5);
     cout<<"\nThread no -4 \nShifting:\n";
      
       int n =x.length() , i;
    i=0;
 
    while(i<n)
    {
           cout<<(char)(x[i]+2);
        i++;
        
    }
    cout<<"\n";
     pthread_exit(NULL);
    return 0;
         
    
   
    
}
int main()
{
 

    pthread_t thread[total_threads];
    pthread_create(&thread[0] ,NULL , &input_string ,NULL);
       pthread_create(&thread[1] ,NULL , &reverse ,NULL);
         pthread_create(&thread[2] ,NULL , &ttouper,NULL);
             pthread_create(&thread[3] ,NULL , &shiftthread,NULL);

   
    pthread_join(thread[0],NULL);
      pthread_join(thread[1],NULL);
          pthread_join(thread[2],NULL);
             pthread_join(thread[3],NULL);
             return 0;
}

