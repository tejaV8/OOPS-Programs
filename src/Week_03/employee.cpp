#include<iostream>
using namespace std;

class Employee{
      int salary, exp;
      string ename, desig;
      
      public:
      int eid;
      
      void setDetails(){
          cout<<"Enter employee name: ";
          cin>>ename;
          
          cout<<"Enter employee ID: ";
          cin>>eid;
          
          cout<<"Enter designation: ";
          cin.ignore();
          getline(cin, desig);
          
          cout<<"Enter experience: ";
          cin>>exp;
          
          cout<<"Enter salary: ";
          cin>>salary;
      }
      
      void setInr(){
          if(exp >= 20)
              salary  += salary*0.15;
          else if(exp >= 10)
              salary += salary*0.10;
          else
              salary += salary*0.05;
      }
      
      void profile(){
          cout<<"\n--Employee profile--\n";
          cout<<"Employee ID: "<<eid<<endl;
          cout<<"Name: "<<ename<<endl;
          cout<<"Designation: "<<desig<<endl;
          cout<<"Experience: "<<exp<<endl;
          cout<<"Updated Salary: "<<salary<<endl;
      }
};

int main(){
    int n;
    cout<<"Enter number of employees: ";
    cin>>n;
    
    Employee e[n];
    
    for(int i = 0; i < n ; i++){
        cout<<"\nEnter details of employee "<<i+1<<": \n";
        e[i].setDetails();
    }
    
    for(int i = 0; i < n ; i++)
        e[i].setInr();
    
    cout<<"\n===== Employee Details =====\n";
    for(int i = 0; i < n; i++)
        e[i].profile();
    
    return 0;
}