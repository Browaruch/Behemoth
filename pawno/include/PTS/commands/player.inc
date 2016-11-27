
CMD:fajerwerki(playerid){
	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	MissileLaunch(MISSILE_TYPE_EXPLODE_HUGE,0.001,0.1,30.0,x,y,z+2.0,0,0,-1,500.0,MISSILE_OBJECT_HYDRA,x,y,z+100.0,playerid);
	return 1;
}

CMD:mandat(playerid,params[]){
	new Float:x, Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	new id,kwota;
	new string[600];
	new string2[600];
	if(gGracz[playerid][FrakcjaPolicja] == 1){
		if(SkinyPolicji(playerid)){
			if(sscanf(params,"dd",id,kwota)){
				return ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Mandat","Aby wystawiæ mandat wpisz:\n/mandat [ID] [Kwota]!","OK","");
			} else if(!IsPlayerConnected(id)){
				return SendClientMessage(playerid,COLOR_RED,"Gracz nie jest na serwerze!");
			} else if(IsPlayerNPC(id)){
				return SendClientMessage(playerid,COLOR_RED,"Nie mo¿esz zrobiæ tego z botem!");
			} else if(kwota > 500000 && kwota < 1){
				return ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Mandat","Mo¿esz wystawiæ mandat na kwote od 1$ do 500000$!","OK","");
			} else if(GetPlayerMoney(id)-kwota < 0){
				return ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Mandat","Gracz nie posiada tyle gotówki!","OK","");
			} else {
		 		if(gGracz[id][ZaplaconeOplaty] == 0){
 					if(IsPlayerInRangeOfPoint(id,10,x,y,z)){
	 					if(kwota > 1 && kwota <= 500000){
							WysokoscRachunku[id] = kwota;
							format(string,sizeof(string),"{009FF5}Wystawi³eœ mandat graczowi {D1D1D1}%s[%i] {009FF5}na {D1D1D1}%d$",GetPlayerNick(id),id,kwota);
							SendClientMessage(playerid,COLOR_AQUA,string);
							format(string2,sizeof(string2),"{009FF5}Policjant {F61E1E}%s[%i] {009FF5}wystawi³ Ci mandat na {F61E1E}%i${009FF5}! {FFFFFF}Wpisz /zaplac, aby zap³aciæ mandat!",GetPlayerNick(playerid),playerid,kwota);
							SendClientMessage(id,COLOR_WHITE,string2);
							TimerOplata[id] = SetTimerEx("Oplata",5*60000,false,"d",id);
							gGracz[id][ZaplaconeOplaty] = 1;
							gGracz[id][OplataPolicji] = 1;
							LiczbaMandatow++;
						} else {
							ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"CMD","{FF0000}Niepoprawna kwota!","Zamknij","");
						}
	  				} else {
						ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"CMD","{FF0000}Gracz jest za daleko od ciebie!","Zamknij","");
					}
				} else {
					SendClientMessage(playerid,COLOR_RED,"Gracz ma nie zap³acone op³aty!");
				}
			}
		}
	}
	return 1;
}

CMD:zlomuj(playerid){
	if(IsPlayerInRangeOfPoint(playerid,5,2412.2439,-1424.2366,23.7618)){
		new PrivAuto[70], status[100], status2[100], buffer[400];
		format(PrivAuto,sizeof(PrivAuto),"/PrivAuta/%s.txt",GetPlayerNick(playerid));
		new PrivAuto2[70];
		format(PrivAuto2,sizeof(PrivAuto2),"/PrivAuta/%s2.txt",GetPlayerNick(playerid));
		if(!dini_Exists(PrivAuto)){
			status = "{00ff00}Wolny";
		} else {
			status = "{FF0000}Zajêty";
		}
		if(!dini_Exists(PrivAuto2)){
			status2 = "{00ff00}Wolny";
		} else {
			status2 = "{FF0000}Zajêty";
		}
		format(buffer,sizeof(buffer),"{FFFFFF}Wybierz auto do zez³omowania\n{C3C3C3}%s: %s\n{C3C3C3}%s: %s",dini_Get(PrivAuto,"Name"),status,dini_Get(PrivAuto2,"Name"),status2);
		ShowPlayerDialog(playerid,107,DIALOG_STYLE_LIST,"{FF0000}Z³omowanie auta",buffer,"Wybierz","Zamknij");
	} else {
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Z³omowanie","{FF0000}Nie jesteœ na z³omowisku","Zamknij","");
	}
	return 1;
}

CMD:pm(playerid,params[]){
	new id, tresc[256], string[256], string2[256];
	if(sscanf(params,"ds[250]",id,tresc)){
		SendClientMessage(playerid,COLOR_RED,"Wpisz: /pm [ID] [Treœæ] aby pisaæ na pm!");
		return 1;
	} else if(!IsPlayerConnected(id)){
		return SendClientMessage(playerid,COLOR_RED,"Gracz o podanym id nie jest na serwerze!");
	} else if(gGracz[playerid][StatusMute] == true){
 		format(string,sizeof(string),"Jesteœ wyciszony. Pozosta³o: {D1D1D1}%i {FF0000}sekund!",CzasMute[playerid]);
		return SendClientMessage(playerid,COLOR_RED,string);
	} else if(gGracz[id][StatusPm] == false && gGracz[playerid][AdminLvl] < 6){
		SendClientMessage(playerid,COLOR_RED,"Ten gracz wy³¹czy³ prywatne wiadomoœci!");
	} else if(id == playerid){
		SendClientMessage(playerid,COLOR_RED,"Nie mo¿esz pisaæ wiadomoœci do siebie!");
	} else if(strlen(tresc) > 150){
		return SendClientMessage(playerid,COLOR_RED,"Za d³uga treœæ wiadomoœci!");
	} else if(gGracz[playerid][Zalogowany] == false){
		SendClientMessage(playerid,COLOR_RED,"Nie jesteœ zalogowany!");
	} else {
		format(string,sizeof(string),"{A5FF0F}[PM : {FFAB0F}do{A5FF0F}]%s [%i]:{D1D1D1} %s",GetPlayerNick(id),id,tresc);
		format(string2,sizeof(string2),"{C1FF0F}[PM : {0F9AFF}od{C1FF0F}]%s [%i]:{D1D1D1} %s",GetPlayerNick(playerid),playerid,tresc);
		
		SendClientMessage(playerid,COLOR_WHITE,string);
		SendClientMessage(id,COLOR_WHITE,string2);
		SavePlayerPM(id,string2);
		PlayerPlaySound(id, 1057, 0, 0, 0);
		if(gGracz[id][StatusZW] == true){
			if(gGracz[id][AdminLvl] > 3){
				SendClientMessage(playerid,COLOR_YELLOW,"Ten administrator jest obecnie na z/w, mo¿e nie odczytaæ wiadomoœci!");
				SendClientMessage(playerid,COLOR_RED,"Spróbuj skontaktowaæ siê z innym administratorem, u¿yj {D1D1D1}/admins /pytanie");
			} else {
				SendClientMessage(playerid,COLOR_YELLOW,"Gracz jest obecnie na z/w, mo¿e nie odczytaæ wiadomoœci!");
			}
		}
		FoxForeach(i,Player){
			if(gGracz[i][AdminLvl] >= 3){
				if(gGracz[i][ViewPM] == true){
					if(playerid == i || id == i) continue;
					if(gGracz[playerid][AdminLvl] <= gGracz[i][AdminLvl]){
						format(string2,sizeof(string2),"{00EBE0}|View PM| %s[%i] > %s[%i]: %s",GetPlayerNick(playerid),playerid,GetPlayerNick(id),id,tresc);
						SendClientMessage(i,COLOR_WHITE,string2);
					}
				}
			}
		}
	}
	return 1;
}

CMD:pw(playerid,params[]) return cmd_pm(playerid,params);
CMD:w(playerid,params[]) return cmd_pm(playerid,params);


CMD:lastpm(playerid){
	new szAREA[(256*MAX_LASTPM)+32];
	szAREA = "Ostatnie wiadomosci\n\n{F5C172}";
	for(new i = 0; i < MAX_LASTPM; i++){
		strcat(szAREA,LastPlayerPM[playerid][i]);
		strcat(szAREA,"\n");
	}
	ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Ostatnie wiadomosci",szAREA,"Wyjdz","");
	return 1;
}

CMD:ostatniepm(playerid) return cmd_lastpm(playerid);

CMD:kdp(playerid,params[]){
	new id, string[300], string2[999],Gracz[300], Float:x, Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	if(sscanf(params,"d",id)) return SendClientMessage(playerid,COLOR_WHITE,"U¿yj: /kdp [id]!");
	if(!IsPlayerConnected(id)) return SendClientMessage(playerid,COLOR_RED,"Gracz o takim ID nie jest po³¹czony z serwerem!");
	format(Gracz,sizeof(Gracz),"/Players/%s.txt",GetPlayerNick(playerid));
	if(dini_Int(Gracz,"KDPsg") == 1){
		if(IsPlayerInRangeOfPoint(id,10,x,y,z) && IsPlayerSpawnedEx(id)){
			format(string,sizeof(string),"Pokazujesz Kartê Darmowego Przejazdu %s[%i].",GetPlayerNick(id),id);
			format(string2,sizeof(string2),"{FF0000}Karta Darmowego Przejazdu\n{D1D1D1}Posiadacz: %s[%i]\nData: %s\n{FFFF00}Gracz ma mo¿liwoœæ darmowego przejazdu przez granicê!",GetPlayerNick(playerid),playerid,dini_Get(Gracz,"DataKDP"));
			SendClientMessage(playerid,COLOR_WHITE,string);
			ShowPlayerDialog(id,DIALOG_INF,DIALOG_STYLE_MSGBOX,"KDP Stra¿ Graniczna",string2,"ZatwierdŸ","");
		} else {
			SendClientMessage(playerid,COLOR_RED,"Gracz jest za daleko, aby przekazaæ mu kartê");
		}
	} else {
		SendClientMessage(playerid,COLOR_RED,"Nie posiadasz Karty darmowego przejazdu!");
	}
	return 1;
}

