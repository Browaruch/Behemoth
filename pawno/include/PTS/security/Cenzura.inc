new const badwords[][] = {
	"4r5e","5h1t","5hit","a55","anal","anus","ar5e","arrse","arse",
	"ass-fucker","asses","assfucker","assfukka","asshole","assholes","asswhole","a_s_s","b!tch","b00bs",
	"b17ch","b1tch","ballbag","balls","ballsack","bastard","beastial","beastiality","bellend","bestial",
	"bestiality","bi+ch","biatch","bitch","bitcher","bitchers","bitches","bitchin","bitching","bloody",
	"blow job","blowjob","blowjobs","boiolas","bollock","bollok","boner","boob","boobs","booobs",
	"boooobs","booooobs","booooooobs","breasts","buceta","bugger","bunny fucker","butt","butthole",
	"buttmuch","buttplug","c0ck","c0cksucker","carpet muncher","cawk","chink","cipa","cl1t","clit",
	"clitoris","clits","cnut","cock","cock-sucker","cockface","cockhead","cockmunch","cockmuncher","cocks",
	"cocksuck","cocksucked","cocksucker","cocksucking","cocksucks","cocksuka","cocksukka","cok","cokmuncher","coksucka",
	"coon","cox","crap","cummer","cumming","cums","cumshot","cunilingus","cunillingus",
	"cunnilingus","cunt","cuntlick","cuntlicker","cuntlicking","cunts","cyalis","cyberfuc","cyberfuck","cyberfucked",
	"cyberfucker","cyberfuckers","cyberfucking","d1ck","damn","dick","dickhead","dildo","dildos","dink",
	"dinks","dirsa","dlck","dog-fucker","doggin","dogging","donkeyribber","doosh","duche","dyke",
	"ejaculate","ejaculated","ejaculates","ejaculating","ejaculatings","ejaculation","ejakulate","f4nny",
	"fag","fagging","faggitt","faggot","faggs","fagot","fagots","fags","fanny","fannyflaps",
	"fannyfucker","fanyy","fatass","fcuk","fcuker","fcuking","feck","fecker","felching","fellate",
	"fellatio","fingerfuck","fingerfucked","fingerfucker","fingerfuckers","fingerfucking","fingerfucks","fistfuck","fistfucked","fistfucker",
	"fistfuckers","fistfucking","fistfuckings","fistfucks","flange","fook","fooker","fuck","fucka","fucked",
	"fucker","fuckers","fuckhead","fuckheads","fuckin","fucking","fuckings","fuckingshitmotherfucker","fuckme","fucks",
	"fuckwhit","fuckwit","fudge packer","fudgepacker","fuk","fuker","fukker","fukkin","fuks","fukwhit",
	"fukwit","fux","fux0r","f_u_c_k","gangbang","gangbanged","gangbangs","gaylord","gaysex","goatse",
	"god-dam","god-damned","goddamn","goddamned","hardcoresex","hell","heshe","hoar","hoare",
	"hoer","homo","hore","horniest","horny","hotsex","jack-off","jackoff","jerk-off",
	"jism","jiz","jizm","jizz","kawk","knob","knobead","knobed","knobend","knobhead",
	"knobjocky","knobjokey","kock","kondum","kondums","kummer","kumming","kums","kunilingus",
	"l3i+ch","l3itch","labia","lust","lusting","m0f0","m0fo","m45terbate","ma5terb8","ma5terbate",
	"masochist","master-bate","masterb8","masterbat*","masterbat3","masterbate","masterbation","masterbations","masturbate","mo-fo",
	"mof0","mofo","mothafuck","mothafucka","mothafuckas","mothafuckaz","mothafucked","mothafucker","mothafuckers","mothafuckin",
	"mothafucking","mothafuckings","mothafucks","mother fucker","motherfuck","motherfucked","motherfucker","motherfuckers","motherfuckin","motherfucking",
	"motherfuckings","motherfuckka","motherfucks","muff","mutha","muthafecker","muthafuckker","muther","mutherfucker","n1gga",
	"n1gger","nazi","nigg3r","nigg4h","nigga","niggah","niggas","niggaz","nigger","niggers",
	"nob","nob jokey","nobhead","nobjocky","nobjokey","numbnuts","nutsack","orgasim","orgasims","orgasm",
	"orgasms","p0rn","pecker","penis","penisfucker","phonesex","phuck","phuk","phuked",
	"phuking","phukked","phukking","phuks","phuq","pigfucker","pimpis","piss","pissed","pisser",
	"pissers","pisses","pissflaps","pissin","pissing","pissoff","poop","porn","porno","pornography",
	"pornos","prick","pricks","pron","pube","pusse","pussi","pussies","pussy","pussys",
	"rectum","retard","rimjaw","rimming","s hit","s.o.b.","sadist","schlong","screwing","scroat",
	"scrote","scrotum","semen","sex","sh!+","sh!t","sh1t","shag","shagger","shaggin",
	"shagging","shemale","shi+","shit","shitdick","shite","shited","shitey","shitfuck","shitfull",
	"shithead","shiting","shitings","shits","shitted","shitter","shitters","shitting","shittings","shitty",
	"skank","slut","sluts","smegma","smut","snatch","son-of-a-bitch","spunk","s_h_i_t",
	"t1tt1e5","t1tties","teets","teez","testical","testicle","tit","titfuck","tits","titt",
	"tittie5","tittiefucker","titties","tittyfuck","tittywank","titwank","tosser","turd","tw4t","twat",
	"twathead","twatty","twunt","twunter","v14gra","v1gra","vagina","viagra","vulva","w00se",
	"wang","wank","wanker","wanky","whoar","whore","willies","willy","xrated","japierdole",
	"spierdolina","kórwa","kórva","huj","chój","hój","chuj","choj","chuje","chóje","hóje","huje","korwa","kurwa","kurva",
	"pierdoliæ","pierdolic","pierdolony","popierdolony","pojebany","kurw@","kórw@","przybierdoli³","przypierdoliæ",
	"przypierdoli³a","pojebaæ","pojebac","jebany","jebanego","pojebanego","pojebana","hójowy","chójowy","hujowy","chujowy",
	"kurw","dziwka","dzifka","dŸwka","fack","jebaæ","pierdole","dojebaæ","dojebac",
	"jebac","pizda","szmata","pizdy","pizdo","wyjebane","hentai","pierdol","pizd","jeban","kutas","pedale",
	"cipy","szmato","zajebie","plecojeb","bjebal","zjeb","spierdala",
	"napierdala","cipka","cipe","suka","suko","pojeb","gówno","gowno"
};


