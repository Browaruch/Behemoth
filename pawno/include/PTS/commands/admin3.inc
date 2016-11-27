CMD:sprcmd(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	new id, szAREA[1000], buffer[200];
	if(sscanf(params,"d",id)){
		return SendClientMessage(playerid,COLOR_WHITE,"U¿yj: /sprcmd [ID]");
	} else if(!IsPlayerConnected(id)){
		return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza");
	} else if(gGracz[playerid][AdminLvl] < gGracz[id][AdminLvl]){
		SendClientMessage(playerid,COLOR_RED,"Gracz ma za wysoka range!");
	} else {
		format(buffer,sizeof buffer,"{FFFFFF}Ostatnie komendy: {00FF00}(%d) %s\n\n",id,GetPlayerNick(id));
		strcat(szAREA,buffer);
		format(buffer,sizeof buffer,"{FFFFFF}CMD1: {00FFFF}%s\n",CMD1[id]);
		strcat(szAREA,buffer);
		format(buffer,sizeof buffer,"{FFFFFF}CMD2: {00FFFF}%s\n",CMD2[id]);
		strcat(szAREA,buffer);
		format(buffer,sizeof buffer,"{FFFFFF}CMD3: {00FFFF}%s\n",CMD3[id]);
		strcat(szAREA,buffer);
		format(buffer,sizeof buffer,"{FFFFFF}CMD4: {00FFFF}%s\n",CMD4[id]);
		strcat(szAREA,buffer);
		format(buffer,sizeof buffer,"{FFFFFF}CMD5: {00FFFF}%s\n",CMD5[id]);
		strcat(szAREA,buffer);
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Ostatnie komendy",szAREA,"Zamknij","");
	}
	return 1;
}

/*
CMD:toropen(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(BramaToruS,-2904.8999,1378.6000,6.40000,2.0,0.0000,0.0000,270.0000);
	return 1;
}

CMD:torclose(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(BramaToruS,-2904.8999,1378.6000,11.3200,2.0,0.0000,0.0000,270.0000);
	return 1;
}
*/

CMD:weather(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	new wid, string[700];
	if(sscanf(params,"d",wid)) return SendClientMessage(playerid,COLOR_WHITE,"U¿yj: /weather [ID pogody]!");
	if(!((wid >= 0 && wid <= 53) || wid == 2009)) return SendClientMessage(playerid,COLOR_ERROR,"Podane id pogody poza dopuszczalnym zakresem (0-53)!");

	format(string,sizeof(string),"{FF8586}Administrator {FFFFFF}%s [%i] {FF8586}zmieni³ pogode na: {FFFFFF}%d{FF8586}!",GetPlayerNick(playerid),playerid,wid);
	SetWeather(wid);
	IDPogody = wid;
	SendClientMessageToAll(COLOR_WHITE,string);
	format(string,sizeof(string),"[Pogoda]%s > %i",GetPlayerNick(playerid),wid);
	WriteLog(string,LOG_FILE_ADMIN);
	return 1;
}

CMD:scenafire(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	if(GetTickCount()-Fajerwerki[0] < 5000) return SendClientMessage(playerid,COLOR_LIGHTGREEN,"Proszê czekaæ, trwa ³adowanie amunicji.");
	Fajerwerki[0] = GetTickCount();
	for(new i = 0; i <= 28; i += 4){
		MissileLaunch(MISSILE_TYPE_EXPLODE_HUGE,0.001,0.1,30.0,67.5000,(1515.0000+i),0.0000,0,0,-1,500.0,MISSILE_OBJECT_HYDRA,67.5000,(1515.0000+i),80.0000);
		MissileLaunch(MISSILE_TYPE_EXPLODE_HUGE,0.001,0.1,30.0,67.5000,(1515.0000+i-2),-50.0000,0,0,-1,500.0,MISSILE_OBJECT_HYDRA,67.5000,(1515.0000+i),80.0000);
		MissileLaunch(MISSILE_TYPE_EXPLODE_HUGE,0.001,0.1,30.0,67.5000,(1515.0000+i),-100.0000,0,0,-1,500.0,MISSILE_OBJECT_HYDRA,67.5000,(1515.0000+i),80.0000);
	}
	SendClientMessage(playerid,COLOR_LIGHTGREEN,"Wystrzelono fajerwerki!");
	return 1;
}