CMD:legitymacja(playerid,params[]){
	new string[1000], text[500], id;
	new string2[599];
	new Float:x, Float:y,Float:z;
	if(sscanf(params,"d",id)) return SendClientMessage(playerid,COLOR_WHITE,"U¿yj: /legitymacja [ID]");
	GetPlayerPos(playerid,x,y,z);
	if(IsPlayerInRangeOfPoint(id,10,x,y,z) && IsPlayerSpawnedEx(id)){
		format(string2,sizeof(string2),"%s[%i]\n{F59400}Frakcja\tNa s³u¿bie?\n",GetPlayerNick(playerid),playerid);
		strcat(string,string2);
		if(gGracz[playerid][FrakcjaPolicja] == 1 && SkinyPolicji(playerid)){
			strcat(string,"{248BFF}Policjant	 {73C922}Tak\n");
		} else if(gGracz[playerid][FrakcjaPolicja] == 1 && !SkinyPolicji(playerid)){
			strcat(string,"{248BFF}Policjant	 {FA0025}Nie\n");
		}
		if(gGracz[playerid][FrakcjaPomocDrogowa] == 1 && SkinyPomocyDrogowej(playerid)){
			strcat(string,"{A8FF24}Mechanik	  {73C922}Tak\n");
		} else if(gGracz[playerid][FrakcjaPomocDrogowa] == 1 && !SkinyPomocyDrogowej(playerid)){
			strcat(string,"{A8FF24}Mechanik	  {FA0025}Nie\n");
		}
		if(gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)){
			strcat(string,"{D50AFF}Stra¿nik	 {73C922}Tak\n");
		} else if(gGracz[playerid][FrakcjaStrazGraniczna] == 1 && !SkinyStrazyGranicznej(playerid)){
			strcat(string,"{D50AFF}Stra¿nik	 {FA0025}Nie\n");
		}
		if(gGracz[playerid][FrakcjaMedyk] == 1 && SkinyMedykow(playerid)){
			strcat(string,"{D0CDD0}Lekarz	   {73C922}Tak\n");
		} else if(gGracz[playerid][FrakcjaMedyk] == 1 && !SkinyMedykow(playerid)){
			strcat(string,"{D0CDD0}Lekarz	   {FA0025}Nie\n");
		}
		if(gGracz[playerid][FrakcjaTaxi] == 1 && SkinyTaxi(playerid)){
			strcat(string,"{FEED2F}Taksówkarz	{73C922}Tak\n");
		} else if(gGracz[playerid][FrakcjaTaxi] == 1 && !SkinyTaxi(playerid)){
			strcat(string,"{FEED2F}Taksówkarz	{FA0025}Nie\n");
		}
		if(gGracz[playerid][FrakcjaWojsko] == 1 && SkinyWojska(playerid)){
			strcat(string,"{995C00}Wojskowy	 {73C922}Tak\n");
		} else if(gGracz[playerid][FrakcjaWojsko] == 1 && !SkinyWojska(playerid)){
			strcat(string,"{995C00}Wojskowy	 {FA0025}Nie\n");
		}
		if(gGracz[playerid][FrakcjaSP] == 1 && SkinySP(playerid)){
			strcat(string,"{E3E2E4}Stra¿ak	 {73C922}Tak\n");
		} else if(gGracz[playerid][FrakcjaSP] == 1 && !SkinySP(playerid)){
			strcat(string,"{E3E2E4}Stra¿ak	 {FA0025}Nie\n");
		}
		format(text,sizeof(text),"Pokazujesz legitymacje frakcyjn¹ graczowi: %s[%i]",GetPlayerNick(id),id);
		SendClientMessage(playerid,COLOR_GREEN,text);
		ShowPlayerDialog(id,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Plakietki frakcyjne",string,"Zamknij","");
	}
	return 1;
}


CMD:dowod(playerid,params[]){
	new id, plec[MAX_PLAYERS], string[500], plectext[20], Float:x, Float:y, Float:z,
		Gracz[64], zameldowanie[70], Domy[50], Firma[70], FirText[40];
	GetPlayerPos(playerid,x,y,z);
	if(gGracz[playerid][Dowod] == 1){
		if(sscanf(params,"d",id)){
			SendClientMessage(playerid,COLOR_WHITE,"Wpisz: /dowod [id]");
			return 1;
		} else if(!IsPlayerConnected(id)){
			SendClientMessage(playerid,COLOR_RED,"Nie ma takiego ID!");
		} else {
			if(IsPlayerInRangeOfPoint(id,20,x,y,z) && IsPlayerSpawnedEx(id)){
				format(Gracz,sizeof(Gracz),"/Players/%s.txt",GetPlayerNick(playerid));
				plec[playerid] = dini_Int(Gracz,"PlecDowod");
				if(plec[playerid] == 2){plectext = "Mê¿czyzna";}
				if(plec[playerid] == 1){plectext = "Kobieta";}
				if(dini_Int(Gracz,"DomUID") > 0){
					format(Domy,sizeof(Domy),"/Domy/%i.txt",dini_Int(Gracz,"DomUID"));
					if(dini_Exists(Domy)){
						format(zameldowanie,sizeof(zameldowanie),"%s",dini_Get(Domy,"Opis"));
					}
				} else {
					zameldowanie = "Las Venturas";
				}
				if(gGracz[playerid][FirmaUID] > 0){
					format(Firma,sizeof(Firma),"/Firmy/%i/Staty.txt",gGracz[playerid][FirmaUID]);
					format(FirText,sizeof(FirText),"%s",dini_Get(Firma,"Nazwa"));
				} else {
					format(FirText,sizeof(FirText),"{FF00FF}[BRAK]");
				}
				SendClientMessage(playerid,COLOR_LIGHTGREEN,"Pokazujesz dowód");
				format(string,sizeof(string),"{CFCFCF}Imiê: {80E1FF}%s\n{CFCFCF}P³eæ: {80E1FF}%s\n{CFCFCF}Numer dowodu: {80E1FF}%s\nZameldowanie: %s\n{CFCFCF}Firma: %s\n{CFCFCF}Podpis: {80E1FF}%s",GetPlayerNick(playerid),plectext,dini_Get(Gracz,"DowodNr"),zameldowanie,FirText,dini_Get(Gracz,"PodpisDowod"));
				ShowPlayerDialog(id,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Dowód",string,"Zamknij","");
			} else {
				ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"b³¹d","{FF0000}Gracz jest za daleko od ciebie!","Zamknij","");
			}
		}
	} else {
		SendClientMessage(playerid,COLOR_LIGHTBLUE,"Nie posiadasz dowodu!");
 	}
	return 1;
}

CMD:zw(playerid,params[]){
	new powod[250];
	new string[400];
	if(gGracz[playerid][StatusZW] == false){
		if(sscanf(params,"s[250]",powod)){
			format(string,sizeof(string),"{E26BFF}Gracz %s [%i] zaraz wróci.",GetPlayerNick(playerid),playerid);
			SendClientMessageToAll(COLOR_WHITE,string);
			gGracz[playerid][StatusZW] = true;
			PlayerTextDrawShow(playerid,ZWTextDraw[playerid]);
			return 1;
		} else {
			if(gGracz[playerid][StatusMute] == false){
				format(string,sizeof(string),"{E26BFF}Gracz %s [%i] zaraz wróci {D1D1D1}(%s){E26BFF}.",GetPlayerNick(playerid),playerid,powod);
				SendClientMessageToAll(COLOR_WHITE,string);
				gGracz[playerid][StatusZW] = true;
				PlayerTextDrawSetString(playerid,ZWTextDraw[playerid],powod);
				PlayerTextDrawShow(playerid,ZWTextDraw[playerid]);
			} else {
				SendClientMessage(playerid,COLOR_RED,"Nie mo¿esz podawaæ powodów, gdy¿ jesteœ wyciszony!");
			}
			return 1;
		}
	} else {
		SendClientMessage(playerid,COLOR_RED,"Jesteœ ju¿ na z/w!");
	}
	return 1;
}

