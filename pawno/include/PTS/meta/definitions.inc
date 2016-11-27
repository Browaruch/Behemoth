//definicje
#define CZASGLODU 		75000
#define CZASZmeczenia 	85000
#define ODBIERZPALIWOCZAS 18000
#define ADMIN_SPEC_TYPE_NONE 15
#define ADMIN_SPEC_TYPE_PLAYER 16
#define ADMIN_SPEC_TYPE_VEHICLE 17

#define COLOR_INFO				(0x00AAAAFF)
#define COLOR_ERROR				(0xCC0000FF)

#define SERVER_START_TICK		(1476619200)

#define dli(%1,%2,%3,%4)		((%1==1)?(%2):(((%1% 10>1)&&(%1% 10<5)&&!((%1% 100>=10)&&(%1% 100<=21)))?(%3):(%4)))

#define LOGIN 0
#define REJESTRACJA 1
#define RozladuekDialog 2
#define DIALOG_FRAKCJI 3
#define DIALOG_INF 4
#define DIALOG_WYPLATA 5
#define DIALOG_WYPLATA2 6
#define DIALOG_WYPLATA3 7
#define DIALOG_WYPLATA4 8
#define DIALOG_WYPLATA5 9
#define DIALOG_WYPLATA6 10

#define DIALOG_ZATRUDNIANIA 11
#define DIALOG_WYRZUCANIA 12
#define DIALOG_PRAWKO 13
#define DIALOG_PRAWKO2 14
#define DIALOG_BANK 15
#define DIALOG_BANK2 16
#define DIALOG_BANK3 17
#define DIALOG_BANK4 18
#define DIALOG_BANK5 19
#define DIALOG_BANK6 20
#define DIALOG_TANK 21
#define DIALOG_TEORIA 22
#define DIALOG_TEORIA2 23
#define DIALOG_TEORIA3 24
#define DIALOG_TEORIA4 25
#define DIALOG_TEORIA5 26
#define DIALOG_TEORIA6 27
#define DIALOG_TEORIA7 28
#define DIALOG_TEORIA8 29
#define DIALOG_TEORIA9 30
#define DIALOG_TEORIA11 32
#define DIALOG_TEORIA10 31
#define DIALOG_PORT1 33
#define DIALOG_PORT2 34
#define DIALOG_PORT3 35
#define DIALOG_PORT4 36
#define DIALOG_PORT5 37

#define DIALOG_STYLWALKI		15003

#define MAX_VIPOW				555
#define MAX_DOMOW				500
#define MAX_ZALADUNKOW			100
#define MAX_TOWAROW				27
#define MAX_FIRM 				21
#define MAX_PRIV 				250
#define MAX_BOMB				15
#define MAX_LASTPM				5
#define MAX_RENIA				11

//#define LEVEL_
//#define LEVEL_
#define LEVEL_OPERATOR			(3)
#define LEVEL_JUNIORADMIN		(4)
#define LEVEL_ADMIN				(5)
#define LEVEL_VICEHEADADMIN		(6)
#define LEVEL_HEADADMIN			(7)

#define LEVEL_VIP				(1)
#define LEVEL_SVIP				(2)

#define LOG_FILE_ADMIN			"/Logs/AdminLog.txt"
#define LOG_FILE_HACK			"/Logs/HackDetect.txt"
#define LOG_FILE_DOSTARCZENIA	"/Logs/LogiDost.txt"
#define LOG_FILE_PRZELEWY		"/Logs/LogiPrzel.txt"
#define LOG_FILE_FIRMY			"/Logs/LogiFirm.txt"

/*
1 //Mapper
2 //€§ponsor€
3 //Operator
4 //Junior Admin
5 //Admin
6 //Vice Head
7 //Head Admin
8 //Programista
9 //Zas³u¿ony
*/
