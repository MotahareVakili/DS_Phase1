
#include"c&f.h"

int main()

{
    QList<akas> info;
    QList<ratings>vote;
    QList<usr>user;
    f func(&user,&info,&vote);

    {
    QFile file_a("title.akas.txt");
   if(! file_a.open(QIODevice::ReadOnly | QIODevice::Text))
     return 0;

    QTextStream qst_a(&file_a);
    func.save_to_list_i(&qst_a);
    file_a.close();
    QFile file_r("title.ratings.txt");
    if(! file_r.open(QIODevice::ReadOnly | QIODevice::Text))
       return 0;

    QTextStream qst_r(&file_r);
   func. save_to_list_v(&qst_r);
    file_r.close();


    }

     HANDLE k = GetStdHandle(STD_OUTPUT_HANDLE);

     SetConsoleTextAttribute(k, 0x7);
     int tmp;
     cin>>tmp;
     while (tmp!=6)
     {

         switch (tmp)
         {
            case 1:cout<<"\n";func.show_info();break;
            case 2:cout<<"\n";func.show_ratings();break;
            case 3:{SetConsoleTextAttribute(k, 0xb);cout<<"Please enter the movie id\n";
             SetConsoleTextAttribute(k, 0x7);string v;cin>>v;func.vote_(v);}break;
            case 4:func.show_10_top();break;
            case 5:func.save_to_file();func.save_to_file_u();SetConsoleTextAttribute(k, 0x2);
             cout<<"\nChanges saved successfully\n";break;

         }
         SetConsoleTextAttribute(k, 0x7);
         cout<<"\n____________________________________________________________________________________________________________________________________\n\n";
         SetConsoleTextAttribute(k, 0xb);
         cout<<"select one of these options(enter option number)\n\n";
         SetConsoleTextAttribute(k, 0x8);
         cout<< "1)information of movies\n"<<
         "2)The IMDb rating and votes information for movies\n3)Voting\n4)10 RTop rated movies\n5)Save changes\n6)close\n\n";
          SetConsoleTextAttribute(k, 0x7);
         cin>>tmp;

     }
     SetConsoleTextAttribute(k, 0xb);
     cout<<"Bye:)\n";
     SetConsoleTextAttribute(k, 0x8);



    return 0;
}