CMD:dokumenty(playerid,params[]){
	new id, Float:x, Float:y, Float:z;
	GetPlayerPos(playerid,x,y,z);
	new string[1000];
	if(sscanf(params,"d",id)){
		return ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Dokumenty","{FFFFFF}U¿yj: /dokumenty [ID]!","Zamknij","");
	} else if(!IsPlayerConnected(id)){
		return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza!");
	} else {
		if(IsPlayerInRangeOfPoint(id,20,x,y,z) && IsPlayerSpawnedEx(id)){
			new DowodText[32], Prawkotext[20],PrawkoCText[20],PrawkoAText[20], Ptext[32], Gracz[64], Wtext[32], Ktext[32];
			if(gGracz[playerid][PrawkoC] == 1){
				PrawkoCText = "{68FF29}Posiada";
			} else {
				PrawkoCText = "{FF4229}Nie posiada";
			}
			if(gGracz[playerid][PrawkoA] == 1){
				PrawkoAText = "{68FF29}Posiada";
			} else {
				PrawkoAText = "{FF4229}Nie posiada";
			}
			if(gGracz[playerid][Prawko] == 1){
				Prawkotext = "{68FF29}Posiada";
			} else {
				Prawkotext = "{FF4229}Nie posiada";
			}
			if(gGracz[playerid][Dowod] == 1){
				DowodText = "{68FF29}Posiada";
			} else {
				DowodText = "{FF4229}Nie posiada";
			}
			if(gGracz[playerid][Paszport] == 1){
				Ptext = "{68FF29}Posiada";
			} else {
				Ptext = "{FF4229}Nie posiada";
			}
			format(Gracz,sizeof(Gracz),"/Players/%s.txt",GetPlayerNick(playerid));
			if(dini_Int(Gracz,"KartaPrzegladu") >= 1){
				Ktext = "{68FF29}Posiada";
			} else {
				Ktext = "{FF4229}Nie posiada";
			}
			if(dini_Int(Gracz,"KartaWedkarska") >= 1){
				Wtext = "{68FF29}Posiada";
			} else {
				Wtext = "{FF4229}Nie posiada";
			}
			format(string,sizeof(string),"{FFFFFF}Dokumenty {F48AFF}%s[%i]\n{FFFFFF}Dowód: %s\n{FFFFFF}Prawo jazdy A: %s\n{FFFFFF}Prawo jazdy B: %s\n{FFFFFF}Prawo jazdy C: %s\n{FFFFFF}Paszport: {FF0000}%s\n{FFFFFF}Karta Przegl¹du: {FF0000}%s {D1D1D1}[%02i.%02i.%04i]\n{FFFFFF}Karta wêdkarska: %s",GetPlayerNick(playerid),playerid,DowodText,PrawkoAText,Prawkotext,PrawkoCText,Ptext,Ktext,dini_Int(Gracz,"DPrzeglad"),dini_Int(Gracz,"MPrzeglad"),dini_Int(Gracz,"YPrzeglad"),Wtext);
			
			ShowPlayerDialog(id,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Dokumenty",string,"Ok","");
			SendClientMessage(playerid,COLOR_AQUA,"Pokazujesz dokumenty");
  		} else {
			return ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Dokumenty","{FF0000}Gracz jest za daleko od ciebie!","Zamknij","");
		}
	}
	return 1;
}

CMD:reanimuj(playerid,params[]){
	new id;
	new inf[256];
	new Prace[64];
	new Float:x, Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	if(sscanf(params,"d",id)){
		SendClientMessage(playerid,COLOR_WHITE,"U¿yj: /reanimuj [ID]");
		return 1;
	} else if(!IsPlayerConnected(id)){
		SendClientMessage(playerid,COLOR_WHITE,"Gracz o podanym id nie jest na serwerze!");
		return 1;
	} else if(playerid == id){
		SendClientMessage(playerid,COLOR_WHITE,"Nie mam na to si³y.");
		return 1;
	} else {
		new Float:health;
		GetPlayerHealth(id,health);
		if(IsPlayerInRangeOfPoint(id,5,x,y,z) && IsPlayerSpawnedEx(id)){
			if(health < 50 && gGracz[id][Zemdlenie] == true){
				ClearAnimations(playerid,0);
				format(Prace,sizeof(Prace),"/Frakcje/Medycy.txt");
				PieniadzeMedykow = PieniadzeMedykow + 350;
				SetPlayerColor(playerid,0x6DC5F3FF);
				DestroyDynamic3DTextLabel(SmiercText[id]);
				dini_IntSet(Prace,"Kasiora", PieniadzeMedykow);
				SendClientMessage(playerid,COLOR_WHITE,"Przystapiles do reanimacji gracza.");
				format(inf,sizeof(inf),"Gracz %s reanimuje cie.",GetPlayerNick(playerid));
				SendClientMessage(id,COLOR_VIOLET,inf);
				SetPlayerHealth(id,5);
				if(!IsPlayerInAnyVehicle(playerid)){ApplyAnimation(playerid, "MEDIC", "CPR", 4.0, 1, 0, 0, 0, 0);} // reanimacja
				SetTimerEx("Reanimacja",3000,false,"d",id);
				DestroyDynamic3DTextLabel(SmiercText[id]);
				KillTimer(TimerSmierc[id]);
				RemovePlayerMapIcon(playerid,41);
				gGracz[id][JuzUmarl] = false;
				ClearAnimations(playerid,1);
				DestroyDynamic3DTextLabel(SmiercText[id]);
				SetPlayerColor(playerid, 0x6DC5F3FF);
			} else {
				SendClientMessage(playerid,COLOR_WHITE,"Gracz nie wymaga reanimacji!");
			}
		} else {
			SendClientMessage(playerid,COLOR_RED,"Gracz jest za daleko od ciebie");
		}
	}
	return 1;
}

CMD:plac(playerid,params[]){
	new id, moneys, string[256], string1[256], Float:x, Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	if(sscanf(params,"di",id,moneys)){
		return ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"{FFFF00}P³acenie","{FFFFFF}U¿yj: /plac [ID] [Kwota]!","Zamknij","");
	} else if(!IsPlayerConnected(id)){
		return SendClientMessage(playerid,0xFF0000AA,"Gracz o podanym id nie istnieje!");
	} else if(moneys > 5000 || moneys < 1){
		return ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"","{D1D1D1}Nie mo¿esz daæ wiêcej ni¿ {FF0000}5000$ {D1D1D1}i mniej ni¿ {FF0000}1$","Zamknij","");
	} else if(GetPlayerMoney(playerid) < moneys){
		return ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"","{D1D1D1}Nie posiadasz tyle pieniêdzy{FF0000}!","Zamknij","");
	} else if(gGracz[playerid][blokadacmd] == true){
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"CMD","{D1D1D1}Odczekaj chwile zanim wpiszesz ponownie t¹ komendê{FF0000}!","Zamknij","");
	} else {
		if(IsPlayerInRangeOfPoint(id,10,x,y,z) && IsPlayerSpawnedEx(id)){
			GivePlayerMoney(id,moneys);
			if(!IsPlayerInAnyVehicle(playerid)) ApplyAnimation(playerid,"DEALER","SHOP_PAY",4.0,1,0,0,0,0);
			gGracz[playerid][blokadacmd] = true;
			SetTimerEx("UBCMD",5000,false,"i",playerid);
			GivePlayerMoney(playerid,-moneys);
			format(string, sizeof(string), "{D1D1D1}Da³eœ {FF00FF}%d$ {D1D1D1}graczowi {FF00FF}%s [%i]",moneys, GetPlayerNick(id), id);
			ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"{FFFF00}P³acenie",string,"Ok","");
			format(string1, sizeof(string1), "{75FF57}Gracz {D1D1D1}%s [%i] {75FF57}przesy³a ci {D1D1D1}%i{75FF57}$",GetPlayerNick(playerid), playerid,moneys);
			ShowPlayerDialog(id,DIALOG_INF,DIALOG_STYLE_MSGBOX,"{FFFF00}P³acenie",string1,"Ok","");
			return 1;
		} else {
			ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"{FFFF00}P³acenie","{FFFF00}Gracz jest za daleko od ciebie!","Zamknij","");
		}
	}
	return 1;
}

