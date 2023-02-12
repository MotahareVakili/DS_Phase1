#ifndef CLASSES_H
#define CLASSES_H
#include <iostream>
#include<QList>
#include<QTextStream>
#include<QStringList>
#include<QString>
#include<iomanip>
#include <windows.h>
#include<QFile>
#include<vector>
#include <algorithm>
using namespace std;
int p_id;

class akas
{
public:

     string titleId;
     int ordering;
     string title;
     string region;
     string language;
     string types;
     string attributes;
     int isOriginalTitle;
};
class ratings
{
public:
    QString tconst;
    double averageRating;
    int numVotes;
};
class usr
{
public:
    QString username;
    QString password;
    QList <QString> voted;

};

class f
{

    QList<akas>*info;
    QList<ratings>*vote;
    QList<usr>*user;
public:
    f( QList<usr>*user,QList<akas>*info,QList<ratings>*vote)
    {
        this->user=user;
        this->info=info;
        this->vote=vote;
        save_to_list_u();
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(h, 0xb);
        cout<<"Welcome!\nLog in to your account to continue(type'log in')\nIf you don't have an account,type'sign up'\n\n";
        string s;


        while (true)
        {
            SetConsoleTextAttribute(h, 0x7);
            getline(cin,s);
            if(s=="log in")
            { sign_in();break;}
            else if(s=="sign up")
            { sigh_up();break;}
            else
             {
                SetConsoleTextAttribute(h, 0x4);
                cout<<"There is a problem, please try again\n";
            }
        }




         SetConsoleTextAttribute(h, 0xb);
         cout<<"\nThank you. Now select one of these options(enter option number)\n\n";
         SetConsoleTextAttribute(h, 0x8);
              cout<< "1)information of movies\n"<<
               "2)The IMDb rating and votes information for movies\n3)Voting\n4)10 Top rated movies\n5)Save changes\n6)close\n\n";
    }
    void sigh_up()
    {
          HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h, 0xb);
        cout<<"\nPlease enter your username and password\n"<<endl;
        SetConsoleTextAttribute(h, 0x8);
         cout<<"USERNAME : ";
        SetConsoleTextAttribute(h, 0x7);
        string name;
        cin>>name;
        int size=user->size();
        for(int i=0;i<size;i++)
        {
            if(user->at(i).username.toStdString()!=name)
                continue;
            else
            {
                SetConsoleTextAttribute(h, 0x4);
                cout<<"sorry,this username is already taken.Please choose another username\n";
                return sigh_up();

            }

        }
        SetConsoleTextAttribute(h, 0x8);
        cout<<"PASSWORD : ";
        SetConsoleTextAttribute(h, 0x7);
        string pass;
        cin>>pass;
         SetConsoleTextAttribute(h, 0x2);
         cout<<"Your account was created successfully\n";
        p_id=size;
        usr u;
        u.password= QString::fromStdString(pass);
        u.username= QString::fromStdString(name);
        user->append(u);

    }
    void sign_in()
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 0xb);
      cout<<"\nPlease enter your username and password\n"<<endl;

        SetConsoleTextAttribute(h, 0x8);
         cout<<"USERNAME : ";
        SetConsoleTextAttribute(h, 0x7);
         string name;
         cin>>name;
         SetConsoleTextAttribute(h, 0x8);
         cout<<"PASSWORD : ";
         SetConsoleTextAttribute(h, 0x7);
         string pass;
         cin>>pass;
         int size=user->size();
         for(int i=0;i<size;i++)
         {
             if(user->at(i).username.toStdString()==name&&user->at(i).password.toStdString()==pass)
                {p_id=i; return;}
             else
                 continue;
         }
          SetConsoleTextAttribute(h, 0x4);
          cout<<"There was a problem logging in. Check your username and password and try again\n";
          return sign_in();

    }
    void save_to_list_i(QTextStream* qst)
    {


        while (!qst->atEnd())
        {
            akas aks;
            QStringList qsl=qst->readLine().split("\t");
            aks.titleId=qsl[0].toStdString();
            aks.ordering=qsl[1].toInt();
            aks.title=qsl[2].toStdString();
            aks.region=qsl[3].toStdString();
            aks.language=qsl[4].toStdString();
            aks.types=qsl[5].toStdString();
            aks.attributes=qsl[6].toStdString();
            aks.isOriginalTitle=qsl[7].toInt();
            info->append(aks);

        }

    }
    void save_to_list_v(QTextStream* qst)
    {
        while (!qst->atEnd())
        {
            ratings rt;
            QStringList qsl=qst->readLine().split("\t");
            rt.tconst=qsl[0];
            rt.averageRating=qsl[1].toDouble();
            rt.numVotes=qsl[2].toInt();
            vote->append(rt);
        }


    }
    void show_info()
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 0x8);
        cout<<left<<setw(12)<<"titleId"<<"ordering\t"<<left<<setw(48)<<"title"<<
              "region\t"<<left<<setw(10)<<"language"<<"types \t"<<left<<setw(25)<<"attributes"<<"isOriginalTitle\n"<<endl;

             int size=info->size();
            for(int i=1;i<size;i++)
              cout<<(*info)[i].titleId<<"\t"<<(*info)[i].ordering<<"\t"<<left<<setw(50)<<(*info)[i].title<<left<<setw(8)<<
              (*info)[i].region<<left<<setw(8)<<(*info)[i].language<<left<<setw(15)<<(*info)[i].types<<
              left<<setw(25)<< (*info)[i].attributes<<(*info)[i].isOriginalTitle<<endl;

    }
    void show_ratings()
    {
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 0x8);
        cout<<left<<setw(12)<<"tconst"<<left<<setw(15)<<"averageRating"<<"numVotes\n"<<endl;
        int size=vote->size();
        for(int i=1;i<size;i++)
            cout<<(*vote)[i].tconst.toStdString()<<"\t"<<left<<setw(12)<<(*vote)[i].averageRating<<(*vote)[i].numVotes<<endl;

    }
    void vote_(string id)
    {

        if(user->at(p_id).voted.contains( QString::fromStdString(id)))
        {
            HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(h, 0x4);
            cout<<"You can not vote for a movie more than once\nPlease enter another Id or type 'return'\n";
            SetConsoleTextAttribute(h, 0x7);
            string v;
            cin>>v;
            if(v=="return")
                return ;
            return vote_(v);
        }

        int size=vote->size();
        for( int i=1;i<size;i++)
        {
            if(vote->at(i).tconst.toStdString()==id )
            {
                (*user)[p_id].voted.push_back( QString::fromStdString(id));
                (*vote)[i].numVotes++;
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, 0xb);
                cout<<"Please rate the movie in the range of 1 to 10\n";
                int num;
                SetConsoleTextAttribute(h, 0x7);
                cin>>num;
                double n=(*vote)[i].numVotes;
                double m=(*vote)[i].averageRating;
                m= ((n*m)+num)/(n+1);
                SetConsoleTextAttribute(h, 0x2);
                cout<<"Your vote has been successfully registered\n";

                return;
                break;

            }


        }
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 0x4);
        cout<<"There is no movie with this id. Please try again\n";
        SetConsoleTextAttribute(h, 0x7);
        string v;
        cin>>v;
        return vote_(v);

    }
    void save_to_file()
    {
        QFile file("title.ratings.txt");
        if(! file.open(QIODevice::WriteOnly | QIODevice::Text))
           return ;
        QTextStream qst(&file);
        qst<<"tconst\taverageRating\tnumVotes\t\n";
        int size=vote->size();
        for(int i=1;i<size;i++)
        {
            QString a=QString::number((*vote)[i].averageRating);
            QString b=QString::number((*vote)[i].numVotes);
           qst<<(*vote)[i].tconst+"\t"+a+"\t"+b+"\n";
        }
        file.close();


    }
    static bool sortByVal( const pair<string,double> &a,  const pair<string,double> &b)
    {
        return (a.second > b.second);
    }

    void show_10_top()
    {   cout<<"\n";
        int size=vote->size();
        vector<pair<string,double>> vect;
        vect.reserve(size);

        for(int i=1;i<size;i++)
           vect.push_back(make_pair((*info)[i].title,(*vote)[i].averageRating));
        sort(vect.begin(), vect.end(),sortByVal);
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, 0x8);
        cout<<left<<setw(44)<<"title"<<"averageRating\n\n";
        for(int i=0;i<10;i++)

        cout <<left<<setw(40)<< vect[i].first << "\t" << vect[i].second << endl;

    }
    void save_to_list_u()
    {

        QFile file_u("usr.txt");
        if(! file_u.open(QIODevice::ReadOnly | QIODevice::Text))
           return ;

        QTextStream qst(&file_u);
        while (!qst.atEnd())
        {
            usr u;
            QStringList qsl=qst.readLine().split(",");
            if(qsl[0]== QString::fromStdString(""))
                return;
            u.username=qsl[0];
            u.password=qsl[1];
            u.voted=qsl[2].split("/");
            user->append(u);

        }
        file_u.close();
    }
    void save_to_file_u()
    {
        QFile file_u("usr.txt");
        if(! file_u.open(QIODevice::WriteOnly | QIODevice::Text))
           return ;
        QTextStream qst(&file_u);
        int size=user->size();
        for(int i=0;i<size;i++)
        {
            qst<<(*user)[i].username+","+(*user)[i].password+",";
            int size_v=(*user)[i].voted.size();
            for(int j=0;j<size_v;j++)
            {
                qst<<(*user)[i].voted.at(j)+"/";
            }
            qst<<"\n";
        }
        file_u.close();
    }
    ~f()
    {
        save_to_file();
        save_to_file_u();
    }
};

#endif // CLASSES_H
