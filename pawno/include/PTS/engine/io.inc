public OnScriptCheck(playerid,errorlevel){
	
	new buffer[256];
	format(buffer,sizeof(buffer),"Skrypt {00FF00}%s{FFFFFF} odpowiada na ¿¹danie kod: {00FF00}0x%08x",SCRIPT_NAME,errorlevel);
	SendClientMessage(playerid,0xFFFFFFFF,buffer);
	
	return 1;
}

#define CALL_CHANEL_ID_INPUT		(0x000000FF)	//Game Mode
#define CALL_CHANEL_ID_OUTPUT		(0x000000FF)	//Game Mode
#define CALL_CHANEL_ID_BROADCAST	(0xFFFFFFFF)

public OnScriptCall(playerid, chanel, errorlevel, data[]){
	if(chanel == CALL_CHANEL_ID_INPUT || chanel == CALL_CHANEL_ID_BROADCAST){
		switch(errorlevel){
			case 0xFE: { //Odbiera czas aktywnoœci skryptu
				new buffer[256], tmp_name[32], tmp_time;
				sscanf(data,"p<:>s[32]d",tmp_name,tmp_time);
				format(buffer,sizeof(buffer),"Skrypt {00FF00}%s{FFFFFF} czas aktywnoœci: {00FF00}%02d:%02d:%02d:%02d",tmp_name,MSToTimeDay(tmp_time));
				SendClientMessage(playerid,0xFFFFFFFF,buffer);
			}
			case 0xFF: { //Wysy³a czas aktywnoœci skryptu
				new buffer[32];
				format(buffer,sizeof buffer,"%s:%d",SCRIPT_NAME,GetFilterScriptActiveTime());
				CallToAllScript(playerid, CALL_CHANEL_ID_OUTPUT, 0xFE, buffer);
			}
		}
	}
	return 1;
}