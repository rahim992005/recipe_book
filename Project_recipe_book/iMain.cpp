# include "iGraphics.h"
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
int musiccook;
//popup
int time_yhnem;
int yhnem;
int time_cooked_done;
int x,y,z;
int t;
//rgb
double r=255,g=255,b=255;
 //buy in rannaghor
 int n_rice,n_basmotirice,n_dal,n_mutton,n_chicken,n_egg,n_fish, n_soyabinoil, n_onion;
 //stock
 int rice,basmotirice,dal,mutton,chicken,egg,fish, soyabinoil, onion;
//price
 int price_rice,price_basmotirice,price_dal,price_mutton,price_chicken,price_egg,price_fish, price_soyabinoil, price_onion;
 int balance;
 int new_balance;
 int loanbalance;
 int new_loan_balance;
 //dish counter
 int dishes=0;
 int remaining_dishes;
 int c_dishes;///temp
//temp cook variable 
int khi_cook;
int msk_cook;
int ip_cook;
//cook in khi
int c_khi_rice;
int c_khi_dal;
int c_khi_soyabinoil;
int c_khi_onion;
//cook in msk
int c_msk_mutton;
int c_msk_dal;
int c_msk_onion;
//cook in ip
int c_ip_basmotirice;
int c_ip_fish;
int c_ip_soyabinoil;
int c_ip_onion;
//not_enough_money/ingredients
int not_enough_money;
int not_enough_ingredients;
//restart
int restart;
int score;
int highestscore;
int new_score;
//shopping list
int skhichuri,smsk,sip;
int n_skhichuri,n_smsk,n_sip;
//
int srice,sbasmotirice,sdal,smutton,schicken,sfish,segg,ssoyabinoil,sonion;
//
int s_total;
int whiteedge;


/*
	function iDraw() is called again and again by the system.

	*/           //     0                1               2            3                4               5              6                 7                8            9          10                     11                      12                   13              14                  15                  16                  17                             18                         19                      20                    21                           22                      23                     24              25                        26                  27                   28                 29                 30                      
char mp[31][35]={"mp\\home.jpg","mp\\1.khi.jpg","mp\\2.msk.jpg","mp\\3.ip.jpg","mp\\4.cc.jpg","mp\\5.dal.jpg","mp\\6.ep.jpg","mp\\7.cb.jpg","mp\\8.fc.jpg","mp\\9.cr.jpg","mp\\my rannaghor.jpg","mp\\recipe list.jpg","mp\\shopping_list.jpg","mp\\1.khi.rec.jpg","mp\\2.msk.rec.jpg","mp\\3.ip.rec.jpg","mp\\cuisine.jpg","mp\\bangladeshi_cuisine.jpg","mp\\indian_cuisine.jpg","mp\\pakistani_cuisine.jpg","mp\\thai_cuisine.jpg","mp\\bd_khichuri_ing.jpg","mp\\bd_khichuri_rec.jpg","mp\\bd_msk_ing.jpg","mp\\bd_msk_rec.jpg","mp\\bd_ip_ing.jpg","mp\\bd_ip_rec.jpg","mp\\ind_ctk_ing.jpg","mp\\ind_ctk_rec.jpg","mp\\sorry.jpg","mp\\game over.jpg"};
int mpIndex=0;
//char animation[8][35]={"animation\\1st.jpg","animation\\2nd.jpg","animation\\3rd.jpg","animation\\4th.jpg","animation\\5th.jpg","animation\\6th.jpg","animation\\7th.jpg","animation\\8th.jpg",};

//char bp[1][20]={"bp\\you_have_not_money.jpg"};
//int bpIndex;


bool musicon=false;	
bool musicCook=false;
bool button=false;
bool gameover = false;
bool buy=false;
bool invalid=false;
bool loanmusic=false;


