function Blowjob(facet,baba,step){
	switch(step){
		case 0: {
			TogglePlayerControllable(facet,0);
			TogglePlayerControllable(baba,0);

			ApplyAnimation(facet,"BLOWJOBZ","BJ_COUCH_START_P",4.1,0,1,1,1,1,1);
			ApplyAnimation(baba,"BLOWJOBZ","BJ_COUCH_START_W",4.1,0,1,1,1,1,1);

			SetTimerEx("Blowjob",1000,false,"ddd",facet,baba,step+1);

			return 1;
		}
		case 1: {
			ApplyAnimation(facet,"BLOWJOBZ","BJ_COUCH_LOOP_P",20.0,1,1,1,1,1,1);
			ApplyAnimation(baba,"BLOWJOBZ","BJ_COUCH_LOOP_W",20.0,1,1,1,1,1,1);
			SetTimerEx("Blowjob",15000,false,"ddd",facet,baba,step+1);
			return 1;
		}
		case 2: {
			ApplyAnimation(facet,"BLOWJOBZ","BJ_COUCH_END_P",4.1,0,1,1,1,1,1);
			ApplyAnimation(baba,"BLOWJOBZ","BJ_COUCH_END_W",4.1,0,1,1,1,1,1);
			SetTimerEx("Blowjob",1000,false,"ddd",facet,baba,step+1);
			return 1;
		}
		case 3: {
			ApplyAnimation(facet,"CARRY","crry_prtial",4.0,0,0,0,0,0);
			ApplyAnimation(baba,"CARRY","crry_prtial",4.0,0,0,0,0,0);
			ClearAnimations(facet);
			ClearAnimations(baba);
			TogglePlayerControllable(facet,1);
			TogglePlayerControllable(baba,1);
			return 1;
		}
	}
	return 1;
}

function Blowjob2(facet,baba,step){
	switch(step){
		case 0: {
			TogglePlayerControllable(facet,0);
			TogglePlayerControllable(baba,0);

			ApplyAnimation(facet,"BLOWJOBZ","BJ_STAND_START_P",4.1,0,1,1,1,1,1);
			ApplyAnimation(baba,"BLOWJOBZ","BJ_STAND_START_W",4.1,0,1,1,1,1,1);

			SetTimerEx("Blowjob2",1000,false,"ddd",facet,baba,step+1);

			return 1;
		}
		case 1: {
			ApplyAnimation(facet,"BLOWJOBZ","BJ_STAND_LOOP_P",20.0,1,1,1,1,1,1);
			ApplyAnimation(baba,"BLOWJOBZ","BJ_STAND_LOOP_W",20.0,1,1,1,1,1,1);
			SetTimerEx("Blowjob2",15000,false,"ddd",facet,baba,step+1);
			return 1;
		}
		case 2: {
			ApplyAnimation(facet,"BLOWJOBZ","BJ_STAND_END_P",4.1,0,1,1,1,1,1);
			ApplyAnimation(baba,"BLOWJOBZ","BJ_STAND_END_W",4.1,0,1,1,1,1,1);
			SetTimerEx("Blowjob2",1000,false,"ddd",facet,baba,step+1);
			return 1;
		}
		case 3: {
			ClearAnimations(facet);
			ClearAnimations(baba);
			TogglePlayerControllable(facet,1);
			TogglePlayerControllable(baba,1);
			return 1;
		}
	}
	return 1;
}

function Odliczanie(val,Float:distance,isFreeze,playerid){
	new buffer[30], F4[Float3D];

	switch(val){
		case 0: format(buffer,sizeof(buffer),"_~n~_~n~~g~~h~~h~GO");
		case 1: format(buffer,sizeof(buffer),"_~n~_~n~~y~%d",val);
		case 2: format(buffer,sizeof(buffer),"_~n~_~n~~r~~h~~h~%d",val);
		case 3: format(buffer,sizeof(buffer),"_~n~_~n~~r~%d",val);
		default: format(buffer,sizeof(buffer),"_~n~_~n~%d",val);
	}
	
	F4[T3D:VW] = GetPlayerVirtualWorld(playerid);
	F4[T3D:INT] = GetPlayerInterior(playerid);

	FoxForeach(i,Player){
		if(GetPlayerInterior(i) == F4[T3D:INT] && GetPlayerVirtualWorld(i) == F4[T3D:VW]){
			if((distance == 0.0) || (GetDistanceBetweenPlayers(playerid,i) <= distance)){
				GameTextForPlayer(i,buffer,1000,6);
				PlayerPlaySound(i,val>0?1056:1057,0.0,0.0,0.0);
				if(isFreeze){
					if(val > 0) TogglePlayerControllable(i,false);
					if(val <= 0) TogglePlayerControllable(i,true);
				}
			}
		}
	}
	LastOdlicz = val;
	if(val > 0) SetTimerEx("Odliczanie",900,false,"dfdd",val-1,distance,isFreeze,playerid);
	return 1;
}

