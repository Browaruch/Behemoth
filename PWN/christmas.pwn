#define FILTERSCRIPT
#define SCRIPT_NAME		"Christmas Tree"

#include <a_samp>
#include <streamer>
#include <SAM/StreamerFunction>
#include <SAM/3DTryg>
#include <sscanf2>
#include <izcmd>

#include <PTS/pts.player>
#undef MAX_PLAYERS
#define MAX_PLAYERS (MAX_SERVER_PLAYERS)

#include <security/ScriptChecker>

public OnScriptCheck(playerid,errorlevel){
	
	new buffer[256];
	format(buffer,sizeof(buffer),"Skrypt {00FF00}%s{FFFFFF} odpowiada na ¿¹danie kod: {00FF00}0x%08x",SCRIPT_NAME,errorlevel);
	SendClientMessage(playerid,0xFFFFFFFF,buffer);
	
	return 1;
}

#define CALL_CHANEL_ID_INPUT		(0x000000AB)	//
#define CALL_CHANEL_ID_OUTPUT		(0x000000FF)	//Game Mode
#define CALL_CHANEL_ID_BROADCAST	(0xFFFFFFFF)	//Kana³ rozg³oszeniowy

public OnScriptCall(playerid, chanel, errorlevel, data[]){
	if(chanel == CALL_CHANEL_ID_INPUT || chanel == CALL_CHANEL_ID_BROADCAST){
		switch(errorlevel){
			case 0xFF: { //Wysy³a czas aktywnoœci skryptu
				new buffer[32];
				format(buffer,sizeof buffer,"%s:%d",SCRIPT_NAME,GetFilterScriptActiveTime());
				CallToAllScript(playerid, CALL_CHANEL_ID_OUTPUT, 0xFE, buffer);
			}
		}
	}
	return 1;
}

#include <PTS/engine/Christmas>

#define NEXT_YEAR               "2017"  //Which year is it next year ?

new Text:NYCounter[3],
	s_Timer[2];

public OnFilterScriptInit(){
	SendClientMessageToAll(0xFF0000FF,"[IMPORTANT] Trwa sadzenie choinek...");
	
	//LoadMetasTextdraws();

	Christmas_OnFilterScriptInit();
	//TextDrawShowForAll(NYCounter[0]);
	CreateStoczniaNGC(0xFF9E3DFF); //ARGB
	for(new i = 0, j = GetPlayerPoolSize(); i <= j; i++){
		SetPlayerAttachedObject(i,0,19065,2,0.113131,0.018596,0.000000,94.697052,90.118164,0.000000,1.226595,1.226595,1.226595 ); // SantaHat2 - czapkamikolaja 5000 respa
	}
	return 1;
}

public OnPlayerSpawn(playerid){
	SetPlayerAttachedObject(playerid,0,19065,2,0.113131,0.018596,0.000000,94.697052,90.118164,0.000000,1.226595,1.226595,1.226595 ); // SantaHat2 - czapkamikolaja 5000 respa
	
	return 1;
}

public OnFilterScriptExit(){

/*
	TextDrawDestroy(NYCounter[0]);
	TextDrawDestroy(NYCounter[1]);
    TextDrawDestroy(NYCounter[2]);
    KillTimer(s_Timer[0]);
    KillTimer(s_Timer[1]);
*/
	return 1;
}

public OnPlayerConnect(playerid){
	if(IsPlayerNPC(playerid)) return 1;
/*
	new year, month, day, hour, minute, second;
    getdate(year, month, day);
    gettime(hour, minute, second);
    if(day == 1 && month == 1 && (second > 0 || hour > 0)) TextDrawShowForPlayer(playerid, NYCounter[2]);
*/
    return 1;
}