CMD:scenawystrzel(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	if(GetTickCount()-Fajerwerki[1] < 20000) return SendClientMessage(playerid,COLOR_LIGHTGREEN,"Proszê czekaæ, trwa ³adowanie amunicji.");
	Fajerwerki[1] = GetTickCount();
	new Float:tx,Float:ty;
	for(new i = 0; i < 360; i += 5){
		GetPointInFront2D(5.7637,1540.9519,float(i)*1.0,200.0,tx,ty);
		MissileLaunch(MISSILE_TYPE_EXPLODE_HUGE,0.001,0.1,30.0,5.7637,1540.9519,15.0000,0,0,-1,800.0,MISSILE_OBJECT_HYDRA,tx,ty,15.0000,INVALID_PLAYER_ID,ANY_TEAM,true,MAX_MISSILE_REMOTE_TARGET,200.0);
	}
	SendClientMessage(playerid,COLOR_LIGHTGREEN,"Wystrzelono fajerwerki!");
	return 1;
}

CMD:viewfc(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	if(gGracz[playerid][StatusViewF] == true){
		SendClientMessage(playerid,COLOR_WHITE,"{FF0000}Wy³¹czy³eœ {FFFFFF}podgl¹d czatu firm!");
		gGracz[playerid][StatusViewF] = false;
	} else {
		SendClientMessage(playerid,COLOR_WHITE,"{00FF00}W³¹czy³eœ {FFFFFF}podgl¹d czatu firm!");
		gGracz[playerid][StatusViewF] = true;
	}
	return 1;
}

CMD:rsp(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	if(respawnblock == 1){
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"CMD","{FF0000}Tej komendy mo¿esz u¿yæ co 30 sekund\nOdczekaj...","Zamknij","");
		return 1;
	} else {
		new string[1000];
		new stringLOG[100];
		KillTimer(timerrsp);
		respawnblock = 1;
		AutomatycznyRespawnB = false;
		odliczaniersp = 20;
		NickRSP = GetPlayerNick(playerid);
		SendClientMessageToAll(COLOR_RED,"**RESPAWN POJAZDÓW!");
		GameTextForAll("~b~Respawn za~n~~r~20 sek",1000,4);
		timerrsp = SetTimerEx("OdliczanieRSP",1000,true,"d");
		SendClientMessage(playerid,0xC6BEBDFF,"Odliczanie rozpoczête.");
		format(string,sizeof(string),"{BD0090}Za 20 sekund wszystkie nieu¿ywane pojazdy zostan¹ zrespawnowane !");
		SendClientMessageToAll(COLOR_RED,string);
		format(stringLOG,sizeof(stringLOG),"[RSP]%s",GetPlayerNick(playerid));
		WriteLog(stringLOG,LOG_FILE_ADMIN);
	}
	return 1;
}

CMD:respawn(playerid) return cmd_rsp(playerid);

CMD:czysc(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	for(new i = 0; i < 100; i++) SendClientMessageToAll(COLOR_WHITE," ");
	GameTextForAll("~r~Admin ~g~wyczyscil czat!",3000,3);
	return 1;
}

CMD:cs(playerid)	return cmd_czysc(playerid);