void iDraw() {
	//place your drawing codes here
	iClear();
	
	
	iShowBMP(0,0,mp[mpIndex]);
	if(not_enough_money==1){
		iShowBMP(555,10,"bp\\you_have_not_money.jpg");
	}
	if(khi_cook==1 || msk_cook==1 || ip_cook==1){
		t=1;
	}
	if(t==1 && (mpIndex==1 || mpIndex==2 || mpIndex==3)){
		iShowBMP(718,224,"bp\\cooked_done.jpg");
	}
	if(whiteedge==1){
		iSetColor(255,0,0);
		iRectangle(31,693,114,133);
		iFilledRectangle(31,693,114,133);
	}
	
	
	iSetColor(r,g, b);
	//iFilledCircle(x, y, r);
	//iFilledRectangle(10, 30, 20, 20);
	//iSetColor(20, 200, 0);
	//iText(0, 0, "Hi RAHIM");

	//shopping list
	FILE* Skhichuri=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\skhichuritext.txt","r+");
	FILE* Smsk=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\smsktext.txt","r+");
	FILE* Sip=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\siptext.txt","r+");
    if(Skhichuri==NULL ){
        printf("skhichuri):");
        exit(1);
    }
	 if(Smsk==NULL ){
        printf("smsk):");
        exit(1);
    }
	 if(Sip==NULL ){
        printf("sip):");
        exit(1);
    }
	fscanf(Skhichuri,"%d",&skhichuri);
	fseek(Skhichuri, 0, SEEK_SET);

	fscanf(Smsk,"%d",&smsk);
	fseek(Smsk, 0, SEEK_SET);

	fscanf(Sip,"%d",&sip);
	fseek(Sip, 0, SEEK_SET);

	skhichuri=skhichuri+n_skhichuri;
	smsk=smsk+n_smsk;
	sip=sip+n_sip;
	n_skhichuri=0;
	n_smsk=0;
	n_sip=0;

	fprintf(Skhichuri,"%02d",skhichuri);
	fseek(Skhichuri, 0, SEEK_SET);
	fprintf(Smsk,"%02d",smsk);
	fseek(Smsk, 0, SEEK_SET);
	fprintf(Sip,"%02d",sip);
	fseek(Sip, 0, SEEK_SET);

	char str_skhichuri[4];
	fscanf(Skhichuri,"%s",&str_skhichuri);
	char str_smsk[4];
	fscanf(Smsk,"%s",&str_smsk);
	char str_sip[4];
	fscanf(Sip,"%s",&str_sip);
	
	
	
	fclose(Skhichuri);
	fclose(Smsk);
	fclose(Sip);

	if(mpIndex==12){
		iText(370,416, str_skhichuri,GLUT_BITMAP_HELVETICA_18);
	}
	if(mpIndex==12){
		iText(370,385, str_smsk,GLUT_BITMAP_HELVETICA_18);
	}
	if(mpIndex==12){
		iText(370,350, str_sip,GLUT_BITMAP_HELVETICA_18);
	}

	///srice.....
	srice=500*skhichuri-rice;
	sbasmotirice=500*sip-basmotirice;
	sdal=100*skhichuri+100*smsk-dal;
	smutton=800*smsk-mutton;
	schicken=00;
	sfish=500*sip-fish;
	segg=00;
	ssoyabinoil=100*skhichuri+200*sip-soyabinoil;
	sonion=100*skhichuri+200*smsk+200*sip-onion;
	if(srice<=0){
		srice=0;
	}
	if(sbasmotirice<=0){
		sbasmotirice=0;
	}
	if(sdal<=0){
		sdal=0;
	}
	if(smutton<=0){
		smutton=0;
	}
	if(schicken<=0){
		schicken=0;
	}
	if(sfish<=0){
		sfish=0;
	}
	if(segg<=0){
		segg=0;
	}
	if(ssoyabinoil<=0){
		ssoyabinoil=0;
	}
	if(sonion<=0){
		sonion=0;
	}
	s_total = srice/10+sbasmotirice/10*3+sdal/10*2+smutton/10*12+schicken/10*5+sfish/10*7+segg*10+ssoyabinoil/10*2+sonion/10;

	char str_srice[5];
	char str_sbasmotirice[5];
	char str_sdal[5];
	char str_smutton[5];
	char str_schicken[5];
	char str_sfish[5];
	char str_segg[5];
	char str_ssoyabinoil[5];
	char str_sonion[5];
	char str_stotal[5];

	sprintf(str_srice,"%d",srice);
	sprintf(str_sbasmotirice,"%d",sbasmotirice);
	sprintf(str_sdal,"%d",sdal);
	sprintf(str_smutton,"%d",smutton);
	sprintf(str_schicken,"%d",schicken);
	sprintf(str_sfish,"%d",sfish);
	sprintf(str_segg,"%d",segg);
	sprintf(str_ssoyabinoil,"%d",ssoyabinoil);
	sprintf(str_sonion,"%d",sonion);
	sprintf(str_stotal,"%d",s_total);

	
	if(mpIndex==12){
		iText(875,565, str_srice,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(875,510, str_sbasmotirice,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(875,448, str_sdal,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(875,388, str_smutton,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(875,330, str_schicken,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(875,270, str_sfish,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(875,220, str_segg,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(875,154, str_ssoyabinoil,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(875,98, str_sonion,GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1275,408, str_stotal,GLUT_BITMAP_TIMES_ROMAN_24);
	}







	//balance
	FILE* Balance=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\balancetext.txt","r+");
    if(Balance==NULL){
        printf("balance):");
        exit(1);
    }
	fscanf(Balance,"%d",&balance);
	fseek(Balance, 0, SEEK_SET);
	balance=balance+new_balance-price_rice-price_basmotirice-price_dal-price_mutton-price_chicken-price_egg-price_fish-price_soyabinoil-price_onion;	
	new_balance=0,price_rice=0,price_basmotirice=0,price_dal=0,price_mutton=0,price_chicken=0,price_egg=0,price_fish=0, price_soyabinoil=0, price_onion=0;
	if(restart==1){
		balance=3000;
	}
	fprintf(Balance,"%04d",balance);
	fseek(Balance, 0, SEEK_SET);
	char str_balance[6];
	fscanf(Balance,"%s",&str_balance);
	fclose(Balance);
	
	if(mpIndex==10){
		iText(1310,458, str_balance,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//balance
	//loan balance
	FILE* Loanbalance=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\loanbalancetext.txt","r+");
    if(Loanbalance==NULL){
        printf("loanbalance):");
        exit(1);
    }
	fscanf(Loanbalance,"%d",&loanbalance);
	fseek(Loanbalance, 0, SEEK_SET);
	loanbalance=loanbalance+new_loan_balance;	
	new_loan_balance=0;
	if(restart==1){
		loanbalance=0;
	}
	fprintf(Loanbalance,"%04d",loanbalance);
	fseek(Loanbalance, 0, SEEK_SET);
	char str_loan_balance[10];
	fscanf(Loanbalance,"%s",&str_loan_balance);
	fclose(Loanbalance);
	
	if(mpIndex==10){
		iText(1295,565, str_loan_balance,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//loan balance
	//remaining_dishes
	FILE* Dishes=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\dishestext.txt","r+");
    if(Dishes==NULL){
        printf("Dishes):");
        exit(1);
    }
	fscanf(Dishes,"%d",&dishes);
	fseek(Dishes, 0, SEEK_SET);
	dishes=dishes-c_dishes;
	c_dishes=0;
	if(dishes==0){
		dishes+=9;
		new_balance=3000-loanbalance;
		new_loan_balance=-loanbalance;
	}
	if(restart==1){
		dishes=9;
	}
	fprintf(Dishes,"%02d",dishes);
	fseek(Dishes, 0, SEEK_SET);
	char str_dishes[10];
	fscanf(Dishes,"%s",&str_dishes);
	fclose(Dishes);
	
	if(mpIndex==10){
		iText(1340,350, str_dishes,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(mpIndex>=1 && mpIndex<=9){
		iText(1348,555, str_dishes,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//remaining dishes
	//highest score
	FILE* Highestscore=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\highestscoretext.txt","r+");
    if(Highestscore==NULL){
        printf("highestscore):");
        exit(1);
    }
	fscanf(Highestscore,"%d",&highestscore);
	fseek(Highestscore, 0, SEEK_SET);
	if(score>=highestscore){
		highestscore=score;
	}
	fprintf(Highestscore,"%04d",highestscore);
	fseek(Highestscore, 0, SEEK_SET);
	char str_highestscore[10];
	fscanf(Highestscore,"%s",&str_highestscore);
	fclose(Highestscore);
	
	if(mpIndex==30){
		iText(1054,276, str_highestscore,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//highest score
	//score
	FILE* Score=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\scoretext.txt","r+");
    if(Score==NULL){
        printf("score):");
        exit(1);
    }
	fscanf(Score,"%d",&score);
	fseek(Score, 0, SEEK_SET);
	score=score+new_score;	
	new_score=0;
	if(restart==1){
		score=0;
	}
	//if(mpIndex==30){
	//	score=score/3;
	//}
	fprintf(Score,"%03d",score);
	fseek(Score, 0, SEEK_SET);
	char str_score[10];
	fscanf(Score,"%s",&str_score);
	fclose(Score);
	
	if(mpIndex==30){
		iText(941,353, str_score,GLUT_BITMAP_TIMES_ROMAN_24);
	}

	//score
	//rice
	FILE* Rice=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\ricetext.txt","r+");
    if(Rice==NULL){
        printf("rice):");
        exit(1);
    }
	 //int rice;
	 
    fscanf(Rice,"%d",&rice);

	if(khi_cook==1){
		 c_khi_rice=500;
	}
	fseek(Rice, 0, SEEK_SET);
	if(restart==1){
		rice=0;
	}
	fprintf(Rice,"%05d",rice+n_rice-c_khi_rice);
	
	c_khi_rice=0;
	n_rice=0;	 

	///khi_rice
	int khi_rice;
	
	if(rice<500){
		khi_rice=500-rice;
	}
	else {
		khi_rice=0;
	}
	char str_khi_rice[5];
	sprintf(str_khi_rice,"%d",khi_rice);
	///khi_rice
	
	
	fseek(Rice, 0, SEEK_SET);
	char str_rice[10];
	fscanf(Rice,"%s",&str_rice);


    fclose(Rice);
	if(mpIndex==10){
		iText(875,530, str_rice ,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(mpIndex==1){
		iText(1090,518,str_khi_rice,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	
	//basmotirice
	FILE* Basmotirice=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\basmotiricetext.txt","r+");
    if(Basmotirice==NULL){
        printf("basmotirice):");
        exit(1);
    }
	 //int basmotirice;
     fscanf(Basmotirice,"%d",&basmotirice);

	if(ip_cook==1 ){
		 c_ip_basmotirice=500;
	}
	fseek(Basmotirice, 0, SEEK_SET);
	if(restart==1){
		basmotirice=0;
	}
	fprintf(Basmotirice,"%05d",basmotirice+n_basmotirice-c_ip_basmotirice);
	
	c_ip_basmotirice=0;
	n_basmotirice=0;	
	//ip_basmotirice
	int ip_basmotirice;
	if(basmotirice<500){
		ip_basmotirice=500-basmotirice;
	}
	else {
		ip_basmotirice=0;
	}
	char str_ip_basmotirice[5];
	sprintf(str_ip_basmotirice,"%d",ip_basmotirice);
	//ip_basmotirice;
	n_basmotirice=0;
	fseek(Basmotirice, 0, SEEK_SET);
	char str_basmotirice[10];
	fscanf(Basmotirice,"%s",&str_basmotirice);


    fclose(Basmotirice);
	if(mpIndex==10){
		iText(875,478, str_basmotirice ,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(mpIndex==3){
		iText(1090,518,str_ip_basmotirice,GLUT_BITMAP_TIMES_ROMAN_24);
	}

	//dal

	FILE* Dal=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\daltext.txt","r+");
    if(Dal==NULL){
        printf("dal):");
        exit(1);
    }
	 //int dal;
    fscanf(Dal,"%d",&dal);

	if(khi_cook==1 ){
		 c_khi_dal=100;
	}
	if(msk_cook==1 ){
		 c_msk_dal=100;
	}
	fseek(Dal, 0, SEEK_SET);
	if(restart==1){
		dal=0;
	}
	fprintf(Dal,"%05d",dal+n_dal-c_khi_dal-c_msk_dal);
	
	c_msk_dal=0;
	c_khi_dal=0;
	n_dal=0;	
	//khi_dal
	int khi_dal;
	if(dal<100){
		khi_dal=100-dal;
	}
	else {
		khi_dal=0;
	}
	char str_khi_dal[5];
	sprintf(str_khi_dal,"%d",khi_dal);
	//khi_dal
	//msk_dal
	int msk_dal;
	if(dal<100){
		msk_dal=100-dal;
	}
	else {
		msk_dal=0;
	}
	char str_msk_dal[5];
	sprintf(str_msk_dal,"%d",msk_dal);
	//msk_dal
	n_dal=0;
	fseek(Dal, 0, SEEK_SET);
	char str_dal[10];
	fscanf(Dal,"%s",&str_dal);


    fclose(Dal);
	if(mpIndex==10){
		iText(875,426, str_dal ,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(mpIndex==1){
		iText(1090,466,str_khi_dal,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(mpIndex==2){
		iText(1090,466,str_msk_dal,GLUT_BITMAP_TIMES_ROMAN_24);
	}

	//mutton

	FILE* Mutton=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\muttontext.txt","r+");
    if(Mutton==NULL){
        printf("mutton):");
        exit(1);
    }
	// int mutton;
     
    fscanf(Mutton,"%d",&mutton);

	if(msk_cook==1 ){
		 c_msk_mutton=800;
	}
	fseek(Mutton, 0, SEEK_SET);
	if(restart==1){
		mutton=0;
	}
	fprintf(Mutton,"%05d",mutton+n_mutton-c_msk_mutton);
	
	c_msk_mutton=0;
	n_mutton=0;	
	//msk_mutton
	int msk_mutton;
	if(mutton<800){
		msk_mutton=800-mutton;
	}
	else {
		msk_mutton=0;
	}
	char str_msk_mutton[5];
	sprintf(str_msk_mutton,"%d",msk_mutton);
	//msk_mutton;
	n_mutton=0;
	fseek(Mutton, 0, SEEK_SET);
	char str_mutton[10];
	fscanf(Mutton,"%s",&str_mutton);


    fclose(Mutton);
	if(mpIndex==10){
		iText(875,372, str_mutton ,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(mpIndex==2){
		iText(1090,518,str_msk_mutton,GLUT_BITMAP_TIMES_ROMAN_24);
	}

	//chicken

	FILE* Chicken=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\chickentext.txt","r+");
    if(Chicken==NULL){
        printf("chicken):");
        exit(1);
    }
	// int chicken;
    fscanf(Chicken,"%d",&chicken);

	fseek(Chicken, 0, SEEK_SET);
	if(restart==1){
		chicken=0;
	}
	
    fprintf(Chicken,"%05d",chicken+n_chicken);
	n_chicken=0;
	fseek(Chicken, 0, SEEK_SET);
	char str_chicken[10];
	fscanf(Chicken,"%s",&str_chicken);


    fclose(Chicken);
	if(mpIndex==10){
		iText(875,319, str_chicken ,GLUT_BITMAP_TIMES_ROMAN_24);
	}

	//fish

	FILE* Fish=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\fishtext.txt","r+");
    if(Fish==NULL){
        printf("fish):");
        exit(1);
    }
	// int fish;
   fscanf(Fish,"%d",&fish);

	if(ip_cook==1){
		 c_ip_fish=500;
	}
	fseek(Fish, 0, SEEK_SET);
	if(restart==1){
		fish=0;
	}
	fprintf(Fish,"%05d",fish+n_fish-c_ip_fish);
	
	c_ip_fish=0;
	n_fish=0;	 

	///khi_rice
	int ip_fish;
	
	if(fish<500){
		ip_fish=500-fish;
	}
	else {
		ip_fish=0;
	}
	char str_ip_fish[5];
	sprintf(str_ip_fish,"%d",ip_fish);
	///khi_rice
	
	
	fseek(Fish, 0, SEEK_SET);
	char str_fish[10];
	fscanf(Fish,"%s",&str_fish);


    fclose(Fish);
	if(mpIndex==10){
		iText(875,265, str_fish ,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(mpIndex==3){
		iText(1090,466,str_ip_fish,GLUT_BITMAP_TIMES_ROMAN_24);
	}


	//egg

	FILE* Egg=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\eggtext.txt","r+");
    if(Egg==NULL){
        printf("egg):");
        exit(1);
    }
	// int egg;
    fscanf(Egg,"%d",&egg);

	fseek(Egg, 0, SEEK_SET);
	if(restart==1){
		egg=0;
	}
	
    fprintf(Egg,"%d",egg+n_egg);
	n_egg=0;
	fseek(Egg, 0, SEEK_SET);
	char str_egg[10];
	fscanf(Egg,"%s",&str_egg);


    fclose(Egg);
	if(mpIndex==10){
		iText(875,212, str_egg ,GLUT_BITMAP_TIMES_ROMAN_24);
	}

	

	//soyabin oil

	FILE* Soyabinoil=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\soyabinoiltext.txt","r+");
    if(Soyabinoil==NULL){
        printf("soyabin oil):");
        exit(1);
    }
	// int soyabinoil;
    fscanf(Soyabinoil,"%d",&soyabinoil);

	if(khi_cook==1){
		 c_khi_soyabinoil=100;
	}
	if(ip_cook==1){
		 c_ip_soyabinoil=200;
	}
	fseek(Soyabinoil, 0, SEEK_SET);
	if(restart==1){
		soyabinoil=0;
	}
	fprintf(Soyabinoil,"%05d",soyabinoil+n_soyabinoil-c_khi_soyabinoil-c_ip_soyabinoil);
	c_ip_soyabinoil=0;
	c_khi_soyabinoil=0;
	n_soyabinoil=0;	
	//khi_soyabinoil
	int khi_soyabinoil;
	if(soyabinoil<100){
		khi_soyabinoil=100-soyabinoil;
	}
	else {
		khi_soyabinoil=0;
	}
	char str_khi_soyabinoil[5];
	sprintf(str_khi_soyabinoil,"%d",khi_soyabinoil);
	//khi_soyabinoil
	//ip_soyabinoil
	int ip_soyabinoil;
	if(soyabinoil<200){
		ip_soyabinoil=200-soyabinoil;
	}
	else {
		ip_soyabinoil=0;
	}
	char str_ip_soyabinoil[5];
	sprintf(str_ip_soyabinoil,"%d",ip_soyabinoil);
	//ip_soyabinoil
	n_soyabinoil=0;
	fseek(Soyabinoil, 0, SEEK_SET);
	char str_soyabinoil[10];
	fscanf(Soyabinoil,"%s",&str_soyabinoil);


    fclose(Soyabinoil);
	if(mpIndex==10){
		iText(875,159, str_soyabinoil ,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(mpIndex==1){
		iText(1090,414,str_khi_soyabinoil,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(mpIndex==3){
		iText(1090,414,str_ip_soyabinoil,GLUT_BITMAP_TIMES_ROMAN_24);
	}

	//onion

	FILE* Onion=fopen("C:\\Users\\Abdur Rahim\\Desktop\\game\\mrg\\oniontext.txt","r+");
    if(Onion==NULL){
        printf("onion):");
        exit(1);
    }
	// int onion;
    fscanf(Onion,"%d",&onion);

	if(khi_cook==1){
		 c_khi_onion=100;
	}
	if(msk_cook==1){
		c_msk_onion=200;
	}
	if(ip_cook==1){
		c_ip_onion=200;
	}
	fseek(Onion ,0, SEEK_SET);
	if(restart==1){
		onion=0;
	}
	fprintf(Onion,"%05d",onion+n_onion-c_khi_onion-c_msk_onion-c_ip_onion);
	
	c_msk_onion=0;
	c_khi_onion=0;
	c_ip_onion=0;
	n_onion=0;
	//khi_onion
	int khi_onion;
	if(onion<100){
		khi_onion=100-onion;
	}
	else {
		khi_onion=0;
	}
	char str_khi_onion[5];
	sprintf(str_khi_onion,"%d",khi_onion);
	//khi_onoion
	//msk_onion
	int msk_onion;
	if(onion<200){
		msk_onion=200-onion;
	}
	else {
		msk_onion=0;
	}
	char str_msk_onion[5];
	sprintf(str_msk_onion,"%d",msk_onion);
	//msk_onoion
	//ip_onion
	int ip_onion;
	if(onion<200){
		ip_onion=200-onion;
	}
	else {
		ip_onion=0;
	}
	char str_ip_onion[5];
	sprintf(str_ip_onion,"%d",ip_onion);
	//ip_onoion
	n_onion=0;
	fseek(Onion, 0, SEEK_SET);
	char str_onion[10];
	fscanf(Onion,"%s",&str_onion);


    fclose(Onion);
	if(mpIndex==10){
		iText(875,106, str_onion,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(mpIndex==1){
		iText(1090,362,str_khi_onion,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(mpIndex==2){
		iText(1090,414,str_msk_onion,GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(mpIndex==3){
		iText(1090,362,str_ip_onion,GLUT_BITMAP_TIMES_ROMAN_24);
	}

	////
	khi_cook=0;
	msk_cook=0;
	ip_cook=0;
	restart=0;

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	//printf("x = %d, y= %d\n",mx,my);
	//place your codes here
	 if (mx>31 && mx<145 && my>693 && my<726 && mpIndex==0) {
		whiteedge=1;
		exit(1);
	}
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		printf("x = %d, y= %d\n",mx,my);
	}
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>217 && mx<456 && my>422 && my<474 && mpIndex==0 ) {

		mpIndex=11;	//my recipe
			button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
		
		
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>547 && mx<786 && my>422 && my<474 && mpIndex==0) {

		 mpIndex=16; //other recipe list
		 button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>224 && mx<462 && my>311 && my<361 && mpIndex==0) {

		mpIndex=10;  //my rannaghor
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>548 && mx<788 && my>310 && my<363 && mpIndex==0) {

		mpIndex=12; //shopping list
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>31 && mx<145 && my>693 && my<726 && mpIndex==0) {

		exit(1);
	}
	/////my recipe list
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>279 && mx<485 && my>454 && my<606 && mpIndex==11) {

		mpIndex=1;
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}	
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>279 && mx<485 && my>249 && my<407 && mpIndex==11) {

		mpIndex=4;
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}	
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>279 && mx<485 && my>47 && my<205 && mpIndex==11) {

		mpIndex=7;
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}	
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>615 && mx<824 && my>454 && my<606 && mpIndex==11) {

		mpIndex=2;
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}	
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>615 && mx<824 && my>249 && my<407 && mpIndex==11) {

		mpIndex=5;
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}	
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>615 && mx<824 && my>47 && my<205 && mpIndex==11) {

		mpIndex=8;
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}	
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>959 && mx<1166 && my>454 && my<606 && mpIndex==11) {

		mpIndex=3;
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>959 && mx<1166 && my>249 && my<407 && mpIndex==11) {

		mpIndex=6;
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>959 && mx<1166 && my>47 && my<205 && mpIndex==11) {

		mpIndex=9;
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}
	/////my recipe list
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>108 && mx<297 && my>70 && my<110 && mpIndex>=1 && mpIndex<=3) {

		mpIndex=11;//back to recipe list
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}	
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>55 && mx<261 && my>70 && my<110 && (mpIndex==11 || mpIndex==10 || mpIndex==12 || mpIndex==16)) {

		mpIndex=0;
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}	
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>1275 && mx<1463 && my>417 && my<465 && mpIndex>=1 && mpIndex<=3 ) {
		mpIndex=mpIndex+12;
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
		
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>108 && mx<297 && my>70 && my<110 && mpIndex>=13 && mpIndex<=15) {

		mpIndex=mpIndex-12; //back to recipe 
		button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>595 && mx<897 && my>138 && my<200 && mpIndex==30 ) {

		restart=1;
		mpIndex=0;
		//use a restart sound 	
	}
///cuisine -> bd/ind/pak/thai cuisine
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  && mpIndex==16 ) {
			if( mx>381 && mx<726 && my>402 && my<612){
					mpIndex=17;
					button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
			}	
			else if( mx>774 && mx<1117 && my>402 && my<612){
					mpIndex=18;
					button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
			}
			else if( mx>381 && mx<726 && my>135 && my<344){
					mpIndex=19;
					button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
			}
			else if( mx>774 && mx<1117 && my>135 && my<344){
					mpIndex=20;
					button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);		
			}				
		
	}
////back to cuisine
else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN   && mx>55 && mx<261 && my>70 && my<110 && (mpIndex==17 || mpIndex==18 || mpIndex==19 || mpIndex==20) ){
	mpIndex=16;
	button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
}
///bd cuisine
else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  && mpIndex==17 ) {
			if( mx>277 && mx<486 && my>453 && my<607){
					mpIndex=21;
					button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
			}
			else if( mx>617 && mx<824 && my>453 && my<607){
					mpIndex=23;
					button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
			}
			else if( mx>957 && mx<1166 && my>453 && my<607){
					mpIndex=25;	
					button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
			}
	}
////back to bd_cuisine
else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN   && mx>55 && mx<261 && my>70 && my<110 && (mpIndex==21 || mpIndex==23|| mpIndex==25) ){
	mpIndex=17;
	button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
}
///ing into rec
else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN   && mx>1265 && mx<1455 && my>565 && my<613 && (mpIndex==21 || mpIndex==23|| mpIndex==25 || mpIndex==27) ){
	mpIndex=mpIndex+1;
	button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
}
//ind cuisine
else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN  && mpIndex==18 ) {
			if( mx>277 && mx<486 && my>453 && my<607){
					mpIndex=27;
					button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
			}
			else if( mx>617 && mx<824 && my>453 && my<607){
					mpIndex=29;
					button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
			}
			else if( mx>957 && mx<1166 && my>453 && my<607){
					mpIndex=29;
					button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);	
			}
	}
	////back to ind_cuisine
else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN   && mx>55 && mx<261 && my>70 && my<110 && (mpIndex==27 || mpIndex==29) ){
	mpIndex=18;
	button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
}
//back to ing from rec
else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN   && mx>55 && mx<261 && my>70 && my<110 && (mpIndex==22 || mpIndex==24|| mpIndex==26 || mpIndex==28) ){
	mpIndex=mpIndex-1;
	button=true;
			PlaySound("music\\button.wav",NULL,SND_ASYNC);
}
/// my rannaghor
	///add here a adding sound
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>1027 && mx<1170 && my>518 && my<558 && mpIndex==10) {

	if(balance>=10){
		n_rice=100;
	price_rice=10;
	buy=true;
	PlaySound("music\\buy.wav",NULL,SND_ASYNC);
	}
	else{
		not_enough_money=1;
		invalid=true;
		PlaySound("music\\invalid.wav",NULL,SND_ASYNC);
	}
	
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>1027 && mx<1170 && my>463 && my<503 && mpIndex==10) {

	if(balance>=30){
		n_basmotirice=100;
	price_basmotirice=30;
	buy=true;
	PlaySound("music\\buy.wav",NULL,SND_ASYNC);
	}
	else{
		not_enough_money=1;
		invalid=true;
		PlaySound("music\\invalid.wav",NULL,SND_ASYNC);
	}
	
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>1027 && mx<1170 && my>411 && my<451 && mpIndex==10) {

	if(balance>=20){
		n_dal=100;
	price_dal=20;
	buy=true;
	PlaySound("music\\buy.wav",NULL,SND_ASYNC);
	}
	else{
		not_enough_money=1;
		invalid=true;
		PlaySound("music\\invalid.wav",NULL,SND_ASYNC);
	}
	
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>1027 && mx<1170 && my>354 && my<394 && mpIndex==10) {

	if(balance>=120){
		n_mutton=100;
	price_mutton=120;
	buy=true;
	PlaySound("music\\buy.wav",NULL,SND_ASYNC);
	}
	else{
		not_enough_money=1;
		invalid=true;
		PlaySound("music\\invalid.wav",NULL,SND_ASYNC);
	}
	
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>1027 && mx<1170 && my>303 && my<343 && mpIndex==10) {

	if(balance>=50){
		n_chicken=100;
	price_chicken=50;
	buy=true;
	PlaySound("music\\buy.wav",NULL,SND_ASYNC);
	}
	else{
		not_enough_money=1;
		invalid=true;
		PlaySound("music\\invalid.wav",NULL,SND_ASYNC);
	}
	
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>1027 && mx<1170 && my>250 && my<290 && mpIndex==10) {

	if(balance>=70){
		n_fish=100;
	price_fish=70;
	buy=true;
	PlaySound("music\\buy.wav",NULL,SND_ASYNC);
	}
	else{
		not_enough_money=1;
		invalid=true;
		PlaySound("music\\invalid.wav",NULL,SND_ASYNC);
	}
	
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>1027 && mx<1170 && my>197 && my<237 && mpIndex==10) {

	if(balance>=10){
		n_egg=1;
	price_egg=10;
	buy=true;
	PlaySound("music\\buy.wav",NULL,SND_ASYNC);
	}
	else{
		not_enough_money=1;
		invalid=true;
		PlaySound("music\\invalid.wav",NULL,SND_ASYNC);
	}
	
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>1027 && mx<1170 && my>143 && my<183 && mpIndex==10) {

	if(balance>=20){
		n_soyabinoil=100;
	price_soyabinoil=20;
	buy=true;
	PlaySound("music\\buy.wav",NULL,SND_ASYNC);
	}
	else{
		not_enough_money=1;
		invalid=true;
		PlaySound("music\\invalid.wav",NULL,SND_ASYNC);
	}
	
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>1027 && mx<1170 && my>88 && my<128 && mpIndex==10) {

	if(balance>=10){
		n_onion=100;
	price_onion=10;
	buy=true;
	PlaySound("music\\buy.wav",NULL,SND_ASYNC);
	}
	else{
		not_enough_money=1;
		invalid=true;
		PlaySound("music\\invalid.wav",NULL,SND_ASYNC);
	}
	
	}
	///cook
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>1274 && mx<1465 && my>347 && my<395 ){
	
		if(mpIndex==1){
			if( rice>=500 && dal>=100 && soyabinoil>=50 && onion>=100){
				khi_cook=1;
				c_dishes=1;
				new_score=1;
				musiccook=1;
		
			musicCook=true;
			PlaySound("music\\cook.wav",NULL,SND_ASYNC);
		
			}
			else{
				not_enough_ingredients=1;
				invalid=true;
			PlaySound("music\\invalid.wav",NULL,SND_ASYNC);
			}
		}
			
		else if(mpIndex==2){
			if( mutton>=800 && dal>=100 && onion>=200){
				msk_cook=1;
				c_dishes=1;
				new_score=1;
				musiccook=1;
				musicCook=true;
			PlaySound("music\\cook.wav",NULL,SND_ASYNC);
			}
			else{
				not_enough_ingredients=1;
			invalid=true;
			PlaySound("music\\invalid.wav",NULL,SND_ASYNC);
			}
		}
			
		else if(mpIndex==3){
			if(basmotirice>=500 && fish>=500 && soyabinoil>=200 && onion>=100){
				ip_cook=1;
				c_dishes=1;
				new_score=1;
				musiccook=1;
				musicCook=true;
			PlaySound("music\\cook.wav",NULL,SND_ASYNC);
			}
			else{
				not_enough_ingredients=1;
			invalid=true;
			PlaySound("music\\invalid.wav",NULL,SND_ASYNC);
			}
		}
					
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mx>1403 && mx<1482 && my>548 && my<597 && mpIndex==10 ) {

		new_balance=500;
		new_loan_balance=500;
		loanmusic=true;
		PlaySound("music\\loan.wav",NULL,SND_ASYNC);
		
		
	}
	else if(loanbalance>3000){
		mpIndex=30;
		gameover=true;
		PlaySound("music\\gameover.wav",NULL,SND_ASYNC);
		//add a game over sound
	}
	//shopping list
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&  mpIndex==12 ){
		if(mx>340 && mx<364 && my>410 && my<436 && skhichuri>=1){
			n_skhichuri=-1;
		}
		else if(mx>394 && mx<409 && my>410 && my<436 && skhichuri<=19){
			n_skhichuri=1;
		}
		else if(mx>340 && mx<364 && my>377 && my<404 && smsk>=1){
			n_smsk =-1;
		}
		else if(mx>394 && mx<409 && my>377 && my<404 && smsk<=19){
			n_smsk =1;
		}
		else if(mx>340 && mx<364 && my>344 && my<364 && sip>=1){
			n_sip = -1;	
		}
		else if(mx>394 && mx<409 && my>344 && my<364 && sip<=19){
			n_sip =1;
		}
	}

	
	
   
	/*if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		printf("x = %d, y= %d\n",mx,my);
		//place your codes here
		//x -= 10;
		//y -= 10;
	}*/

	   
		
	











}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}

	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	 if (key == GLUT_KEY_F1) {
		if(musicon){
			musicon=false;
			PlaySound(0,0,0);
		}
		else{
			musicon=true;
			PlaySound("music\\temp.wav",NULL,SND_LOOP | SND_ASYNC);
		}
	}
	//place your codes for other keys here
}

void popup(){
	not_enough_money=0;
	t=0;
}
void cooked_done(){
	iPauseTimer(1);
	if(t==1){
		t=0;
	}
	
}
//#pragma comment(lib, "Winmm.lib")
int main() {
	//time_yhnem=
	iSetTimer(1000, popup);
	//time_cooked_done=
	iSetTimer(3000,cooked_done);
	if(musicCook){
	 PlaySound("music\\cook.wav",NULL,SND_ASYNC);
	}
	//musiccook=0;
       if(button){
	 PlaySound("music\\button.wav",NULL,SND_ASYNC);
	}
	//button
	if(musicon){
	   PlaySound("music\\temp.wav",NULL,SND_LOOP | SND_ASYNC);
	}
	//full music
	if(gameover){
	   PlaySound("music\\gameover.wav",NULL,SND_ASYNC);
	}
	//gameover
	if(buy){
	   PlaySound("music\\buy.wav",NULL,SND_ASYNC);
	}
	//buy
	if(invalid){
	   PlaySound("music\\invalid.wav",NULL,SND_ASYNC);
	}
	//invalid
	if(loanmusic){
	   PlaySound("music\\loan.wav",NULL,SND_ASYNC);
	}
	//place your own initialization codes here.
	iInitialize(1500, 750, "demo");

	return 0;
}