CMD:lekarstwo(playerid,params[]){
	new id, inf[256], Prace[64], Float:x, Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	if(gGracz[playerid][FrakcjaMedyk] == 1){
		if(SkinyMedykow(playerid)){
			if(sscanf(params,"d",id)){
				SendClientMessage(playerid,COLOR_WHITE ,"U¿yj: /lekarstwo [ID] aby uleczyæ gracza");
				return 1;
			} else if(!IsPlayerConnected(id)){
		  		SendClientMessage(playerid,COLOR_WHITE,"Gracz o podanym id nie jest na serwerze!");
				return 1;
			} else if(gGracz[id][AntyAFKLicznik] >= 5){
		  		SendClientMessage(playerid,COLOR_WHITE,"Gracz o podanym id jest AFK!");
				return 1;
			} else {
			  	new Float:health;
				GetPlayerHealth(id,health);
				if(IsPlayerInRangeOfPoint(id,5,x,y,z) && IsPlayerSpawnedEx(id)){
					if(health < 95.0){
						if(gGracz[id][Zemdlenie] == false){
							format(inf,sizeof(inf),"{FF7770}Lekarz {FFFFFF}%s [%i] {FF7770}poda³ ci lekarstwo!\nCzekaj a¿ zacznie dzia³aæ...\n{D1D1D1}Koszt leczenia poniós³ rz¹d.",GetPlayerNick(playerid),playerid);
							ShowPlayerDialog(id,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Lekarstwo",inf,"OK","");
							SendClientMessage(playerid,COLOR_WHITE,"{FF7770}Poda³eœ lekarstwo graczowi! Na konto twojej frakcji dochodzi 750$! Czekaj a¿ lekarswo zadzia³a...");
							format(Prace,sizeof(Prace),"/Frakcje/Medycy.txt");
							PieniadzeMedykow = PieniadzeMedykow + 750;
							dini_IntSet(Prace,"Kasiora", PieniadzeMedykow);
							RemovePlayerMapIcon(playerid,41);
							SetPlayerHealth(id,100.0);
							DestroyDynamic3DTextLabel(SmiercText[id]);
							SetPlayerColor(playerid,0x6DC5F3FF);
						} else {
							SendClientMessage(playerid,COLOR_RED,"Gracz jest nieprzytomny, nie mo¿e przyj¹æ leku!");
						}
						return 1;
					} else {
						SendClientMessage(playerid,COLOR_WHITE,"Gracz ma wystarczaj¹c¹ iloœæ hp, nie trzeba mu lekarstwa!");
					}
				} else {
					SendClientMessage(playerid,COLOR_RED,"Gracz jest za daleko od ciebie");
				}
			}
		} else {
			SendClientMessage(playerid,COLOR_WHITE,"Nie jesteœ na s³u¿bie!");
		}
	} else {
		SendClientMessage(playerid,COLOR_WHITE,"Nie jesteœ lekarzem!");
	}
	return 1;
}

CMD:schowajtd(playerid){
	CancelSelectTextDraw(playerid);
	TextDrawHideForPlayer(playerid,SalonVIP);
	TextDrawHideForPlayer(playerid,SalonSportowe);
	TextDrawHideForPlayer(playerid,SalonLowriders);
	TextDrawHideForPlayer(playerid,SalonKup);
	TextDrawHideForPlayer(playerid,SalonWyjdz);
	PlayerTextDrawHide(playerid,SalonDalejTd[playerid]);
	TextDrawHideForPlayer(playerid,SalonOffroad);
	TextDrawHideForPlayer(playerid,SalonMotocykle);
	TextDrawHideForPlayer(playerid,SalonSalonowe);
	PlayerTextDrawHide(playerid,SalonModel[playerid]);
	PlayerTextDrawHide(playerid,StatySalon[playerid]);
	gGracz[playerid][FirmaID] = -1;
	gGracz[playerid][UIDbazy] = -1;
	PokazPasekStanu(playerid);
	TextDrawHideForPlayer(playerid,KKPole1);
	TextDrawHideForPlayer(playerid,KKPole2);
	TextDrawHideForPlayer(playerid,KKPole3);
	TextDrawHideForPlayer(playerid,KKPole4);
	TextDrawHideForPlayer(playerid,KKPole5);
	TextDrawHideForPlayer(playerid,KKPole6);
	TextDrawHideForPlayer(playerid,KKPole7);
	TextDrawHideForPlayer(playerid,KKPole8);
	TextDrawHideForPlayer(playerid,KKPole9);
	TextDrawHideForPlayer(playerid,KKTlo);
	TextDrawHideForPlayer(playerid,KKCom);
}

CMD:998(playerid){
	if(gGracz[playerid][Blokada998] <= 0){
		ShowPlayerDialog(playerid,315,DIALOG_STYLE_INPUT,"Nr. alarmowy 998","{D1D1D1}Witaj, dodzwoni³eœ siê do Stra¿y Po¿arnej.\nPodaj nam {FF0000}powód wzywania {D1D1D1}stra¿y:","Dalej","Zamknij");
	} else {
		SendClientMessage(playerid,COLOR_ORANGE,"Wys³a³eœ niedawno zg³oszenie do Stra¿y Po¿arnej. Odczekaj..");
	}
	return 1;
}

CMD:pmenu(playerid){
	new PrivAuto1[70], PrivAuto2[70], buffer[600];
	format(PrivAuto1,sizeof(PrivAuto1),"/PrivAuta/%s.txt",GetPlayerNick(playerid));
	format(PrivAuto2,sizeof(PrivAuto2),"/PrivAuta/%s2.txt",GetPlayerNick(playerid));
	if(!dini_Exists(PrivAuto1) && !dini_Exists(PrivAuto2)) return SendClientMessage(playerid,COLOR_RED,"*{D1D1D1}Musisz posiadaæ prywatny pojazd, udaj siê do salonu w SF.");
	
	if(!dini_Exists(PrivAuto1)){
		format(buffer,sizeof(buffer),"{C3C3C3}Brak");
	} else{
		format(buffer,sizeof(buffer),"{C3C3C3}%s",dini_Get(PrivAuto1,"Name"));
	}
	if(!dini_Exists(PrivAuto2)){
		format(buffer,sizeof(buffer),"%s\n{C3C3C3}Brak",buffer);
	} else{
		format(buffer,sizeof(buffer),"%s\n{C3C3C3}%s",buffer,dini_Get(PrivAuto2,"Name"));
	}
	ShowPlayerDialog(playerid,61,DIALOG_STYLE_LIST,"{FF0000}Prywatne Auto - {FF00FF}Menu",buffer,"Wybierz","Zamknij");
	return 1;
}

CMD:rozwiez(playerid){
	new gPVID = GetPlayerVehicleID(playerid);
	if(gGracz[playerid][MiniJob] == 4){
		if(Nasiona[playerid] != 21){
			SendClientMessage(playerid,COLOR_RED,"Nie za³adowa³eœ wszystkich nasion");
			return 1;
		}
		if(GetVehicleModel(gPVID) == 532){
			SendClientMessage(playerid,COLOR_RED,"Rozpocz¹³eœ scinanie ");
			SetPlayerRaceCheckpoint(playerid,0,-128.0286,57.0711,3.1172,-157.3431,55.8090,3.1172,3);
			Koszenie[playerid] = 1;
		} else {
			SendClientMessage(playerid,COLOR_RED,"Nie jesteœ w kombajnie!");
		}
	} else {
		SendClientMessage(playerid,COLOR_RED,"Nie pracujesz jako ¿niwiarz");
	}
	return 1;
}

CMD:autobus(playerid){
	new buffer[100];
	new gString[1000];
	if(IsPlayerInRangeOfPoint(playerid,5,1112.5901,1381.0674,10.5474) || IsPlayerInRangeOfPoint(playerid,5,1635.9369,2179.9766,10.5070) || IsPlayerInRangeOfPoint(playerid,5,1458.7109,2773.8467,10.5474)){
		strcat(gString,"{008CE5}Cel\t\t\tKoszt:\tDystans\n");
		if(GetPlayerDistanceFromPoint(playerid,1635.9369,2179.9766,10.5070) > 100){
			format(buffer,sizeof(buffer),"Sprz¹tanie ulic\t\t100$\t%.2f\n",GetPlayerDistanceFromPoint(playerid,1635.9369,2179.9766,10.5070));
			strcat(gString,buffer);
		} else {
			format(buffer,sizeof(buffer),"Sprz¹tanie ulic\t\t50$\t%.2f\n",GetPlayerDistanceFromPoint(playerid,1635.9369,2179.9766,10.5070));
			strcat(gString,buffer);
		}
		if(GetPlayerDistanceFromPoint(playerid,1458.7109,2773.8467,10.5474) > 100){
			format(buffer,sizeof(buffer),"Spawn Truck\t\t120$\t%.2f\n",GetPlayerDistanceFromPoint(playerid,1458.7109,2773.8467,10.5474));
			strcat(gString,buffer);
		} else {
			format(buffer,sizeof(buffer),"Spawn Truck\t\t50$\t%.2f\n",GetPlayerDistanceFromPoint(playerid,1458.7109,2773.8467,10.5474));
			strcat(gString,buffer);
		}
		if(GetPlayerDistanceFromPoint(playerid,1112.5901,1381.0674,10.5474) > 100){
			format(buffer,sizeof(buffer),"Szko³a Jazdy\t\t70$\t%.2f\n",GetPlayerDistanceFromPoint(playerid,1112.5901,1381.0674,10.5474));
			strcat(gString,buffer);
		} else {
			format(buffer,sizeof(buffer),"Spawn Nowych\t\t30$\t%.2f\n",GetPlayerDistanceFromPoint(playerid,1112.5901,1381.0674,10.5474));
			strcat(gString,buffer);
		}
		ShowPlayerDialog(playerid,345,DIALOG_STYLE_LIST,"Przystanek: Spawn Nowych",gString,"JedŸ","Zamknij");
	} else {
		SendClientMessage(playerid,COLOR_RED,"*{D1D1D1}Nie jesteœ na przystanku.");
	}
	return 1;
}

CMD:spij(playerid){
	for(new i = 0, j = sizeof(Motele); i < j; i++){
		if(IsPlayerInRangeOfPoint(playerid,3,Motele[i][0],Motele[i][1],Motele[i][2])){
			ShowPlayerDialog(playerid,47,DIALOG_STYLE_MSGBOX,"Spanie","{66B9F4}Nocleg w tym motelu kosztuje {FFFFFF}250{66B9F4}$\nCzy na pewno chcesz siê tutaj przespaæ?","Tak","Nie");
			return 1;
		}
	}
	return 1;
}

CMD:p(playerid){
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER){
		new vehicleid = GetPlayerVehicleID(playerid);
		new engine,lights,bonnet,door,costam,boot,objective;
		new string[2000],string2[100];
		GetVehicleParamsEx(vehicleid,engine,lights,costam,door,bonnet,boot,objective);

		if(engine == 1){
			strcat(string,"Silnik\t\t[{63E907}ON{D1D1D1}]\n");
		} else {
			strcat(string,"Silnik\t\t[{FF0000}OFF{D1D1D1}]\n");
		}
		if(lights == 1){
			strcat(string,"Œwiat³a\t\t[{63E907}ON{D1D1D1}]\n");
		} else {
			strcat(string,"Œwiat³a\t\t[{FF0000}OFF{D1D1D1}]\n");
		}
		if(bonnet == 1){
			strcat(string,"Maska\t\t[{63E907}Otwarta{D1D1D1}]\n");
		} else {
			strcat(string,"Maska\t\t[{FF0000}Zamkniêta{D1D1D1}]\n");
		}
		if(boot == 1){
			strcat(string,"Baga¿nik\t[{63E907}Otwarty{D1D1D1}]\n");
		} else {
			strcat(string,"Baga¿nik\t[{FF0000}Zamkniêty{D1D1D1}]\n");
		}
		if(door == 1){
			strcat(string,"Drzwi\t\t[{FF0000}Zamkniête{D1D1D1}]\n");
		} else {
			strcat(string,"Drzwi\t\t[{63E907}Otwarte{D1D1D1}]\n");
		}
		if(gGracz[playerid][PoradnikNumer] == 14 || gGracz[playerid][PoradnikNumer] == 15){
			gGracz[playerid][PoradnikNumer]++;
			PoradnikTimer[playerid] = SetTimerEx("TutorialZmiana",1000,false,"d",playerid);
		}

		if(GetVehicleModel(vehicleid) == 508){
			strcat(string,"Utnij sobie drzemkê\nZjedz coœ na szybko\n");
		}
		format(string2,sizeof(string2),"Panel:{FFFF00} %s",VehicleNames[GetVehicleModel(vehicleid)-400]);
		ShowPlayerDialog(playerid, 15000, DIALOG_STYLE_LIST, string2, string, "Wybierz", "Anuluj");
	} else {
		SendClientMessage(playerid, COLOR_RED, "Musisz byæ kierowc¹ w pojeŸdzie!");
	}
	return 1;
}