stock FindString(string1[],string2[],&start = 0,&end = 0){
	if(!strlen(string1) || !strlen(string2)) return false;
	new num = strfind(string1,string2,true);
	if(num != -1){
		start = num;
		end = start+strlen(string2);
		return true;
	}
	return false;
}

stock CensorText(text[]){
	new tmp_buff[32], szSource[256], _start, _end, _find = 0;
	fstrcopy(text,szSource);
	
	for(new i = 0,j = sizeof(badwords); i < j; i++){
		while(FindString(szSource,badwords[i],_start,_end)){
			//if(_start != 0 && (szSource[_start-1]) != ' ') break;

			fstrcopy(badwords[i],tmp_buff);

			for(new g = 1,h = strlen(tmp_buff); g < h - 1; g++){
				tmp_buff[g] = '*';
			}

			strdel(text,_start,_end);
			strins(text,tmp_buff,_start,256);

			strdel(szSource,_start,_end);
			strins(szSource,tmp_buff,_start,256);

			_find++;
		}
	}

	if(_find>0) {
		return 1;
	} else {
		return 0;
	}
}

/*
//Hook: SendClientMessage
stock AC_SendClientMessage(playerid,color,const message[]){
	new tmp_buff[256];
	format(tmp_buff,sizeof(tmp_buff),"%s",message);
	CensorText(tmp_buff);
	SendClientMessage(playerid,color,tmp_buff);
	return 1;
}

#if defined _ALS_SendClientMessage
    #undef SendClientMessage
#else
    #define _ALS_SendClientMessage
#endif
#define SendClientMessage AC_SendClientMessage

//Hook: SendClientMessageToAll
stock AC_SendClientMessageToAll(color,const message[]){
	new tmp_buff[256];
	format(tmp_buff,sizeof(tmp_buff),"%s",message);
	CensorText(tmp_buff);
	SendClientMessageToAll(color,tmp_buff);
	return 1;
}

#if defined _ALS_SendClientMessageToAll
    #undef SendClientMessageToAll
#else
    #define _ALS_SendClientMessageToAll
#endif
#define SendClientMessageToAll AC_SendClientMessageToAll

*/
