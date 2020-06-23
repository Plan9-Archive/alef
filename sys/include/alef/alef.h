#pragma src "/sys/src/alef/lib"
#pragma lib "/$M/lib/alef/libA.a"

/*
 *	definitions common to Plan 9 & Unix
 */

typedef uint Rune;

enum
{
	ERRLEN	=	64,
	ERRMAX	=	128,

	/* open */
	OREAD	=	0,
	OWRITE	=	1,
	ORDWR	=	2,
	OEXEC	=	3,
	OTRUNC	=	16,
	OCEXEC	=	32,
	ORCLOSE	=	64,
	OEXCL	=	0x1000,
};
	/* Runtime system constants settable by applications */

extern	int	ALEFstack;
extern	int	ALEFrfflag;
extern	void	(*ALEFcheck)(byte*, byte*);

aggr Arg
{
	byte	*arg0;
	int	ac;
	byte	**av;
	byte	*p;
};

/* common utility functions and system calls */
void	abort(void);
int	access(byte*, int);
int	alarm(uint);
byte	*argf(Arg*);
Arg	*arginit(int, byte**);
Rune	argopt(Arg*);
int	atoi(byte*);
int	brk(void*);
int	chdir(byte*);
int	close(int);
int	errstr(byte*, uint);
int	exec(byte*, byte**);
int	execl(byte*, ...);
void	exits(byte*);
void	_exits(byte*);
void	fatal(byte*, ...);
int	fork(void);
byte*	getenv(byte*);
int	getpid(void);
int	getppid(void);
byte	*getuser(void);
void	qsort(void*, int, int, int (*)(void*, void*));
int	rfork(int);
int	open(byte*, int);
int	pipe(int*);
int	pread(int, void*, int, lint);
int	pwrite(int, void*, int, lint);
int	read(int, void*, int);
int	readn(int, void*, int);
int	rendezvous(void*, void*);
void*	sbrk(uint);
int	sleep(int);
int	tokenize(byte*, byte**, int);
void	terminate(byte*);
void	werrstr(byte*, ...);
int	write(int, void*, int);

int	atexit(void(*)(void));
void	atexitdont(void(*)(void));
/*
 * time routines
 */
byte*	ctime(int);
/*
 * print routines
 */
aggr Printspec
{
	void	*o;
	int	f1, f2, f3;
	int	chr;

	byte	*out;
	byte	*eout;
};

int	print(byte*, ...);
int	fprint(int, byte*, ...);
int	sprint(byte*, byte*, ...);
int	snprint(byte*, int, byte*, ...);
byte*	doprint(byte*, byte*, byte*, void*);
void	strconv(Printspec*, byte*);
int	fmtinstall(int, int (*)(Printspec*));
/*
 * mem routines
 */
void*	memccpy(void*, void*, int, uint);
void*	memset(void*, int, uint);
int	memcmp(void*, void*, uint);
void*	memcpy(void*, void*, uint);
void*	memmove(void*, void*, uint);
void*	memchr(void*, int, uint);
/*
 * string routines
 */
byte*	strcat(byte*, byte*);
byte*	strchr(byte*, byte);
int	strcmp(byte*, byte*);
byte*	strcpy(byte*, byte*);
byte*	strdup(byte*);
byte*	strncpy(byte*, byte*, int);
int	strncmp(byte*, byte*, int);
byte*	strrchr(byte*, byte);
int	strlen(byte*);
byte*	strstr(byte*, byte*);
float	strtof(byte*, byte**);
int	strtoi(byte*, byte**, int);
uint	strtoui(byte*, byte**, int);
/*
 * math
 */
float	Inf(int);
float	NaN(void);
int	abs(int);
float	acos(float);
float	asin(float);
float	atan(float);
float	atan2(float, float);
float	ceil(float);
float	cos(float);
float	cosh(float);
float	exp(float);
float	fabs(float);
float	floor(float);
float	fmod(float, float);
float	frexp(float, int*);
uint	getfcr();
uint	getfsr();
float	hypot(float, float);
int	isInf(float, int);
int	isNaN(float);
float	ldexp(float, int);
float	log(float);
float	modf(float, float*);
float	pow(float, float);
float	pow10(int);
void	setfcr(uint);
void	setfsr(uint);
float	sin(float);
float	sinh(float);
float	sqrt(float);
float	tan(float);
float	tanh(float);

#define	HUGE	3.4028234e38
#define	PIO2	1.570796326794896619231e0
#define	PI	(PIO2+PIO2)


/*
 * memory allocation
 */
void*	malloc(uint);
void	free(void*);
void*	realloc(void*, uint);
/*
 * rune routines
 */
enum
{
	UTFmax		= 4,		/* maximum bytes per rune */
	Runesync	= 0x80,		/* cannot represent part of a UTF sequence (<) */
	Runeself	= 0x80,		/* rune and UTF sequences are the same (<) */
	Runeerror	= 0xFFFD,		/* decoding error in UTF */
};
int	runetochar(byte*, Rune*);
int	chartorune(Rune*, byte*);
int	runelen(int);
int	fullrune(byte*, int);
/*
 * rune routines from converted str routines
 */