function UBCMD(playerid){
	gGracz[playerid][blokadacmd] = false;
	return 1;
}

function SzpitalCamera(playerid){
	TogglePlayerSpectating(playerid, 1);
	InterpolateCameraPos(playerid,2147.1934,-1525.5465,66.1633,2029.5406,-1402.1368,18.6213,14*1000,CAMERA_MOVE);
	InterpolateCameraLookAt(playerid,2029.2019,-1406.7269,17.2012,2029.2019,-1406.7269,17.2012,14*1000,CAMERA_MOVE);
	SetTimerEx("KoniecLeczenia",15*1000,false,"d",playerid);
	TextDrawHideForPlayer(playerid,TDZasypianie);
	return 1;
}

function ZamknijGarazM(drzwiid){
	switch(drzwiid){
		case 0: MoveDynamicObject(DrzwiMedykow[0],1594.2574, 1843.3073, 11.2659,1.5,0.0000, 0.0000, 90.0000);
		case 1: MoveDynamicObject(DrzwiMedykow[1],1599.2574, 1843.3073, 11.2659,1.5,0.0000, 0.0000, 90.0000);
		case 2: MoveDynamicObject(DrzwiMedykow[2],1604.2574, 1843.3073, 11.2659,1.5,0.0000, 0.0000, 90.0000);
		case 3: MoveDynamicObject(DrzwiMedykow[3],1609.2375, 1843.3073, 11.2659,1.5,0.0000, 0.0000, 90.0000);
		case 4: MoveDynamicObject(DrzwiMedykow[4],1614.2576, 1843.3073, 11.2659,1.5,0.0000, 0.0000, 90.0000);
		case 5: MoveDynamicObject(DrzwiMedykow[5],1619.2776, 1843.3073, 11.2659, 1.5, 0.0000, 0.0000, 90.0000);
		case 6: MoveDynamicObject(DrzwiMedykow[6],1623.9576, 1843.3073, 11.2659, 1.5, 0.0000, 0.0000, 90.0000);
	}
	return 1;
}

function ParalizatorGracza(playerid){
	if(gGracz[playerid][Kajdanki] == 1){
		TogglePlayerControllable(playerid,0);
		gGracz[playerid][Zemdlenie] = false;
		TextDrawHideForPlayer(playerid,TDZasypianie);
	} else {
		TogglePlayerControllable(playerid,1);
		gGracz[playerid][Zemdlenie] = false;
		TextDrawHideForPlayer(playerid,TDZasypianie);
	}
	return 1;
}

function OdblRespawn(){
	respawnblock = 0;
	return 1;
}

function updatekolczatka(playerid){
	FoxForeach(i,Player){
		if(GetPlayerState(i) == PLAYER_STATE_DRIVER){
			new vd = GetPlayerVehicleID(i);
			new panels, doors, lights, tires;
			GetVehicleDamageStatus(vd, panels, doors, lights, tires);
			if(IsPlayerInRangeOfPoint(i, 3, kolczx[playerid],kolczy[playerid],kolczz[playerid])){
				UpdateVehicleDamageStatus(vd, panels, doors, lights, 15);
			}
		}
	}
	return 1;
}

