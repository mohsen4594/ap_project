# include <httplib.h>
# include <iostream>
# include <string>
# include "qurridor.h"
using namespace httplib;
int turn=0;
using namespace std;
int ii=0;
string s [4]={"first","secon","third","forth"};
quoridor q;
int main(void) {
	Server svr;

  //Server svr;
		int x_pos;
		int y_pos;

		svr.Get("/hi", [&](const Request & req , Response &res) {
			if (ii<4){
			q.register1 (ii);
			q.print();
			res.set_content(s[ii], "text/plain");}
			ii++;

  });
	 //cout<<a<<endl;
	 svr.Post("/post",
  [&](const Request &req, Response &res, const ContentReader &content_reader) {
		if (req.is_multipart_form_data()) {
      MultipartFormDataItems files;
      content_reader(
        [&](const MultipartFormData &file) {
          files.push_back(file);
          return true;
        },
        [&](const char *data, size_t data_length) {
          files.back().content.append(data, data_length);
					//cout<<"jyfhhhhhhhhhhhhhhhh"<<endl;
          return true;
        });
    }
		else {
		 string body;
		 content_reader([&](const char *data, size_t data_length) {
			 body.append(data, data_length);
			 return true;
		 });

		 		if(body[5]=='z'){
				string s100="";
				string s200="";
				s100+=body[24];
				if (body[25] !='&')
					 s100+=body[25];
				 int temp =body.length();
				 s200+=body[temp-1];
				 if (body[temp-2]!='=')
						 s200=body[temp-2]+s200;
				  x_pos=stoi(s100);
				  y_pos=stoi(s200);
				 cout<<x_pos<< "        "<<y_pos<<endl<<endl;}
				 string str=body.substr(12,5);
      	 cout<<body<<endl<<endl;

			string result = q.move_pawn(body[5],str,turn,x_pos,y_pos);
			if (result=="invalid")
					res.set_content("fal", "text/plain");

			else if (result=="true"){
				if (!q.win_check()){
						turn++;
						q.print();
					  res.set_content("tru", "text/plain");}
				else
						res.set_content("over", "text/plain");
				}
				else if (result=="turn")
							res.set_content("turn", "text/plain");

				else
							res.set_content("fal", "text/plain");

  }});

	svr.Get("/stop", [&](const Request& req, Response& res) {
    svr.stop();
  });


	svr.listen("localhost", 8080);


}
