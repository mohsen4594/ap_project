# include <httplib.h>
# include <iostream>
# include <string>
using namespace httplib;
#define H 23
#define W 23
using namespace std;
int a=0;
//bool continue1 =true;
int ii=0;
int turn =0;
int wall_a=5;
int wall_b=5;
int wall_c=5;
int wall_d=5;
string s [4]={"first","secon","third","forth"};
char player_name [4]={'a','b','c','d'};

char board [H][W]=
{{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
{'#',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','#'},
{'#','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-','#'},
{'#',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','#'},
{'#','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-','#'},
{'#',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','#'},
{'#','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-','#'},
{'#',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','#'},
{'#','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-','#'},
{'#',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','#'},
{'#','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-','#'},
{'#',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','#'},
{'#','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-','#'},
{'#',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','#'},
{'#','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-','#'},
{'#',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','#'},
{'#','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-','#'},
{'#',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','#'},
{'#','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-','#'},
{'#',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','#'},
{'#','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-','#'},
{'#',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','|',' ','#'},
{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};

class quoridor
{
	public:
	void print(){

	 	for (int i=0;i<H;i++)
	 	{
	 		for (int j=0;j<W;j++){
	 			cout<<board[i][j];

			 }
			 cout<<endl;
		 }

		}
		bool win_check(){
			if (board [11][11]!=' ' ){
			//	continue1=false;
				if (board[11][11]=='a'){
					cout <<" the first player is winner"<<endl<<endl;
					return true;

				}
			else if (board[11][11]=='b'){
					cout <<" the second  player is winner"<<endl<<endl;
					return true;
								}
				else if (board[11][11]=='c'){
						cout <<" the third  player is winner"<<endl<<endl;
						return true;
									}
					else if (board[11][11]=='d'){
							cout <<" the forth player is winner"<<endl<<endl;
							return true;
					}
			}

		return false;
		}

};
quoridor q;

int ax=1;int ay=1;int bx=1;int by=21;int cx=21;int cy=1;int dx=21;int dy=21;
int main(void) {

  Server svr;


		svr.Get("/hi", [](const Request & req , Response &res) {
		if (ii<4){

			if (ii==0)
					board [ax][ay]=player_name[ii];
			else if (ii==1)
					board [bx][by]=player_name[ii];
			else if (ii==2)
					board [cx][cy]=player_name[ii];
			else
					board[dx][dy]=player_name[ii];

			q.print();
    	res.set_content(s[ii], "text/plain");
		}
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
    } else {
      string body;
      content_reader([&](const char *data, size_t data_length) {
        body.append(data, data_length);
        return true;
      });
			string str=body.substr(12,5);
      cout<<body<<endl<<endl;
		if (body[5] !='z'){
		if (str=="first"){
			if (turn %4 ==0)

			{	switch(body[5]) {
	      case 'w' :
	         {
						 if (ax-2<=0 || board [ax-2][ay]!=' ' ||board [ax-1][ay]=='w'){
							 res.set_content("fal", "text/plain");

						 }
						 else{
							 board [ax-2][ay]='a';
							 board[ax][ay]=' ';
							 ax-=2;
							 q.print();
								if (!q.win_check()){
									turn++;
							 		 res.set_content("tru", "text/plain");}
								else
									 res.set_content("over", "text/plain");



						 }
	         break;}
	      case 'a' :
				{
					if (ay-2<=0 || board [ax][ay-2]!=' '||board [ax][ay-1]=='w'){
						res.set_content("fal", "text/plain");

					}
					else{
						board [ax][ay-2]='a';
						board[ax][ay]=' ';
						ay-=2;
						 q.print();
						 if (!q.win_check()){
							 turn++;
								res.set_content("tru", "text/plain");}
						 else
								res.set_content("over", "text/plain");
					}
				break;}
	      case 's' :
				{
				 if (ax+2>=22 || board [ax+2][ay]!=' '||board [ax+1][ay]=='w'){
					 res.set_content("fal", "text/plain");

				 }
				 else{
					 board [ax+2][ay]='a';
					 board[ax][ay]=' ';
					 ax+=2;
					  q.print();
						if (!q.win_check()){
							turn++;
							 res.set_content("tru", "text/plain");}
						else
							 res.set_content("over", "text/plain");
				 }
				break;}
	      case 'd' :
				{
				 if (ay+2>=22 || board [ax][ay+2]!=' '||board [ax][ay+1]=='w'){
					 res.set_content("fal", "text/plain");

				 }
				 else{
					 board [ax][ay+2]='a';
					 board[ax][ay]=' ';
					 ay+=2;
					  q.print();
						if (!q.win_check()){
 						 turn++;
 							res.set_content("tru", "text/plain");}
					 else
							res.set_content("over", "text/plain");
				 }
			 break;}

	      default :
				res.set_content("fal", "text/plain");

	   }}

		 else
		 		res.set_content("turn", "text/plain");



	 }
		 else if (str=="secon")
		 					{
								if (turn %4 ==1){
		 				switch(body[5]) {
		 	      case 'w' :
		 	         {
		 						 if (bx-2<=0 || board [bx-2][by]!=' '||board [bx-1][by]=='w'){
		 							 res.set_content("fal", "text/plain");

		 						 }
		 						 else{
		 							 board [bx-2][by]='b';
		 							 board [bx][by]=' ';
		 							 bx-=2;
									  q.print();
										if (!q.win_check()){
											turn++;
									 		 res.set_content("tru", "text/plain");}
										else
											 res.set_content("over", "text/plain");
		 						 }
		 	         break;}
		 	      case 'a' :
		 				{
		 					if (by-2<=0 || board [bx][by-2]!=' '|| board [bx][by-1]=='w'){
		 						res.set_content("fal", "text/plain");

		 					}
		 					else{
		 						board [bx][by-2]='b';
		 						board [bx][by]=' ';
		 						by-=2;
								 q.print();
								 if (!q.win_check()){
 									turn++;
 							 		 res.set_content("tru", "text/plain");}
 								else
 									 res.set_content("over", "text/plain");
		 					}
		 				break;}
		 	      case 's' :
		 				{
		 				 if (bx+2>=22 || board [bx+2][by]!=' '||board [bx+1][by]=='w'){
		 					 res.set_content("fal", "text/plain");

		 				 }
		 				 else{
		 					 board [bx+2][by]='b';
		 					 board [bx][by]=' ';
		 					 bx+=2;
							  q.print();
								if (!q.win_check()){
									turn++;
							 		 res.set_content("tru", "text/plain");}
							 else
									res.set_content("over", "text/plain");
		 				 }
		 				break;}
		 	      case 'd' :
		 				{
		 				 if (by+2>=22 || board [bx][by+2]!=' '||board [bx][by+1]=='w'){
		 					 res.set_content("fal", "text/plain");

		 				 }
		 				 else{
		 					 board [bx][by+2]='b';
		 					 board [bx][by]=' ';
		 					 by+=2;
							  q.print();
								if (!q.win_check()){
									turn++;
									 res.set_content("tru", "text/plain");}
							 else
									res.set_content("over", "text/plain");
		 				 }
		 			 break;}

		 	      default :
		 				res.set_content("fal", "text/plain");

		 	   }}
				 else
				 		res.set_content("turn", "text/plain");

			 }
				 else if (str=="third")
					{
						if (turn %4 ==2){
				switch(body[5]) {
	      case 'w' :
	         {
						 if (cx-2<=0 || board [cx-2][cy]!=' '||board [cx-1][cy]=='w'){
							 res.set_content("fal", "text/plain");

						 }
						 else{
							 board [cx-2][cy]='c';
							 board [cx][cy]=' ';
							 cx-=2;
							  q.print();
								if (!q.win_check()){
									turn++;
							 		 res.set_content("tru", "text/plain");}
							 else
									res.set_content("over", "text/plain");
						 }
	         break;}
	      case 'c' :
				{
					if (cy-2<=0 || board [cx][cy-2]!=' '||board [cx][cy-1]=='w'){
						res.set_content("fal", "text/plain");

					}
					else{
						board [cx][cy-2]='c';
						board [cx][cy]=' ';
						cy-=2;
						 q.print();
						 if (!q.win_check()){
							 turn++;
								res.set_content("tru", "text/plain");}
						else
							 res.set_content("over", "text/plain");
					}
				break;}
	      case 's' :
				{
				 if (cx+2>=22 || board [cx+2][cy]!=' '||board [cx+1][cy]=='w'){
					 res.set_content("fal", "text/plain");

				 }
				 else{
					 board [cx+2][cy]='c';
					 board [cx][cy]=' ';
					 cx+=2;
					  q.print();
						if (!q.win_check()){
							turn++;
							 res.set_content("tru", "text/plain");}
					 else
							res.set_content("over", "text/plain");
				 }
				break;}
	      case 'd' :
				{
				 if (cy+2>=22 || board [cx][cy+2]!=' '||board [cx][cy+1]=='w'){
					 res.set_content("fal", "text/plain");

				 }
				 else{
					 board [cx][cy+2]='c';
					 board[cx][cy]=' ';
					 cy+=2;
					  q.print();
						if (!q.win_check()){
							turn++;
							 res.set_content("tru", "text/plain");}
					 else
							res.set_content("over", "text/plain");
				 }
			 break;}

	      default :
				res.set_content("fal", "text/plain");

	   }}
		 else{
			 	res.set_content("turn", "text/plain");

		 }


	 }
		 else if (str=="forth")
					{
						if (turn %4 ==3){
				switch(body[5]) {
	      case 'w' :
	         {
						 if (dx-2<=0 || board [dx-2][dy]!=' '||board [dx-1][dy]=='w'){
							 res.set_content("fal", "text/plain");

						 }
						 else{
							 board [dx-2][dy]='d';
							 board[dx][dy]=' ';
							 dx-=2;
							  q.print();
								if (!q.win_check()){
									turn++;
							 		 res.set_content("tru", "text/plain");}
							 else
									res.set_content("over", "text/plain");
						 }
	         break;}
	      case 'a' :
				{
					if (dy-2<=0 || board [dx][dy-2]!=' '||board [dx][dy-1]=='w'){
						res.set_content("fal", "text/plain");

					}
					else{
						board [dx][dy-2]='d';
						board[dx][dy]=' ';
						dy-=2;
						 q.print();
						 if (!q.win_check()){
							 turn++;
								res.set_content("tru", "text/plain");}
	 				 else
	 						res.set_content("over", "text/plain");
					}
				break;}
	      case 's' :
				{
				 if (dx+2>=22 || board [dx+2][dy]!=' '||board [dx+1][dy]=='w'){
					 res.set_content("fal", "text/plain");

				 }
				 else{
					 board [dx+2][dy]='d';
					 board[dx][dy]=' ';
					 dx+=2;
					  q.print();
						if (!q.win_check()){
							turn++;
							 res.set_content("tru", "text/plain");}
					 else
							res.set_content("over", "text/plain");
				 }
				break;}
	      case 'd' :
				{
				 if (dy+2>=22 || board [dx][dy+2]!=' '||board [dx][dy+1]=='w'){
					 res.set_content("fal", "text/plain");

				 }
				 else{
					 board [dx][dy+2]='d';
					 board[dx][dy]=' ';
					 dy+=2;
					  q.print();
						if (!q.win_check()){
							turn++;
							 res.set_content("tru", "text/plain");}
					 else
							res.set_content("over", "text/plain");
				 }
			 break;}

	      default :
				res.set_content("fal", "text/plain");

	   }}
		 else
		 		res.set_content("turn", "text/plain");
	 }
	 }
	 else
	 {
		 //res.set_content(body, "text/plain");
				 string s100="";
				 string s200="";
				 s100+=body[24];
				 if (body[25] !='&')
				 		s100+=body[25];
					int temp =body.length();
					s200=body[temp-1];
					if (body[temp-2]!='=')
							s200=body[temp-2]+s200;
					int x_pos=stoi(s100);
					int y_pos=stoi(s200);
					cout<<x_pos<< "        "<<y_pos<<endl<<endl;

					 if (str=="first" && turn%4==0 && wall_a!=0){

							if (x_pos%2==0){
									if (board [x_pos][y_pos]=='w'|| board [x_pos][y_pos+2]=='w' )	{
												res.set_content("fal", "text/plain");
									}
									else{
										board [x_pos][y_pos]='w';
										board [x_pos][y_pos+2]='w';
										turn++;
										wall_a--;
										q.print();
										res.set_content("tru", "text/plain");
									}
					  	}
							else{
								if (board [x_pos][y_pos]=='w'|| board [x_pos+2][y_pos]=='w' )	{
											res.set_content("fal", "text/plain");
								}
								else{
									board [x_pos][y_pos]='w';
									board [x_pos+2][y_pos]='w';
									turn++;
									wall_a--;
									q.print();
									res.set_content("tru", "text/plain");
								}
							}
			 }


				else	if (str=="secon" && turn%4==1 && wall_b!=0){

						 if (x_pos%2==0){
								 if (board [x_pos][y_pos]=='w'|| board [x_pos][y_pos+2]=='w' )	{
											 res.set_content("fal", "text/plain");
								 }
								 else{
									 board [x_pos][y_pos]='w';
									 board [x_pos][y_pos+2]='w';
									 turn++;
									 wall_b--;
									 q.print();
									 res.set_content("tru", "text/plain");
								 }
						 }
						 else{
							 if (board [x_pos][y_pos]=='w'|| board [x_pos+2][y_pos]=='w' )	{
										 res.set_content("fal", "text/plain");
							 }
							 else{
								 board [x_pos][y_pos]='w';
								 board [x_pos+2][y_pos]='w';
								 turn++;
								 wall_b--;
								 q.print();
								 res.set_content("tru", "text/plain");
							 }
						 }
			}
			else	if (str=="third" && turn%4==2 && wall_c!=0){

					 if (x_pos%2==0){
							 if (board [x_pos][y_pos]=='w'|| board [x_pos][y_pos+2]=='w' )	{
										 res.set_content("fal", "text/plain");
							 }
							 else{
								 board [x_pos][y_pos]='w';
								 board [x_pos][y_pos+2]='w';
								 turn++;
								 wall_c--;
								 q.print();
								 res.set_content("tru", "text/plain");
							 }
					 }
					 else{
						 if (board [x_pos][y_pos]=='w'|| board [x_pos+2][y_pos]=='w' )	{
									 res.set_content("fal", "text/plain");
						 }
						 else{
							 board [x_pos][y_pos]='w';
							 board [x_pos+2][y_pos]='w';
							 turn++;
							 wall_c--;
							 q.print();
							 res.set_content("tru", "text/plain");
						 }
					 }
		}
		else	if (str=="forth" && turn%4==3 && wall_d!=0){

				 if (x_pos%2==0){
						 if (board [x_pos][y_pos]=='w'|| board [x_pos][y_pos+2]=='w' )	{
									 res.set_content("fal", "text/plain");
						 }
						 else{
							 board [x_pos][y_pos]='w';
							 board [x_pos][y_pos+2]='w';
							 turn++;
							 wall_d--;
							 q.print();
							 res.set_content("tru", "text/plain");
						 }
				 }
				 else{
					 if (board [x_pos][y_pos]=='w'|| board [x_pos+2][y_pos]=='w' )	{
								 res.set_content("fal", "text/plain");
					 }
					 else{
						 board [x_pos][y_pos]='w';
						 board [x_pos+2][y_pos]='w';
						 turn++;
						 wall_d--;
						 q.print();
						 res.set_content("tru", "text/plain");
					 }
				 }
	}

			else
			 	res.set_content("fal", "text/plain");
}

  }});

	svr.Get("/stop", [&](const Request& req, Response& res) {
    svr.stop();
  });


	svr.listen("localhost", 8080);


}