CMD:pojazd(playerid) return cmd_p(playerid);


CMD:wojsko(playerid,params[]){
	new string[500];
 	new text[250];
	if(SkinyPolicji(playerid)){
		if(sscanf(params,"s[250]",text)){
			SendClientMessage(playerid,COLOR_WHITE,"U¿yj: /wojsko [miejsce]!");
			return 1;
		} else {
			format(string,sizeof(string),"{FFFFFF}Policjant {9AFF00}%s {FFFFFF}wzywa posi³ki wojska:{9AFF00} %s",GetPlayerNick(playerid),text);
			SendClientMessage(playerid,COLOR_BROWN,"Wezwa³eœ pomoc wojska!");
			FoxForeach(i,Player){
				new Skinw = GetPlayerSkin(i);
				if(Skinw == 287|| Skinw == 286|| Skinw == 285){
					SendClientMessage(i,COLOR_BROWN,string);
				}
			}
		}
	} else {
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"B³¹d","{FF0000}Nie pracujesz w Policji!","Zamknij","");
	}
	return 1;
}

CMD:evtp(playerid){
	if(evtp[T3D:X] == FLOAT_INFINITY) return SendClientMessage(playerid,COLOR_RED,"Nie ma zapisanego teleportu");
	SetPlayerPos(playerid,evtp[T3D:X],evtp[T3D:Y],evtp[T3D:Z]);
	SetPlayerInterior(playerid,evtp[T3D:INT]);
	SetPlayerVirtualWorld(playerid,evtp[T3D:VW]);
	SetPlayerFacingAngle(playerid,evtp[T3D:rZ]);
	SetCameraBehindPlayer(playerid);
	return 1;
}

CMD:bankomat(playerid,params[]){
	for(new i = 0, j = sizeof(Bankomaty); i < j; i++){
		if(IsPlayerInRangeOfPoint(playerid,5,Bankomaty[i][0],Bankomaty[i][1],Bankomaty[i][2])){
			new Gracz[100];
			format(Gracz,sizeof(Gracz),"Players/%s.txt",GetPlayerNick(playerid));
			if(dini_Int(Gracz,"KartaDebetowa") == 1){
				ShowPlayerDialog(playerid,165,DIALOG_STYLE_LIST,"Bankomat","{D1D1D1}Wyp³aæ pieni¹dze\n{FFFFFF}Saldo konta","Wybierz","WyjdŸ");
			} else {
				ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Bankomat","{FF0000}Nie posiadasz karty debetowej!","Zamknij","");
			}
		}
	}
	return 1;
}

CMD:lornetka(playerid){
	new szLIST[3096], buffer[128], cnt = 0;
	FoxForeach(i,Character){
		if(playerid == i) continue;
		if(IsPlayerSpawnedEx(i)){
			if((GetPlayerInterior(playerid) == GetPlayerInterior(i)) && (GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(i))){
				if(IsPlayerVisible[i] && IsPlayerOnPlayerScreen(playerid,i)){
					format(buffer,sizeof(buffer),"{FFFFFF}%d. {00FF00}%s\n",i,GetPlayerNick(i));
					strcat(szLIST,buffer);
					cnt++;
				}
			}
		}
	}
	if(cnt == 0) szLIST = "{FFFFFF}Nie widzê nikogo w pobli¿u\n";
	ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_LIST,"Lornetka",szLIST,"Zamknij","");
	return 1;
}

CMD:anuluj(playerid){
	if(gGracz[playerid][towar] >= 1){
		if(gGracz[playerid][AnulowanieTowaru] == true){
			ShowPlayerDialog(playerid,199,DIALOG_STYLE_MSGBOX,"Zlecenie","{D1D1D1}Anulowanie zlecenia\nkosztowaæ ciê bêdzie 2500$\n{FF0000}Czy na pewno chcesz anulowaæ?","Tak","Nie");
		} else {
			ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Anulowanie","{D1D1D1}Nie mo¿esz jeszcze anulowaæ towaru{FF0000}!","Zamknij","");
		}
	}
	return 1;
}

CMD:poziomy(playerid){
	new buffer[2000];
	strcat(buffer,"{9600B3}Kryteria przyznawania poziomów\n");
	strcat(buffer,"{FF0000}Poziom:\t\tGracz:\tFirma\n");
	strcat(buffer,"{BF0082}1\t\t{C4C4C4}10\t{009AE5}30\n");
	strcat(buffer,"{BF0082}2\t\t{C4C4C4}20\t{009AE5}90\n");
	strcat(buffer,"{BF0082}3\t\t{C4C4C4}40\t{009AE5}160\n");
	strcat(buffer,"{BF0082}4\t\t{C4C4C4}60\t{009AE5}220\n");
	strcat(buffer,"{BF0082}5\t\t{C4C4C4}90\t{009AE5}270\n");
	strcat(buffer,"{BF0082}6\t\t{C4C4C4}110\t{009AE5}320\n");
	strcat(buffer,"{BF0082}7\t\t{C4C4C4}135\t{009AE5}370\n");
	strcat(buffer,"{BF0082}8\t\t{C4C4C4}170\t{009AE5}470\n");
	strcat(buffer,"{BF0082}9\t\t{C4C4C4}200\t{009AE5}490\n");
	strcat(buffer,"{BF0082}10\t\t{C4C4C4}250\t{009AE5}530\n");
	strcat(buffer,"{BF0082}11\t\t{C4C4C4}290\t{009AE5}570\n");
	strcat(buffer,"{BF0082}12\t\t{C4C4C4}320\t{009AE5}620\n");
	strcat(buffer,"{BF0082}13\t\t{C4C4C4}380\t{009AE5}700\n");
	strcat(buffer,"{BF0082}14\t\t{C4C4C4}420\t{009AE5}750\n");
	strcat(buffer,"{BF0082}15\t\t{C4C4C4}480\t{009AE5}800\n");
	strcat(buffer,"{BF0082}16\t\t{C4C4C4}520\t{009AE5}860\n");
	strcat(buffer,"{BF0082}17\t\t{C4C4C4}580\t{009AE5}910\n");
	strcat(buffer,"{BF0082}18\t\t{C4C4C4}650\t{009AE5}970\n");
	strcat(buffer,"{BF0082}19\t\t{C4C4C4}700\t{009AE5}1050\n");
	strcat(buffer,"{BF0082}20\t\t{C4C4C4}820\t{009AE5}1150\n");
	strcat(buffer,"{BF0082}21\t\t{C4C4C4}950\t{009AE5}1300\n");
	strcat(buffer,"{BF0082}22\t\t{C4C4C4}1000\t{009AE5}1500\n");
	strcat(buffer,"{BF0082}23\t\t{C4C4C4}1100\t{009AE5}2000\n");
	strcat(buffer,"{BF0082}24\t\t{C4C4C4}1300\t{009AE5}2300\n");
	strcat(buffer,"{BF0082}25\t\t{C4C4C4}1500\t{009AE5}2500\n");
	strcat(buffer,"{BF0082}26\t\t{C4C4C4}1750\t{009AE5}2700\n");
	strcat(buffer,"{BF0082}27\t\t{C4C4C4}2000\t{009AE5}3000\n");
	strcat(buffer,"{BF0082}28\t\t{C4C4C4}2300\t{009AE5}3200\n");
	strcat(buffer,"{BF0082}29\t\t{C4C4C4}2600\t{009AE5}3500\n");
	strcat(buffer,"{BF0082}30\t\t{C4C4C4}3000\t{009AE5}3700\n");
	strcat(buffer,"{BF0082}31\t\t{C4C4C4}3100\t{009AE5}4000\n");
	strcat(buffer,"{BF0082}32\t\t{C4C4C4}3200\t{009AE5}4200\n");
	strcat(buffer,"{BF0082}33\t\t{C4C4C4}3350\t{009AE5}4500\n");
	strcat(buffer,"{BF0082}34\t\t{C4C4C4}3500\t{009AE5}4800\n");
	strcat(buffer,"{BF0082}35\t\t{C4C4C4}3700\t{009AE5}5100\n");
	ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"{C4C4C4}Poziomy",buffer,"ZatwierdŸ","");
	return 1;
}