function AutomatycznyZapisStatystyk(){
	FoxForeach(i,Player){
		if(gGracz[i][Zalogowany] == true){
			ZapisGracza(i);
		}
	}
	for(new fir = 1; fir < MAX_FIRM; fir++){
		SprawdzPoziomFirmy(fir);
	}
	StanRejestracji = dini_Int("/Serwer.txt","StanRejestracji");

	for(new fir = 1; fir < MAX_FIRM; fir++){
		new Firma[64];
		format(Firma,sizeof(Firma),"/Firmy/%i/Staty.txt",fir);
		if(dini_Exists(Firma)){
			dini_IntSet(Firma,"MaxCzlonkow",fFirma[fir][MaxCzlonkow]);
			dini_IntSet(Firma,"LiczbaCzlonkow",fFirma[fir][LiczbaCzlonkow]);
			dini_IntSet(Firma,"Kasa",fFirma[fir][Kasa]);
			dini_IntSet(Firma,"Dostarczenia",fFirma[fir][Dostarczenia]);
		}
	}
	dini_IntSet("/Serwer.txt","LiczbaDowodow",DowodNR);
	dini_IntSet("/Serwer.txt","KasaCh1",Hipciokosz1);
	dini_IntSet("/Serwer.txt","LiczbaBanow",LiczbaBanow);
	dini_IntSet("/Serwer.txt","LiczbaMandatow",LiczbaMandatow);
	
	// reloadbans
	//SendRconCommand("reloadbans");
	return 1;
}

function LosowanieLotto(){
	new liczba;
	new string[300];
	new wygrani = 0;
	liczba = random(30);
	if(liczba == 0){
		liczba = random(30);
	}
	SendClientMessageToAll(COLOR_YELLOW,"***********************Losowanie Lotto*****************************");
	format(string,sizeof(string),"**W losowaniu wygrywa liczba... {FF0000}%d. {FFFF00}Zwyciêzcy otrzymuj¹ {FF0000}%d${FFFF00}",liczba,Kumulacja);
	SendClientMessageToAll(COLOR_YELLOW,string);
	SendClientMessageToAll(COLOR_YELLOW,"***********************Losowanie zakoñczone********************");
	FoxForeach(i,Player){
		if(gGracz[i][Zalogowany] == true){
			if(gGracz[i][NumerLotto] >= 1){
				if(gGracz[i][NumerLotto] == liczba){
					GivePlayerMoney(i,Kumulacja);
					wygrani++;
					SendClientMessage(i,COLOR_YELLOW,"**Gratulacje wygra³eœ ca³¹ kumulacjê!");
				} else {
					SendClientMessage(i,COLOR_YELLOW,"**Niestety twój numerek nie zosta³ wylosowany. Próbuj dalej :)");
				}
				gGracz[i][NumerLotto] = 0;
			}
		}
	}
	if(wygrani > 0){
		Kumulacja = 7000;
	}
	return 1;
}

function ChowajTextDrawAuto(playerid){
	TextDrawHideForPlayer(playerid,InfoAuto);
	return 1;
}


function UpdatePasek(playerid){
	if(IsPlayerConnected(playerid) && gGracz[playerid][Zalogowany] == true){
		new wiadomosc[1000];
		new Float:x, Float:y,Float:z;
		new Float:Health;
		GetPlayerPos(playerid,x,y,z);

		if(gGracz[playerid][Glod] <= 1){
			SetPlayerDrunkLevel(playerid,4500);
			GetPlayerHealth(playerid,Health);
			if(Health > 2){
				SetPlayerHealth(playerid, Health - 0.5);
			}

		 	format(wiadomosc,sizeof(wiadomosc),"{F68FFF}%s zemdla³ z wyg³odzenia..",GetPlayerNick(playerid));
			gGracz[playerid][Zemdlenie] = true;
			FoxForeach(i,Player){
				if(IsPlayerInRangeOfPoint(i,10,x,y,z)){
					SendClientMessage(i,COLOR_PURPLE,wiadomosc);
				}
			}
		} else if(gGracz[playerid][Glod] < 999){ //licho nigdy nie g³oduje
			gGracz[playerid][Glod]--;
		}
		UpdatujPaski(playerid,1);
	}
	return 1;
}

function UpdatePasekZ(playerid){
	new Float:Health;
	if(gGracz[playerid][Zalogowany] == true && IsPlayerConnected(playerid)){
		if(gGracz[playerid][Zmeczenie] < 1){
			gGracz[playerid][Zemdlenie] = true;
			GetPlayerHealth(playerid,Health);
			SetPlayerDrunkLevel(playerid,4500);
			SetPlayerHealth(playerid, Health - 5.5);
			TextDrawShowForPlayer(playerid,TDZasypianie);
			TextDrawShowForPlayer(playerid,TDZasypianie2);
			SetTimerEx("Zasypianie",5500,false,"d",playerid);
		} else if(gGracz[playerid][Zmeczenie] < 999){ //licho nigdy nie œpi
			gGracz[playerid][Zmeczenie]--;
		}
	}
	UpdatujPaski(playerid,2);
	return 1;
}