stock LoadMetasTextdraws(){
    NYCounter[0] = TextDrawCreate(316.399780, 0.995545, "_");
	TextDrawLetterSize(NYCounter[0], 0.293599, 1.510400);
	TextDrawAlignment(NYCounter[0], 2);
	TextDrawColor(NYCounter[0], -1);
	TextDrawSetShadow(NYCounter[0], 0);
	TextDrawSetOutline(NYCounter[0], 1);
	TextDrawBackgroundColor(NYCounter[0], 51);
	TextDrawFont(NYCounter[0], 1);
	TextDrawSetProportional(NYCounter[0], 1);

	NYCounter[1] = TextDrawCreate(394.000000, 1.500000, "usebox");
	TextDrawLetterSize(NYCounter[1], 0.000000, 5.158888);
	TextDrawTextSize(NYCounter[1], 242.000000, 0.000000);
	TextDrawAlignment(NYCounter[1], 1);
	TextDrawColor(NYCounter[1], 0);
	TextDrawUseBox(NYCounter[1], true);
	TextDrawBoxColor(NYCounter[1], 102);
	TextDrawSetShadow(NYCounter[1], 0);
	TextDrawSetOutline(NYCounter[1], 0);
	TextDrawFont(NYCounter[1], 0);

    NYCounter[2] = TextDrawCreate(340.000000, 350.000000, "~>~ HAPPY NEW YEAR ~<~~n~~y~"NEXT_YEAR"!");
    TextDrawAlignment(NYCounter[2], 2);
    TextDrawBackgroundColor(NYCounter[2], 255);
    TextDrawFont(NYCounter[2], 1);
    TextDrawLetterSize(NYCounter[2], 1.000000, 4.000000);
    TextDrawColor(NYCounter[2], 16777215);
    TextDrawSetOutline(NYCounter[2], 1);
	TextDrawSetProportional(NYCounter[2], 1);

    s_Timer[0] = SetTimer("CounterTimer", 400, true);
    return 1;
}

forward CounterTimer();
public CounterTimer()
{
    new string[150];
    new year, month, day, hour, minute, second;
    getdate(year, month, day);
    gettime(hour, minute, second);
    if(month == 1 && day == 1)
    {
        TextDrawHideForAll(NYCounter[0]);
        TextDrawShowForAll(NYCounter[2]);
        KillTimer(s_Timer[0]);
    }
    else
    {
        //gettime(hour, minute, second);

        new day2;
        switch(month)
        {
            case 1, 3, 5, 7, 8, 10, 12: day2 = 31;
            case 2: { if(year%4 == 0){ day2 = 29; } else { day2 = 28; } }
            case 4, 6, 9, 11: day2 = 30;
        }
        month = 12 - month;
        day = day2 - day;
        hour = 24 - hour;
		if(hour == 24){ hour = 0; }
		if(minute > 0){ hour--; }
        minute = 60 - minute;
		if(minute == 60){ minute = 0; }
		if(second > 0){ minute--; }
        second = 60 - second;
		if(second == 60){ second = 0; }

		if(month > 0){
			format(string, sizeof(string), "~p~%d ~w~miesiecy, ~p~%d ~w~dni~n~~p~%d ~w~godzin, ~p~%d ~w~minut, ~p~%d ~w~sekund~n~~y~Do nowego roku ~b~~h~%s", month, day, hour, minute, second, NEXT_YEAR);
		} else {
			format(string, sizeof(string), "~p~%d ~w~dni~n~~p~%d ~w~godzin, ~p~%d ~w~minut, ~p~%d ~w~sekund~n~~y~Do nowego roku ~b~~h~%s", day, hour, minute, second, NEXT_YEAR);
		}
        //TextDrawHideForAll(NYCounter[0]);
        TextDrawSetString(NYCounter[0], string);
        TextDrawShowForAll(NYCounter[0]);
    }
    return 1;
}

/****************************************************************************************************
 * Axion Vatallus Ship by Abyss Morgan                                                              *
 ****************************************************************************************************/

#define StoczniaVW	0
#define StoczniaINT	0

new StoczniaNGC[22];

