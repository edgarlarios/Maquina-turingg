#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <string>
#define strg 100
using namespace std;

map<int,char> cinta;

int cle=0;
char cadena[strg]="";


char write(char c){
     return cinta[cle]= c;
}

char read(){     
     return cinta[cle];
     }

bool move(char a, char b, int d){
            
     if(read()==a){  
          write(b);
           
          if(d==1){
               cle++;          
          }          
          else if(d==0){
               cle--;           
          }                 
         return true;          
     }
     else{
          return false;          
     }     
}

void R(){    
    move(read(), read(), 1);  
}
     
void L(){    
    move(read(),read(),0);
}
  
void Rx(char a){    
       if(read()=='\0'){                        
           cinta[cle]=' ';
       }
     while(read()!= ' '){
         move(read(), read(), 1);  
       if(read()=='\0'){
         cinta[cle]=' ';
       }
     }                
}
     
void Lx(char a){   
   if(read()=='\0'){
           cinta[cle]=' ';
   }
     while((read()=='1')||(read()=='0')){
         move(read(), read(), 0);       
         if(read()=='\0'){
             cinta[cle]=' ';
         } 
     }    
}
        
void A(char a){
    move(read(), a, 1); 
    move(read(), read(), 0);        
}
void leerCinta(){        
     int j=-1;
      if((cinta[j-1]=='1')||(cinta[j-1]=='0')){
              cout<<"."<<cinta[j-1];
      }
     if((read()==' ')&&(cle==-1)){
         cout<<"."<<cinta[j++];         
     }
     else{
         cout<<cinta[j++];           
     }       
     while((cinta[j] == '0')||(cinta[j] == '1')){                                 
          if(j == cle){
              cout<<"."<<cinta[j++];                                        
           }              
          if(j != cle){
                cout<<cinta[j++];                             
          }                                  
      }
      if((read()==' ')&&(cle>0)){
            cout<<"."<<cinta[j++];          
       }     
      cout<<endl;
}

char MComp(){
   Lx('\0');
   leerCinta();   
   R();
   while(read()!= ' '){   
                
       if(read()== '1'){
                                
           A('0'); 
           leerCinta(); 
           R();                      
       }
       if(read() == '0'){                                  
            A('1');
            leerCinta();  
            R();           
       }       
   }
    leerCinta();                                                     
}

             
void MInc(){  
   leerCinta();                             
   L();
   
   if(read()=='1'){                                   
        A('0');
        leerCinta();   
        L();
        if(read()=='1'){                                        
           while(read()== '1'){             
               A('0');
               leerCinta();   
               L();                                
           }           
        }  
        if(read()== ' '){
           leerCinta();              
           L();                              
           A('1');
           leerCinta();             
          }
   }                                                                                               
   if(read()== '0'){      
       A('1'); 
       leerCinta();   
       L();      
       while((read()=='0') || (read()== '1')){
              if(read()== '1'){                  
                   A('1');
                   leerCinta();   
                   L();                     
              }      
              if(read()== '0'){                 
                  A('0');
                  leerCinta();  
                  L();      
              }            
       }
        if(read()== ' '){ 
           leerCinta();             
           L();                              
           A('0');
           leerCinta();             
          }                                           
    }     
   cout<<endl;                                                          
}                                                                    

void insertandoCadena( char *z){                           
     while(z[cle] != '\0'){
         write(z[cle]);  
         R();                               
     } 
     Rx('\0');         
     cout<<endl; 
     cout<<endl;        
     cle=0;           
}   

void M(){     
     
    cout<<"complemento a unos: ";      
    cout<<endl;   
    MComp();   
    cout<<endl;
    cout<<"complemento a 2's ";
    cout<<endl;             
    MInc();                                                  
    cout<<endl;      
    cout<<"la operacion de transicion tuvo exito"<<endl;
    cout<<endl;
}
   

int main(){
   
    cout<<"ingrese una cadena binaria: ";
    cin>>cadena;
    cout<<endl;
    insertandoCadena(cadena);            
    M();                  
    system("PAUSE");  
}