function Zasypianie(playerid){
	TextDrawHideForPlayer(playerid,TDZasypianie);
	TextDrawHideForPlayer(playerid,TDZasypianie2);
	return 1;
}

function FotoradarCooldown(playerid){
	gGracz[playerid][FotoradarCount] = true;
	return 1;
}

function SchowajTD(playerid){
	TextDrawHideForPlayer(playerid,FotoradarBlysk);
	return 1;
}

function CameraTimerCut(playerid){
	InterpolateCameraPos(playerid,1835.1957,1529.8992,75.0308,997.7135,1084.0840,17.3022, 20000, CAMERA_MOVE);
	InterpolateCameraLookAt(playerid,992.4662,1074.4725,14.4882,992.4662,1074.4725,14.4882, 20000, CAMERA_MOVE);
	return 1;
}

function KoniecLeczenia(playerid){
	TogglePlayerSpectating(playerid,0);
	return 1;
}

function ZamykanieSzlabanu(){
	MoveDynamicObject(SzlabanVip,2606.1001000,2302.6001000,12.6000000,1.0,0.0000000,0.000,0.000);
	return 1;
}

function SearchForNewAdmin(){
	FoxForeach(playerid,Player){
		if(!gGracz[playerid][isRcon] && IsPlayerAdmin(playerid) && gGracz[playerid][AdminLvl] >= LEVEL_HEADADMIN){
			gGracz[playerid][isRcon] = true;
			OnPlayerRCONLogin(playerid);
			break;
		} else if(!gGracz[playerid][isRcon] && IsPlayerAdmin(playerid) && gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN){
			new buffer[255];
			format(buffer,sizeof buffer,"Nieautoryzowane logowanie na admina RCON %d (dobre haslo!) przez %s (%d)! Poziom %d.",gGracz[playerid][isRcon],GetPlayerNick(playerid),playerid,gGracz[playerid][AdminLvl]);
			MSGToAdmins(COLOR_RED,buffer,LEVEL_HEADADMIN);
			BanEx(playerid,"Logowanie na RCON bez autoryzacji");
			break;
		}
	}
	return 1;
}

function OnPlayerRCONLogin(playerid){
	if(gGracz[playerid][AdminLvl] >= LEVEL_HEADADMIN){
		new buffer[256];
		format(buffer,sizeof(buffer),"Gracz [%i]%s zalogowa³ siê poprawnie na rcon!",playerid,GetPlayerNick(playerid));
		SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zalogowa³eœ siê na RCON. Od teraz jesteœ {0000FF}'Rcon Adminem'");
		MSGToAdmins(COLOR_RED,buffer,LEVEL_ADMIN);
	}
	return 1;
}

function Ping(playerid){
	gGracz[playerid][adminping] = false;
	return 1;
}

function Tankowanie(playerid){
	new vehicleid = GetPlayerVehicleID(playerid);
	new string[100];
	new engine, lights, alarm, doors, bonnet, boot, objective;
	if(GetVehicleParamsEx(vehicleid, engine, lights, alarm, doors, bonnet, boot, objective)){
		if(engine == 0){
			Paliwo[vehicleid] += float(gGracz[playerid][UIDbazy]);
			format(string,sizeof(string),"{FFFFFF}Zatankowa³eœ swój pojazd za: {0076E5}%d$",kosztsprzed[playerid]);
			kosztsprzed[playerid] = 0;
			ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Tankowanie",string,"Zamknij","");
		} else{
			kosztsprzed[playerid] = 0;
			ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Tankowanie","{FF0000}Zatankowanie twojego auta nie bylo mozliwe\n{D1D1D1}Prawdopodobnie wlaczyles silnik.","Zamknij","");
		}
	}
	kosztsprzed[playerid] = 0;
	return 1;
}

