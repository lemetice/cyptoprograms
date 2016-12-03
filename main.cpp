/* 
 * File:   main.cpp
 * Author: Arnold
 *
 * Created on November 29, 2016, 11:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <process.h>
#include <string.h>

using namespace std;

/*
 * 
 */
int Eucli(long a, long b);
int ExtdEucli(long a, long b);
void rsa();
void railFence();
void ceaserCipher();

int main(int argc, char** argv) {
    
    cout<<"Cryptographic Programs: CSE515"<<endl;
    int i=1, ch;
    long a,b;
    
    do{
        cout<<"\n 1. To find GCD of Euclidean Algorithm";
        cout<<"\n 2. To find GCD and MI using Extended Euclidean Algorithm";
        cout<<"\n 3. To run RSA Algorithm";
        cout<<"\n 4. To run RailFence Algorithm";
        cout<<"\n 5. To run Ceaser Cipher Algorithm";
        cout<<"\n 6. To Exit(^_^) \n";
        cin>>ch;
        
        switch(ch){
            case 1:
                cout<<"Enter two numbers"<<endl;
                cin>>a>>b;
                 Eucli(a,b);                
                break;            
            case 2:
                cout<<"Enter two numbers"<<endl;
                cin>>a>>b;
               // ExtdEucli(a,b);
                break;                
            case 3:  
                rsa();
                break;
            case 4:
                railFence();
                break;
            
            case 5:
                   ceaserCipher();
                   break;
                   
            case 6:
                exit(0);
            default:
                cout<<"Wrong choice!. Select from the list above"<<endl;
        }
        i++;
    }while(i>0);
    
    return 0;
}

/*GCD Algorithm*/
int Eucli(long a, long b){
    long r, r1,r2;
    if(a>b){
        r1=a; r2=b;
    }else{
        r2=a; r1=b;
    }
    
    while(r2!=0){
        r=r1%r2;
        r1=r2;
        r2=r;
    }
    cout<<"\n|** The GCF is:"<<r1<<"\t**|"<<endl;
    
    return r1;
}

/*RSA Algorithm*/
void rsa(){
    int p,q,e,m,d,n,c,pi, i;
    cout<<"\tEnter two prime numbers\n";
    cin>>p>>q;
    
    n = p*q;
    pi = (p-1)*(q-1);
    
    cout<<" Euler Totient (phi)="<<pi<<endl<<" N = "<<n<<endl;
    for(i=2;i<=100;i++){
        e = Eucli(i, pi);
        if(e==1){
            cout<<"Public key= {"<<i<<","<<n<<"}"<<endl;
            break;
        }
    
    }
    
    cout<<"################# e="<< i <<" ###############";
    
    for(d=2; d<=100;d++){
        if((d*i)%pi == 1){
            cout<<"Private key= {"<<d<<","<<n<<"}"<<endl;
            break;
        }
            
    }
    
}

/*RailFence Algorithm*/
void railFence(){
    cout<<"Welcome to RailFence Cipher Algorithm\n";
    int i,j,k;
    char pt[20], ct[20],dt[20];
    
    cout<<"Enter plain text:\n";
    cin>>pt;
    int l = strlen(pt);
    
    /*Ciphering*/
    for(i=0,j=0;i<l;i++){
        if(i%2==0) ct[j++]= pt[i];
    }
    for(i=0;i<l;i++){
        if(i%2==1) ct[j++]= pt[i];
    }
    
    ct[j]='\0';
    cout<<"\n Cipher text is:\n"<<ct;
    
    /*Deciphering*/
    if(l%2==0){
        k =l/2;
    }else{
        k=(l/2)+1;
    }
    for(i=0,j=0;i<k;i++){
        dt[j] = ct[i];
        j=j+2;
    }
    for(i=k,j=1;i<l;i++){
        dt[j]=ct[i];
        j=j+2;
    }
    dt[l]='\0';
    cout<<"\n Decrypted text :\n"<<dt;
    
}

/*Ceaser Cipher Algorithm*/
void ceaserCipher(){
    
    cout<<"Welcome to Ceaser cipher Encryption\n\n";
    char pt[100], c[100],ct[100];
    int i=0,k;
    
    cout<<"Enter the key (must be an integer):\n"<<endl;
    cin>>k;
    cout<<"Enter the Plain text:"<<endl;
    cin>>pt;
    
    /*Normal Ciphering*/
    for(i=0;i<=strlen(pt);i++){
        if(isalpha(pt[i])){
            pt[i]=toupper(pt[i]);//use upper to keep from having to use two seperate for A..Z a..z
            ct[i]=(((pt[i]-65)+13)%26)+65;
        }
    }
    cout<<"\nCiphertext(Without Key):\n"<<ct;
    
    /*Ciphering*/
    for(i=0;pt[i]!='\0';i++){
        
        c[i]= (pt[i]-'a'+k)%26+'a';
        //cout<<c[i];
        ct[i]=c[i];
    }
    cout<<"\nCipher text:\n"<<ct;
    
    /*Deciphering*/
    for(i=0;ct[i]!='\0';i++){
        pt[i]= 'z'-('z'+k-c[i]);
        //cout<<pt[i];
    }
    cout<<"\nPlaintext:"<<pt<<endl;
}