CMD:rozbrojbombe(playerid){
	if(GetTickCount() - gGracz[playerid][ostatnie_rozbrojenie] < 30000) return SendClientMessage(playerid,COLOR_ERROR,"Poczekaj 30 sekund przed kolejnym u¿yciem komendy");
	if(gGracz[playerid][FrakcjaWojsko] == 1 && SkinyWojska(playerid)){
		for(new mobid = 0; mobid < MAX_BOMB; mobid++){
			if(BombStatus[mobid]){
				new Float:x,Float:y,Float:z;
				GetDynamicObjectPos(BombObject[mobid],x,y,z);
				if(IsPlayerInRangeOfPoint(playerid,4.0,x,y,z)){
					gGracz[playerid][ostatnie_rozbrojenie] = GetTickCount();
					if(BombTick[mobid] >= 895) return SendClientMessage(playerid,COLOR_ERROR,"Jest ju¿ zapuŸno na rozbrojenie");
					if(IsProbable(40)){
						SendClientMessage(playerid,COLOR_ERROR,"Rozbrajanie nie powiod³o siê, bomba wybuchnie za kilka sekund!");
						new rand = 290+random(9);
						if(rand > 298) rand = 298;
						BombTick[mobid] = rand;
					} else {
						BombStatus[mobid] = false;
						BombTick[mobid] = 0;
						if(IsValidDynamicObject(BombObject[mobid])) DestroyDynamicObject(BombObject[mobid]);
						if(IsValidDynamicMapIcon(BombMapIcon[mobid])) DestroyDynamicMapIcon(BombMapIcon[mobid]);
						if(IsValidDynamic3DTextLabel(BombText[mobid])) DestroyDynamic3DTextLabel(BombText[mobid]);
						if(IsValidDynamicArea(BombArea[mobid])) DestroyDynamicArea(BombArea[mobid]);
						new buffer[128];
						format(buffer,sizeof buffer,"##Bomba zosta³a rozbrojona przez: {00FF00}%s",GetPlayerNick(playerid));
						FoxForeach(i,Player){
							if(SkinyWojska(i) && gGracz[i][FrakcjaWojsko] == 1){
								SendClientMessage(i,COLOR_ORANGE,buffer);
							}
						}
						PieniadzeWojska += 5000;
					}
					return 1;
				}
			}
		}
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ w pobli¿u bomby");
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem wojska");
	}
	return 1;
}

CMD:bomby(playerid){
	if(gGracz[playerid][FrakcjaWojsko] == 1 && SkinyWojska(playerid)){
		new buffer[1024];
		buffer = "Bomby:\n{00FF00}";
		for(new mobid = 0; mobid < MAX_BOMB; mobid++){
			if(BombStatus[mobid]){
				strcat(buffer,BombLocation[mobid]);
				strcat(buffer,"\n");
			}
		}
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Bomby",buffer,"Zamknij","");
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ pracownikiem wojska");
	}
	return 1;
}

CMD:zaladuj(playerid){
	new string[2048];
	new czstring[500];
	new Towar = gGracz[playerid][towar];
	new vehicleid = GetPlayerVehicleID(playerid);
	new pid = GetVehicleModel(vehicleid);
	string = "";
	czstring = "";
	if(Towar >= 1){
		return ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"B³¹d","{FF0000}Masz ju¿ towar!","Zamknij","");
	} else if(StatusTrucka[playerid] == false){
		return ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"B³¹d","{FF0000}Nie jesteœ na skinie kierowcy!","Zamknij","");
	} else if(VehLadunek[vehicleid] == true){
		return ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Za³adunek","{FF0000}To auto zosta³o ju¿ za³adowane!","Zamknij","");
	} else {
		if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER){
			for(new pz = 0, j = sizeof(punktyzaladunku); pz < j; pz++){
				if(IsPlayerInRangeOfPoint(playerid,10,punktyzaladunku[pz][0],punktyzaladunku[pz][1],punktyzaladunku[pz][2])){
					if(GetPlayerPing(playerid) > 200){SendClientMessage(playerid,COLOR_RED,"Twój ping jest wysoki! Administracja nie odpowiada za problemy z tym zwi¹zane.");}
					gGracz[playerid][towar_gotowy] = false;
					PlayerInfo[playerid][ZaladunekID] = pz;
					PlayerInfo[playerid][RozladunekID] = 0;
					if(ContainInSeries(pid,482,459,440,499,414,498,413,609)){
						strcat(string,"{4DA3FF}ID:\tTowar:\t\tKasa:\tDostêpnoœæ[t.]:\n");
						format(czstring,sizeof(czstring),"{AAFF4D}1\t{FFFFFF}Metal\t\t1500$\t%i\n",sZlecenia[pz][1]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}2\t{FFFFFF}Odzie¿\t\t1600$\t%i\n",sZlecenia[pz][2]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}3\t{FFFFFF}Jab³ka\t\t1600$\t%i\n",sZlecenia[pz][3]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}4\t{FFFFFF}Kosmetyki\t1700$\t%i\n",sZlecenia[pz][4]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}5\t{FFFFFF}Akc.Erotyczne\t1800$\t%i\n",sZlecenia[pz][5]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}6\t{FFFFFF}Meble\t\t1900$\t%i\n",sZlecenia[pz][6]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}7\t{FFFFFF}Tytoñ\t\t2000$\t%i\n",sZlecenia[pz][7]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}8\t{FF0000}Amfetamina\t3200$\t%i\n",sZlecenia[pz][8]);
						strcat(string,czstring);
						ShowPlayerDialog(playerid,49,DIALOG_STYLE_LIST,"Za³adunek",string,"Za³aduj","Anuluj");
					} else if((ContainInSeries(pid,403,514,415,515) && IsTrailerAttachedToVehicle(vehicleid))){
						strcat(string,"{4DA3FF}ID:\tTowar:\t\tKasa:\tDostêpnoœæ[t.]:\n");
						format(czstring,sizeof(czstring),"{AAFF4D}9\t{FFFFFF}Owoce i Warzywa\t2100$\t%i\n",sZlecenia[pz][9]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}10\t{FFFFFF}Drewno\t\t2200$\t%i\n",sZlecenia[pz][10]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}11\t{FFFFFF}Dywany\t\t2300$\t%i\n",sZlecenia[pz][11]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}12\t{FFFFFF}Komputery\t2400$\t%i\n",sZlecenia[pz][12]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}13\t{FFFFFF}Zabawki\t2500$\t%i\n",sZlecenia[pz][13]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}14\t{FFFFFF}Cukier\t\t2600$\t%i\n",sZlecenia[pz][14]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}15\t{FFFFFF}Bawe³na\t2700$\t%i\n",sZlecenia[pz][15]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}16\t{FFFFFF}Wo³owina\t2900$\t%i\n",sZlecenia[pz][16]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}17\t{FFFFFF}Pszenica\t3000$\t%i\n",sZlecenia[pz][17]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}18\t{FFFFFF}Kamienie\t3000$\t%i\n",sZlecenia[pz][18]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}19\t{FF0000}Broñ\t\t3100$\t%i\n",sZlecenia[pz][19]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}20\t{FF0000}Marihuana\t3200$\t%i\n",sZlecenia[pz][20]);
						strcat(string,czstring);
						ShowPlayerDialog(playerid,52,DIALOG_STYLE_LIST,"Za³adunek",string,"Za³aduj","Anuluj");
						return 1;
					} else if(ContainInSeries(pid,422,543,478,554)){
						strcat(string,"{4DA3FF}ID:\tTowar:\t\tDostêpnoœæ[szt.]:\n");
						format(czstring,sizeof(czstring),"{AAFF4D}21\t{FFFFFF}Woda\t\t1800$\t%i\n",sZlecenia[pz][21]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}22\t{FFFFFF}Cement\t\t1900$\t%i\n",sZlecenia[pz][22]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}23\t{FFFFFF}Prezerwatywy\t2100$\t%i\n",sZlecenia[pz][23]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}24\t{FFFFFF}Owies\t\t2400$\t%i\n",sZlecenia[pz][24]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}25\t{FF0000}Bimber\t\t2900$\t%i\n",sZlecenia[pz][25]);
						strcat(string,czstring);
						format(czstring,sizeof(czstring),"{AAFF4D}26\t{FFFFFF}Bagietki\t2000$\t%i\n",sZlecenia[pz][26]);
						strcat(string,czstring);
						ShowPlayerDialog(playerid,82,DIALOG_STYLE_LIST,"Za³adunek dla pojazdów",string,"Za³aduj","Anuluj");
					}
				}
			}
		} else {
			ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"B³¹d","{FF0000}Nie jesteœ na kierowc¹ pojazdu!","Zamknij","");
		}
	}
	return 1;
}