function Spanie(playerid){
	SendClientMessage(playerid,COLOR_WHITE,"Wyspa³eœ siê!");
	if(gGracz[playerid][Kajdanki] == 0){
		TogglePlayerControllable(playerid, 1);
	}
	gGracz[playerid][Zmeczenie] = 100;
	UpdatujPaski(playerid,2);
	TextDrawHideForPlayer(playerid,TDZasypianie);
	return 1;
}

function LadowanieTowaru(playerid){
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER){
		StworzChckpoint(playerid);
		TogglePlayerControllable(playerid, 1);
		SendClientMessage(playerid,COLOR_WHITE,"Za³adowano towar.");
		gGracz[playerid][towar_gotowy] = true;
	}
	return 1;
}

function AnulowanieZlecenia(playerid){
	if(gGracz[playerid][towar] >= 1){
		SendClientMessage(playerid,COLOR_RED,"Anulowa³eœ zlecenie za {FFFFFF}2500$");
		gGracz[playerid][towar] = 0;
		
		GivePlayerMoney(playerid,-2500);
		gGracz[playerid][TowarTony] = 0;
		PlayerInfo[playerid][ZaladunekID] = -1;
		PlayerInfo[playerid][RozladunekID] = -1;
		DisablePlayerCheckpoint(playerid);
		VehLadunek[gGracz[playerid][pojazdzleceniowy]] = false;
	} else{
		SendClientMessage(playerid,COLOR_RED,"Niemasz towaru!");
	}
	return 1;
}

function SchowajTDDom(playerid){
	PlayerTextDrawHide(playerid,TDDom[playerid]);
	return 1;
}

function WygasZaproszenie(playerid){
	if(gGracz[playerid][ZaproszenieDoFirmy] >= 0){
		gGracz[playerid][ZaproszenieDoFirmy] = -1;
	}
	return 1;
}

function OdbierzPaliwo(){
	for(new i = 0, j = GetVehiclePoolSize(); i <= j; i++){
		new engine, lights, alarm, doors, bonnet, boot, objective;
		if(GetVehicleParamsEx(i, engine, lights, alarm, doors, bonnet, boot, objective)){
			if(engine == 1){
				if(Paliwo[i] > 0){
					new mid = GetVehicleModel(i);
					if(mid == 509 || mid == 481 || mid == 510 || mid == 537 || mid == 538) return 1;
					
					new Predkosc = floatround(GetVehicleSpeed(i));
					if(mid == 523 || mid == 522 || mid == 448 || mid == 461 || mid == 462 || mid == 463 || mid == 468 || mid == 471 || mid == 521 || mid == 581 || mid == 586){
						if(Predkosc <= 5){
							Paliwo[i] -= 0.02;
						} else if(Predkosc > 5 && Predkosc <= 10){
							Paliwo[i] -= 0.1;
						} else if(Predkosc > 10 && Predkosc <= 30){
							Paliwo[i] -= 0.18;
						} else if(Predkosc > 30 && Predkosc <= 50){
							Paliwo[i] -= 0.2;
						} else if(Predkosc > 50 && Predkosc <= 70){
							Paliwo[i] -= 0.3;
						} else if(Predkosc > 70 && Predkosc <= 90){
							Paliwo[i] -= 0.4;
						} else if(Predkosc > 90 && Predkosc <= 100){
							Paliwo[i] -= 0.5;
						} else if(Predkosc > 100 && Predkosc <= 160){
							Paliwo[i] -= 0.6;
						} else if(Predkosc > 160){
							Paliwo[i] -= 0.8;
						}
					} else {
						if(Predkosc <= 5){
							Paliwo[i] -= 0.1;
						} else if(Predkosc > 5 && Predkosc <= 10){
							Paliwo[i] -= 0.2;
						} else if(Predkosc > 10 && Predkosc <= 30){
							Paliwo[i] -= 0.3;
						} else if(Predkosc > 30 && Predkosc <= 50){
							Paliwo[i] -= 0.5;
						} else if(Predkosc > 50 && Predkosc <= 70){
							Paliwo[i] -= 0.7;
						} else if(Predkosc > 70 && Predkosc <= 90){
							Paliwo[i] -= 0.8;
						} else if(Predkosc > 90 && Predkosc <= 100){
							Paliwo[i] -= 0.9;
						} else if(Predkosc > 100){
							Paliwo[i] -= 1.0;
						}
						if(GetVehicleTrailer(i)){
							Paliwo[i] -= 0.2;
						}
					}
				}
			}
		}
	}
	KillTimer(PaliwoTimer);
	PaliwoTimer = SetTimer("OdbierzPaliwo", ODBIERZPALIWOCZAS, true);
	return 1;
}