int	utflen(byte*);			/* was countrune */
byte*	utfrune(byte*, int);
byte*	utfrrune(byte*, int);
byte*	utfutf(byte*, byte*);
/*
 * random number generators
 */
void	srand(uint);
int	lrand(void);
int	nrand(int);
float	frand(void);

/*	common adt's */
/*
 * synchronisation
 */
adt Lock
{
	int	val;

	void	lock(*Lock);
	void	unlock(*Lock);
	int	canlock(*Lock);
};

adt QLock
{
	Lock	use;
	int	used;
	void	*queue;

	void	lock(*QLock);
	void	unlock(*QLock);
	int	canlock(*QLock);
};

adt RWlock
{
	Lock;
	QLock	x;
	QLock	k;
	int	readers;

	void	Rlock(*RWlock);
	void	Runlock(*RWlock);

	void	Wlock(*RWlock);
	void	Wunlock(*RWlock);
};

adt Ref
{
	Lock	l;
	int	cnt;

	int	inc(*Ref);
	int	dec(*Ref);
	int	ref(*Ref);
};

/*	--CUT HERE--
 *	Definitions specific to Plan 9
 */
enum
{
	NAMELEN	=	28,
	DIRLEN	=	116,

	/* bind/mount */
	MORDER	=	0x0003,
	MREPL	=	0x0000,
	MBEFORE	=	0x0001,
	MAFTER	=	0x0002,
	MCREATE	=	0x0004,
	MCACHE	=	0x0010,
	MMASK	=	0x0017,

	/* notes */
	NCONT	=	0,
	NDFLT	=	1,
	NSAVE	=	2,
	NRSTR	=	3,

	/* rfork */
	RFNAMEG		= (1<<0),
	RFENVG		= (1<<1),
	RFFDG		= (1<<2),
	RFNOTEG		= (1<<3),
	RFPROC		= (1<<4),
	RFMEM		= (1<<5),
	RFNOWAIT	= (1<<6),
	RFCNAMEG	= (1<<10),
	RFCENVG		= (1<<11),
	RFCFDG		= (1<<12),
	RFREND		= (1<<13),
	RFNOMNT		= (1<<14),

	/* File modes */
	CHDIR	= 0x80000000,
	CHAPPEND= 0x40000000,
	CHEXCL	= 0x20000000,
	CHREAD	= 0x4,
	CHWRITE	= 0x2,
	CHEXEC	= 0x1,

	PNPROC	= 1,
	PNGROUP	= 2,
};

aggr Qid
{
	ulint	path;
	uint	vers;
	byte	type;
};

aggr Dir
{
	usint	type;
	uint	dev;

	Qid	qid;
	uint	mode;
	uint	atime;
	uint	mtime;
	lint	length;
	byte*	name;
	byte*	uid;
	byte*	gid;
	byte*	muid;
};

aggr Waitmsg
{
	int	pid;
	uint	time[3];
	byte*	msg;
};

aggr Tm
{
	int	sec;
	int	min;
	int	hour;
	int	mday;
	int	mon;
	int	year;
	int	wday;
	int	yday;
	byte	zone[4];
	int	tzoff;
};
/*
 *	Plan 9 system calls
 */
int	bind(byte*, byte*, int);
int	brk_(void*);
int	create(byte*, int, uint);
int	dup(int, int);
int	fauth(int, byte*);
int	_fsession(int, byte*, uint);
int	fstat(int, byte*, int);
int	fwstat(int, byte*, int);
int	mount(int, int, byte*, int, byte*);
int	noted(int);
int	notify(void(*)(void*, byte*));
int	postnote(int, int, byte*);
int	remove(byte*);
int	seek(int, lint, int);
int	segattach(int, byte*, void*, uint);
int	segbrk(void*, void*);
int	segdetach(void*);
int	segflush(void*, uint);
int	segfree(void*, uint);
int	stat(byte*, byte*, int);
int	unmount(byte*, byte*);
int	_wait(Waitmsg*);
int	wstat(byte*, byte*, int);
/*
 *	Directory access
 */
int	convM2D(byte*, Dir*);
int	convD2M(Dir*, byte*);
int	dirfstat(int, Dir*);
int	dirfwstat(int, Dir*);
int	dirread(int, Dir*, int);
int	dirstat(byte*, Dir*);
int	dirwstat(byte*, Dir*);
/*
 *  Network dialing and authentication
 */
#define NETPATHLEN 40
int	accept(int, byte*);
int	announce(byte*, byte*);
int	dial(byte*, byte*, byte*, int*);
int	hangup(int);
int	listen(byte*, byte*);
byte*	netmkaddr(byte*, byte*, byte*);
int	reject(int, byte*, byte*);
int	encrypt(void*, void*, int);
int	decrypt(void*, void*, int);
/*
 *	Time routines
 */
byte*	asctime(Tm*);
Tm*	gmtime(int);
Tm*	localtime(int);
uint	mstime();
int	time(void);
/*
 *	Miscellaneous Plan 9 functions
 */
byte	*getwd(byte*, int);
int	putenv(byte*, byte*);
void	syslog(int, byte*, byte*, ...);
int	times(int*);
