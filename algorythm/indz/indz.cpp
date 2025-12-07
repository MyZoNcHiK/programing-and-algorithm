
#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long linear_search_idx(long long n,long long x){
    for(long long i=0;i<n;i++){
        long long v=i*2;
        if(v==x){
            return i;
        }
    }
    return -1;
}

long long binary_search_idx(long long n,long long x){
    long long l=0,r=n-1;
    while(l<=r){
        long long m=l+(r-l)/2;
        long long v=m*2;
        if(v==x){
            return m;
        }
        if(v<x){
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return -1;
}

long long linear_search_cmp(long long n,long long x,long long& cmp){
    cmp=0;
    for(long long i=0;i<n;i++){
        long long v=i*2;
        cmp++;
        if(v==x){
            return i;
        }
    }
    return -1;
}

long long binary_search_cmp(long long n,long long x,long long& cmp){
    cmp=0;
    long long l=0,r=n-1;
    while(l<=r){
        cmp++;
        long long m=l+(r-l)/2;
        long long v=m*2;
        if(v==x){
            return m;
        }
        if(v<x){
            l=m+1;
        }else{
            r=m-1;
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N[4]={10,1000,1000000,1000000000LL};
    double lin_t_pres_us[4],lin_t_abs_us[4],bin_t_pres_us[4],bin_t_abs_us[4];
    long long lin_cmp_pres[4],lin_cmp_abs[4],bin_cmp_pres[4],bin_cmp_abs[4];
    long long lin_idx_pres[4],bin_idx_pres[4];
    volatile long long sink=0;

    for(int s=0;s<4;s++){
        long long n=N[s];
        long long x_pres=(n/2)*2;
        long long x_abs=(n-1)*2+1;

        long long reps=1;
        if(n<=10){
            reps=400000;
        }else if(n<=1000){
            reps=15000;
        }else if(n<=1000000){
            reps=5;
        }else{
            reps=1;
        }

        auto t1=steady_clock::now();
        for(long long r=0;r<reps;r++){
            sink+=linear_search_idx(n,x_pres);
        }
        auto t2=steady_clock::now();
        lin_t_pres_us[s]=duration_cast<nanoseconds>(t2-t1).count()/1000.0/reps;

        t1=steady_clock::now();
        for(long long r=0;r<reps;r++){
            sink+=linear_search_idx(n,x_abs);
        }
        t2=steady_clock::now();
        lin_t_abs_us[s]=duration_cast<nanoseconds>(t2-t1).count()/1000.0/reps;

        t1=steady_clock::now();
        for(long long r=0;r<reps;r++){
            sink+=binary_search_idx(n,x_pres);
        }
        t2=steady_clock::now();
        bin_t_pres_us[s]=duration_cast<nanoseconds>(t2-t1).count()/1000.0/reps;

        t1=steady_clock::now();
        for(long long r=0;r<reps;r++){
            sink+=binary_search_idx(n,x_abs);
        }
        t2=steady_clock::now();
        bin_t_abs_us[s]=duration_cast<nanoseconds>(t2-t1).count()/1000.0/reps;

        long long c=0;
        lin_idx_pres[s]=linear_search_cmp(n,x_pres,c);
        lin_cmp_pres[s]=c;
        linear_search_cmp(n,x_abs,c);
        lin_cmp_abs[s]=c;
        bin_idx_pres[s]=binary_search_cmp(n,x_pres,c);
        bin_cmp_pres[s]=c;
        binary_search_cmp(n,x_abs,c);
        bin_cmp_abs[s]=c;
    }

    const int W=20;

    cout<<left<<fixed<<setprecision(2);
    cout<<"+--------------------------------------+";
    for(int i=0;i<4;i++){
        cout<<setw(W)<<setfill('-')<<""<<"+";
    }
    cout<<setfill(' ')<<"\n";

    cout<<"|"<<setw(38)<<"К-сть елементів N у впорядкованому масиві";
    for(int i=0;i<4;i++){
        cout<<"|"<<setw(W-1)<<N[i]<<" ";
    }
    cout<<"|\n";

    cout<<"+--------------------------------------+";
    for(int i=0;i<4;i++){
        cout<<setw(W)<<setfill('-')<<""<<"+";
    }
    cout<<setfill(' ')<<"\n";

    cout<<"|"<<setw(38)<<"Лінійний пошук: t(наявн), мкс";
    for(int i=0;i<4;i++){
        cout<<"|"<<setw(W-1)<<lin_t_pres_us[i]<<" ";
    }
    cout<<"|\n";
    cout<<"|"<<setw(38)<<"Лінійний пошук: порівняння (наявн)";
    for(int i=0;i<4;i++){
        cout<<"|"<<setw(W-1)<<lin_cmp_pres[i]<<" ";
    }
    cout<<"|\n";
    cout<<"|"<<setw(38)<<"Лінійний пошук: індекс (наявн)";
    for(int i=0;i<4;i++){
        cout<<"|"<<setw(W-1)<<lin_idx_pres[i]<<" ";
    }
    cout<<"|\n";
    cout<<"|"<<setw(38)<<"Лінійний пошук: t(відсутн), мкс";
    for(int i=0;i<4;i++){
        cout<<"|"<<setw(W-1)<<lin_t_abs_us[i]<<" ";
    }
    cout<<"|\n";
    cout<<"|"<<setw(38)<<"Лінійний пошук: порівняння (відсутн)";
    for(int i=0;i<4;i++){
        cout<<"|"<<setw(W-1)<<lin_cmp_abs[i]<<" ";
    }
    cout<<"|\n";

    cout<<"+--------------------------------------+";
    for(int i=0;i<4;i++){
        cout<<setw(W)<<setfill('-')<<""<<"+";
    }
    cout<<setfill(' ')<<"\n";

    cout<<"|"<<setw(38)<<"Бінарний пошук: t(наявн), мкс";
    for(int i=0;i<4;i++){
        cout<<"|"<<setw(W-1)<<bin_t_pres_us[i]<<" ";
    }
    cout<<"|\n";
    cout<<"|"<<setw(38)<<"Бінарний пошук: порівняння (наявн)";
    for(int i=0;i<4;i++){
        cout<<"|"<<setw(W-1)<<bin_cmp_pres[i]<<" ";
    }
    cout<<"|\n";
    cout<<"|"<<setw(38)<<"Бінарний пошук: індекс (наявн)";
    for(int i=0;i<4;i++){
        cout<<"|"<<setw(W-1)<<bin_idx_pres[i]<<" ";
    }
    cout<<"|\n";
    cout<<"|"<<setw(38)<<"Бінарний пошук: t(відсутн), мкс";
    for(int i=0;i<4;i++){
        cout<<"|"<<setw(W-1)<<bin_t_abs_us[i]<<" ";
    }
    cout<<"|\n";
    cout<<"|"<<setw(38)<<"Бінарний пошук: порівняння (відсутн)";
    for(int i=0;i<4;i++){
        cout<<"|"<<setw(W-1)<<bin_cmp_abs[i]<<" ";
    }
    cout<<"|\n";

    cout<<"+--------------------------------------+";
    for(int i=0;i<4;i++){
        cout<<setw(W)<<setfill('-')<<""<<"+";
    }
    cout<<setfill(' ')<<"\n";

    volatile long long guard=0;
    if(guard==1){
        cout<<"";
    }

    return 0;
}

