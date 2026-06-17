#include <bits/stdc++.h>
using namespace std;
    //Library Management Sysytem
    //database of Students, Faculties
    //Database of books
    //maxlimit on books alloted
    //record of books taken 
    //tech stack:  vector, Oops, maps, time library

    //phase 2
    //auto assignment of B_id and M_id

    //also make a sysytem which can log in daily and maintain record of sign in daily

typedef long long ll;
    struct Member{
        int M_id;
        string name;
        long long phone;

        Member() {}; //default constructor necessary since you are creating a blank object first
        Member(int a, string b, ll c){
            M_id=a;
            name=b;
            phone =c;
        }        
    };

    struct Book{
        int B_id;
        string name;
        double price;
        int total_copies;
        int avl_copies;

        Book() {};
        Book(int a, string b, double c,int n){
            B_id=a;
            name=b;
            price=c;
            total_copies=n;
            avl_copies=n;
        }
    };

    struct issueRecord{
        int M_id;
        int B_id;
        time_t time;

        issueRecord() {};
        issueRecord(int a,int b, time_t c){
            M_id=a;
            B_id=b;
            time=c;
        }
    };

    class Library{
        unordered_map<int,Member> Members;
        unordered_map<int,Book> books;
        vector<issueRecord> record;

        int countBook=1,countMember=1; //auto increment;

        public:
        void add_Book(){
            cout<<"Enter name of book: ";
            string q; cin>>q;
            cout<<"Enter price of book: ";
            double r; cin>>r;
            cout<<"Enter available copies: ";
            int s; cin>>s;
            Book b(countBook,q,r,s);
            books.insert({countBook,b});
            cout<<"\nBook added successfully\nBook_id= "<<countBook++<<endl;
            return;
        }
        
        void add_Member(){
            string b; 
            ll c;
            cout<<"Enter name: ";
            cin>>b;
            cout<<"Enter phone number: ";
            cin>>c;
            Member x(countMember,b,c);
            Members.insert({countMember,x});
            cout<<"\nMember added successfully\nMember_id= "<<countMember++<<endl;
        }
        void issue_Book(){
            int a;
            int b;
            cout<<"Enter Member id: ";
            cin>>a;
            cout<<"Enter the book Id: ";
            cin>>b;

            if(Members.find(a) == Members.end()){
                cout<<"Member not found\n";
                return;
            }
            if(books.find(b) == books.end()){
                cout<<"Book not found\n";
                return;
            }
            if(books[b].avl_copies==0){
                cout<<"No book available at this time\n Come again later";
                return;
            }
            
            issueRecord temp(a,b,time(0));
            record.push_back(temp);
            books[b].avl_copies--;
            cout<<"\nBook issued successfully\n";
        }
        void return_Book(){
            int Mid;
            int Bid;
            cout<<"Enter Member id: ";
            cin>>Mid;
            cout<<"Enter book id: ";
            cin>>Bid;
            for(auto it= record.begin();it!=record.end();++it){
                if(it->M_id==Mid && it->B_id==Bid){

                    int days=difftime(time(0),it->time)/(60*60*24);
                    cout<<"Book kept for "<<days<<" days\n";
                    if(days>45){
                        cout<<"Total fine occured @1/day = "<<days-45<<endl;
                    }
                    books[Bid].avl_copies++;
                    record.erase(it);
                    cout<<"\nBook returned successfully\n";
                    return;
                }
            }   
            cout<<"No such record found \n";
        }
    };


int main(){ 
    Library Shivang;
    cout<<"Good morning!\nWelcome to the Shivang's Library: \n";
    while(1){
        cout<<"Choose from the options:\n";
        cout<<"1. Add Books\n2. Add members\n3. Issue Books\n4. Return Books \n5.Exit\n";
        int option; 
        cin>>option;
        if(option==1){
            Shivang.add_Book();
        }
        if(option==2){
            Shivang.add_Member();
        }
        if(option==3){
            Shivang.issue_Book();
        }
        if(option==4){
            Shivang.return_Book();
        }
        if(option==5){
            break;
        }
    }
    cout<<"Thank you for your coordination\nSee you tomorrow\n";
}
