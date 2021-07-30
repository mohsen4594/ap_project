# include <iostream>
# include <string>
using namespace std;
#define H 23
#define W 23
class quoridor
{   //int H=23;
    //int W=23;
    int wall_a=5;
    int wall_b=5;
    int wall_c=5;
    int wall_d=5;
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

    int ax=1;int ay=1;int bx=1;int by=H-2;int cx=H-2;int cy=1;int dx=H-2;int dy=H-2;


public:

  void register1 (int ii){
    if (ii<4){

      if (ii==0)
          board [ax][ay]=player_name[ii];
      else if (ii==1)
          board [bx][by]=player_name[ii];
      else if (ii==2)
          board [cx][cy]=player_name[ii];
      else
          board[dx][dy]=player_name[ii];

    }
  }
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

		string move_pawn( char body_5,string str,int turn,int x_pos,int y_pos){

        if (body_5 !='z'){
		        if (str=="first"){
			           if (turn %4 ==0)

			            {	switch(body_5) {

	      case 'w' :
	         {
						 if (ax-2<=0 || board [ax-2][ay]!=' ' ||board [ax-1][ay]=='w'){
               return "invalid";
						 }
						 else{
							 board [ax-2][ay]='a';
							 board[ax][ay]=' ';
							 ax-=2;

						 }
             return "true";
	         break;}
	      case 'a' :
				{
					if (ay-2<=0 || board [ax][ay-2]!=' '||board [ax][ay-1]=='w'){
						return "invalid";

					}
					else{
						board [ax][ay-2]='a';
						board[ax][ay]=' ';
						ay-=2;
            return "true";

					}

				break;}
	      case 's' :
				{
				 if (ax+2>=22 || board [ax+2][ay]!=' '||board [ax+1][ay]=='w'){
					 return "invalid";

				 }
				 else{
					 board [ax+2][ay]='a';
					 board[ax][ay]=' ';
					 ax+=2;
					  return "true";
				 }
				break;}
	      case 'd' :
				{
				 if (ay+2>=22 || board [ax][ay+2]!=' '||board [ax][ay+1]=='w'){
					 return "invalid";

				 }
				 else{
					 board [ax][ay+2]='a';
					 board[ax][ay]=' ';
					 ay+=2;
					 return "true";
				 }
			 break;}

	      default :
				return "invalid";

	   }}

		 else
		 		return "turn";



	 }
		 else if (str=="secon")
		 					{
								if (turn %4 ==1){
		 				switch(body_5) {
		 	      case 'w' :
		 	         {
		 						 if (bx-2<=0 || board [bx-2][by]!=' '||board [bx-1][by]=='w'){
		 							 return "invalid";

		 						 }
		 						 else{
		 							 board [bx-2][by]='b';
		 							 board [bx][by]=' ';
		 							 bx-=2;
									  return "true";}
		 	         break;}
		 	      case 'a' :
		 				{
		 					if (by-2<=0 || board [bx][by-2]!=' '|| board [bx][by-1]=='w'){
		 						return "invalid";

		 					}
		 					else{
		 						board [bx][by-2]='b';
		 						board [bx][by]=' ';
		 						by-=2;
								 return "true";
		 					}
		 				break;}
		 	      case 's' :
		 				{
		 				 if (bx+2>=22 || board [bx+2][by]!=' '||board [bx+1][by]=='w'){
		 					 return "invalid";

		 				 }
		 				 else{
		 					 board [bx+2][by]='b';
		 					 board [bx][by]=' ';
		 					 bx+=2;
							  return "true";
		 				 }
		 				break;}
		 	      case 'd' :
		 				{
		 				 if (by+2>=22 || board [bx][by+2]!=' '||board [bx][by+1]=='w'){
		 					 return "invalid";

		 				 }
		 				 else{
		 					 board [bx][by+2]='b';
		 					 board [bx][by]=' ';
		 					 by+=2;
							 return "true";
		 				 }
		 			 break;}

		 	      default :
		 				return "invalid";

		 	   }}
				 else
				 		return "turn";

			 }
				 else if (str=="third")
					{
						if (turn %4 ==2){
				switch(body_5) {
	      case 'w' :
	         {
						 if (cx-2<=0 || board [cx-2][cy]!=' '||board [cx-1][cy]=='w'){
							 return "invalid";

						 }
						 else{
							 board [cx-2][cy]='c';
							 board [cx][cy]=' ';
							 cx-=2;
							 return "true";
						 }
	         break;}
	      case 'c' :
				{
					if (cy-2<=0 || board [cx][cy-2]!=' '||board [cx][cy-1]=='w'){
						return "invalid";

					}
					else{
						board [cx][cy-2]='c';
						board [cx][cy]=' ';
						cy-=2;
						 return "true";
					}
				break;}
	      case 's' :
				{
				 if (cx+2>=22 || board [cx+2][cy]!=' '||board [cx+1][cy]=='w'){
					 return "invalid";

				 }
				 else{
					 board [cx+2][cy]='c';
					 board [cx][cy]=' ';
					 cx+=2;
					  return "true";
				 }
				break;}
	      case 'd' :
				{
				 if (cy+2>=22 || board [cx][cy+2]!=' '||board [cx][cy+1]=='w'){
					 return "invalid";

				 }
				 else{
					 board [cx][cy+2]='c';
					 board[cx][cy]=' ';
					 cy+=2;
					  return "true";
				 }
			 break;}

	      default :
				return "invalid";

	   }}
		 else{
			 	return "turn";

		 }}



		 else if (str=="forth")
					{
						if (turn %4 ==3){
				switch(body_5) {
	      case 'w' :
	         {
						 if (dx-2<=0 || board [dx-2][dy]!=' '||board [dx-1][dy]=='w'){
							 return "invalid";

						 }
						 else{
							 board [dx-2][dy]='d';
							 board[dx][dy]=' ';
							 dx-=2;
							  return "true";
						 }
	         break;}
	      case 'a' :
				{
					if (dy-2<=0 || board [dx][dy-2]!=' '||board [dx][dy-1]=='w'){
						return "invalid";

					}
					else{
						board [dx][dy-2]='d';
						board[dx][dy]=' ';
						dy-=2;
						 return "true";
					}
				break;}
	      case 's' :
				{
				 if (dx+2>=22 || board [dx+2][dy]!=' '||board [dx+1][dy]=='w'){
					 return "invalid";

				 }
				 else{
					 board [dx+2][dy]='d';
					 board[dx][dy]=' ';
					 dx+=2;
					  return "true";
				 }
				break;}
	      case 'd' :
				{
				 if (dy+2>=22 || board [dx][dy+2]!=' '||board [dx][dy+1]=='w'){
					 return "invalid";

				 }
				 else{
					 board [dx][dy+2]='d';
					 board[dx][dy]=' ';
					 dy+=2;
					  return "true";
				 }
			 break;}

	      default :
				return "invalid";

	   }}
		 else
		 		return "turn";
	 }
	 }
		else
	 {
		 //res.set_content(body, "text/plain");
				if (str=="first" && turn%4==0 && wall_a!=0){

							if (x_pos%2==0){
									if (board [x_pos][y_pos]=='w'|| board [x_pos][y_pos+2]=='w' )	{
												return "invalid";
									}
									else{
										board [x_pos][y_pos]='w';
										board [x_pos][y_pos+2]='w';

										wall_a--;
										return "true";
									}
					  	}
							else{
								if (board [x_pos][y_pos]=='w'|| board [x_pos+2][y_pos]=='w' )	{
											return "invalid";
								}
								else{
									board [x_pos][y_pos]='w';
									board [x_pos+2][y_pos]='w';

									wall_a--;
									return "true";
								}
							}
			 }


				else	if (str=="secon" && turn%4==1 && wall_b!=0){

						 if (x_pos%2==0){
								 if (board [x_pos][y_pos]=='w'|| board [x_pos][y_pos+2]=='w' )	{
											 return "invalid";
								 }
								 else{
									 board [x_pos][y_pos]='w';
									 board [x_pos][y_pos+2]='w';

									 wall_b--;
									return "true";
								 }
						 }
						 else{
							 if (board [x_pos][y_pos]=='w'|| board [x_pos+2][y_pos]=='w' )	{
										 return "invalid";
							 }
							 else{
								 board [x_pos][y_pos]='w';
								 board [x_pos+2][y_pos]='w';

								 wall_b--;
								return "true";
							 }
						 }
			}
			else	if (str=="third" && turn%4==2 && wall_c!=0){

					 if (x_pos%2==0){
							 if (board [x_pos][y_pos]=='w'|| board [x_pos][y_pos+2]=='w' )	{
										 return "invalid";
							 }
							 else{
								 board [x_pos][y_pos]='w';
								 board [x_pos][y_pos+2]='w';

								 wall_c--;
								return "true";
							 }
					 }
					 else{
						 if (board [x_pos][y_pos]=='w'|| board [x_pos+2][y_pos]=='w' )	{
									 return "invalid";
						 }
						 else{
							 board [x_pos][y_pos]='w';
							 board [x_pos+2][y_pos]='w';

							 wall_c--;
							return "true";
						 }
					 }
		}
		else	if (str=="forth" && turn%4==3 && wall_d!=0){

				 if (x_pos%2==0){
						 if (board [x_pos][y_pos]=='w'|| board [x_pos][y_pos+2]=='w' )	{
									 return "invalid";
						 }
						 else{
							 board [x_pos][y_pos]='w';
							 board [x_pos][y_pos+2]='w';

							 wall_d--;
							 return "true";
						 }
				 }
				 else{
					 if (board [x_pos][y_pos]=='w'|| board [x_pos+2][y_pos]=='w' )	{
								 return "invalid";
					 }
					 else{
						 board [x_pos][y_pos]='w';
						 board [x_pos+2][y_pos]='w';

						 wall_d--;
						 return "true";
					 }
				 }
	}

			else
			 	return "invalid";
}
    return "invalid";
		}
};
