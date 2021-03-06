enum ZmiennePojazdy {
	//bool:IsUsedATrailer,
	//TrailerIDUsed,
	TuningID,
	PrywatneAutoH,
	PrywatneAutoKola
};

enum Zlecenia {
	ZaladunekID,
	RozladunekID
};

enum FirmaDane {
	Kasa,
	LiczbaCzlonkow,
	MaxCzlonkow,
	Poziom,
	Dostarczenia,
	Pojazd[MAX_VEHICLES]
};

enum Dane {
	AktualnyCheckpoint,
	MaxCheckpointy,
	FrakcjaPolicja,
	FrakcjaPomocDrogowa,
	FrakcjaStrazGraniczna,
	FrakcjaMedyk,
	FrakcjaTaxi,
	FrakcjaWojsko,
	FrakcjaSP,
	towar,
	ban,
	bool:Radar,
	bool:StatusJail,
	bool:adminping,
	bool:StatusMute,
	bool:Vip,
	TowarTony,
	Float:checkx,
	Float:checky,
	Float:checkz,
	pojazdzleceniowy,
	przyczepazleceniowa,
	ZaplaconeOplaty,
	CzasWiezienia,
	OplataPolicji,
	OplataTaxi,
	OplataSG,
	OplataPomocyDrogowej,
	Poziom,
	Prawko,
	KontoBankowe,
	KasaBank,
	Warny,
	VipLvl,
	LiderPolicji,
	LiderPomocyDrogowej,
	LiderStrazyGranicznej,
	LiderMedykow,
	LiderTaxi,
	LiderSP,
	LiderWojska,
	bool:StatusZW,
	bool:LiderPD,
	bool:LiderP,
	bool:LiderT,
	bool:LiderM,
	bool:LiderW,
	bool:LiderSG,
	bool:LiderStraz,
	bool:Zalogowany,
	AdminLvl,
	RangaGracza,
	bool:TestTeoretyczny,
	bool:GraczPickup,
	bool:WynajemKuter,
	bool:WynajemLaunch,
	bool:WynajemCoastguard,
	bool:Nowy,
 	bool:StatusSmierci,
 	bool:StatusViewC,
 	bool:FotoradarCount,
	NumerLotto,
	IloscPKT,
	PrzynetaJakosc,
	Wedka,
	RybaJakosc1,
	RybaJakosc2,
	bool:Zemdlenie,
 	bool:StatusPm,
	RybaJakosc3,
	RybaJakosc4,
	RybaJakosc5,
	Kajdanki,
	Wiadro,
	WiadroPojemnosc,
	Dowod,
	Paszport,
	PoradnikNumer,
	StawkaPrzejazdu,
 	PktKarne,
 	CzasPrawka,
 	Wizyty,
 	Zgony,
 	IDWyplaty,
	bool:GraczRobiPrawko,
 	ZapisanySkin,
 	SmiercSpawn,
 	SlotyAuta,
 	Plec,
 	VWarny,
 	WiadomosciTick,
 	Glod,
 	Zmeczenie,
 	IPp[18],
	bool:Pasy,
	bool:ViewPM,
	IloscPytan,
	Float:SpecX,
	Float:SpecY,
	Float:SpecZ,
	bool:SluchaRadia,
	bool:LowiRyby,
	WarnyMH,
	bool:PozwolenieBron,
	WydanychVipow,
	bool:AdminDalBron,
	bool:MisjaVip,
	CheckpointVip,
	bool:Specowanie,
	DomID,
	Float:SmiercX,
	Float:SmiercY,
	Float:SmiercZ,
	UIDDomu,
	CzasOnline,
	DniOplacenia,
	bool:TrybFilmowy,
	bool:DostalLek,
	bool:blokadacmd,
	MiniJob,
	JobsID,
	bool:BLCMD,
	ZespawnowaneAuto,
	WskaznikLowienia,
	BronM4,
	CBKanal,
	bool:vippogo,
	bool:RaportAB,
	bool:VwarnBlokada,
	bool:WiezienieWoj,
	bool:StatusIP,
	SkinKierowcy,
	Kask,
	Float:fotoradarX,
	Float:fotoradarY,
	Float:fotoradarZ,
	bool:PostawilFotoradar,
	fotoradarLimit,
	bool:JuzUmarl,
	FirmaID,
	FirmaUID,
	ZaproszenieDoFirmy,
	CzasAJ,
 	LiderFirmy,
	bool:ZalogowanyBank,
	bool:AnulowanieTowaru,
	bool:StatusViewF,
	UIDbazy,
	bool:tempomat,
	OstatniaWiadomosc[300],
	PrawkoC,
	PrawkoA,
	Blokada998,
	KasynoGra,
	IDprzeciwnika,
	ZaliczylKolej,
	Float:NewX,
	Float:NewY,
	Float:NewZ,
	MozliwoscRzutu,
	AntyAFKLicznik,
	Float:AntyAFKx,
	Float:AntyAFKy,
	Float:AntyAFKz,
	Float:AntyAFKr,
	bool:GraczRobiPrawkoC,
	//LogowanieKick,
	LicencjaBronBiala,
	TestTeoretycznyC,
	LicznikPrzejecia,
	SprawdzenieAntySob,
	bool:GlosowalWankiecie,
	PodrozAutokarem,
	bool:PrywatneAutoSpawn,
	PozwolenieNaWejscie,
	BledneLogowanie,
	p_money,
	p_score,
	tick_count,
	pozar_auto,
	bool:acid_renia,
	bool:towar_gotowy,
	performingAnim,
	lastFireKeypress,
	bool:firstspawn,
	bool:prot_hack_detect,
	prot_pizdr,
	last_weapon,
	isRcon,
	bool:connected,
	ostatnie_rozbrojenie
};

enum PozaryDane {
	Float:Pozx,
	Float:Pozy,
	Float:Pozz,
	Float:PozHP,
	Text3D:Text3D,
	PozTimer,
	Obiekt,
	Float:Zasieg,
	TrwaniePozaru
};

enum PrywatneLodzie
{
	UID,
	Model,
	Float:SpawnX,
	Float:SpawnY,
	Float:SpawnZ,
	Float:SpawnR,
	WlascicielLodzi[40],
	Nazwa[30],
	CenaLodzi,
	Poziom,
	Wlasc[24],
	GtaUID,
	OwnerID
};