CMD:kontrola(playerid,params[]){
	new id, string[256], Float:x, Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	if(SkinyPolicji(playerid) && gGracz[playerid][FrakcjaPolicja] == 1|| gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)){
		if(sscanf(params,"d",id)){
		 	SendClientMessage(playerid,COLOR_WHITE,"U¿yj: /kontrola [ID]!");
			return 1;
		} else if(!IsPlayerConnected(id)){
			SendClientMessage(playerid,COLOR_WHITE,"Gracz o podanym id nie jest na serwerze!");
		} else if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER){
			SendClientMessage(playerid,COLOR_RED,"Nie mo¿esz sprawdziæ towaru prowadz¹c pojazd!");
		} else {
			if(IsPlayerInRangeOfPoint(id,20,x,y,z) && IsPlayerSpawnedEx(id)){
				if(GetPlayerState(id) == PLAYER_STATE_DRIVER){
		 			new vid = GetPlayerVehicleID(id);
					if(gGracz[id][towar] == -1){
						format(string,sizeof(string),"{9E00C7}Stra¿nik {D1D1D1}%s [%i] {9E00C7}spradzi³ twój towar. Niestety go nie posiadasz.",GetPlayerNick(playerid),playerid);
						SendClientMessage(id,COLOR_WHITE,string);
						format(string,sizeof(string),"{9E00C7}Skontrolowa³eœ {D1D1D1}%s [%i] {9E00C7}brak towaru",GetPlayerNick(id),id);
						SendClientMessage(playerid,COLOR_WHITE,string);
					} else {
						format(string,sizeof(string),"{9E00C7}Stra¿nik {D1D1D1}%s [%i] {9E00C7}spradzi³ twój towar. Wieziesz: {C4C4C4}%s {9E00C7}Tony:{C4C4C4} %i",GetPlayerNick(playerid),playerid,TowarNazwa[gGracz[id][towar]],gGracz[id][TowarTony]);
						SendClientMessage(id,COLOR_WHITE,string);
						format(string,sizeof(string),"{9E00C7}Skontrolowa³eœ {D1D1D1}%s [%i] {9E00C7}towar: %s, pojazd: %s, tony %i",GetPlayerNick(id),id,TowarNazwa[gGracz[id][towar]],GetVehicleIDModelName(vid),gGracz[id][TowarTony]);
						SendClientMessage(playerid,COLOR_WHITE,string);
					}
				} else {
					ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"B³¹d","{FF0000}Gracz nie jest kierwoc¹ ¿adnego pojazdu!","Zamknij","");
				}
			} else {
				ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"B³¹d","{FF0000}Gracz jest za daleko od ciebie!","Zamknij","");
			}
		}
	} else {
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"B³¹d","{FF0000}Nie pracujesz w Policji, ani Stra¿y Granicznej!","Zamknij","");
	}
	return 1;
}

CMD:zaladunek(playerid){
	if(SkinyPolicji(playerid) || SkinyPomocyDrogowej(playerid) || SkinyTaxi(playerid) || SkinyStrazyGranicznej(playerid) || SkinyMedykow(playerid) || SkinyWojska(playerid) || SkinySP(playerid)){
		return SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ kierowc¹");
	}
	
	new Float:dist, Float:ldist = 20000.0, zaladunek = 0;
	for(new pz = 0, j = sizeof(punktyzaladunku); pz < j; pz++){
		dist = GetPlayerDistanceFromPoint(playerid,punktyzaladunku[pz][0],punktyzaladunku[pz][1],punktyzaladunku[pz][2]);
		if(dist < ldist){
			ldist = dist;
			zaladunek = pz;
		}
	}
	SendClientMessage(playerid,COLOR_WHITE,"{BAE600}Najbli¿szy za³adunek zosta³ zaznaczony na radarze ró¿owym znacznikiem.");
	SetPlayerMapIcon(playerid,41,punktyzaladunku[zaladunek][0],punktyzaladunku[zaladunek][1],punktyzaladunku[zaladunek][2],59,0,MAPICON_GLOBAL);
	return 1;
}

CMD:gasnica(playerid){
	if(!SkinySP(playerid)) return SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ stra¿akiem");
	GivePlayerWeapon(playerid,42,8000);
	return 1;
}

CMD:serwer(playerid){
	new string[1000], part1[500], part2[500];
	format(part1,sizeof(part1),"{55B8FC}Ostatni zarejestrowany: {C4C4C4}%s\n{55B8FC}Iloœæ banów: {C4C4C4}%i\n{55B8FC}Wystawionych mandatów: {C4C4C4}%i\n{55B8FC}Iloœæ dowodów: {C4C4C4}%i\n{55B8FC}Liczba zarejestrowanych: {C4C4C4}%i\n{55B8FC}Liczba zarejestrowanych dzisiaj: {C4C4C4}%i\n{55B8FC}Data w³¹czenia: {C4C4C4}%s\n",
		dini_Get("Serwer.txt","OstatniZarejestrowany"),LiczbaBanow,LiczbaMandatow,DowodNR,dini_Int("Serwer.txt","LiczbaRej"),LiczbaRejDzis,dini_Get("Serwer.txt","Data ON")
	);
	strcat(string,part1);
	format(part2,sizeof(part2),"{55B8FC}Iloœæ slotów: {C4C4C4}%i\n{55B8FC}Iloœæ zalogowanych: {C4C4C4}%i\n{55B8FC}Rekord graczy: {C4C4C4}%i\n{55B8FC}Adres forum: {C4C4C4}%s\n{55B8FC}Adres Team Speak 3: {C4C4C4}%s\n{55B8FC}W³aœciciel: {C4C4C4}%s\n{55B8FC}Serwer ma: {D1D1D1}%02d:%02d:%02d:%02d\n\n{FF0000}Autor GameMode: {D1D1D1}Bambo\n",
		GetMaxPlayers()-CountFoxBot(),CountFoxPlayer(),dini_Int("Serwer.txt","Rekord"),dini_Get("Serwer.txt","Forum"),dini_Get("Serwer.txt","TeamSpeek"),dini_Get("Serwer.txt","Wlasciciel"),SecToTimeDay(gettime()-SERVER_START_TICK)
	);
	strcat(string,part2);
	ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Dane serwera",string,"Zamknij","");
	return 1;
}

CMD:serw(playerid,params[]) return cmd_serwer(playerid);

CMD:stylwalki(playerid){
	return ShowPlayerDialog(playerid,DIALOG_STYLWALKI,DIALOG_STYLE_LIST,"Wybierz swoj styl walki!","Normalny\nKungFu\nBoxing\nKneehead\nGrabKick\nElbow","Wybieram","Anuluj");
}

CMD:uptime(playerid){
	new buffer[128];
	format(buffer,sizeof(buffer),"Server aktywny od: {00FF00}%02d:%02d:%02d:%02d",MSToTimeDay(GetFilterScriptActiveTime()));
	SendClientMessage(playerid,0xFFFFFFFF,buffer);
	return 1;
}

CMD:lokalizacja(playerid){
	new Float:P[3], Float:fa, str[200];

	new vid = GetPlayerVehicleID(playerid);
	if(vid > 0){
		GetVehiclePos(vid,P[0],P[1],P[2]);
		GetVehicleZAngle(vid,fa);
	} else {
		GetPlayerPos(playerid,P[0],P[1],P[2]);
		GetPlayerFacingAngle(playerid,fa);
	}

	new zname[MAX_ZONE_NAME];
	GetPlayer3DZone(playerid,zname,sizeof(zname));

	new flag = GetPlayerCollisionFlags(playerid);
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
	
	return 1;
}

CMD:kup(playerid,params[]){
	if(IsPlayerInRangeOfPoint(playerid,3,6.7990,1479.5439,12.9172)){
		ShowPlayerDialog(playerid,188,DIALOG_STYLE_LIST,"Kupno jedzenia","Frytki {F2D563}(50$){578EFF}[10%]\n{D1D1D1}Kebab {F2D563}(90$) {578EFF}[20%]\n{D1D1D1}Popcorn {F2D563}(100$){578EFF} [15%]\n{D1D1D1}Mocna kawa {F2D563}(320$) {C4FF57}[45%]","Kup","WyjdŸ");
	} else if(IsPlayerInRangeOfPoint(playerid,3,-2.9972,1478.2721,12.9172)){
		ShowPlayerDialog(playerid,189,DIALOG_STYLE_LIST,"Picie i inne","Aparat (350$) [3]\n{FFFFFF}Kwiaty (120$) [1]\n{D1D1D1}Napój (100$) [1]\n{FFFFFF}Piwo (150$) [1]","Kup","Zamknij");
	} else if(IsPlayerInRangeOfPoint(playerid,3,2200.5786,1981.0084,5.8390) || IsPlayerInRangeOfPoint(playerid,3,1030.3199,-938.6127,28.5700)){
		ShowPlayerDialog(playerid,228,DIALOG_STYLE_LIST,"Picie i inne","Aparat (750$) [10]\n\n{FFFFFF}Napój (200$) [1]\n{D1D1D1}Piwo (550$) [1]\n{FDF712}Los Lotto (100$)\nNiebieski kask\nRó¿owy kask\nBia³y kask\nCzerwony kask","Kup","Zamknij");
	} else if(IsPlayerInRangeOfPoint(playerid,3,2202.9023,1994.9110,5.8390) || IsPlayerInRangeOfPoint(playerid,3,1023.4841,-939.3843,29.5561)){
		ShowPlayerDialog(playerid,232,DIALOG_STYLE_LIST,"Akcesoria domowe","Radio do domu [3500$]\nDzwonek do domku  [9000$]\nSlot do domku [30.000$]\nJedzenie do domku [760$] (10 sztuk)","Kup","Zamknij");
	} else if(IsPlayerInRangeOfPoint(playerid,2,1665.5304,1773.0662,17.8999)){
		ShowPlayerDialog(playerid,285,DIALOG_STYLE_LIST,"Apteka","Glukoza\t100$\tDo 30% HP\nApap\t\t260$\t-\nIg³a i niæ\t2500$\tDo 75% armor","Kup","WyjdŸ");
	} else if(IsPlayerInRangeOfPoint(playerid,3,14.9483,1475.8129,12.9172)){
		ShowPlayerDialog(playerid,2000,DIALOG_STYLE_LIST,"Kupno bagietek","Ma³a bagietka {F2D563}(25$){578EFF}[10%]\n{D1D1D1}Œrednia bagietka{F2D563}(50$) {578EFF}[20%]\n{D1D1D1}Du¿a bagietka {F2D563}(75$){578EFF} [30%]\n{D1D1D1}Du¿a bagietka z czosnkiem {F2D563}(100$){578EFF} [40%]","Kup","WyjdŸ");
	}
	return 1;
}