function SmiercGracza(playerid){
	TextDrawHideForPlayer(playerid,TDZasypianie);
	KillTimer(TimerSmierc[playerid]);
 	if(gGracz[playerid][StatusSmierci] == false){
 		TogglePlayerSpectating(playerid,1);
 		SendClientMessage(playerid,COLOR_RED,"Medyk nie zd¹¿y³ udzieliæ ci pomocy..");
 		gGracz[playerid][PozwolenieBron] = false;
		if(GetPlayerScore(playerid) > 10){
			SendClientMessage(playerid,COLOR_LIGHTBLUE,"{FFFFFF}[{FFFF00}Zgon{FFFFFF}] {C4C4C4}Koszty leczenia(1600$) zosta³y pobrane!");

			GivePlayerMoney(playerid,-1600);
		} else {
			gGracz[playerid][KasaBank] = gGracz[playerid][KasaBank] - 550;SendClientMessage(playerid,COLOR_LIGHTBLUE,"{FFFFFF}[{FFFF00}Zgon{FFFFFF}] {C4C4C4}Koszty leczenia(500$) zosta³y pobrane z konta bankowego!");
		}
		InterpolateCameraPos(playerid,1928.3345,-1531.6101,69.6668,2026.9659,-1432.0634,26.3701,10*1000,CAMERA_MOVE);
   		InterpolateCameraLookAt(playerid,2025.7209,-1422.7653,25.4549,2025.7209,-1422.7653,25.4549,10*1000,CAMERA_MOVE);
   		SetTimerEx("KoniecLeczenia",10*1000,false,"d",playerid);
  		gGracz[playerid][StatusSmierci] = false;
		gGracz[playerid][SmiercSpawn] = 1;
		gGracz[playerid][StatusJail] = true;
		gGracz[playerid][JuzUmarl] = false;
		SchowajPasekStanu(playerid);
		PieniadzeMedykow = PieniadzeMedykow - 3000;
		return 1;
	}
	return 1;
}

function LadowanieTowaru2(playerid){
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER){
		new vehicleid = GetPlayerVehicleID(playerid);
		new pid = GetVehicleModel(vehicleid);
		new string2[500];

		if(ContainInSeries(pid,403,514,415,515)){
			if(GetVehicleTrailer(vehicleid) != 0){
				gGracz[playerid][pojazdzleceniowy] = vehicleid;
				gGracz[playerid][przyczepazleceniowa] = GetVehicleTrailer(vehicleid);
			} else {
				gGracz[playerid][towar] = 0;
				PlayerInfo[playerid][ZaladunekID] = -1;
				SendClientMessage(playerid,COLOR_RED,"Nie masz naczepy, nie mo¿esz siê za³adowaæ!");
				return 1;
			}
		} else {
			gGracz[playerid][pojazdzleceniowy] = vehicleid;
		}

		TogglePlayerControllable(playerid, 1);
	  	format(string2,sizeof(string2),"{D2FF3D}Dokumentacja za³adunku:\n{D2FF3D}Pojazd: {C3C3C3}%s\n{D2FF3D}Roz³adunek: {C3C3C3}%s\n{D2FF3D}Towar: {C3C3C3}%s [%i]\n{D2FF3D}Iloœæ ton: {C3C3C3}%d",VehicleNames[GetVehicleModel(vehicleid)-400],RozladunekText[PlayerInfo[playerid][RozladunekID]],TowarNazwa[gGracz[playerid][towar]],gGracz[playerid][towar],gGracz[playerid][TowarTony]);
	   	ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Za³adunek",string2,"Zamknij","");
		SetPlayerCheckpoint(playerid,gGracz[playerid][checkx],gGracz[playerid][checky],	gGracz[playerid][checkz],15);
		SendClientMessage(playerid,COLOR_WHITE,"Za³adowano towar.");
		gGracz[playerid][towar_gotowy] = true;
	}
	return 1;
}