CMD:getpos(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	new Float:P[14],int,vw,Float:fa,str[200],userid,Float:MAz;
	if(sscanf(params,"d",userid)){
		userid = playerid;
	} else if(!IsPlayerConnected(userid)){
		return SendClientMessage(playerid,COLOR_ERROR,"Nie ma takiego gracza!");
	}
	new vid = GetPlayerVehicleID(userid);
	if(vid > 0){
		GetVehiclePos(vid,P[0],P[1],P[2]);
		GetVehicleRotation(vid,P[3],P[4],P[5]);
		GetVehicleZAngle(vid,fa);
	} else {
		GetPlayerPos(userid,P[0],P[1],P[2]);
		GetPlayerFacingAngle(userid,fa);
	}
	GetPlayerCameraPos(userid,P[6],P[7],P[8]);
	GetPlayerCameraRotation(userid,P[9],P[10]);
	GetPointInFrontOfCamera3D(userid,P[11],P[12],P[13],5.0);
	int = GetPlayerInterior(userid);
	vw = GetPlayerVirtualWorld(userid);

	new zname[MAX_ZONE_NAME];
	GetPlayer3DZone(userid,zname,sizeof(zname));
	
	SendClientMessage(playerid,0xFFFFFFFF," ");
	
	new flag = GetPlayerCollisionFlags(userid);
	if(IsCollisionFlag(flag,POSITION_FLAG_UNDERWATER)){
		format(str,sizeof str,"Lokalizacja: {00FFFF}%s {00FF00}Pod wod¹",zname);
	} else if(IsCollisionFlag(flag,POSITION_FLAG_WATER)){
		format(str,sizeof str,"Lokalizacja: {00FFFF}%s {00FF00}Na wodzie",zname);
	} else if(IsCollisionFlag(flag,POSITION_FLAG_AIR)){
		format(str,sizeof str,"Lokalizacja: {00FFFF}%s {00FF00}W powietrzu",zname);
	} else if(IsCollisionFlag(flag,POSITION_FLAG_UNDERGROUND)){
		format(str,sizeof str,"Lokalizacja: {00FFFF}%s {00FF00}Pod ziemi¹",zname);
	} else if(IsCollisionFlag(flag,POSITION_FLAG_GROUND)){
		format(str,sizeof str,"Lokalizacja: {00FFFF}%s {00FF00}Na ziemi",zname);
	}
	if(IsCollisionFlag(flag,POSITION_FLAG_WORLD)){
		format(str,sizeof str,"%s (Œwiat)",str);
	} else if(IsCollisionFlag(flag,POSITION_FLAG_INTERIOR)){
		format(str,sizeof str,"%s (Wnêtrze)",str);
	}
	SendClientMessage(playerid,0xFFFFFFFF,str);
	
	format(str,sizeof(str),"XYZ: {FF0000}%.2f %.2f %.2f {FFFFFF}Angle: {FF0000}%.2f",P[0],P[1],P[2],fa);
	SendClientMessage(playerid,0xFFFFFFFF,str);
	if(vid > 0){
		format(str,sizeof(str),"RXYZ: {FF0000}%.2f %.2f %.2f",P[3],P[4],P[5]);
		SendClientMessage(playerid,0xFFFFFFFF,str);
	}
	format(str,sizeof str ,"Interior: {FF0000}%d {FFFFFF}World: {FF0000}%d",int,vw);
	SendClientMessage(playerid,0xFFFFFFFF,str);
	
	format(str,sizeof(str),"Camera: {FF0000}%.2f %.2f %.2f {FFFFFF}Rotation: {FF0000}%.2f %.2f",P[6],P[7],P[8],P[9],P[10]);
	SendClientMessage(playerid,0xFFFFFFFF,str);
	
	format(str,sizeof(str),"Look: {FF0000}%.2f %.2f %.2f {FFFFFF}Mode: {FF0000}%d",P[11],P[12],P[13],GetPlayerCameraMode(userid));
	SendClientMessage(playerid,0xFFFFFFFF,str);
	
	format(str,sizeof(str),"Camera Distance: {FF0000}%.2f",GetDistanceBetweenPoints3D(P[6],P[7],P[8],P[0],P[1],P[2]));
	SendClientMessage(playerid,0xFFFFFFFF,str);
	
	if(int == 0){
		if(IsPointInWater(P[0],P[1])){
			UndergroundFindZ(P[0],P[1],MAz);
			format(str,sizeof(str),"Wysokosc mapy: {00FF00}%.4f (Woda)",MAz);
		} else {
			Tryg3DMapAndreasFindZ(P[0],P[1],MAz);
			format(str,sizeof(str),"Wysokosc mapy: {00FF00}%.4f (Ziemia)",MAz);
		}
		SendClientMessage(playerid,0xFFFFFFFF,str);
	} else {
		InteriorFindZ(P[0],P[1],P[2],2.0,MAz);
		format(str,sizeof(str),"Wysokosc mapy: {00FF00}%.4f (Wnêtrze)",MAz);
		SendClientMessage(playerid,0xFFFFFFFF,str);
	}
	
	return 1;
}

CMD:dancefloorg(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(scena,56.17857,1528.65503,14.17820,0.1,0.00000,0.00000,0.00000);
	MoveDynamicObject(scena2,62.33010,1518.32922,16.18000,0.5,0.00000,90.00000,180.00000);
	MoveDynamicObject(scena3,62.33177,1518.34900,20.00000,0.5,0.00000,90.00000,180.00000);
	MoveDynamicObject(scena4,62.16532,1540.24768,20.00000,1.5,0.00000,90.00000,180.00000);
	MoveDynamicObject(scena5,62.22818,1540.26514,16.00000,1.5,0.00000,90.00000,180.00000);
	return 1;
}

CMD:dancefloord(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(scena,56.1786,1528.6550,14.0982,0.5,0.00000,0.00000,0.00000);
	MoveDynamicObject(scena2,62.3318,1524.5690,19.1600,0.5,0.00000,90.00000,180.00000);
	MoveDynamicObject(scena3,62.3318,1524.5690,19.1600,0.5,0.00000,90.00000,180.00000);
	MoveDynamicObject(scena4,62.3318,1524.5690,19.1600,0.5,0.00000,90.00000,180.00000);
	MoveDynamicObject(scena5,62.3318,1524.5690,19.1600,0.5,0.00000,90.00000,180.00000);
	return 1;
}

