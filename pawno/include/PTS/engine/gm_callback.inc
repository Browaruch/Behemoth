public OnVehicleSpawn(vehicleid){

	return 1;
}

public OnVehicleDeath(vehicleid,killerid){
	
	return 1;
}

public OnPlayerStreamIn(playerid, forplayerid){
	if(IsPlayerNPC(playerid) || IsPlayerNPC(forplayerid)) return 1;
	if(!IsPlayerVisible[playerid]){
		SetPlayerColor(playerid,0x6DC5F300);
		HidePlayerForPlayer(forplayerid,playerid);
	}
	return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid, bodypart){
	if(issuerid != INVALID_PLAYER_ID){
		if(!IsPlayerVisible[issuerid] || !IsPlayerVisible[playerid]) return 1;
	}
	return 1;
}

public OnPlayerStreamOut(playerid,forplayerid){

	return 1;
}

public OnVehicleStreamIn(vehicleid,forplayerid){

	return 1;
}

public OnVehicleStreamOut(vehicleid,forplayerid){

	return 1;
}

public OnServerMessage(const msg[]){
	printf("[SERVER MSG] %s",msg);
	return 1;
}

public OnRemoteRCONPacket(const ipaddr[], port, const password[], success, const command[]){
	printf("[RCON PACKET] %s:%d (%d) Pass: '%s' CMD: '%s'",ipaddr,port,success,password,command);
	return 1;
}

public OnPlayerCommandReceived(playerid,cmdtext[]){
	/*
	if(!CG_ProtVar::cgod_clear[playerid] && gGracz[playerid][PoradnikNumer] == 0){
		SendClientMessage(playerid,COLOR_RED,"Trwa skanowanie");
		return 0;
	} else 
	*/
	if(gGracz[playerid][StatusJail] == false && gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN){
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Wiezienie","{FF0000}Jesteœ w wiêzieniu, nie mo¿esz u¿ywaæ komend\n{FFFFFF}Poczekaj na koniec kary!","Zamknij","");
		return 0;
	} else if(gGracz[playerid][BLCMD] == true){
		new string8[500];
		format(string8,sizeof(string8),"{D1D1D1}Nie mo¿esz wpisywaæ komend, pozosta³o ci {FF0000}%i {D1D1D1}kary.",CzasBlokady[playerid]);
		SendClientMessage(playerid,COLOR_RED,string8);
		return 0;
	} else if(gGracz[playerid][Zalogowany] == false && !IsPlayerNPC(playerid)){
		//zbyt d³ugie logowanie
		new buffer[200];
		format(buffer,sizeof(buffer),"[SECURITY] [%s](%d)%s bypassing login",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid));
		print(buffer);
		WriteLog(buffer,LOG_FILE_HACK);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
		SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu omijania logowania.");
		SetTimerEx("KickGracza",200,false,"d",playerid);
		return 0;
	}
	CMD5[playerid] = CMD4[playerid];
	CMD4[playerid] = CMD3[playerid];
	CMD3[playerid] = CMD2[playerid];
	CMD2[playerid] = CMD1[playerid];
	format(CMD1[playerid],200,"%s",cmdtext);
	return 1;
}

public OnPlayerCommandPerformed(playerid,cmdtext[],success){
	if(success){
		printf("[CMD] (%d)%s %s",playerid,GetPlayerNick(playerid),cmdtext);
	} else {
		return SendClientMessage(playerid,COLOR_ERROR,"Nieznana komenda, u¿yj /komendy aby zobaczyæ pe³n¹ listê komend.");
	}
	return 1;
}

