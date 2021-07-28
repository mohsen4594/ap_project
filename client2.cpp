#include "httplib.h"
#include <iostream>
# include<string>
#include <sstream>
#define CA_CERT_FILE "./ca-bundle.crt"

using namespace std;

string pn2 = "";
//bool gs=0;
int main(void) {

  httplib::Client cli("localhost", 8080);

  if ( auto res = cli.Get("/hi") ) {

    if (res->body !="" ){
        pn2=res->body;}
    else{
        cout<<" you cant enter the game "<<endl;
      }

    }


    cout<<pn2<<endl;

    string move ;
    int x,y;
    while (true){


      cout<<"if you want to move pawn  please enter (w) for up -(a) for left- (d)for right- (s) for down"<<endl<<endl;
      cout<<"if you want to put wall please enter z "<<endl<<endl;
      cin>>move;
      if (move[0] == 'w' ){

      //  cout<<"hellllllllllllllllllllll"<<endl;
        httplib::Params params;
        params.emplace("move", move);
        params.emplace("name", pn2);

        auto res = cli.Post("/post", params);

        if (res->body =="tru"){
            cout<< res->body<<endl;}
        else if (res->body =="over"){
          cli.Get("/stop");

        }
        else if (res->body =="turn"){
            cout<< "its not your turn !!!!!!!!!! be patient"<<endl<<endl;}
        else{
            cout<<" your movement is invalid!!! try again "<<endl<<endl;
          }

        }

      else if (move[0] == 'a' ){
        httplib::Params params;
        params.emplace("move", move);
        params.emplace("name", pn2);

        auto res = cli.Post("/post", params);
        if (res->body =="tru"){
            cout<< res->body<<endl;}
            else if (res->body =="over"){
              cli.Get("/stop");
            }
            else if (res->body =="turn"){
                cout<< "its not your turn !!!!!!!!!! be patient"<<endl<<endl;}

        else{
            cout<<" your movement is invalid!!! try again "<<endl<<endl;
          }

      }
      else if (move[0] == 'd'){
        httplib::Params params;
        params.emplace("move", move);
        params.emplace("name", pn2);

        auto res = cli.Post("/post", params);
        if (res->body =="tru"){
            cout<< res->body<<endl;}
            else if (res->body =="over"){
              cli.Get("/stop");

            }
            else if (res->body =="turn"){
                cout<< "its not your turn !!!!!!!!!! be patient"<<endl<<endl;}
        else{
          cout<<" your movement is invalid!!! try again "<<endl<<endl;
          }

      }
      else if (move[0] == 's' ){
        httplib::Params params;
        params.emplace("move", move);
        params.emplace("name", pn2);

        auto res = cli.Post("/post", params);
        if (res->body =="tru"){
            cout<< res->body<<endl;}
            else if (res->body =="over"){
              cli.Get("/stop");

            }
            else if (res->body =="turn"){
                cout<< "its not your turn !!!!!!!!!! be patient"<<endl<<endl;}
        else{
            cout<<" your movement is invalid!!! try again "<<endl<<endl;
          }


      }
      else if (move[0]=='z') {

        cout<< " please enter the x_position and y_position of wall "<<endl;
        cin>> x>>y;

        if (x<1 || x>21 || y<1 || y>21 ||(x+y)%2==0){
            cout<<" your movement is invalid!!! try again "<<endl<<endl;
        }
        else {

                ostringstream str1,str2;
                str1 << x;
                str2<< y;
                string s10 = str1.str();
                string s20 = str2.str();
                cout<<s10<<s20<<endl;
                httplib::Params params;
                params.emplace("move", move);
                params.emplace("name", pn2);
                params.emplace("x_pos", s10);
                params.emplace("y_pos", s20);
                auto res = cli.Post("/post", params);
                cout<< res->body<<endl<<endl;

        }

      }
}
  return 0;
}