CMD:kurtynao(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(kurtyna[0],48.8809,1538.7021,9.3321,1.0,90.0000,0.0000,0.0000);
	MoveDynamicObject(kurtyna[1],48.8602,1528.4321,9.3600,1.0,90.0000,0.0000,0.0000);
	MoveDynamicObject(kurtyna[2],48.8757,1518.3933,9.3600,1.0,90.0000,0.0000,0.0000);
	return 1;
}

CMD:kurtynac(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(kurtyna[0],48.86094,1538.70068,18.31210,1.0,90.00000,0.00000,0.00000);
	MoveDynamicObject(kurtyna[1],48.88014,1528.43030,18.31210,1.0,90.00000,0.00000,0.00000);
	MoveDynamicObject(kurtyna[2],48.87575,1518.39331,18.31210,1.0,90.00000,0.00000,0.00000);
	return 1;
}

CMD:nkurtynao(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(kurtyna[3],48.8809,1538.7021,9.3321,1.0,90.0000,0.0000,0.0000);
	MoveDynamicObject(kurtyna[4],48.8602,1528.4321,9.3600,1.0,90.0000,0.0000,0.0000);
	MoveDynamicObject(kurtyna[5],48.8757,1518.3933,9.3600,1.0,90.0000,0.0000,0.0000);
	return 1;
}

CMD:nkurtynac(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(kurtyna[3],48.86094,1538.70068,18.31210,1.0,90.00000,0.00000,0.00000);
	MoveDynamicObject(kurtyna[4],48.88014,1528.43030,18.31210,1.0,90.00000,0.00000,0.00000);
	MoveDynamicObject(kurtyna[5],48.87575,1518.39331,18.31210,1.0,90.00000,0.00000,0.00000);
	return 1;
}

CMD:kurtynalo(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(kurtyna[6],58.600,1512.2000,12.500-12.0,2.0,0.000,270.000,90.000);
	MoveDynamicObject(kurtyna[7],58.600,1512.7000,12.500-12.0,2.0,0.000,90.000,90.000);
	return 1;
}

CMD:kurtynalc(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(kurtyna[6],58.600,1512.2000,12.500,2.0,0.000,270.000,90.000);
	MoveDynamicObject(kurtyna[7],58.600,1512.7000,12.500,2.0,0.000,90.000,90.000);
	return 1;
}

CMD:kurtynapo(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(kurtyna[8],58.600,1545.2000,12.500-12.0,2.0,0.000,90.000,90.000);
	MoveDynamicObject(kurtyna[9],58.600,1544.7000,12.500-12.0,2.0,0.000,270.000,90.000);
	return 1;
}

CMD:kurtynapc(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(kurtyna[8],58.600,1545.2000,12.500,2.0,0.000,90.000,90.000);
	MoveDynamicObject(kurtyna[9],58.600,1544.7000,12.500,2.0,0.000,270.000,90.000);
	return 1;
}


CMD:scplacc(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(BramaPlacu,-29.8507,1526.8535,13.5000,1.5,0.0000,0.0000,-90.0000);
	return 1;
}

CMD:scplaco(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(BramaPlacu,-29.8627,1518.0856,13.5000,1.5,0.0000,0.0000,-90.0000);
	return 1;
}

CMD:scbramao(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(BramaSceny,28.1347,1478.7844,14.6830,1.5,0.00000,0.00000,118.18200);
	return 1;
}

CMD:scbramac(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(BramaSceny,24.25501,1486.04846,14.68300,2.0,0.00000,0.00000,118.18200);
	return 1;
}

CMD:platd(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(platforma,59.37280,1507.14819,11.91270,0.5,0.00000,90.00000,0.00000);
	return 1;
}

CMD:platg(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(platforma,59.3580,1507.2673,14.1200,0.4 ,0.00000,90.00000,0.00000);
	return 1;
}

CMD:starto(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(DrzwiStad2,1357.7662,2208.3728,11.1948,0.5);
	MoveDynamicObject(DrzwiStad1,1328.0909,2208.4551,11.1347,0.5);
	return 1;
}

CMD:startc(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return 0;
	MoveDynamicObject(DrzwiStad1,1329.65088,2208.47510,11.13467,0.5);
	MoveDynamicObject(DrzwiStad2,1359.26624,2208.37280,11.19480,0.5);
	return 1;
}