public OnPlayerText(playerid, text[]){
	if((gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN) && (GetTickCount()-gGracz[playerid][WiadomosciTick] < 1500)){
		SendClientMessage(playerid,COLOR_RED,"Za szybko chcesz napisaæ kolejn¹ wiadomoœæ! :)");
		return 0;
	}
	CensorText(text);
	/*
	if(ContainsIP(text)){
		new buffer[200];
		format(buffer,sizeof buffer,"[SECURITY] [%s](%d)%s ADS: %s",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid),text);
		print(buffer);
		WriteLog(buffer,LOG_FILE_HACK);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
		return 0;
	}
	*/
	
	new frakcjatext[60], wiadomosc[256], Skin = GetPlayerSkin(playerid);
	gGracz[playerid][AntyAFKLicznik] = 0;
	if(gGracz[playerid][PoradnikNumer] > 0){
		SendClientMessage(playerid,COLOR_RED,"*{D1D1D1}Poradnika nie da siê wy³¹czyæ! Czytaj i wykonuj polecenia, aby go ukoñczyæ");
	}
	if(gGracz[playerid][StatusMute]){
		format(wiadomosc,sizeof(wiadomosc),"{FF0000}Jesteœ wyciszony pozosta³o: {FFFFFF}%i {FF0000}sekund\n{D1D1D1}Odczekaj do koñca kary..",CzasMute[playerid]);
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Wyciszony",wiadomosc,"Zamknij","");
		return 0;
	} else if(!gGracz[playerid][StatusJail]){
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Wiezienie","{FF0000}Jesteœ w wiêzieniu, nie mo¿esz pisaæ.\n{FFFFFF}Poczekaj na koniec kary!","Zamknij","");
		return 0;
	} else if(gGracz[playerid][WiezienieWoj] == true){
		SendClientMessage(playerid,COLOR_RED,"Masz w³¹czon¹ blokadê wpisywania komend. {FFFFFF}U¿ywaj /l [tekst].");
		return 0;
	}
	
	if(gGracz[playerid][RangaGracza] == 1){
		frakcjatext = "{DB7200}[Mapper]{E3E3E3}";
	} else if(gGracz[playerid][RangaGracza] == 2){
		frakcjatext = "{FF38EA}[€§ponsor€]{E3E3E3}";
	} else if(gGracz[playerid][RangaGracza] == 3 && Ukrycie[playerid] == false){
		frakcjatext = "{AD0094}[Operator]{E3E3E3}";
	} else if(gGracz[playerid][RangaGracza] == 4 && Ukrycie[playerid] == false){
		frakcjatext = "{33DFFF}[Junior Admin]{E3E3E3}";
	} else if(gGracz[playerid][RangaGracza] == 5 && Ukrycie[playerid] == false){
		frakcjatext = "{0062E0}[Admin]{E3E3E3}";
	} else if(gGracz[playerid][RangaGracza] == 6 && Ukrycie[playerid] == false){
		frakcjatext = "{089114}[Vice Head]{E3E3E3}";
	} else if(gGracz[playerid][RangaGracza] == 7 && Ukrycie[playerid] == false){
		frakcjatext = "{FF001D}[Head Admin]{E3E3E3}";
	} else if(gGracz[playerid][RangaGracza] == 8){
		frakcjatext = "{4B828B}[Programista]{E3E3E3}";
	} else if(gGracz[playerid][RangaGracza] == 9){
		frakcjatext = "{964A55}[Zas³u¿ony]{E3E3E3}";
	} else if(gGracz[playerid][FrakcjaPolicja] == 1 && SkinyPolicji(playerid)){
		frakcjatext = "{26B0E8}[Policjant]{E3E3E3}";
	} else if(gGracz[playerid][FrakcjaPomocDrogowa] == 1 && SkinyPomocyDrogowej(playerid)){
		frakcjatext = "{C6E826}[Mechanik]{E3E3E3}";
	} else if(gGracz[playerid][FrakcjaStrazGraniczna] == 1 && SkinyStrazyGranicznej(playerid)){
		frakcjatext = "{9A02A7}[Stra¿nik]{E3E3E3}";
	} else if(gGracz[playerid][FrakcjaSP] == 1 && SkinySP(playerid)){
		frakcjatext = "{E55900}[Stra¿ak]{E3E3E3}";
	} else if(gGracz[playerid][FrakcjaMedyk] == 1 && SkinyMedykow(playerid)){
		frakcjatext = "{BFB8C7}[Medyk]{E3E3E3}";
	} else if(gGracz[playerid][FrakcjaTaxi] == 1 && SkinyTaxi(playerid)){
		frakcjatext = "{FFDE05}[Taxi CAB]{E3E3E3}";
	} else if(gGracz[playerid][FrakcjaWojsko] == 1 && SkinyWojska(playerid)){
		frakcjatext = "{985501}[¯o³nierz]{E3E3E3}";
	} else if(Skin == 20||Skin == 41||Skin == 72||Skin == 215||Skin == 56){
		frakcjatext = "{FFA3F9}[Kursant]{D1D1D1}";
	} else if(gGracz[playerid][FirmaUID] > 0 && StatusTrucka[playerid] == true){
		new firma[64];
		format(firma,sizeof(firma),"/Firmy/%i/Staty.txt",gGracz[playerid][FirmaUID]);
		if(dini_Exists(firma)){
			format(frakcjatext,sizeof(frakcjatext),"{6EF155}[%s]{E3E3E3}",dini_Get(firma,"Tag"));
		}
	} else {
		frakcjatext = "{E8B626}[Kierowca]{D1D1D1}";
	}
	new Float:x, Float:y,Float:z;
	GetPlayerPos(playerid,x,y,z);
	if(gGracz[playerid][Zalogowany] == false){
		SendClientMessage(playerid,COLOR_RED,"Nie jesteœ zalogowany!");
		return 0;
	}
	if(strfind(gGracz[playerid][OstatniaWiadomosc],text) == 0 && gGracz[playerid][AdminLvl] < 3){
		SendClientMessage(playerid,COLOR_RED,"Nie powielaj swoich wiadomoœci, mo¿e byæ to uznane jako spam!");
		return 0;
	}
	
	if(text[0] == '`' || text[0] == '!'){
		if(gGracz[playerid][PoradnikNumer] == 2){
			gGracz[playerid][PoradnikNumer]++;
			PoradnikTimer[playerid] = SetTimerEx("TutorialZmiana",1000,false,"d",playerid);
		}
		if(StatusOOC == true || gGracz[playerid][AdminLvl] >= 5){
			if(strfind(text[1],"[b]",false) == 0  && gGracz[playerid][VipLvl] >= 1){
				format(wiadomosc,sizeof(wiadomosc),"{FFFFFF}[%i]%s: {1ABBFF}%s",playerid,GetPlayerNick(playerid),text[4]);
				SendClientMessageToAll(COLOR_WHITE,wiadomosc);
			} else if(strfind(text[1],"[z]",false) == 0 && gGracz[playerid][VipLvl] >= 1){
				format(wiadomosc,sizeof(wiadomosc),"{FFFFFF}[%i]%s: {FFF63D}%s",playerid,GetPlayerNick(playerid),text[4]);
				SendClientMessageToAll(COLOR_WHITE,wiadomosc);
			} else if(strfind(text[1],"[r]",false) == 0 && gGracz[playerid][VipLvl] >= 2){
				format(wiadomosc,sizeof(wiadomosc),"{FFFFFF}[%i]%s: {FB3DFF}%s",playerid,GetPlayerNick(playerid),text[4]);
				SendClientMessageToAll(COLOR_WHITE,wiadomosc);
			} else if(strfind(text[1],"[zi]",false) == 0 && gGracz[playerid][VipLvl] >= 2){
				format(wiadomosc,sizeof(wiadomosc),"{FFFFFF}[%i]%s: {7ED30D}%s",playerid,GetPlayerNick(playerid),text[5]);
				SendClientMessageToAll(COLOR_WHITE,wiadomosc);
			} else if(strfind(text[1],"[c]",false) == 0 && gGracz[playerid][VipLvl] >= 2){
				format(wiadomosc,sizeof(wiadomosc),"{FFFFFF}[%i]%s: {D30D10}%s",playerid,GetPlayerNick(playerid),text[4]);
				SendClientMessageToAll(COLOR_WHITE,wiadomosc);
			} else if(strfind(text[1],"[f]",false) == 0 && gGracz[playerid][VipLvl] >= 2){
				format(wiadomosc,sizeof(wiadomosc),"{FFFFFF}[%i]%s: {6E05FF}%s",playerid,GetPlayerNick(playerid),text[4]);
				SendClientMessageToAll(COLOR_WHITE,wiadomosc);
			} else {
				if(gGracz[playerid][AdminLvl] >= 3 && Ukrycie[playerid] == false){
					format(wiadomosc,sizeof(wiadomosc),"{FFFFFF}[%i]%s %s: {FFFFFF}%s",playerid,GetPlayerNick(playerid),frakcjatext,text[1]);
				} else if(gGracz[playerid][VipLvl] == 1 && Ukrycie[playerid] == false){
					format(wiadomosc,sizeof(wiadomosc),"{F8FF38}[%i]%s %s: %s",playerid,GetPlayerNick(playerid),frakcjatext,text[1]);
				} else if(gGracz[playerid][VipLvl] == 2 && Ukrycie[playerid] == false){
					format(wiadomosc,sizeof(wiadomosc),"{00E6A9}[%i]%s %s: %s",playerid,GetPlayerNick(playerid),frakcjatext,text[1]);
				} else {
					format(wiadomosc,sizeof(wiadomosc),"{C9C9C9}[%i]%s %s: %s",playerid,GetPlayerNick(playerid),frakcjatext,text[1]);
				}
				SendClientMessageToAll(COLOR_WHITE,wiadomosc);
			}
		} else {
			SendClientMessage(playerid,COLOR_RED,"Czat ogólny zosta³ wy³¹czony przez administratora!");
		}
	} else if(text[0] == '.'){
		format(wiadomosc,sizeof(wiadomosc),"{C2C2C2}%s szepcze: %s",GetPlayerNick(playerid),text[1]);
		FoxForeach(i,Player){
			if(IsPlayerInRangeOfPoint(i,3,x,y,z) && GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid)){
				if(i != playerid){
					SendClientMessage(i,COLOR_WHITE,wiadomosc);
				}
			}
		}
		format(wiadomosc,sizeof(wiadomosc),"{B3B3B3}%s szepcze: %s",GetPlayerNick(playerid),text[1]);
		SendClientMessage(playerid,COLOR_WHITE,wiadomosc);
		SetPlayerChatBubble(playerid,text[1],COLOR_AQUA,3,10000);
	} else if(text[0] == '@'){
		new Firma[64];
		format(Firma,sizeof(Firma),"/Firmy/%i/Staty.txt",gGracz[playerid][FirmaUID]);
		if(gGracz[playerid][FirmaUID] > 0 && !SkinyPolicji(playerid) && !SkinyPomocyDrogowej(playerid) && !SkinyTaxi(playerid) && !SkinyStrazyGranicznej(playerid) && !SkinyMedykow(playerid) && !SkinyWojska(playerid)){
			format(wiadomosc,sizeof(wiadomosc),"(%s chat)%s[%i]: %s",dini_Get(Firma,"Tag"),GetPlayerNick(playerid),playerid,text[1]);
			FoxForeach(i,Player){
				if(gGracz[i][Zalogowany] == true){
					if(!SkinyPolicji(i) && !SkinyPomocyDrogowej(i) && !SkinyTaxi(i) && !SkinyStrazyGranicznej(i) && !SkinyMedykow(i) && !SkinyWojska(i)){
						if(gGracz[i][FirmaUID] == gGracz[playerid][FirmaUID]){
							SendClientMessage(i,COLOR_LIMEGREEN,wiadomosc);
						}
					}
					if(gGracz[i][AdminLvl] >= 3){
						if(gGracz[i][StatusViewF] == true){
							if(gGracz[i][FirmaUID] != gGracz[playerid][FirmaUID]){
								format(wiadomosc,sizeof(wiadomosc),"(%s) %s[%i]: %s",dini_Get(Firma,"Tag"),GetPlayerNick(playerid),playerid,text[1]);
								if(i != playerid){
									SendClientMessage(i,COLOR_LIMEGREEN,wiadomosc);
								}
							}
						}
					}
				}
			}
		} else {
			new admstring[256];
			format(wiadomosc,sizeof(wiadomosc),"{99E4FF}%s mówi: %s",GetPlayerNick(playerid),text);
			format(admstring,sizeof(admstring),"{99E4FF}[%i]%s mówi: %s",playerid,GetPlayerNick(playerid),text);
			FoxForeach(i,Player){
				if(IsPlayerInRangeOfPoint(i,30,x,y,z)&& GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid) && gGracz[i][AdminLvl] < 3){
					if(i != playerid){
						SendClientMessage(i,COLOR_WHITE,wiadomosc);
					}
				}
				if(IsPlayerInRangeOfPoint(i,30,x,y,z)&& GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid) && gGracz[i][AdminLvl] >= 3){
					if(i != playerid){
						SendClientMessage(i,COLOR_WHITE,admstring);
					}
				}
			}
			format(wiadomosc,sizeof(wiadomosc),"{6BD0FF}%s mówi: %s",GetPlayerNick(playerid),text);
			SendClientMessage(playerid,COLOR_WHITE,wiadomosc);
			SetPlayerChatBubble(playerid,text,COLOR_WHITE,20,10000);
			/*
			if(gGracz[playerid][Zemdlenie] == false){
				ApplyAnimation(playerid, "ped", "IDLE_chat", 4.1, 1, 1, 1, 1, 1);
			}
			*/
			format(wiadomosc,sizeof(wiadomosc),"{00ff00}[ViewChat]{0DA9D3}[%i]%s mówi: %s",playerid,GetPlayerNick(playerid),text);
			FoxForeach(i,Player){
				if(gGracz[i][AdminLvl] >= 3){
					if(gGracz[i][StatusViewC] == true){
						if(!IsPlayerInRangeOfPoint(i,30,x,y,z)){
							SendClientMessage(i,COLOR_PURPLE,wiadomosc);
						}
					}
				}
			}
		}
	} else {
		new admstring[256];
		format(wiadomosc,sizeof(wiadomosc),"{99E4FF}%s mówi: %s",GetPlayerNick(playerid),text);
		format(admstring,sizeof(admstring),"{99E4FF}[%i]%s mówi: %s",playerid,GetPlayerNick(playerid),text);
		FoxForeach(i,Player){
			if(IsPlayerInRangeOfPoint(i,30,x,y,z)&& GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid) && gGracz[i][AdminLvl] < 3){
				if(i != playerid){
					SendClientMessage(i,COLOR_WHITE,wiadomosc);
				}
			}
			if(IsPlayerInRangeOfPoint(i,30,x,y,z)&& GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid) && gGracz[i][AdminLvl] >= 3){
				if(i != playerid){
					SendClientMessage(i,COLOR_WHITE,admstring);
				}
			}
		}
		format(wiadomosc,sizeof(wiadomosc),"{6BD0FF}%s mówi: %s",GetPlayerNick(playerid),text);
		SendClientMessage(playerid,COLOR_WHITE,wiadomosc);
		SetPlayerChatBubble(playerid,text,COLOR_WHITE,20,10000);
		/*
		if(gGracz[playerid][Zemdlenie] == false){
			ApplyAnimation(playerid, "ped", "IDLE_chat", 4.1, 1, 1, 1, 1, 1);
		}
		*/
		format(wiadomosc,sizeof(wiadomosc),"{00ff00}[ViewChat]{0DA9D3}[%i]%s mówi: %s",playerid,GetPlayerNick(playerid),text);
		FoxForeach(i,Player){
			if(gGracz[i][AdminLvl] >= 3){
				if(gGracz[i][StatusViewC] == true){
					if(!IsPlayerInRangeOfPoint(i,30,x,y,z)){
						SendClientMessage(i,COLOR_PURPLE,wiadomosc);
					}
				}
			}
		}
	}
	gGracz[playerid][WiadomosciTick] = GetTickCount();
	format(gGracz[playerid][OstatniaWiadomosc],300,"%s",text);
	
	return 0;
}