CMD:skonczsluzbe(playerid){
	if(SkinyPolicji(playerid)){
		if(IsPlayerInRangeOfPoint(playerid,3,-1617.1699,685.2437,7.1875) || IsPlayerInRangeOfPoint(playerid,3,2272.5220,2486.4961,-18.8838) || IsPlayerInRangeOfPoint(playerid,3,1555.0624,-1708.0728,822.4559)){
			SetPlayerSkin(playerid,gGracz[playerid][SkinKierowcy]);
			PokazPasekStanu(playerid);
			if(GetPlayerWantedLevel(playerid) <= 0){
				SetPlayerColor(playerid,0x6DC5F3FF);
			}
			ResetPlayerWeapons(playerid);
			if(gGracz[playerid][VipLvl] < 1){
				SetPlayerArmour(playerid,0.0);
			}
			StatusTrucka[playerid] = true;
			gGracz[playerid][PozwolenieBron] = false;
			gGracz[playerid][ZapisanySkin] = GetPlayerSkin(playerid);
			return 1;
		}
	} else if(gGracz[playerid][FrakcjaPomocDrogowa] == 1 && SkinyPomocyDrogowej(playerid) && IsPlayerInRangeOfPoint(playerid,2,1393.7915,667.5272,7.4078)){
		ResetPlayerWeapons(playerid);
		SetPlayerSkin(playerid,gGracz[playerid][SkinKierowcy]);
		PokazPasekStanu(playerid);
		if(GetPlayerWantedLevel(playerid) <= 0){
			SetPlayerColor(playerid,0x6DC5F3FF);
		}
		ResetPlayerWeapons(playerid);
		if(gGracz[playerid][VipLvl] < 1){
			SetPlayerArmour(playerid,0.0);
		}
		StatusTrucka[playerid] = true;
		gGracz[playerid][PozwolenieBron] = false;
		gGracz[playerid][ZapisanySkin] = GetPlayerSkin(playerid);
		return 1;
	} else if(gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid) && IsPlayerInRangeOfPoint(playerid,5,2439.9395,146.3940,26.5164)){
		ResetPlayerWeapons(playerid);

		SetPlayerSkin(playerid,gGracz[playerid][SkinKierowcy]);
		PokazPasekStanu(playerid);
		if(GetPlayerWantedLevel(playerid) <= 0){
			SetPlayerColor(playerid,0x6DC5F3FF);
		}
		if(gGracz[playerid][VipLvl] < 1){
			SetPlayerArmour(playerid,0.0);
		}
		StatusTrucka[playerid] = true;
		ResetPlayerWeapons(playerid);
		gGracz[playerid][PozwolenieBron] = false;
		gGracz[playerid][ZapisanySkin] = GetPlayerSkin(playerid);
		new straznicy = 0;
		FoxForeach(i,Player){
			if(gGracz[i][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(i)){
				straznicy++;
			}
		}
		if(straznicy < 1){
			OtworzGranice();
		}
		return 1;
	} else if(gGracz[playerid][FrakcjaMedyk] == 1 && SkinyMedykow(playerid) && IsPlayerInRangeOfPoint(playerid,3,1593.6837,1780.0699,10.6098)){
		SetPlayerSkin(playerid,gGracz[playerid][SkinKierowcy]);
		PokazPasekStanu(playerid);
		ResetPlayerWeapons(playerid);
		if(GetPlayerWantedLevel(playerid) <= 0){
			SetPlayerColor(playerid,0x6DC5F3FF);
		}
		ResetPlayerWeapons(playerid);
		if(gGracz[playerid][VipLvl] < 1){
			SetPlayerArmour(playerid,0.0);
		}
		StatusTrucka[playerid] = true;
		gGracz[playerid][PozwolenieBron] = false;
		gGracz[playerid][ZapisanySkin] = GetPlayerSkin(playerid);
		return 1;
	} else if(gGracz[playerid][FrakcjaTaxi] == 1 && SkinyTaxi(playerid) && IsPlayerInRangeOfPoint(playerid,3,2612.6880,1208.9967,-2.6419)){
		SetPlayerSkin(playerid,gGracz[playerid][SkinKierowcy]);
		PokazPasekStanu(playerid);
		if(GetPlayerWantedLevel(playerid) <= 0){
			SetPlayerColor(playerid,0x6DC5F3FF);
		}
		ResetPlayerWeapons(playerid);
		ResetPlayerWeapons(playerid);
		if(gGracz[playerid][VipLvl] < 1){
			SetPlayerArmour(playerid,0.0);
		}
		StatusTrucka[playerid] = true;
		gGracz[playerid][PozwolenieBron] = false;
		gGracz[playerid][ZapisanySkin] = GetPlayerSkin(playerid);
		return 1;
	} else if(gGracz[playerid][FrakcjaWojsko] == 1 && SkinyWojska(playerid) && IsPlayerInRangeOfPoint(playerid,5,112.6999, 1755.1999, 17.5)){
		SetPlayerSkin(playerid,gGracz[playerid][SkinKierowcy]);
		PokazPasekStanu(playerid);
		if(GetPlayerWantedLevel(playerid) <= 0){
			SetPlayerColor(playerid,0x6DC5F3FF);
		}
		ResetPlayerWeapons(playerid);
		if(gGracz[playerid][VipLvl] < 1){
			SetPlayerArmour(playerid,0.0);
		}
		StatusTrucka[playerid] = true;
		gGracz[playerid][PozwolenieBron] = false;
		gGracz[playerid][ZapisanySkin] = GetPlayerSkin(playerid);
		return 1;
	} else if(gGracz[playerid][FrakcjaSP] == 1 && SkinySP(playerid) && IsPlayerInRangeOfPoint(playerid,5,1088.5908,2406.8672,6.3469)){
		SetPlayerSkin(playerid,gGracz[playerid][SkinKierowcy]);
		PokazPasekStanu(playerid);
		if(GetPlayerWantedLevel(playerid) <= 0){
			SetPlayerColor(playerid,0x6DC5F3FF);
		}
		ResetPlayerWeapons(playerid);
		if(gGracz[playerid][VipLvl] < 1){
			SetPlayerArmour(playerid,0.0);
		}
		StatusTrucka[playerid] = true;
		gGracz[playerid][PozwolenieBron] = false;
		gGracz[playerid][ZapisanySkin] = GetPlayerSkin(playerid);
		return 1;
	} else {
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"S³u¿ba","{FFFFFF}Nie jesteœ na s³u¿bie, lub nie jesteœ w przebieralni{FF0000}!","Zamknij","");
	}
	return 1;
}

CMD:bank(playerid){
	if(gGracz[playerid][LiderPolicji] == 1 || gGracz[playerid][LiderPomocyDrogowej] == 1 || gGracz[playerid][LiderMedykow] == 1 || gGracz[playerid][LiderStrazyGranicznej] == 1 || gGracz[playerid][LiderWojska] ==1 || gGracz[playerid][LiderTaxi] == 1 || gGracz[playerid][LiderSP]){
		if(IsPlayerInRangeOfPoint(playerid,2,2309.8228,-8.4246,26.7422)){
			new buffer[1000];
			gGracz[playerid][LiderPD] = false;
			gGracz[playerid][LiderP] = false;
			gGracz[playerid][LiderT] = false;
			gGracz[playerid][LiderM] = false;
			gGracz[playerid][LiderW] = false;
			gGracz[playerid][LiderSG] = false;
			gGracz[playerid][LiderStraz] = false;
			strcat(buffer,"{C4C4C4}Zarz¹dzaj kontem {0088FA}Policji\n");
			strcat(buffer,"{C4C4C4}Zarz¹dzaj kontem {B2FA00}Pomocy Drogowej\n");
			strcat(buffer,"{C4C4C4}Zarz¹dzaj kontem {C000FA}Stra¿y Granicznej\n");
			strcat(buffer,"{C4C4C4}Zarz¹dzaj kontem {FA8D00}Pogotowia\n");
			strcat(buffer,"{C4C4C4}Zarz¹dzaj kontem {FAD100}Taxi\n");
			strcat(buffer,"{C4C4C4}Zarz¹dzaj kontem {A18702}Wojska\n");
			strcat(buffer,"{C4C4C4}Zarz¹dzaj kontem {FAB92E}Stra¿y Po¿arnej\n");
			ShowPlayerDialog(playerid,168,DIALOG_STYLE_LIST,"Konta frakcji",buffer,"Wybierz","Anuluj");
		}
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nie jesteœ liderem frakcji");
	}
	return 1;
}