SetStoczniaColor(color){
	SetDynamicObjectMaterial(StoczniaNGC[0],0,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[0],4,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[0],5,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[1],0,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[1],4,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[1],5,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[2],0,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[2],1,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[2],2,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[3],0,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[3],1,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[3],2,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[4],0,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[4],1,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[4],2,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[5],0,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[5],1,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[5],2,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[6],0,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[6],1,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[6],2,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[7],0,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[7],1,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[7],2,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[8],1,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[8],2,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[8],4,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[8],5,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[9],1,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[9],2,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[9],4,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[9],5,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[10],1,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[10],2,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[10],4,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[10],5,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[11],1,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[11],2,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[11],4,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[11],5,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[12],1,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[12],2,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[12],4,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[12],5,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[13],1,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[13],2,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[13],4,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[13],5,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[14],0,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[14],1,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[14],2,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[14],3,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[14],4,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[14],5,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[14],6,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[15],0,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[15],1,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[15],2,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[15],3,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[15],4,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[15],5,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[15],6,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[16],0,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[16],1,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[16],2,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[16],3,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[16],4,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[16],5,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[16],6,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[17],0,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[17],1,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[17],2,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[17],3,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[17],4,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[17],5,2707,"Shopping","white",color);
	SetDynamicObjectMaterial(StoczniaNGC[17],6,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[18],0,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[19],0,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[20],0,10817,"airportgnd_sfse","black64",0x00000000);
	SetDynamicObjectMaterial(StoczniaNGC[21],0,10817,"airportgnd_sfse","black64",0x00000000);	
}

CreateStoczniaNGC(color){
	StoczniaNGC[0] = CreateDynamicObject(9900,4050.0000000,100.0000000,200.0000000,90.0000000,0.0000000,180.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[1] = CreateDynamicObject(9900,3950.0000000,100.0000000,200.0000000,90.0000000,0.0000000,180.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[2] = CreateDynamicObject(7236,4050.0000000,-75.0000000,220.0000000,45.0000000,0.0000000,0.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[3] = CreateDynamicObject(7236,3950.0000000,-75.0000000,180.0000000,135.0000000,0.0000000,0.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[4] = CreateDynamicObject(7236,4080.0000000,-75.0000000,200.0000000,90.0000000,0.0000000,45.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[5] = CreateDynamicObject(7236,3920.0000000,-75.0000000,200.0000000,90.0000000,0.0000000,315.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[6] = CreateDynamicObject(7236,3950.0000000,-75.0000000,220.0000000,45.0000000,0.0000000,0.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[7] = CreateDynamicObject(7236,4050.0000000,-75.0000000,180.0000000,135.0000000,0.0000000,0.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[8] = CreateDynamicObject(5882,3962.5000000,0.0000000,200.0000000,0.0000000,270.0000000,0.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[9] = CreateDynamicObject(5882,4037.5000000,0.0000000,200.0000000,0.0000000,270.0000000,180.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[10] = CreateDynamicObject(5882,4083.8999000,0.0000000,200.0000000,0.0000000,270.0000000,180.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[11] = CreateDynamicObject(5882,3916.1006000,0.0000000,200.0000000,0.0000000,270.0000000,0.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[12] = CreateDynamicObject(5882,3950.0000000,-60.0000000,200.0000000,0.0000000,270.0000000,90.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[13] = CreateDynamicObject(5882,4050.0000000,-60.0000000,200.0000000,0.0000000,270.0000000,90.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[14] = CreateDynamicObject(3489,4050.0000000,-15.0000000,220.0000000,0.0000000,0.0000000,270.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[15] = CreateDynamicObject(3489,4050.0000000,-15.0000000,180.0000000,0.0000000,180.0000000,270.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[16] = CreateDynamicObject(3489,3950.0000000,-15.0000000,220.0000000,0.0000000,0.0000000,90.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[17] = CreateDynamicObject(3489,3950.0000000,-15.0000000,180.0000000,0.0000000,180.0000000,90.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[18] = CreateDynamicObject(3659,3950.0000000,235.0000000,200.5000000,0.0000000,0.0000000,0.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[19] = CreateDynamicObject(3659,4050.0000000,235.0000000,200.5000000,0.0000000,0.0000000,0.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[20] = CreateDynamicObject(3659,3950.0000000,235.0000000,199.5000000,0.0000000,180.0000000,0.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	StoczniaNGC[21] = CreateDynamicObject(3659,4050.0000000,235.0000000,199.5000000,0.0000000,180.0000000,0.0000000,StoczniaVW,StoczniaINT,-1,800.0,800.0);
	SetStoczniaColor(color);
}

CMD:setshipcolor(playerid,params[]){
	if(!IsPlayerAdmin(playerid)) return 0;
	if(isnull(params)) return SendClientMessage(playerid,0xFFFFFFFF,"››› Use: /setshipcolor <ARGB>");
	new xcolor;
	sscanf(params,"x",xcolor);
	SetStoczniaColor(xcolor);
	return 1;
}

//EOF