public OnPlayerCommandText(playerid,cmdtext[]){
	CensorText(cmdtext);
	/*
	if(ContainsIP(cmdtext)){
		new buffer[200];
		format(buffer,sizeof buffer,"[SECURITY] [%s](%d)%s ADS: %s",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid),cmdtext);
		print(buffer);
		WriteLog(buffer,LOG_FILE_HACK);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
		return 0;
	}
	*/
	
	if(gGracz[playerid][Zalogowany] == false && !IsPlayerNPC(playerid)){
		//zbyt d³ugie logowanie
		new buffer[200];
		format(buffer,sizeof(buffer),"[SECURITY] [%s](%d)%s bypassing login",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid));
		print(buffer);
		WriteLog(buffer,LOG_FILE_HACK);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
		SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu omijania logowania.");
		SetTimerEx("KickGracza",200,false,"d",playerid);
		return 1;
	}
	gGracz[playerid][AntyAFKLicznik] = 0;

	return 1;
}


public OnRconLoginAttempt(ip[], password[], success){
	if(success){
		SetTimer("SearchForNewAdmin",50,false);
	} else {
		FoxForeach(hackerid,Player){
			if(!strcmp(ip,GetPlayerIP(hackerid),true)){
				if(gGracz[hackerid][AdminLvl] < 7){
					BanEx(hackerid,"Logowanie na RCON bez autoryzacji");
				} else {
					break;
				}
			}
		}
	}

	new buffer[128];

	format(buffer,sizeof buffer,"[Logowanie na RCON] IP: %s - haslo: %s - zalogowano: %s",ip,password,success?("tak"):("nie"));
	printf(buffer);
	return 1;
}

